use std::collections::VecDeque;
struct HitCounter {
    ttl: i32,
    queue: VecDeque<i32>,
}


/**
 * `&self` means the method takes an immutable reference
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl HitCounter {
    fn new() -> Self {
        Self {
            ttl: 300,
            queue: VecDeque::new(),
        }
    }

    fn hit(&mut self, timestamp: i32) {
        self.queue.push_back(timestamp);
    }

    fn get_hits(&mut self, timestamp: i32) -> i32 {
        self.queue = self.queue.iter().skip_while(|&x| timestamp - x >= self.ttl).cloned().collect();
        self.queue.len() as i32
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn it_works() {
        let mut counter = HitCounter::new();
        counter.hit(1);
        counter.hit(2);
        counter.hit(3);
        assert_eq!(counter.get_hits(4), 3);
        counter.hit(300);
        assert_eq!(counter.get_hits(300), 4);
        assert_eq!(counter.get_hits(301), 3);
    }
}
