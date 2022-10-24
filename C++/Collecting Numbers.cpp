/***
CSES Problemset: https://cses.fi/problemset/task/2216
***/

#include<iostream>
using namespace std;

int main(){
   
    #ifdef LOCAL
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
    #endif
   
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   
    int n;
    cin>>n;
    int l=1;
    int ind[n+1]={0};
    for (int i= 1;i<=n;i++){
        int x;
        cin>>x;
        ind[x]=i;
    }
    int c=1;
    for(int i = 1; i <= n; i++) {
        if (l > ind[i])
            c++;
        l=ind[i];
    }
    cout<<c<<"\n";
    return 0;
}

	
