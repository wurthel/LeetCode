use std::cmp::min;
use std::collections::VecDeque;

trait BrowserHistory {
    fn new(homepage: String) -> Self;
    fn visit(&mut self, url: String);
    fn forward(&mut self, steps: i32) -> String;
    fn back(&mut self, steps: i32) -> String;
}

struct BrowserHistoryVecDeque {
    current: String,
    history_stack: VecDeque<String>,
    future_stack: VecDeque<String>,
}

struct BrowserHistoryVec {
    current: usize,
    upper_bound: usize,
    history: Vec<String>,
}

impl BrowserHistory for BrowserHistoryVecDeque {
    fn new(homepage: String) -> Self {
        Self {
            current: homepage,
            history_stack: VecDeque::new(),
            future_stack: VecDeque::new(),
        }
    }
    fn visit(&mut self, url: String) {
        if !self.future_stack.is_empty() {
            self.future_stack.clear();
        }
        self.history_stack.push_front(self.current.clone());
        self.current = url;
    }

    fn forward(&mut self, steps: i32) -> String {
        let steps = min(steps as usize, self.future_stack.len());
        for _ in 0..steps {
            self.history_stack.push_front(self.current.clone());
            self.current = self.future_stack.pop_front().unwrap();
        }
        self.current.clone()
    }

    fn back(&mut self, steps: i32) -> String {
        let steps = min(steps as usize, self.history_stack.len());
        for _ in 0..steps {
            self.future_stack.push_front(self.current.clone());
            self.current = self.history_stack.pop_front().unwrap();
        }
        self.current.clone()
    }
}

impl BrowserHistory for BrowserHistoryVec {
    fn new(homepage: String) -> Self {
        Self {
            current: 0,
            upper_bound: 0,
            history: vec![homepage],
        }
    }

    fn visit(&mut self, url: String) {
        self.current += 1;
        self.upper_bound = self.current;
        if self.current >= self.history.len() {
            self.history.push(url);
        } else {
            self.history[self.current] = url;
        }
    }

    fn forward(&mut self, steps: i32) -> String {
        let steps = min(self.upper_bound - self.current, steps as usize);
        self.current += steps;
        self.history[self.current].clone()
    }

    fn back(&mut self, steps: i32) -> String {
        let steps = min(self.current, steps as usize);
        self.current -= steps;
        self.history[self.current].clone()
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn it_works_vec_deque() {
        let mut obj = BrowserHistoryVecDeque::new("leetcode.com".to_string());
        obj.visit("google.com".to_string());
        obj.visit("facebook.com".to_string());
        obj.visit("youtube.com".to_string());
        assert_eq!(obj.back(1), "facebook.com");
        assert_eq!(obj.back(1), "google.com");
        assert_eq!(obj.forward(1), "facebook.com");
        assert_eq!(obj.back(10), "leetcode.com");
        obj.visit("linkedin.com".to_string());
        assert_eq!(obj.forward(10), "linkedin.com");
    }

    #[test]
    fn it_works_vec() {
        let mut obj = BrowserHistoryVec::new("leetcode.com".to_string());
        obj.visit("google.com".to_string());
        obj.visit("facebook.com".to_string());
        obj.visit("youtube.com".to_string());
        assert_eq!(obj.back(1), "facebook.com");
        assert_eq!(obj.back(1), "google.com");
        assert_eq!(obj.forward(1), "facebook.com");
        assert_eq!(obj.back(10), "leetcode.com");
        obj.visit("linkedin.com".to_string());
        assert_eq!(obj.forward(10), "linkedin.com");
    }
}
