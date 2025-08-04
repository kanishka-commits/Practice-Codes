
## 1752. Check if Array Is Sorted and Rotated
```cpp
class Solution {
public:
    bool check(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(nums[i] > nums[(i + 1) % n]) {
                count++;
            }
        }
        return count <= 1;
    }
};
```
**Left Rotation**: Shift each element to the left by `x` positions — `A[i] → A[(i + x) % n]`.
**Right Rotation**: Shift each element to the right by `x` positions — `A[i] → A[(i - x + n) % n]`.

1<2<3<4<5 but 5>1, thus to check if it's rotated, we can do  `if(nums[i] > nums[(i + 1)]) count++, if count==0, not rotated`
`nums[(i + 1) % n]` means, it's starting from 0 `if i==n-1` 

### 152 Maximum Product Subarray

```cpp
class Solution {
public:
    int maxProduct(vector<int>& arr) {
        int n = arr.size(); //size of array.

        int pre = 1, suff = 1;
        int ans = INT_MIN;
        for (int i = 0; i < n; i++) {
      // Whenever we encounter 0, we'll make out product = 1
            if (pre == 0) pre = 1; 
            if (suff == 0) suff = 1;
            pre *= arr[i];
            suff *= arr[n - i - 1];
            ans = max(ans, max(pre, suff));
        }
        return ans;
    }
};
```
