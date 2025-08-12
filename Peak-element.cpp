// https://leetcode.com/problems/find-peak-element/description/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] > nums[mid + 1])
                r = mid;       // Peak is on the left (including mid)
            else
                l = mid + 1;   // Peak is on the right
        }
        return l; // l == r, peak index
    }
};

