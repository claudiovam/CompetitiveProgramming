#include <cstdio>
#include <queue>
using namespace std;
typedef long long ll;

int n;

int main() {
	scanf("%d", &n);
	priority_queue<int> pq;
	for (int i = 1; i <= n; ++i) {
		int x; scanf("%d", &x);
		if (i <= (n / 2) + (n & 1) + 1) {
			pq.push(x);
		} else {
			if (x < pq.top()) {
				pq.pop();
				pq.push(x);
			}
		}
	}
	ll a = pq.top(); pq.pop();
	ll b = pq.top(); pq.pop();
	if (n & 1) {
		printf("%lld.0\n", b);
	} else {
		ll sum = a + b;
		if (sum & 1) {
			printf("%lld.5\n", sum / 2);
		} else {
			printf("%lld.0\n", sum / 2);
		}
	}
	return 0;
}
