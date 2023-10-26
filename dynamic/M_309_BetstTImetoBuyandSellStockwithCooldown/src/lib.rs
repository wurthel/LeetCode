use std::cmp::max;
use std::collections::HashMap;

struct Solution {}

impl Solution {
    pub fn max_profit(prices: Vec<i32>) -> i32 {
        let mut mem = HashMap::new();
        Solution::dp(&mut mem, &prices, 0, 0)
    }

    fn dp(mem: &mut HashMap<(i32, i32), i32>, prices: &Vec<i32>, i: i32, handling: i32) -> i32 {
        if i >= prices.len() as i32 {
            return 0;
        } else {
            if mem.contains_key(&(i, handling)) {
                return *mem.get(&(i, handling)).unwrap();
            }
            let mut profit = i32::MIN;
            if handling == 1 {
                let sell = prices[i as usize] + Solution::dp(mem, prices, i + 2, 0);
                let nothing = Solution::dp(mem, prices, i + 1, handling);
                profit = max(sell, nothing);
            } else {
                let buy = -prices[i as usize] + Solution::dp(mem, prices, i + 1, 1);
                let nothing = Solution::dp(mem, prices, i + 1, handling);
                profit = max(buy, nothing);
            }
            mem.insert((i, handling), profit);
            return profit;
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn it_works() {
        let result = Solution::max_profit(vec![1, 2, 3, 0, 2]);
        assert_eq!(result, 3);

        let result = Solution::max_profit(vec![1]);
        assert_eq!(result, 0);
    }
}
