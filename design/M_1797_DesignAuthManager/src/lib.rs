use std::collections::HashMap;

struct Token {
    name: String,
    expired_at: i32,
}

impl Token {
    fn new(name: String, expired_at: i32) -> Self {
        Self {
            name,
            expired_at,
        }
    }

    fn is_valid(&self, current_time: i32) -> bool {
        (self.expired_at - current_time) > 0
    }

    fn renew(&mut self, expired_at: i32) {
        self.expired_at = expired_at;
    }
}

struct AuthenticationManager {
    time_to_live: i32,
    tokens: HashMap<String, Token>,
}

impl AuthenticationManager {
    fn new(time_to_live: i32) -> Self {
        Self {
            time_to_live,
            tokens: HashMap::new(),
        }
    }

    fn generate(&mut self, token_id: String, current_time: i32) {
        let token = Token::new(token_id.clone(), current_time + self.time_to_live);
        self.tokens.insert(token_id, token);
    }

    fn renew(&mut self, token_id: String, current_time: i32) {
        if let Some(token) = self.tokens.get_mut(&token_id) {
            if token.is_valid(current_time) {
                token.renew(current_time + self.time_to_live);
            }
        }
    }

    fn count_unexpired_tokens(&self, current_time: i32) -> i32 {
        self.tokens.values().filter(|token| token.is_valid(current_time)).count() as i32
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn it_works() {
        let mut manager = AuthenticationManager::new(5);
        manager.renew("aaa".to_string(), 1);
        manager.generate("aaa".to_string(), 2);
        assert_eq!(manager.count_unexpired_tokens(6), 1);
        manager.generate("bbb".to_string(), 7);
        manager.renew("aaa".to_string(), 8);
        manager.renew("bbb".to_string(), 10);
        assert_eq!(manager.count_unexpired_tokens(15), 0);
    }
}
