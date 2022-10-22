/***
CSES Problemset: https://cses.fi/problemset/task/1085
***/


#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	
	#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n,k;
	cin >> n >> k;
	vector<ll> arr(n);
	
	ll max_sum = 0;
	for(int i=0;i<n;i++) {
		cin>>arr[i];
		max_sum=max_sum + arr[i];
	}
	ll beg= 0,end=max_sum,ans=0;
	auto w=[&](ll mid){
		int grp=0;
		ll sum =0;
		for(int i = 0; i < n; i++){
			if (arr[i] > mid) {
				return false;
			}
			if (sum + arr[i] > mid) {
				++grp;
				sum = 0;
			}
			sum += arr[i];
		}
		if (sum > 0) {
			++grp;
		}
		return grp<=k;
	};
	while (beg<=end) {
		ll mid = (beg+end) / 2;
		if (w(mid)) {
			end = mid - 1;
			ans = mid;
		}
		else {
			beg= mid + 1;
		}
	}
	cout << ans << '\n';
	return 0;
}
