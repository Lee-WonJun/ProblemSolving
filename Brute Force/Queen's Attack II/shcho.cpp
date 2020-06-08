#pragma GCC optimize ("Ofast")

#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;


const int DIR[][2] = { {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1} };
set<string> obstacle;

bool in_range(const int& y, const int& x, const int& n) {
    return y >= 0 && y < n && x >= 0 && x < n;
}

string pt_to_str(const int& r, const int& c) {
    return to_string(r) + "," + to_string(c);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n, k;
    cin >> n >> k;

    int rq, cq;
    cin >> rq >> cq;
    --rq, --cq;

    while (k--) {
        int r, c;
        cin >> r >> c;
        --r, --c;
        obstacle.insert(pt_to_str(r, c));
    }

    int counter = 0;
    for (const auto& d : DIR) {
        //cout << "--\n";
        const auto& dy = d[0], & dx = d[1];
        auto y = rq + dy, x = cq + dx;

        while (in_range(y, x, n) && obstacle.find(pt_to_str(y, x))==obstacle.end()) {
            //cout << y << ", " << x << '\n';
            y += dy, x += dx;
            ++counter;
        }
    }
    cout << counter << '\n';

    
    return 0;
}
