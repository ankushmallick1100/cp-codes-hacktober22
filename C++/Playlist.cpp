/***
CSES Problemset: https://cses.fi/problemset/task/1141
***/

#include<bits/stdc++.h>
#define ll long long 
using namespace std;

ll cost(vector<int> arr,int tgt){
	ll cost=0;
	for(auto ele:arr)
		cost += abs(tgt - ele);
	return cost;
}

int main()
{
// 	#ifndef ONLINE_JUDGE
//     freopen("input.txt","r",stdin);
//     freopen("output.txt","w",stdout);
//     #endif
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++)
		cin >> arr[i];
		
	int i=0,j=0,max_len=0,len=0;
	map<int, int> f;
	while (j<n){
		if(f.find(arr[j])==f.end() || f[arr[j]]==0){
			f[arr[j]]++;
			len++;
			max_len=max(max_len,len);
			j++;
		}
		else{
			len--;
			f[arr[i]]--;
			i++;
		}
	}
	cout<<max_len;
	return 0;
}
