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

// Function to find largest prefix which is also a suffix
int largest_prefix_suffix(const std::string &str) {

int n = str.length();

if(n < 2) {
    return 0;
}

int len = 0;
int i = n/2;

while(i < n) {
    if(str[i] == str[len]) {
    ++len;
    ++i;
    } else {
    if(len == 0) { // no prefix
        ++i;
    } else { // search for shorter prefixes
        --len;
    }
    }
}
return len;
}

//***********************************************************
// A C++ program to check if a string is 'n' times
// repetition of one of its substrings


// A utility function to fill lps[] or compute prefix funcrion
// used in KMP string matching algorithm. Refer
// https://www.geeksforgeeks.org/archives/11902 for details
void computeLPSArray(string str, int M, int lps[])
{
    int len = 0; //lenght of the previous longest prefix suffix
    int i;

    lps[0] = 0; //lps[0] is always 0
    i = 1;

    // the loop calculates lps[i] for i = 1 to M-1
    while (i < M)
    {
    if (str[i] == str[len])
    {
        len++;
        lps[i] = len;
        i++;
    }
    else // (pat[i] != pat[len])
    {
        if (len != 0)
        {
            // This is tricky. Consider the example AAACAAAA
            // and i = 7.
            len = lps[len-1];

            // Also, note that we do not increment i here
        }
        else // if (len == 0)
        {
            lps[i] = 0;
            i++;
        }
    }
    }
}

// Returns true if str is repetition of one of its substrings
// else return false.
int isRepeat(string str)
{
    // Find length of string and create an array to
    // store lps values used in KMP
    int n = str.length();
    int lps[n];

    // Preprocess the pattern (calculate lps[] array)
    computeLPSArray(str, n, lps);

    // Find length of longest suffix which is also
    // prefix of str.
    int len = lps[n-1];

    // If there exist a suffix which is also prefix AND
    // Length of the remaining substring divides total
    // length, then str[0..n-len-1] is the substring that
    // repeats n/(n-len) times (Readers can print substring
    // and value of n/(n-len) for more clarity.
    return (n-len);
    // return (len > 0 && n%(n-len) == 0)? true: false;
}






signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        string w,s;
        cin>>w>>s;
        int r=largest_prefix_suffix(w);
        int n=w.length();
        int m=s.length();
        map<char,int> m1;
        map<char,int> m2;
        for(int i=0;i<m;i++){
            m2[s[i]]++;
        }
        for(int i=0;i<n;i++){
            m1[w[i]]++;
        }
        if(r!=n){
            bool check=false;
            for(int i=0;i<r;i++){
                int x=m2[w[i]];
                if(x==0){
                    check=true;
                    break;
                }
                m2[w[i]]--;
            }
            if(check){
                cout<<0<<endl;
                continue;
            }
            map<char,int> m3;
            for(int i=r;i<n;i++){
                m3[w[i]]++;
            }
            map<char,int> :: iterator it=m3.begin();
            int res=INT_MAX;
            while(it!=m3.end()){
                char c=it->first;
                int val=m2[c];
                int opt=(val/(it->second));
                res=min(res,opt);
                it++;
            }
            cout<<res<<endl;
        }else{
            int y=isRepeat(w);
            map<char,int> m3;
            for(int i=0;i<y;i++){
                m3[w[i]]++;
            }
            map<char,int> :: iterator it=m3.begin();
            int res=INT_MAX;
            while(it!=m3.end()){
                char c=it->first;
                int val=m2[c];
                int opt=(val/(it->second));
                res=min(res,opt);
                it++;
            }
            int total=(n/y);
            int res2=(res/total);
            cout<<res2<<endl;
        }
    }
    return 0;
}
