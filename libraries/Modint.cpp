#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define _GLIBCXX_DEBUG
#define rep(i, c) for (int i = 0; i < (int)c; i++)
#define debug(x) cout << #x << " = " << x << endl
#define print(x) cout << x << endl;
const int MOD = 1000000007;

int modPow(ll a, ll n, ll p)
{
    if (n == 1)
        return a % p;
    if (n % 2 == 1)
        return (a * modPow(a, n - 1, p)) % p;
    long long t = modPow(a, n / 2, p);
    return (t * t) % p;
}

ll modInv(ll a, ll p)
{
    ll b = p, u = 1, v = 0;
    while (b)
    {
        ll t = a / b;
        a -= t * b;
        swap(a, b);
        u -= t * v;
        swap(u, v);
    }
    u %= p;
    if (u < 0)
        u += p;
    return u;
}

// modint: mod 計算を int を扱うように扱える構造体
template <int MOD>
struct Fp
{
    ll val;
    constexpr Fp(ll v = 0) noexcept : val(v % MOD)
    {
        if (val < 0)
            val += MOD;
    }
    constexpr int getmod() { return MOD; }
    constexpr Fp operator-() const noexcept
    {
        return val ? MOD - val : 0;
    }
    constexpr Fp operator+(const Fp &r) const noexcept { return Fp(*this) += r; }
    constexpr Fp operator-(const Fp &r) const noexcept { return Fp(*this) -= r; }
    constexpr Fp operator*(const Fp &r) const noexcept { return Fp(*this) *= r; }
    constexpr Fp operator/(const Fp &r) const noexcept { return Fp(*this) /= r; }
    constexpr Fp &operator+=(const Fp &r) noexcept
    {
        val += r.val;
        if (val >= MOD)
            val -= MOD;
        return *this;
    }
    constexpr Fp &operator-=(const Fp &r) noexcept
    {
        val -= r.val;
        if (val < 0)
            val += MOD;
        return *this;
    }
    constexpr Fp &operator*=(const Fp &r) noexcept
    {
        val = val * r.val % MOD;
        return *this;
    }
    constexpr Fp &operator/=(const Fp &r) noexcept
    {
        ll a = r.val, b = MOD, u = 1, v = 0;
        while (b)
        {
            ll t = a / b;
            a -= t * b;
            swap(a, b);
            u -= t * v;
            swap(u, v);
        }
        val = val * u % MOD;
        if (val < 0)
            val += MOD;
        return *this;
    }
    constexpr bool operator==(const Fp &r) const noexcept
    {
        return this->val == r.val;
    }
    constexpr bool operator!=(const Fp &r) const noexcept
    {
        return this->val != r.val;
    }
    friend constexpr ostream &operator<<(ostream &os, const Fp<MOD> &x) noexcept
    {
        return os << x.val;
    }
    friend constexpr Fp<MOD> modpow(const Fp<MOD> &a, ll n) noexcept
    {
        if (n == 0)
            return 1;
        auto t = modpow(a, n / 2);
        t = t * t;
        if (n & 1)
            t = t * a;
        return t;
    }
};

const int MOD = 1000000007;
using mint = Fp<MOD>;

int main()
{
    mint a = 423343;
    mint b = 74324;
    mint c = 13231;
    mint d = 8432455;

    cout << (a * b + c) / d << endl;
}