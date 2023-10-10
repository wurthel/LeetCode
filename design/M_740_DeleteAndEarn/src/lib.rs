use std::cmp::max;
use std::collections::HashMap;

struct Solution {}

impl Solution {
    pub fn delete_and_earn(nums: Vec<i32>) -> i32 {
        let mut mem = HashMap::new();

        // Track total sums
        let mut earns = HashMap::new();
        for x in nums.into_iter() {
            earns
                .entry(x)
                .and_modify(|val| *val = *val + x)
                .or_insert(x);
        }

        // Take unique numbers and sort in descending order
        // It is important to keep numbers in descending order
        // since the core logic assumes the numbers are sorted
        let mut nums_unique: Vec<i32> = earns.keys().cloned().collect();
        nums_unique.sort();

        Solution::_delete_and_earn(&mut mem, &earns, &nums_unique, nums_unique.len() as i32 - 1)
    }

    fn _delete_and_earn(mem: &mut HashMap<i32, i32>, earns: &HashMap<i32, i32>, nums: &Vec<i32>, idx: i32) -> i32 {
        if idx < 0 {
            // Edge case, nothing to earn
            return 0;
        } else if idx == 0 {
            // The best case is always to earn
            return *earns.get(&nums[0]).unwrap();
        } else {
            if mem.contains_key(&idx) {
                return *mem.get(&idx).unwrap();
            }

            let mut s = 0;
            match nums[idx as usize] - nums[(idx - 1) as usize] {
                1 => {
                    // We need to decide if it is better to earn the current number and delete it along with the previous one
                    // OR don't earn and keep the previous one

                    // Earn and delete
                    let s1 = earns.get(&nums[idx as usize]).unwrap() + Solution::_delete_and_earn(mem, earns, nums, idx - 2);

                    // Don't earn
                    let s2 = Solution::_delete_and_earn(mem, earns, nums, idx - 1);

                    // Return the best score
                    s = max(s1, s2);
                }
                _ => {
                    // The best decision is always earn and delete
                    // Since the difference between the current number and neighbour is > 1,
                    // we earn money and keep all other numbers in the list
                    s = earns.get(&nums[idx as usize]).unwrap() + Solution::_delete_and_earn(mem, earns, nums, idx - 1);
                }
            }
            mem.insert(idx, s);
            s
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn it_works() {
        let result = Solution::delete_and_earn(vec![3, 4, 2]);
        assert_eq!(result, 6);

        let result = Solution::delete_and_earn(vec![2, 2, 3, 3, 3, 4]);
        assert_eq!(result, 9);

        let result = Solution::delete_and_earn(vec![1,2,2,2,3,4,5,1,2,3,4,1,3,7,8,4,6,8,1,22,3,4,666,7,4,5,7]);
        assert_eq!(result, 738);
    }
}
