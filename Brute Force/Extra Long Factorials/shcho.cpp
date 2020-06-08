#pragma GCC optimize ("Ofast")

#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define GROUP_DEC_SIZE 4
class BigInt {
private:
    vector<int> groups;
    void incDigit(int, int);

public:
    BigInt() : groups({ 0 }) {};
    BigInt(int n) : groups({ 0 }) { incDigit(0, n); };
    ~BigInt() {};

    BigInt& operator*(int x);
    BigInt& operator+(const BigInt& rhs) const;
    BigInt& operator*(const BigInt& rhs) const;

    friend ostream& operator<<(ostream&, const BigInt&);
};

void BigInt::incDigit(int idx, int n) {
    if (groups.size() <= idx) groups.resize(idx + 1);

    int dec_mod = pow(10, GROUP_DEC_SIZE);
    groups[idx] += n;
    int mod_g = groups[idx] % dec_mod;
    int extra = groups[idx] / dec_mod;
    groups[idx] = mod_g;

    if (extra > 0) {
        incDigit(idx + 1, extra);
    }
}

BigInt& BigInt::operator*(int x) {
    int extra = 0;
    int dec_mod = pow(10, GROUP_DEC_SIZE);

    for (auto& g : groups) {
        g = g * x + extra;
        int mod_g = g % dec_mod;
        extra = g / dec_mod;
        g = mod_g;
    }

    while (extra > 0) {
        groups.push_back(extra % dec_mod);
        extra /= dec_mod;
    }

    return *this;
}

BigInt& BigInt::operator*(const BigInt& rhs) const {
    BigInt* mul = new BigInt();

    int size_lhs = groups.size();
    int size_rhs = rhs.groups.size();

    for (int i_lhs = 0; i_lhs < size_lhs; i_lhs++) {
        for (int i_rhs = 0; i_rhs < size_rhs; i_rhs++) {
            mul->incDigit(i_lhs + i_rhs, groups[i_lhs] * rhs.groups[i_rhs]);
        }
    }

    return *mul;
}

BigInt& BigInt::operator+(const BigInt& rhs) const {
    BigInt& sum = const_cast<BigInt&>(*this);

    int size_rhs = rhs.groups.size();
    for (int i = 0; i < size_rhs; i++) {
        sum.incDigit(i, rhs.groups[i]);
    }

    return sum;
}

ostream& operator<<(ostream& os, const BigInt& bi) {
    os.fill('0');
    for (auto pg = bi.groups.rbegin(); pg != bi.groups.rend(); pg++) {
        if (pg == bi.groups.rbegin()) {
            os << *pg;
        }
        else {
            os << std::setw(GROUP_DEC_SIZE) << *pg;
        }
    }
    return os;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n;
    cin >> n;

    BigInt ret(1);
    for (int i = 2; i <= n; ++i)
        ret = ret * i;
    
    cout << ret;

    return 0;
}
