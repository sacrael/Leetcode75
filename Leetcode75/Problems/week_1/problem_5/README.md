# Problem 5
## Maximum Sum Subarray

Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

**Example 1**
```
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
```

**Example 2**
```
Input: nums = [-1]
Output: -1
```

<details>
    <summary>Solution explanation</summary>

```
int maxSubArray(vector<int>& nums) {
    int max_sum = nums[0];
    std::vector<int> cache {nums[0]};
    
    for (int i = 1; i < nums.size(); ++i) {
        cache.push_back(std::max(nums[i], cache[i - 1] + nums[i]));
        max_sum = std::max(max_sum, cache[i]);
    }
    
    return max_sum;
}
```
</details>