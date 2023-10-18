use std::cmp::min;
use std::collections::HashMap;

struct Solution {}

impl Solution {
    pub fn maximal_square(matrix: Vec<Vec<char>>) -> i32 {
        let mut mem = HashMap::new();
        let n = matrix.len() as i32;
        let m = matrix[0].len() as i32;
        Solution::dp(&mut mem, &matrix, n - 1, m - 1);
        let score = mem.values().cloned().max().unwrap_or(0);
        score * score
    }

    fn dp(mem: &mut HashMap<(i32, i32), i32>, matrix: &Vec<Vec<char>>, i: i32, j: i32) -> i32 {
        if i < 0 || j < 0 {
            return 0;
        } else if matrix[i as usize][j as usize] == '1' {
            if mem.get(&(i, j)).is_some() {
                // Already precalculated
                return *mem.get(&(i, j)).unwrap();
            }
            let s1 = Solution::dp(mem, matrix, i - 1, j - 1);
            let s2 = Solution::dp(mem, matrix, i, j - 1);
            let s3 = Solution::dp(mem, matrix, i - 1, j);
            let score = 1 + min(min(s1, s2), s3);
            mem.insert((i, j), score);
            return score;
        } else {
            // Propagate calculations
            Solution::dp(mem, matrix, i - 1, j - 1);
            Solution::dp(mem, matrix, i, j - 1);
            Solution::dp(mem, matrix, i - 1, j);
            return 0;
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn it_works() {
        let matrix = vec![
            vec!['1', '0', '1', '0', '0'],
            vec!['1', '0', '1', '1', '1'],
            vec!['1', '1', '1', '1', '1'],
            vec!['1', '0', '0', '1', '0'],
        ];
        let result = Solution::maximal_square(matrix);
        assert_eq!(result, 4);

        let matrix = vec![
            vec!['0','1',],
            vec!['1','0',]
        ];
        let result = Solution::maximal_square(matrix);
        assert_eq!(result, 1);

        let matrix = vec![
            vec!['0'],
        ];
        let result = Solution::maximal_square(matrix);
        assert_eq!(result, 0);
    }
}
