# Problem 6
## Maximum Product Subarray

Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.

**Example 1**
```
Input: [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
```

**Example 2**
```
Input: [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
```

<details>
    <summary>Solution Explanation</summary>

Unlike in the maximum sum subarray problem where we only kept track of the iterative maximum sum value, for the maximum product subarray value, we need to also keep track of the iterative minimum value, because a single negative will throw our previous maximum to becoming the minimum. All it would need is a another negative somewhere down the array to become our max value again. While keeping track of the iterative min and max value, we should set our answer to be the maximum of the current answer and the current max value.

```
int maxProduct(vector<int>& nums) {
    size_t size = nums.size();
    int curr_min = nums[0], curr_max = nums[0];
    int answer = nums[0];
    
    for (size_t i = 1; i < size; ++i) {
        curr_min *= nums[i];
        curr_max *= nums[i];
        
        int new_min, new_max;
        new_min = std::min(curr_min, std::min(curr_max, nums[i]));
        new_max = std::max(curr_min, std::max(curr_max, nums[i]));
        curr_min = new_min; curr_max = new_max;
        
        answer = std::max(answer, curr_max);
    }
    return answer;
}
```
</details>