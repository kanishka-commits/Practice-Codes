//https://takeuforward.org/arrays/find-the-highest-lowest-frequency-element/

#include <iostream>
#include <map>
#include <climits>
using namespace std;
int main() {
    map<int,int> mapp;
    int array[]={1,2,3,3,10,10,1,2,10};
    for(int i=0;i<9;i++){
        mapp[array[i]]++;
    }
    int mini=INT_MIN;
    int maxi=INT_MAX;
    for(auto it:mapp) {
        if(mini<it.second) mini=it.second;
        if(maxi>it.second) maxi=it.second;
    }
    
    cout<<"Maxi and mini are"<<maxi<<" "<<mini;
    
    
    return 0;
}
