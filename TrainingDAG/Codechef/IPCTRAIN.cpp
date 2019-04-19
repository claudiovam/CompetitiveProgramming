#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = (1e5) + 5;
vector<int> v[N];
int D[N], T[N], S[N];
int n, d;

void testCase() {
	scanf("%d %d", &n, &d);
	for (int i = 0; i < d; ++i) {
		v[i].clear();
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d %d %d", &D[i], &T[i], &S[i]);
	}
	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		ans += 1LL * S[i] * T[i];
		v[D[i] - 1].push_back(i);
	}
	priority_queue<pair<int, int> > pq;
	for (int i = 0; i < d; ++i) {
		for (int j = 0; j < v[i].size(); ++j) {
			int ind = v[i][j];
			pq.push(make_pair(S[ind], T[ind]));
		}
		if (!pq.empty()) {
			pair<int, int> p = pq.top();
			pq.pop();
			ans -= p.first;
			--p.second;
			if (p.second != 0) {
				pq.push(p);
			}
		}
	}
	printf("%lld\n", ans);
}

int main() {
	int tc; scanf("%d", &tc);
	for (int c = 1; c <= tc; ++c)	{
		testCase();
	}
	return 0;
}
