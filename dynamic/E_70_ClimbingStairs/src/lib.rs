use std::collections::HashMap;

struct Solution {}

impl Solution {
    pub fn climb_stairs(n: i32) -> i32 {
        let mut mem = HashMap::new();
        Solution::_climb_stairs(&mut mem, n)
    }

    fn _climb_stairs(mem: &mut HashMap<i32, i32>, n: i32) -> i32 {
        if n == 1 {
            1
        } else if n == 2 {
            2
        }
        else if mem.contains_key(&n) {
            *mem.get(&n).unwrap()
        } else {
            let r1 = Solution::_climb_stairs(mem, n - 1);
            let r2 = Solution::_climb_stairs(mem, n - 2);
            let r = r1 + r2;
            mem.insert(n, r);
            r
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn it_works() {
        let res = Solution::climb_stairs(2);
        assert_eq!(res, 2);

        let res = Solution::climb_stairs(3);
        assert_eq!(res, 3);

        let res = Solution::climb_stairs(45);
        assert_eq!(res, 1836311903);
    }
}
