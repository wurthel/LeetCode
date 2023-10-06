use std::collections::HashMap;

use rand::Rng;
use rand::seq::SliceRandom;

struct RandomizedSet {
    map: HashMap<i32, i32>,
    arr: Vec<i32>,
}


impl RandomizedSet {
    fn new() -> Self {
        Self {
            map: HashMap::new(),
            arr: Vec::new(),
        }
    }

    fn insert(&mut self, val: i32) -> bool {
        if self.map.contains_key(&val) {
            false
        } else {
            self.map.insert(val, self.arr.len() as i32);
            self.arr.push(val);
            true
        }
    }

    fn remove(&mut self, val: i32) -> bool {
        match self.map.remove(&val) {
            None => false,
            Some(i) => {
                self.arr.swap_remove(i as usize);
                if i < self.arr.len() as i32 {
                    self.map.insert(self.arr[i as usize], i);
                }
                true
            }
        }
    }

    fn get_random(&self) -> i32 {
        *self.arr.choose(&mut rand::thread_rng()).unwrap()
    }
}

#[cfg(test)]
mod tests {
    use crate::RandomizedSet;

    #[test]
    fn it_works() {
        let mut obj = RandomizedSet::new();
        assert_eq!(obj.insert(1), true);
        assert_eq!(obj.insert(1), false);
        assert_eq!(obj.remove(2), false);
        assert_eq!(obj.insert(2), true);
        obj.get_random();
        assert_eq!(obj.remove(1), true);
        assert_eq!(obj.insert(2), false);
        assert_eq!(obj.get_random(), 2);
    }
}
