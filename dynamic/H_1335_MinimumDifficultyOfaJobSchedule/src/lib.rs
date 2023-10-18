use std::cmp::{max, min};
use std::collections::HashMap;

struct Solution {}

impl Solution {
    pub fn min_difficulty(job_difficulty: Vec<i32>, days: i32) -> i32 {
        let mut mem = HashMap::new();
        Solution::dp(&mut mem, &job_difficulty, days, 0, 1)
    }

    fn dp(mem: &mut HashMap<(i32, i32), i32>, job_difficulty: &Vec<i32>, days: i32, i: i32, d: i32) -> i32 {
        // i -- is the index of the first job that will be done on the current day
        // d -- what day it currently is
        // days -- total days
        if job_difficulty.len() < days as usize {
            return -1;
        }
        if d == days {
            return *job_difficulty[i as usize..].iter().max().unwrap_or(&0);
        }
        if mem.contains_key(&(i, d)) {
            return *mem.get(&(i, d)).unwrap();
        }

        let n = job_difficulty.len() as i32;
        let mut score = i32::MAX;
        let mut hardest = 0;
        for idx in i..(n - (days - d)) {
            hardest = max(hardest, job_difficulty[idx as usize]);
            score = min(score, hardest + Solution::dp(mem, job_difficulty, days, idx + 1, d + 1))
        }
        mem.insert((i, d), score);
        score
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn it_works() {
        let result = Solution::min_difficulty(vec![6, 5, 4, 3, 2, 1], 2);
        assert_eq!(result, 7);

        let result = Solution::min_difficulty(vec![6, 5, 4, 3, 2, 1], 20);
        assert_eq!(result, -1);

        let result = Solution::min_difficulty(vec![1, 1, 1], 3);
        assert_eq!(result, 3);
    }
}
