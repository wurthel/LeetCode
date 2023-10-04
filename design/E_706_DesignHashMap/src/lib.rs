struct MyHashMap {
    buckets: Vec<Vec<(i32, i32)>>,
    key_range: i32,
}


impl MyHashMap {
    fn new() -> Self {
        let key_range = 2049;
        Self {
            buckets: vec![Vec::new(); key_range],
            key_range: key_range as i32,
        }
    }

    fn put(&mut self, key: i32, value: i32) {
        let bucket_key = self.bucket_key(key);
        let bucket = self.buckets.get_mut(bucket_key).unwrap();
        if let Some(idx) = bucket.iter().position(|(k, _)| *k == key) {
            bucket[idx] = (key, value)
        } else {
            bucket.push((key, value))
        }
    }

    fn get(&mut self, key: i32) -> i32 {
        let bucket_key = self.bucket_key(key);
        let bucket = self.buckets.get_mut(bucket_key).unwrap();
        match bucket.iter().position(|(k, _)| *k == key) {
            Some(idx) => bucket[idx].1,
            None => -1
        }
    }

    fn remove(&mut self, key: i32) {
        let bucket_key = self.bucket_key(key);
        let bucket = self.buckets.get_mut(bucket_key).unwrap();
        if let Some(idx) = bucket.iter().position(|(k, _)| *k == key) {
            bucket.swap_remove(idx);
        }
    }

    fn bucket_key(&self, key: i32) -> usize {
        (key % self.key_range) as usize
    }
}

/**
 * Your MyHashMap object will be instantiated and called as such:
 * let obj = MyHashMap::new();
 * obj.put(key, value);
 * let ret_2: i32 = obj.get(key);
 * obj.remove(key);
 */
#[cfg(test)]
mod tests {
    use crate::MyHashMap;

    #[test]
    fn it_works() {
        let mut hm = MyHashMap::new();
        hm.put(1, 1);
        hm.put(2, 2);
        assert_eq!(hm.get(1), 1);
        assert_eq!(hm.get(3), -1);
        hm.put(2, 1);
        assert_eq!(hm.get(2), 1);
        hm.remove(2);
        assert_eq!(hm.get(2), -1);
    }
}
