use std::cmp::max;
use std::collections::HashMap;

struct Solution {}

impl Solution {
    pub fn rob(nums: Vec<i32>) -> i32 {
        let mut mem = HashMap::new();
        Solution::_rob(&mut mem, &nums, nums.len() as i32 - 1)
    }

    fn _rob(mem: &mut HashMap<i32, i32>, nums: &Vec<i32>, idx: i32) -> i32 {
        if idx == 0 {
            nums[0]
        } else if idx == 1 {
            max(nums[0], nums[1])
        } else if mem.contains_key(&idx) {
            *mem.get(&idx).unwrap()
        } else {
            let g1 = nums[idx as usize] + Solution::_rob(mem, nums, idx - 2); // Rob the house
            let g2 = Solution::_rob(mem, nums, idx - 1); // Don't rob the house
            let g = max(g1, g2);
            mem.insert(idx, g);
            g
        }
    }

    pub fn rob_button_up(nums: Vec<i32>) -> i32 {
        // Button-Up reimplementation of the above solution
        if nums.len() == 1 {
            nums[0]
        } else if nums.len() == 1 {
            max(nums[0], nums[1])
        } else {
            let mut dp = vec![0; nums.len()];
            dp[0] = nums[0];
            dp[1] = max(nums[0], nums[1]);
            for i in 2..nums.len() {
                let g1 = nums[i] + dp[i - 2];
                let g2 = dp[i - 1];
                dp[i] = max(g1, g2);
            }
            dp[nums.len() - 1]
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn it_works() {
        let result = Solution::rob(vec![1, 2, 3, 1]);
        assert_eq!(result, 4);

        let result = Solution::rob(vec![2, 7, 9, 3, 1]);
        assert_eq!(result, 12);

        let result = Solution::rob_button_up(vec![1, 2, 3, 1]);
        assert_eq!(result, 4);

        let result = Solution::rob_button_up(vec![2, 7, 9, 3, 1]);
        assert_eq!(result, 12);
    }
}
