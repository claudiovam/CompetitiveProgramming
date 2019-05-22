/*  
 *  @tags brute force
 *  
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int N = 18;
ll n, a[N];

void solve() {
	for (int i = 0; i < n; ++i) {
		scanf("%lld", &a[i]);
	}
	ll mx = 0;
	for (int l = 0; l <= n-1; ++l) {
		for (int r = l; r <= n-1; ++r) {
			ll prod = 1;
			for (int i = l; i <= r; ++i) {
				prod *= a[i];
			}
			mx = max(mx, prod);
		}
	}
	printf("The maximum product is %lld.\n", mx);
}

int main() {
	int c = 0;
	while (scanf("%lld", &n) == 1) {
		printf("Case #%d: ", ++c);
		solve();
		printf("\n");
	}
	return 0;
}
