#pragma GCC optimize ("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")

#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;


const int INF = 987654321;

int dp[1005];

int solve(int n) {
	int& ret = dp[n];
	if (ret != -1) return ret;

	ret = solve(n-1)+1;
	if (n - 2 >= 0) ret = min(ret, solve(n-2) + 1);
	if (n - 5 >= 0) ret = min(ret, solve(n-5) + 1);

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);


	memset(dp, -1, sizeof(dp));
	dp[0] = 0;

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> arr(n);
		for (auto& c : arr)
			cin >> c;

		int min_val = *min_element(arr.begin(), arr.end());

		for (auto& c : arr)
			c -= min_val;

		int cnt0 = 0, cnt1 = 0, cnt2 = 0;
		for (auto& c : arr) {
			cnt0 += solve(c);
			cnt1 += solve(c + 1);
			cnt2 += solve(c + 2);
		}
		cout << min({cnt0, cnt1, cnt2}) << '\n';
	}
	
	return 0;
}
