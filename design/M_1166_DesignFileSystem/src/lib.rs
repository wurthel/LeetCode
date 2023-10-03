use std::collections::HashMap;

struct Path {
    name: String,
    value: i32,
    childs: HashMap<String, Box<Path>>,
}

impl Path {
    fn new(name: &str, value: i32) -> Self {
        Self {
            name: name.to_string(),
            value,
            childs: HashMap::new(),
        }
    }
}

struct FileSystem {
    root: Path,
}


impl FileSystem {
    fn new() -> Self {
        Self {
            root: Path::new("", -1)
        }
    }

    fn create_path(&mut self, path: String, value: i32) -> bool {
        if path.is_empty() || path == "/" {
            return false;
        }
        let current = &mut self.root;
        FileSystem::_create_path(current, path[1..].split('/').collect(), value)
    }

    fn _create_path(parent: &mut Path, paths: Vec<&str>, value: i32) -> bool {
        let is_created = match paths.split_first() {
            None => false, // Vector is empty?
            Some((head, tail)) => {
                if tail.is_empty() {
                    // reached the end of the tree
                    let new = Path::new(head.clone(), value);
                    if parent.childs.contains_key(*head) {
                        return false
                    }
                    parent.childs.entry(head.to_string()).or_insert(Box::new(new));
                    return true;
                }

                // Otherwise trying to next next file in the path
                match parent.childs.get_mut(*head) {
                    Some(next) => return FileSystem::_create_path(next, tail.to_vec(), value),
                    None => return false,
                }
            }
        };
        is_created
    }

    fn get(&mut self, path: String) -> i32 {
        if path.is_empty() || path == "/" {
            return -1;
        }
        let next = &mut self.root;
        FileSystem::_get(next, path[1..].split('/').collect())
    }

    fn _get(current: &mut Path, paths: Vec<&str>) -> i32 {
        let val = match paths.split_first() {
            None => -1, // Vector is empty?
            Some((head, tail)) => {
                if tail.is_empty() {
                    // reached the end of the tree
                    match current.childs.get(*head) {
                        Some(path) => return path.value,
                        None => return -1
                    }
                }

                // Otherwise trying to next next file in the path
                match current.childs.get_mut(*head) {
                    Some(next) => return FileSystem::_get(next, tail.to_vec()),
                    None => return -1,
                }
            }
        };
        val
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn it_works_1() {
        let mut fs = FileSystem::new();
        assert!(fs.create_path("/a".to_string(), 1));
        assert_eq!(fs.get("/a".to_string()), 1);
    }

    #[test]
    fn it_works_2() {
        let mut fs = FileSystem::new();
        assert!(fs.create_path("/leet".to_string(), 1));
        assert!(fs.create_path("/leet/code".to_string(), 2));
        assert_eq!(fs.get("/leet/code".to_string()), 2);
        assert!(!fs.create_path("/c/d".to_string(), 2));
        assert_eq!(fs.get("/c".to_string()), -1);
    }

    #[test]
    fn it_works_3() {
        let mut fs = FileSystem::new();
        assert!(fs.create_path("/leet".to_string(), 1));
        assert!(fs.create_path("/leet/code".to_string(), 2));
        assert_eq!(fs.get("/leet/code".to_string()), 2);
        assert!(!fs.create_path("/leet/code".to_string(), 3));
        assert_eq!(fs.get("/leet/code".to_string()), 2);
    }
}
