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
while using set<string> (tree-based) we get  O(log n) lookup

explanation: Here we could've taken just one set, but then if that string is already in set, and appears for more than 2 times we'll keep on adding it in.
*that means, we wanted our answer to be a set, why? to remove duplicate strings*
### B. 3305 Count of Substrings Containing Every Vowel and K Consonants I

```cpp
class Solution {
public:
    bool isVowel(char x){
        if(x=='a'||x=='e'|| x=='i'|| x=='o'|| x=='u') return true;
        return false;
    }
    int f(string word, int k) {
        if (k < 0) return 0;

        unordered_map<char, int> mp;
        int vCount = 0, totalVCount = 0;
        int i = 0, j = 0;
        int n = word.size();
        int res = 0;

        while (j < n) {
            if (isVowel(word[j])) {
                totalVCount++;
                if (mp.find(word[j]) != mp.end()) {
                    if (mp[word[j]] < i) {
                        vCount++;
                    }
                    mp[word[j]] = j;
                } else {
                    mp[word[j]] = j;
                    vCount++;
                }
            }

            while ((j - i + 1 - totalVCount) > k) {
                if (isVowel(word[i])) {
                    if (mp[word[i]] == i) vCount--;
                    totalVCount--;
                }
                i++;
            }

            if (vCount == 5) {
                int x = min({mp['a'], mp['e'], mp['i'], mp['o'], mp['u']});
                res += (x - i + 1);
            }
            j++;
        }

        return res;
    }

    int countOfSubstrings(string word, int k) {
        return f(word, k) - f(word, k - 1);
    }
};
```





