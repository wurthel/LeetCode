use std::collections::HashMap;

struct Solution {}

impl Solution {
    pub fn tribonacci(n: i32) -> i32 {
        let mut mem = HashMap::new();
        Solution::_tribonacci(&mut mem, n)
    }

    fn _tribonacci(mem: &mut HashMap<i32, i32>, n: i32) -> i32 {
        if n == 0 {
            0
        } else if n == 1 || n == 2 {
            1
        } else if let Some(val) = mem.get(&n) {
            *val
        } else {
            let val =
                Solution::_tribonacci(mem, n - 3)
                    + Solution::_tribonacci(mem, n - 2)
                    + Solution::_tribonacci(mem, n - 1);
            mem.insert(n, val);
            val
        }
    }

    pub fn tribonacci_button_up(n: i32) -> i32 {
        // Button-Up reimplementation of the above solution
        if n == 0 {
            0
        } else if n == 1 || n == 2 {
            1
        } else {
            let mut dp = vec![0; n as usize + 1];
            dp[0] = 0;
            dp[1] = 1;
            dp[2] = 1;
            for i in 3..(n + 1) as usize {
                dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
            }
            dp[n as usize]
        }
    }
}

#[cfg(test)]
mod tests {
    use crate::Solution;

    #[test]
    fn it_works() {
        let result = Solution::tribonacci(4);
        assert_eq!(result, 4);

        let result = Solution::tribonacci(25);
        assert_eq!(result, 1389537);

        let result = Solution::tribonacci_button_up(4);
        assert_eq!(result, 4);

        let result = Solution::tribonacci_button_up(25);
        assert_eq!(result, 1389537);
    }
}
