use std::cmp::max;

struct Solution {}

impl Solution {
    pub fn length_of_lis(nums: Vec<i32>) -> i32 {
        let mut dp = vec![0; nums.len()];
        for i in 0..nums.len() {
            let mut best = 0;
            for j in 0..i {
                if nums[i] > nums[j] {
                    best = max(best, dp[j]);
                }
            }
            dp[i] = best + 1;
        }
        return *dp.iter().max().unwrap_or(&0);
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn it_works() {
        let result = Solution::length_of_lis(vec![10, 9, 2, 5]);
        assert_eq!(result, 2);
        //
        let result = Solution::length_of_lis(vec![10, 9, 2, 5, 3, 7, 101, 18]);
        assert_eq!(result, 4);

        let result = Solution::length_of_lis(vec![0, 1, 0, 3, 2, 3]);
        assert_eq!(result, 4);

        let result = Solution::length_of_lis(vec![7, 7, 7, 7, 7]);
        assert_eq!(result, 1);
        //
        let result = Solution::length_of_lis(vec![10, 9, 2, 5, 3, 7, 101, 18, 1, 1, 1, 2, 3]);
        assert_eq!(result, 4);

        let result = Solution::length_of_lis(vec![10, 9, 2, 5, 3, 7, 101, 18, 1, 1, 1, 2, 3, 4, 5, 6, 7, 8, 10, 11, 1, 1, 1, 2, 3, 4, 1001, 1, 1, 2, 5, 3, 77, 7, 8, 3]);
        assert_eq!(result, 11);
    }
}
