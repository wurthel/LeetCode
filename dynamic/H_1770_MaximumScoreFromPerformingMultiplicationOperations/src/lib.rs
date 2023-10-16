use std::cmp::max;
use std::collections::HashMap;

struct Solution{}

impl Solution {
    pub fn maximum_score(nums: Vec<i32>, multipliers: Vec<i32>) -> i32 {
        let mut mem = HashMap::new();
        Solution::_maximum_score(&mut mem, &nums, &multipliers, 0, 0)
    }

    fn _maximum_score(mem: &mut HashMap<(i32, i32), i32>, nums: &Vec<i32>, multipliers: &Vec<i32>, i: i32, left: i32) -> i32 {
        if i == multipliers.len() as i32 {
            0
        } else {
            if mem.get(&(i, left)).is_some() {
                return *mem.get(&(i, left)).unwrap();
            }
            let right = nums.len() as i32 - (i - left) - 1;
            let s1 = nums[left as usize] * multipliers[i as usize] + Solution::_maximum_score(mem, nums, multipliers, i + 1, left + 1);
            let s2 = nums[right as usize] * multipliers[i as usize] + Solution::_maximum_score(mem, nums, multipliers, i + 1, left);
            let s = max(s1, s2);
            mem.insert((i, left), s);
            s
        }
    }
}
#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn it_works() {
        let result = Solution::maximum_score(vec![1,2,3], vec![3,2,1]);
        assert_eq!(result, 14);

        let result = Solution::maximum_score(vec![-5,-3,-3,-2,7,1], vec![-10,-5,3,4,6]);
        assert_eq!(result, 102);
    }
}
