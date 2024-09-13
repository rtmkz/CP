#include <bits/stdc++.h>

#define ll long long int

using namespace std;

const int N = (int)1e5 + 7;
const int A = (int)1e9 + 7;
const ll linf = (ll)1e18 + 7;
const int LOG = 30;

int n;
int a[N], b[N];
ll dp[N];

struct line {
    ll k, b;

    ll get(ll x) {
        return k * x + b;
    }
};

struct lichao {
    int sz{0}, root{0};
    int ls[N * LOG], rs[N * LOG];
    line t[N * LOG];

    void upd(line x, int& v, int tl = 1, int tr = A) {
        if (!v) {
            v = ++sz;
            t[v] = x;
            return;
        }
        int tm = (tl + tr) / 2;
        bool lef_opt = x.get(tl) < t[v].get(tl);
        bool mid_opt = x.get(tm) < t[v].get(tm);

        if (mid_opt) {
            swap(x, t[v]);
        }
        if (tl == tr) return;
        if (lef_opt != mid_opt) upd(x, ls[v], tl, tm);
        else upd(x, rs[v], tm + 1, tr);
    }
    void upd(line x) {
        upd(x, root);
    }
    ll get(int x, int v = 1, int tl = 1, int tr = A) {
        if (!v) return linf;
        if (tl == tr) {
            return t[v].get(x);
        }
        int tm = (tl + tr) / 2;
        if (x <= tm) return min(t[v].get(x), get(x, ls[v], tl, tm));
        else return min(t[v].get(x), get(x, rs[v], tm + 1, tr));
    }
} t;


int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        dp[i] = linf;
    }
    dp[1] = 0;
    t.upd({b[1], dp[1]});
    for (int i = 2; i <= n; i++) {
        /*
          for (int j = 1; j < i; j++) {
              dp[i] = min(dp[i], dp[j] + a[i] * b[j]);
          }
        */
        dp[i] = t.get(a[i]);
        t.upd({b[i], dp[i]});
    }
    cout << dp[n];
    return 0;
}
