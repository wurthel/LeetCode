use std::collections::HashMap;

struct Solution {}

impl Solution {
    pub fn word_break(s: String, word_dict: Vec<String>) -> bool {
        let mut mem = HashMap::new();
        Solution::dp(&mut mem, &word_dict, s.clone(), s.len() as i32 - 1)
    }

    fn dp(mem: &mut HashMap<i32, bool>, word_dict: &Vec<String>, s: String, i: i32) -> bool {
        if i < 0 {
            true
        } else {
            let mut result = false;
            if mem.contains_key(&i) {
                return *mem.get(&i).unwrap();
            }
            'outer: for word in word_dict.iter() {
                let previous = Solution::dp(mem, word_dict, s.clone(), i - word.len() as i32) && i >= word.len() as i32 - 1;
                if previous && s.as_str()[(i - word.len() as i32 + 1) as usize..(i + 1) as usize] == word.as_str()[..] {
                    result = true;
                    break 'outer;
                }
            }
            mem.insert(i, result);
            result
        }
    }
}

#[cfg(test)]
mod tests {
    use crate::Solution;

    #[test]
    fn it_works() {
        let result = Solution::word_break("leetcode".to_string(), vec!["leet".to_string(), "code".to_string()]);
        assert!(result);

        let result = Solution::word_break("applepenapple".to_string(), vec!["apple".to_string(), "pen".to_string()]);
        assert!(result);

        let result = Solution::word_break("catsandog".to_string(), vec!["cats".to_string(), "dog".to_string()]);
        assert!(!result);
    }
}
