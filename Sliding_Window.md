## SLIDING WINDOW

### A. 187 Repeated DNA Sequences

```cpp
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        set<string> st;
        set<string> finalset;
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

### B. 395 Longest Substring with At Least K Repeating Characters




