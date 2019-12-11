#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mp make_pair
#define pi pair<int,int>
#define ppi pair<int,pi >
#define ld long double
#define pb push_back
#define F first
#define S second
#define endl "\n"

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        int n,c;
        cin>>n>>c;
        int a=1;
        int b=2;
        if(n==1){
            cout<<(1*c)<<endl;
            continue;
        }
        if(n==2){
            cout<<(2*c)<<endl;
            continue;
        }
        int count=3;
        int ans;
        while(1){
            int c=(a+b);

            if(c>n){
                ans=count-1;
                break;
            }else{
                if(c==n){
                    ans=count;
                    break;
                }
            }
            a=b;
            b=c;
            count++;
        }
        cout<<(ans*c)<<endl;
    }
    return 0;
}
