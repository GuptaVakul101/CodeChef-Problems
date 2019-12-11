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
vector<vector<char> > board;

bool check(int x,int y,char num){
    for(int i=0;i<9;i++){
        if(i==y){
            continue;
        }
        if(board[x][i]==num){
            return false;
        }
    }
    for(int i=0;i<9;i++){
        if(i==x){
            continue;
        }
        if(board[i][y]==num){
            return false;
        }
    }
    int x1=x/3;
    int y1=y/3;
    int count=0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            int i1=(i+(3*x1));
            int i2=(j+(3*y1));
            if(board[i1][i2]==num){
                count++;
            }
        }
    }
    if(count>=2){
        return false;
    }
    return true;
}

bool func(int x,int y){
    // cout<<board[x][y]<<" "<<x<<" "<<y<<endl;
    if(board[x][y]!='.'){
        if(y!=8){
            return func(x,y+1);
        }else{
            if(x!=8){
                return func(x+1,0);
            }else{
                return true;
            }
        }
    }else{
        for(int i=1;i<=9;i++){
            char c=(char)(i+48);
            board[x][y]=(char)(i+48);
            if(check(x,y,c)){
                if(func(x,y)){
                    return true;
                }
            }
        }
        board[x][y]='.';
        return false;
    }
}

void solveSudoku(vector<vector<char> > &A) {
    int n=A.size();
    int f=board.size();
    for(int i=0;i<f;i++){
        board[i].clear();
    }
    board.clear();
    for(int i=0;i<n;i++){
        vector<char> v;
        for(int j=0;j<n;j++){
            v.pb(A[i][j]);
        }
        board.pb(v);
    }
    bool d=func(0,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            A[i][j]=board[i][j];
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<vector<char>> arr;
    for(int i=0;i<9;i++){
        vector<char> v;
        for(int j=0;j<9;j++){
            char c;
            cin>>c;
            if(c=='0'){
                v.pb('.');
                continue;
            }
            v.pb(c);
        }
        arr.pb(v);
    }
    solveSudoku(arr);
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
