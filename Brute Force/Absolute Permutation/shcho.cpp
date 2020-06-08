#pragma GCC optimize ("Ofast")

#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<bool> used(n);
        vector<int> ans;
        bool flag = true;
        for (int i = 1; i <= n && flag; ++i) {
            if (i-k>0 && i-k<=n && !used[i-k-1]) {
                ans.push_back(i - k);
                used[i-k-1] = true;
            }
            else if (i+k>0 && i+k<=n && !used[i+k-1]) {
                ans.push_back(i + k);
                used[i+k-1] = true;
            }
            else {
                flag = false;
            }
        }

        if (flag) {
            for (auto& c : ans)
                cout << c << ' ';
            cout << '\n';
        }
        else {
            cout << -1 << '\n';
        }
    }

    return 0;
}
