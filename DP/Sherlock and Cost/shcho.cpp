#pragma GCC optimize ("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")

#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;


typedef long long ll;

ll dp[100001][2];	//0: 제일 작은거(1), 1: 제일 큰거

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t, n;
	cin >> t;
	while (t--) {
		memset(dp, 0, sizeof(dp));

		cin >> n;
		vector<int> arr_b(n);
		for (auto& c : arr_b)
			cin >> c;

		for (int i = 2; i <= n; ++i) {
			dp[i][0] = max(dp[i - 1][0], dp[i-1][1] + llabs(arr_b[i-2] - 1));
			dp[i][1] = max(dp[i - 1][0] + llabs(arr_b[i-1] - 1), dp[i-1][1] + llabs(arr_b[i-1] - arr_b[i-2]));
		}

		cout << *max_element(dp[n], dp[n] + 2) << '\n';
	}

	return 0;
}