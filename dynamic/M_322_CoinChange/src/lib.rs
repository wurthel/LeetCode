use std::cmp::min;
use std::collections::HashMap;

struct Solution {}

impl Solution {
    pub fn coin_change(coins: Vec<i32>, amount: i32) -> i32 {
        let mut mem = HashMap::new();
        Solution::dp(&mut mem, &coins, amount)
    }

    fn dp(mem: &mut HashMap<i32, i32>, coins: &Vec<i32>, amount: i32) -> i32 {
        if amount == 0 {
            // Nothing to take
            return 0;
        } else if amount < 0 {
            // We can't take any amount of coins.
            return -1;
        }

        if mem.contains_key(&amount) {
            return *mem.get(&amount).unwrap();
        }

        let mut score = i32::MAX;
        for coin in coins {
            let s = Solution::dp(mem, coins, amount - coin);
            if s != -1 {
                score = min(score, s + 1);
            }
        }
        if score == i32::MAX {
            score = -1;
        }
        mem.insert(amount, score);
        score
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn it_works() {
        let result = Solution::coin_change(vec![1, 2, 5], 11);
        assert_eq!(result, 3);

        let result = Solution::coin_change(vec![2], 3);
        assert_eq!(result, -1);

        let result = Solution::coin_change(vec![1, 2, 5, 10], 18);
        assert_eq!(result, 4);

        let result = Solution::coin_change(vec![2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24], 9999);
        assert_eq!(result, -1);
    }
}
