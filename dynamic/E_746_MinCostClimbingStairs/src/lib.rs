use std::cmp::min;
use std::collections::HashMap;

struct Solution {}

impl Solution {
    pub fn min_cost_climbing_stairs(cost: Vec<i32>) -> i32 {
        let mut mem = HashMap::new();
        let p1 = Solution::_min_cost_climbing_stairs(&mut mem, &cost, cost.len() as i32 - 1);
        let p2 = Solution::_min_cost_climbing_stairs(&mut mem, &cost, cost.len() as i32 - 2);
        min(p1, p2)
    }

    fn _min_cost_climbing_stairs(mem: &mut HashMap<i32, i32>, cost: &Vec<i32>, idx: i32) -> i32 {
        if idx == 0 {
            cost[0]
        } else if idx == 1 {
            min(cost[1], cost[0] + cost[1]) // actually it will always return the first value
        } else {
            if mem.contains_key(&idx) {
                *mem.get(&idx).unwrap()
            } else {
                let p0 = cost[idx as usize];
                let p1 = Solution::_min_cost_climbing_stairs(mem, cost, idx - 1);
                let p2 = Solution::_min_cost_climbing_stairs(mem, cost, idx - 2);
                let p = p0 + min(p1, p2);
                mem.insert(idx, p);
                p
            }
        }
    }

    pub fn min_cost_climbing_stairs_button_up(cost: Vec<i32>) -> i32 {
        // Button-up reimplementation of the above solution
        if cost.len() == 1 {
            cost[0]
        } else if cost.len() == 2 {
            min(cost[1], cost[0])
        } else {
            let mut dp = vec![0; cost.len()];
            dp[0] = cost[0];
            dp[1] = min(cost[1], cost[0] + cost[1]);
            for i in 2..cost.len() {
                let p1 = dp[i - 1];
                let p2 = dp[i - 2];
                dp[i] = cost[i] + min(p1, p2);
            }
            min(dp[cost.len() - 1], dp[cost.len() - 2])
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn it_works() {
        let result = Solution::min_cost_climbing_stairs(vec![10, 15, 20]);
        assert_eq!(result, 15);

        let result = Solution::min_cost_climbing_stairs(vec![1,100,1,1,1,100,1,1,100,1]);
        assert_eq!(result, 6);

        let result = Solution::min_cost_climbing_stairs(vec![1,100]);
        assert_eq!(result, 1);

        let result = Solution::min_cost_climbing_stairs_button_up(vec![10, 15, 20]);
        assert_eq!(result, 15);

        let result = Solution::min_cost_climbing_stairs_button_up(vec![1,100,1,1,1,100,1,1,100,1]);
        assert_eq!(result, 6);

        let result = Solution::min_cost_climbing_stairs_button_up(vec![1,100]);
        assert_eq!(result, 1);
    }
}
