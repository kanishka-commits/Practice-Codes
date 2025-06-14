//https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int maxLength = 0;
        set<char> dup;

        for (int right = 0; right < s.length(); right++) {
            while (dup.find(s[right]) != dup.end()) {
                dup.erase(s[left]);
                left++;
            }

            dup.insert(s[right]);
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;        
    }
};
