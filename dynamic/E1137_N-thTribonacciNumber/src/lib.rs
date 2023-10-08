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
    }
}
