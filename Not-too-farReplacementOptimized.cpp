#include <bits/stdc++.h>
#define ll long long int
using namespace std;
#define c(x) cin>>x;
//#define for(i,n) for(ll i=0;i<n;i++)
#define co(x) cout<<x<<endl;

int main() {
  ll t; c(t);
  while(t--){
     ll n;
     c(n);
     ll a[n+1];
     for(ll i=0;i<n+1;i++) {
         c(a[i]);
        }
  
     sort(a,a+n);
     ll sum=0;
    
       for(ll i=0;i<n;i++){
         if(a[i]<=2*a[n] && a[i]>a[n] ){
             swap(a[i],a[n]);
         }
     } 
     
       ll prefixsum[n];
     for(ll i=0;i<n;i++){
         sum+=a[i];
         prefixsum[i]=sum; 
     }
    cout<<prefixsum[n-1]<<endl;
  }

  return 0;
}


/*

Logic:
make the array sort in increasing order from 0 to n-1
and if a[i]>=2*a[n] swap a[i] and a[n]

PROBLEM in case: 1 2 2 5 3, at the end we'll get 3 1 2 5 2 and then 2*2<5, not possible

SOLUTION:
we'll swap the number only when a[i]>a[n] and a[i]<=2*a[n]
why we did this? We need to move biggest number out of all 0->n-1 to nth position, thus we do a[i]>a[n]

take eg: 1 2 4 5 3, here even tho biggest is 5, we can swap 3 with 4 so that in next swapping, 4 will be swapped with 5
*/