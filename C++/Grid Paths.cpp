#include<bits/stdc++.h>
#define ll long long

using namespace std;
bool v[7][7];
string path;
int ans=0;

inline bool valid(int i,int j){
    if(i<7 && j<7 && i>=0 && j>=0 && !v[i][j])
        return true;
    return false;
}

void sol(int i,int j,int a){
    //dbg(i, j, a);
    if(i==6 && j==0){
        if(a==48)
            ans++;
        return;
    }
    v[i][j]=true;

    if((path[a]=='U' || path[a]=='?')){
        if(i>0 && valid(i-1,j)){
            if(!(!valid(i-2,j) && valid(i-1,j-1) && valid(i-1,j+1)) || (i-1==6 && j==0))
                sol(i-1,j,a+1);
        }
    }
    if(path[a]=='D' || path[a]=='?'){
        if(i<6 && valid(i+1,j)) {
            if(!(!valid(i+2,j) && valid(i+1,j-1) && valid(i+1,j+1))) 
                sol(i+1,j,a+1);
        }
    }
    if(path[a]=='L' || path[a]=='?'){
        if(j>0 && valid(i,j-1)) {
            if(!(!valid(i,j-2) && valid(i-1,j-1) && valid(i+1,j-1))) 
                sol(i,j-1,a+1);
        }
    }
    if(path[a]=='R' || path[a]=='?'){
        if (j<6 && valid(i,j+1)){
            if(!(!valid(i,j+2)  && valid(i-1,j+1) && valid(i+1,j+1)))
                sol(i,j+1,a+1);
        }
    }

    v[i][j]=false;
    return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
 	cin>>path;
    sol(0,0,0);
    cout<<ans;
}
