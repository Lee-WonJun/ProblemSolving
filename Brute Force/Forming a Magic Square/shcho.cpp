#pragma GCC optimize ("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")

#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;


const int INF = 987654321;

bool is_magic(const vector<int>& v) {
    const int sum = v[0] + v[1] + v[2];

    return (sum == v[3]+v[4]+v[5] &&
        sum == v[6]+v[7]+v[8] &&
        sum == v[0]+v[3]+v[6] &&
        sum == v[1]+v[4]+v[7] &&
        sum == v[2]+v[5]+v[8] &&
        sum == v[0]+v[4]+v[8] &&
        sum == v[2]+v[4]+v[6]);
}

int cost(const vector<int>& v1, const vector<int>& v2) {
    int ret = 0;
    for (int i = 0; i < 9; ++i) {
        ret += abs(v1[i] - v2[i]);
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<int> arr = { 1,2,3,4,5,6,7,8,9 };
    vector<int> input(9);
    for (auto& c : input)
        cin >> c;

    int min_cost = INF;
    do {
        if (is_magic(arr))
            min_cost = min(min_cost, cost(arr, input));
    } while (next_permutation(arr.begin(), arr.end()));

    cout << min_cost << '\n';

    return 0;
}
