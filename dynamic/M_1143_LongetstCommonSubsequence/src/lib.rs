use std::cmp::max;
use std::collections::HashMap;

struct Solution {}

impl Solution {
    pub fn longest_common_subsequence(text1: String, text2: String) -> i32 {
        let mut mem = HashMap::new();
        Solution::_dp_button_up(&mut mem, text1.as_str(), text2.as_str(), 0, 0)
    }

    fn _dp(mem: &mut HashMap<(i32, i32), i32>, text1: &str, text2: &str, idx1: i32, idx2: i32) -> i32 {
        if idx1 as usize == text1.len() || idx2 as usize == text2.len()  {
            0
        } else {
            if mem.get(&(idx1, idx2)).is_some() {
                return *mem.get(&(idx1, idx2)).unwrap();
            }
            let score = match text1.as_bytes()[idx1 as usize] == text2.as_bytes()[idx2 as usize] {
                true => {
                    let s = 1 + Solution::_dp(mem, text1, text2, idx1 + 1, idx2 + 1);
                    mem.insert((idx1, idx2), s);
                    s
                },
                false => {
                    let s1 = Solution::_dp(mem, text1, text2, idx1 + 1, idx2);
                    let s2 = Solution::_dp(mem, text1, text2, idx1, idx2 + 1);
                    let s = max(s1, s2);
                    mem.insert((idx1, idx2), s);
                    s
                }
            };
            score
        }
    }

    fn _dp_button_up(mem: &mut HashMap<(i32, i32), i32>, text1: &str, text2: &str, idx1: i32, idx2: i32) -> i32 {
        // Button-Up reimplementation of the above solution
        let n = text1.len();
        let m = text2.len();
        let mut dp = vec![vec![0; n + 1]; m + 1];
        for i in (0..m).rev() {
            for j in (0..n).rev() {
                if text1.as_bytes()[j] == text2.as_bytes()[i] {
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                } else {
                    let s = max(dp[i + 1][j], dp[i][j + 1]);
                    dp[i][j] = s
                }
            }
        }
        dp[0][0]
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn it_works() {
        let result = Solution::longest_common_subsequence("abcde".to_string(), "ace".to_string());
        assert_eq!(result, 3);

        let result = Solution::longest_common_subsequence("ace".to_string(), "abcde".to_string());
        assert_eq!(result, 3);

        let result = Solution::longest_common_subsequence("abc".to_string(), "abc".to_string());
        assert_eq!(result, 3);

        let result = Solution::longest_common_subsequence("abc".to_string(), "def".to_string());
        assert_eq!(result, 0);

        let result = Solution::longest_common_subsequence("abcdeiuquwuejjjshhfydhdddddhdhhhdhdhhhhfhayshwhhg".to_string(), "aceshhfydhdddddhdhhhdhdhhhhfhkjjsiiwuqksjnntmnsnz".to_string());
        assert_eq!(result, 31);

        let result = Solution::longest_common_subsequence("aceshhfydhdddddhdhhhdhdhhhhfhkjjsiiwuqksjnntmnsnz".to_string(), "abcdeiuquwuejjjshhfydhdddddhdhhhdhdhhhhfhayshwhhg".to_string());
        assert_eq!(result, 31);
    }
}
