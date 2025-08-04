
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

### 88. Merge Sorted Array

```cpp
    void merge(vector<int>& a, int m, vector<int>& b, int n) {
        int i = m - 1, j = n - 1, k = m + n - 1;

        while(j >= 0) {
            if(i >= 0 && a[i] > b[j]) {
                a[k] = a[i];
                i--;
            } else {
                a[k] = b[j];
                j--;
            }
            k--;
        }
    }
```

in case, if size of num1!= m + n, where m is no of elements in num1 except trial zeroes and n is no of elements in num2
then 
we need to do, `num1=[1,2,3,4,5] num2=[6,7,8,9]` i.e 
```cpp
    int left = n - 1;
    int right = 0;

    //Swap the elements until arr1[left] is
    // smaller than arr2[right]:
    while (left >= 0 && right < m) {
        if (arr1[left] > arr2[right]) {
            swap(arr1[left], arr2[right]);
            left--, right++;
        } else break;
    }

    // Sort arr1[] and arr2[] individually:
```
Another optimal solution is, Gap method or Shell Sort
