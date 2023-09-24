
use std::cell::RefCell;
use std::option::Option;
use std::rc::Rc;

type NodeType = Option<Rc<RefCell<Node>>>;

struct Node {
    val: i32,
    prev: NodeType,
    next: NodeType,
}

impl Node {
    fn new(val: i32) -> Self {
        Self {
            val,
            prev: None,
            next: None,
        }
    }
}

struct MyLinkedList {
    head: NodeType,
    tail: NodeType,
    size: usize,
}

impl MyLinkedList {
    fn new() -> Self {
        MyLinkedList { head: None, tail: None, size: 0 }
    }

    fn len(&self) -> usize {
        self.size
    }

    fn get(&self, index: i32) -> i32 {
        let node = self.get_node_at(index);
        match node {
            Some(node) => node.borrow().val,
            None => -1,
        }
    }

    fn get_node_at(&self, index: i32) -> Option<Rc<RefCell<Node>>> {
        let mut ptr = self.head.as_ref().map(Rc::clone);
        for _ in 0..index {
            ptr = match ptr {
                Some(node) => node.borrow().next.as_ref().map(Rc::clone),
                None => None,
            };
        }
        ptr
    }

    fn add_at_head(&mut self, val: i32) {
        let node = Rc::new(RefCell::new(Node::new(val)));
        if let Some(prev_head) = self.head.take() {
            prev_head.borrow_mut().prev = Some(Rc::clone(&node));
            node.borrow_mut().next = Some(prev_head);
            self.head = Some(node);
            self.size += 1
        } else {
            // edge case: the list is empty
            self.head = Some(Rc::clone(&node));
            self.tail = Some(node);
            self.size = 1;
        }
    }

    fn add_at_tail(&mut self, val: i32) {
        let node = Rc::new(RefCell::new(Node::new(val)));
        if let Some(pref_tail) = self.tail.take() {
            pref_tail.borrow_mut().next = Some(Rc::clone(&node));
            node.borrow_mut().prev = Some(pref_tail);
            self.tail = Some(node);
            self.size += 1
        } else {
            // edge case: the list is empty
            self.head = Some(Rc::clone(&node));
            self.tail = Some(node);
            self.size = 1;
        }
    }

    fn add_at_index(&mut self, index: i32, val: i32) {
        if index == 0 {
            self.add_at_head(val);
        } else if index as usize == self.size {
            self.add_at_tail(val);
        } else if index as usize > self.size {
            return;
        } else if let Some(next) = self.get_node_at(index) {
            let node = Rc::new(RefCell::new(Node::new(val)));
            node.borrow_mut().next = Some(Rc::clone(&next));
            node.borrow_mut().prev = next.borrow().prev.as_ref().map(Rc::clone);
            next.borrow_mut().prev.as_ref().unwrap().borrow_mut().next = Some(Rc::clone(&node));
            next.borrow_mut().prev = Some(node);
            self.size += 1;
        }
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

    fn delete_at_index(&mut self, index: i32) {
        if index == 0 {
            self.delete_at_head();
        } else if index as usize == (self.size - 1) {
            self.delete_at_tail();
            return;
        } else if index as usize >= self.size {
            return;
        } else if let Some(node) = self.get_node_at(index) {
            let prev = node.borrow().prev.clone().unwrap();
            let next = node.borrow().next.clone().unwrap();
            prev.borrow_mut().next = Some(Rc::clone(&next));
            next.borrow_mut().prev = Some(Rc::clone(&prev));
            Rc::try_unwrap(node).ok();
            self.size -= 1;
        }
    }
}

fn main() { }

#[cfg(test)]
mod tests {
    use super::MyLinkedList;

    #[test]
    fn it_works() {
        let mut list = MyLinkedList::new();

        list.add_at_tail(3);
        list.add_at_tail(4);
        assert_eq!(list.delete_at_head(), Some(3));
        assert_eq!(list.len(), 1);

        list.add_at_head(5);
        assert_eq!(list.delete_at_tail(), Some(4));
        assert_eq!(list.delete_at_tail(), Some(5));
        assert_eq!(list.delete_at_tail(), None);
        assert_eq!(list.delete_at_head(), None);
        assert_eq!(list.len(), 0);
    }

    #[test]
    fn can_add_at_tail() {
        let mut list = MyLinkedList::new();
        assert_eq!(list.delete_at_tail(), None);

        list.add_at_tail(3);
        list.add_at_tail(4);
        list.add_at_tail(5);
        assert_eq!(list.delete_at_tail(), Some(5));

        list.add_at_tail(6);
        list.add_at_tail(7);
        assert_eq!(list.delete_at_tail(), Some(7));
        assert_eq!(list.delete_at_tail(), Some(6));
        assert_eq!(list.delete_at_tail(), Some(4));
        assert_eq!(list.delete_at_tail(), Some(3));

        list.add_at_tail(2);
        assert_eq!(list.delete_at_tail(), Some(2));
        assert_eq!(list.delete_at_tail(), None);
        assert_eq!(list.len(), 0);
    }

    #[test]
    fn it_drops_correctly() {
        let mut list = MyLinkedList::new();
        for i in 0..3 {
            list.add_at_tail(i);
        }

        drop(list);
    }

    #[test]
    fn leetcode_test_1() {
        let mut list = MyLinkedList::new();
        list.add_at_head(1);
        list.add_at_tail(3);
        list.add_at_index(1, 2);
        assert_eq!(list.get(0), 1);
        assert_eq!(list.get(1), 2);
        assert_eq!(list.get(2), 3);
        list.delete_at_index(1);
        assert_eq!(list.get(0), 1);
        assert_eq!(list.get(1), 3);
        assert_eq!(list.get(2), -1);
    }

    #[test]
    fn leetcode_test_2() {
        let mut list = MyLinkedList::new();
        list.add_at_head(2);
        list.delete_at_index(1);
        list.add_at_head(2);
        list.add_at_head(7);
        list.add_at_head(7);
        list.add_at_head(3);
        list.add_at_head(2);
        list.add_at_head(5);
        list.add_at_tail(5);
        assert_eq!(list.get(0),5);
        assert_eq!(list.get(1),2);
        assert_eq!(list.get(2),3);
        assert_eq!(list.get(3),7);
        assert_eq!(list.get(4),7);
        assert_eq!(list.get(5),2);
        assert_eq!(list.get(6),2);
        assert_eq!(list.get(7),5);
        assert_eq!(list.get(8),-1);

        list.delete_at_index(6);
        assert_eq!(list.get(5),2);
        assert_eq!(list.get(6),5);
        assert_eq!(list.get(7),-1);
        list.delete_at_index(4);
    }
}
