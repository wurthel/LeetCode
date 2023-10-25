use std::cmp::max;
use std::collections::HashMap;

struct Solution {}

impl Solution {
    pub fn max_profit(k: i32, prices: Vec<i32>) -> i32 {
        let mut mem = HashMap::new();
        Solution::dp(&mut mem, &prices, 0, k, 0)
    }

    fn dp(mem: &mut HashMap<(i32, i32, i32), i32>, prices: &Vec<i32>, i: i32, k: i32, h: i32) -> i32 {
        if i == prices.len() as i32 || k == 0 {
            return 0;
        } else {
            if mem.contains_key(&(i, k, h)) {
                return *mem.get(&(i, k, h)).unwrap();
            }
            let mut buy = i32::MIN;
            let mut sell = i32::MIN;
            if h == 0 {
                buy = -prices[i as usize] + Solution::dp(mem, prices, i + 1, k, 1);
            }
            if h == 1 {
                sell = prices[i as usize] + Solution::dp(mem, prices, i + 1, k - 1, 0);
            }
            let do_nothing = Solution::dp(mem, prices, i + 1, k, h);
            let profit = max(max(buy, sell), do_nothing);
            mem.insert((i, k, h), profit);
            profit
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn it_works() {
        let result = Solution::max_profit(2, vec![2, 4, 1]);
        assert_eq!(result, 2);

        let result = Solution::max_profit(2, vec![3, 2, 6, 5, 0, 3]);
        assert_eq!(result, 7);

        let result = Solution::max_profit(2, vec![3,3,5,0,0,3,1,4]);
        assert_eq!(result, 6);
    }
}
