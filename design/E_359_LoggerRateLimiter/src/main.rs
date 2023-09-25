use std::collections::HashMap;

struct Logger {
    history: HashMap<String, i32>,
}


impl Logger {
    fn new() -> Self {
        Self {
            history: HashMap::new()
        }
    }

    fn should_print_message(&mut self, timestamp: i32, message: String) -> bool {
        let mut should_be_printed = true;
        self.history
            .entry(message)
            .and_modify(|next_allowed| {
                if timestamp < *next_allowed {
                    should_be_printed = false
                } else {
                    *next_allowed = timestamp + 10;
                }
            })
            .or_insert(timestamp + 10);
        should_be_printed
    }
}

fn main() {}

#[cfg(test)]
mod test {
    use crate::Logger;

    #[test]
    fn test_simple() {
        let mut logger = Logger::new();
        assert_eq!(logger.should_print_message(1, "foo".to_string()), true);  // return true, next allowed timestamp for "foo" is 1 + 10 = 11
        assert_eq!(logger.should_print_message(2, "bar".to_string()), true);  // return true, next allowed timestamp for "bar" is 2 + 10 = 12
        assert_eq!(logger.should_print_message(3, "foo".to_string()), false);  // 3 < 11, return false
        assert_eq!(logger.should_print_message(8, "bar".to_string()), false);  // 8 < 12, return false
        assert_eq!(logger.should_print_message(10, "foo".to_string()), false); // 10 < 11, return false
        assert_eq!(logger.should_print_message(11, "foo".to_string()), true); // 11 >= 11, return true,
    }
}