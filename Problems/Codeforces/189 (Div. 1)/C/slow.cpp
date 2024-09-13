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
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            dp[i] = min(dp[i], dp[j] + a[i] * b[j]);
        }
    }
    cout << dp[n];
    return 0;
}
