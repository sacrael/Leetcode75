# Problem 7
# Find Minimum in Rotated Sorted Subarray

Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array `nums = [0,1,2,4,5,6,7]` might become:
- `[4,5,6,7,0,1,2]` if it was rotated 4 times.
- `[0,1,2,4,5,6,7]` if it was rotated 7 times.
Notice that rotating an array `[a[0], a[1], a[2], ..., a[n-1]]` 1 time results in the array `[a[n-1], a[0], a[1], a[2], ..., a[n-2]]`.

Given the sorted rotated array nums, return the minimum element of this array.

**Example 1**
```
Input: nums = [3,4,5,1,2]
Output: 1
Explanation: The original array was [1,2,3,4,5] rotated 3 times.
```

**Example 2**
```
Input: nums = [4,5,6,7,0,1,2]
Output: 0
Explanation: The original array was [0,1,2,4,5,6,7] and it was rotated 4 times.
```

<details>
    <summary>Solution Explanation</summary>
The minimum is either the first value in the array of the next value
lower than that in the array, since the array is sorted but just rotated from some pivot. So the solution is just a loop until min is found.

```
int findMin(vector<int>& nums) {
    int min = nums[0];
    int size = nums.size();
    for (size_t i = 1; i < size; ++i) {
        if (nums[i] < min) return nums[i];
    }
    return min;
}
```
</details>