# Problem 4
## Product of Array Except Self

Given an array nums of n integers where n > 1,  return an array output such that `output[i]` is equal to the product of all the elements of nums except `nums[i]`.

**Example**
```
Input:  [1,2,3,4]
Output: [24,12,8,6]
```

**Constraints** It's guaranteed that the product of the elements of any prefix or suffix of the array (including the whole array) fits in a 32 bit integer.

**Note:** Please solve it without division and in O(n).

<details>
    <summary>Solution 1 explanation</summary>

It's much easier to build an intuition for solving this problem without division once you visualize how the different products except self look like for each of the elements. So, let's take a look at an example array and the different products.

Looking at the figure about we can figure another way of computing those different product values.

Instead of dividing the product of all the numbers in the array by the number at a given index to get the corresponding product, we can make use of the product of all the numbers to the left and all the numbers to the right of the index. Multiplying these two individual products would give us the desired result as well.

For every given index, ii, we will make use of the product of all the numbers to the left of it and multiply it by the product of all the numbers to the right. This will give us the product of all the numbers except the one at the given index ii. Let's look at a formal algorithm describing this idea more concretely.

```
public int[] productExceptSelf(int[] nums) {

    // The length of the input array
    int length = nums.length;

    // The left and right arrays as described in the algorithm
    int[] L = new int[length];
    int[] R = new int[length];

    // Final answer array to be returned
    int[] answer = new int[length];

    // L[i] contains the product of all the elements to the left
    // Note: for the element at index '0', there are no elements to the left,
    // so L[0] would be 1
    L[0] = 1;
    for (int i = 1; i < length; i++) {

        // L[i - 1] already contains the product of elements to the left of 'i - 1'
        // Simply multiplying it with nums[i - 1] would give the product of all
        // elements to the left of index 'i'
        L[i] = nums[i - 1] * L[i - 1];
    }

    // R[i] contains the product of all the elements to the right
    // Note: for the element at index 'length - 1', there are no elements to the right,
    // so the R[length - 1] would be 1
    R[length - 1] = 1;
    for (int i = length - 2; i >= 0; i--) {

        // R[i + 1] already contains the product of elements to the right of 'i + 1'
        // Simply multiplying it with nums[i + 1] would give the product of all
        // elements to the right of index 'i'
        R[i] = nums[i + 1] * R[i + 1];
    }

    // Constructing the answer array
    for (int i = 0; i < length; i++) {
        // For the first element, R[i] would be product except self
        // For the last element of the array, product except self would be L[i]
        // Else, multiple product of all elements to the left and to the right
        answer[i] = L[i] * R[i];
    }

    return answer;
}
```
</details>