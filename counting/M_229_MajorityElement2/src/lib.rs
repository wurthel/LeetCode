struct Solution {}

impl Solution {
    pub fn majority_element(mut nums: Vec<i32>) -> Vec<i32> {
        if nums.len() == 0 {
            return vec![];
        }
        let n = nums.len() / 3;
        nums.sort_unstable();


        let mut result = Vec::with_capacity(n);
        let mut previous = nums[0];
        let mut counter = 0;
        for num in &nums[1..] {
            if *num == previous {
                counter += 1;
            } else {
                if counter >= n {
                    result.push(previous);
                }
                previous = *num;
                counter = 0;
            }
        }
        if counter >= n {
            result.push(previous);
        }
        result

    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn it_works() {
        let result = Solution::majority_element(vec![1,2,3]);
        assert_eq!(result, []);

        let result = Solution::majority_element(vec![3,2,3]);
        assert_eq!(result, [3]);

        let result = Solution::majority_element(vec![1]);
        assert_eq!(result, [1]);

        let result = Solution::majority_element(vec![1,2]);
        assert_eq!(result, [1,2]);

        let result = Solution::majority_element(vec![1,1,1,2,2,2,3]);
        assert_eq!(result, [1,2]);
    }
}
