#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mp make_pair
#define pi pair<int,int>
#define ppi pair<int,pi >
#define ld long double
#define pb push_back
#define mod 1000000007
#define F first
#define S second
#define endl "\n"

//RETURNS ALL PRIME NOS. LESS THAN N
vector<int> sieve(int n){
bool *a=new bool[n];
for(int i=2;i<n;i++){
a[i]=true;
}
a[0]=false;
a[1]=false;
for(int i=2;i<=sqrt(n);i++){
if(a[i]==true){
  for(int j=i*i;j<=n;j=j+i){
    a[j]=false;
  }
}
}
vector<int> v;
for(int i=2;i<n;i++){
if(a[i]==true){
  v.pb(i);
}
}
return v;
}

signed main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);

vector<int> primes=sieve(2000000);
// for(int i=0;i<primes.size();i++){
//     // cout<<primes[i]<<" ";
// }
// cout<<primes.size()<<endl;
int t;
cin>>t;
while(t--){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<primes[i]<<endl;
    }
}
return 0;
}
