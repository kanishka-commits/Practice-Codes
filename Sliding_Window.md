## SLIDING WINDOW

### A. 187 Repeated DNA Sequences

```cpp
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string> st;
        unordered_set<string> finalset;
        vector<string> ans;
        int left=0;
        if(s.size()<10) return ans;
        while(left<=(s.size()-10)){
            string temp=s.substr(left,10);
            if(st.find(temp)!=st.end())  finalset.insert(temp);
            else st.insert(temp);
            left++;
        }
        for(string x:finalset) ans.push_back(x);
        return ans;
    }
};
```
Use unordered_set<string> (hash-based), thus we get O(1) avg lookup
while using set<string> (tree-based0 we get  O(log n) lookup

### B. 395 Longest Substring with At Least K Repeating Characters




