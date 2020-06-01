#pragma GCC optimize ("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")

#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;


typedef unsigned long long ull;
const ull MOD = 1000000007;

// dp[i]: i번째까지 배열을 채울 수 있는 경우의 수
// dp[i][0]: 끝에 넣는 수가 1
// dp[i][1]: 끝에 넣는 수가 1초과
ull dp[100001][2];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ull n, k, x;
    cin >> n >> k >> x;

    dp[1][0] = 1;
    for (int i = 2; i <= n; ++i) {
        dp[i][0] = dp[i - 1][1] * (k - 1) % MOD;
        dp[i][1] = (dp[i - 1][0] + (k - 2) * dp[i - 1][1]) % MOD;
    }

    cout << (x == 1 ? dp[n][0] : dp[n][1]) << '\n';

    return 0;
}
