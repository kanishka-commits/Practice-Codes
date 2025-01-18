//Longest Subarray with Sum K
#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[]={1,1,2,2,3,1,4,1,1,1,2,6};
    int k=6;
    int n=sizeof(arr)/sizeof(arr[0]);
    int i=0,j=0;
    int sum=0;
    int maxi=0;
    while(j<n){
      sum+=arr[j];
      if(sum==k){
          maxi=max(maxi,j-i+1);
          
      }
      j++;
      if(j==n) {
          sum=0;
          i++;
          j=i;
      }
    }
    cout<<maxi<<endl;
    
    return 0;
}
