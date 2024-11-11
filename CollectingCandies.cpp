/*
CodeVita:https://prepinsta.com/tcs-codevita/c-program-for-collecting-candies-problem/
*/
#include <bits/stdc++.h>
using namespace std;
int main() {
    int a[5]={1,2,3,5,4};
    int n=5;
    sort(a,a+n);
    int sum=0;
    for(int i=0;i<n;i++) {
        sum+=a[i];
        a[i]=sum;
    }
    int ans=0;
    for(int i=1;i<n;i++){
        ans+=a[i];
    }
    cout<<ans;
    return 0;
}