#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1000000007;
ll a, b, c, n;

void testCase() {
	priority_queue<ll> pq1;
	priority_queue<ll, vector<ll>, greater<ll> > pq2; 
	scanf("%lld %lld %lld %lld", &a, &b, &c, &n);
	pq1.push(1);
	ll sum = 1;
	for (ll i = 2; i <= n; ++i) {
		ll m = pq1.top();
		ll f = (a * m + b * i + c) % MOD;
		sum += f;
		if ((i - 1) % 2 == 1) {
			pq1.push(f);
			pq2.push(pq1.top());
			pq1.pop();
		} else {
			pq2.push(f);
			pq1.push(pq2.top());
			pq2.pop();
		}
	}
	printf("%lld\n", sum);
}

int main() {
	int tc; scanf("%d", &tc);
	for (int c = 1; c <= tc; ++c)	{
		testCase();
	}
	return 0;
}
