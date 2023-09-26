

struct MyHashSet {
    bucket: Vec<Vec<i32>>,
    key_range: i32,
}

impl MyHashSet {
    fn new() -> Self {
        let key_range = 2049;
        Self {
            key_range,
            bucket: vec![Vec::new(); key_range as usize]
        }
    }

    fn add(&mut self, key: i32) {
        if !self.contains(key) {
            let bucket_key = (key % self.key_range) as usize;
            self.bucket.get_mut(bucket_key).unwrap().push(key);
        }

    }

    fn remove(&mut self, key: i32) {
        let bucket_key = (key % self.key_range) as usize;
        let mut bucket = self.bucket.get_mut(bucket_key).unwrap();
        if let Some(index) = bucket.iter().position(|&x| x == key){
            bucket.swap_remove(index);
        }
    }

    fn contains(&self, key: i32) -> bool {
        let bucket_key = (key % self.key_range) as usize;
        let mut bucket = self.bucket.get(bucket_key).unwrap();
        bucket.iter().position(|&x| x == key ).is_some()
    }

    fn len(&self) -> usize {
        let mut total_len= 0;
        for bucket in &self.bucket {
            total_len += bucket.len();
        }
        total_len
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn it_works() {
        let mut set = MyHashSet::new();
        set.add(1);
        set.add(2);
        assert_eq!(set.len(), 2);
        assert_eq!(set.contains(1), true);
        assert_eq!(set.contains(2), true);
        set.add(1);
        assert_eq!(set.len(), 2);
        set.remove(1);
        assert_eq!(set.contains(1), false);
        assert_eq!(set.len(), 1);
    }
}
