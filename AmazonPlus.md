### Find row with maximum 1's 

```cpp
class Solution {
public:   
    int rowWithMax1s(vector<vector<int>> &mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        
        int miniCol = INT_MAX;
        int ansRow = -1;

    /*
     Here we'll have to search for 1, so instead of linear search, we can do BS (as they're sorted also)
    */
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (mat[i][j] == 1) {
                    if (j < miniCol) {
                        miniCol = j;   // update leftmost 1
                        ansRow = i;    // store row index
                    }
                    break; // move to next row, since rest are 1's
                }
            }
        }

        return ansRow;
    }
};
```


### Buildings With an Ocean View

```cpp
class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        vector<int> ans;
        int maxRight = 0; // max height seen so far from the right
        for (int i = heights.size() - 1; i >= 0; i--) {
            if (heights[i] > maxRight) {
                ans.push_back(i);
                maxRight = heights[i];
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
```

We've used a variable instead of a stack because we only need to track the maximum height seen so far and **never pop elements**; the stack in this problem acts just as a memory of the tallest building, so a single variable maxRight is enough.

### Brightest Position on Street

```cpp
class Solution {
public:
    int brightestPosition(vector<vector<int>>& lights) {
        // Using map to handle negative or large positions
        map<int,int> diff;

        // Mark the start and end+1 of each lamp's interval
        for(auto &lamp : lights){
            int start = lamp[0] - lamp[1];
            int end = lamp[0] + lamp[1];
            diff[start] += 1;
            diff[end + 1] -= 1;
        }

        int brightness = 0;
        int maxBrightness = 0;
        int ans = INT_MAX; // smallest position with max brightness

        // Sweep line: compute brightness at each key position
        for(auto &[pos, change] : diff){
            brightness += change;
            if(brightness > maxBrightness){
                maxBrightness = brightness;
                ans = pos;
            }
        }

        return ans;
    }
};
```

Intuition: We Count how many lamps cover each point:
   - Brute, for every point increase its value by 1 in map
   - Optimal, only mark changes at start/end instead of iterating every position: increase start position by 1 and decrease end+1 position by 1, now use prefix kind of array, such that for every position from start to end, there's a brightnes value which decreasesonly at end+1


### Diet Plan Performance

```cpp
class Solution {
public:
    int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) {
        int n=calories.size();
        int sum=0;
        for(int i=0;i<n;i++) {
            sum+=calories[i];
            calories[i]=sum;
            // cout<<calories[i]<<" ";
        }

        int left=0,points=0;
        if(calories[k-1]<lower) points-=1;
        else if(calories[k-1]>upper) points+=1;

        for(int i=k;i<n;i++){
            if(calories[i]-calories[left]<lower) points-=1;
            else if(calories[i]-calories[left]>upper) points+=1;
            left++;
        }


        return points;
    }
};
```

Intuition:
  - we need a window and need to find sum of that window, so what I did here is calculated prefix summ at each index and let I got PS array as 2 6 12 20 30, then I did a[k]-a[left] where left is starting from 0 and keeping track of window of size k as I keep on increaisng i and left with same pace
  - There's still a better approach




