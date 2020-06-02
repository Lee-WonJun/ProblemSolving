#pragma GCC optimize ("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")

#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;


typedef long long ll;

ll histogram[100];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    memset(bino, -1, sizeof(bino));
    
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;
        ++histogram[tmp % k];
    }

    ll subsets = 0;

    if (histogram[0])
        ++subsets;

    for (int i = 1; i * 2 <= k; ++i) {
        if (i * 2 == k) subsets += (histogram[i] > 0);
        else subsets += max(histogram[i], histogram[k - i]);
    }

    cout << subsets << '\n';

    return 0;
}
