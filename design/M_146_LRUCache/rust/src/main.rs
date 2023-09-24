use std::cell::RefCell;
use std::collections::HashMap;
use std::option::Option;
use std::rc::Rc;

type NodeType = Rc<RefCell<Node>>;
type NodeOrNull = Option<NodeType>;

struct Node {
    key: i32,
    val: i32,
    prev: NodeOrNull,
    next: NodeOrNull,
}

impl Node {
    fn new(key: i32, val: i32) -> Self {
        Self {
            key,
            val,
            prev: None,
            next: None,
        }
    }
}

struct DoubleLinkedList {
    head: NodeOrNull,
    tail: NodeOrNull,
    size: usize,
}

impl DoubleLinkedList {
    fn new() -> Self {
        DoubleLinkedList { head: None, tail: None, size: 0 }
    }

    fn len(&self) -> usize {
        self.size
    }

    fn add_at_head(&mut self, node: NodeType) {
        if let Some(prev_head) = self.head.take() {
            prev_head.borrow_mut().prev = Some(Rc::clone(&node));
            node.borrow_mut().next = Some(prev_head);
            self.head = Some(node);
            self.size += 1;
        } else {
            // edge case: the list is empty
            self.head = Some(Rc::clone(&node));
            self.tail = Some(node);
            self.size = 1;
        }
    }

    fn add_at_tail(&mut self, node: NodeType) {
        if let Some(pref_tail) = self.tail.take() {
            pref_tail.borrow_mut().next = Some(Rc::clone(&node));
            node.borrow_mut().prev = Some(pref_tail);
            self.tail = Some(node);
            self.size += 1;
        } else {
            // edge case: the list is empty
            self.head = Some(Rc::clone(&node));
            self.tail = Some(node);
            self.size = 1;
        }
    }

    fn deattach(&mut self, node: NodeType) {
        let prev_node = node.borrow().prev.as_ref().map(Rc::clone);
        let next_node = node.borrow().next.as_ref().map(Rc::clone);
        if let Some(prev_node) = prev_node.as_ref() {
            prev_node.borrow_mut().next = next_node.as_ref().map(Rc::clone);
        } else {
            // the current node is the head node
            self.head = next_node.as_ref().map(Rc::clone);
        }
        if let Some(next_node) = next_node {
            next_node.borrow_mut().prev = prev_node.as_ref().map(Rc::clone);
        } else {
            // the current node is the tail node
            self.tail = prev_node.as_ref().map(Rc::clone);
        }
        node.borrow_mut().next.take();
        node.borrow_mut().prev.take();
        self.size -= 1;
    }

    fn delete_at_head(&mut self) -> Option<i32> {
        self.head.take().map(|prev_head| {
            self.size -= 1;
            match prev_head.borrow_mut().next.take() {
                Some(node) => {
                    node.borrow_mut().prev = None;
                    self.head = Some(node);
                }
                None => {
                    self.tail.take();
                }
            }
            Rc::try_unwrap(prev_head).ok().unwrap().into_inner().val
        })
    }

    fn delete_at_tail(&mut self) -> Option<i32> {
        self.tail.take().map(|prev_tail| {
            self.size -= 1;
            match prev_tail.borrow_mut().prev.take() {
                Some(node) => {
                    node.borrow_mut().next = None;
                    self.tail = Some(node);
                }
                None => {
                    self.head.take();
                }
            }
            Rc::try_unwrap(prev_tail).ok().unwrap().into_inner().val
        })
    }
}

struct LRUCache {
    capacity: usize,
    map: HashMap<i32, NodeType>,
    lru: DoubleLinkedList,
}

impl LRUCache {
    fn new(capacity: i32) -> Self {
        Self {
            capacity: capacity as usize,
            map: HashMap::new(),
            lru: DoubleLinkedList::new(),
        }
    }

    fn get(&mut self, key: i32) -> i32 {
        if let Some(node) = self.map.get(&key) {
            self.lru.deattach(Rc::clone(node));
            self.lru.add_at_head(Rc::clone(node));
            node.borrow().val
        } else {
            -1
        }
    }

    fn put(&mut self, key: i32, val: i32) {
        if let Some(node) = self.map.get(&key) {
            node.borrow_mut().val = val;
            self.lru.deattach(Rc::clone(node));
            self.lru.add_at_head(Rc::clone(node));
        } else {
            if self.lru.len() >= self.capacity {
                let key = self.lru.tail.as_ref().unwrap().borrow().key;
                self.map.remove(&key);
                self.lru.delete_at_tail();
            }
            let node = Rc::new(RefCell::new(Node::new(key, val)));
            self.lru.add_at_head(Rc::clone(&node));
            self.map.insert(key, node);
        }
    }
}


fn main() {}

#[cfg(test)]
mod tests {
    use std::cell::RefCell;
    use std::rc::Rc;

    use crate::{Node, NodeType};
    
    use crate::LRUCache;

    fn node(key: i32, val: i32) -> NodeType {
        Rc::new(RefCell::new(Node::new(key, val)))
    }

    #[test]
    fn test_leetcode_1() {
        let mut lru = LRUCache::new(2);
        lru.put(1, 1); // cache is {1=1}
        lru.put(2, 2); // cache is {1=1, 2=2}
        lru.get(1);    // return 1
        lru.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
    }

    #[test]
    fn test_leetcode_2() {
        let mut lru = LRUCache::new(3);
        lru.put(1,1);
        lru.put(2,2);
        lru.put(3,3);
        lru.put(4,4);
        assert_eq!(lru.get(4), 4);
        assert_eq!(lru.get(3), 3);
        assert_eq!(lru.get(2), 2);
        assert_eq!(lru.get(1),-1);
        lru.put(5,5);
        assert_eq!(lru.get(1), -1);
        assert_eq!(lru.get(2), 2);
        assert_eq!(lru.get(3), 3);
        assert_eq!(lru.get(4), -1);
        assert_eq!(lru.get(5), 5);
    }
}
