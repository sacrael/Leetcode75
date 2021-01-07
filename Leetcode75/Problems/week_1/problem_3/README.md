# Problem 3
## Contains Duplicate

### Problem
Given an array of integers, find if the array contains any duplicates.

Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.

**Example 1**
```
Input: [1,2,3,1]
Output: true
```

**Example 2**
```
Input: [1,2,3,4]
Output: false
```

**Example 3**
```
Input: [1,1,1,3,3,4,3,2,4,2]
Output: true
```

<details>
<summary>Solution explanation</summary>
Utilize a dynamic data structure that supports fast search and insert operations.

```
public boolean containsDuplicate(int[] nums) {
    Set<Integer> set = new HashSet<>(nums.length);
    for (int x: nums) {
        if (set.contains(x)) return true;
        set.add(x);
    }
    return false;
}
```

**Complexity Analysis**
- Time complexity : O(n)O(n). We do search() and insert() for nn times and each operation takes constant time.
- Space complexity : O(n)O(n). The space used by a hash table is linear with the number of elements in it.
</details>