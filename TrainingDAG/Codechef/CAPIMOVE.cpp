#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = (5e4) + 5;
vector<pair<int, int> > v;
int n, P[N];

void testCase() {
	scanf("%d", &n);
	priority_queue<pair<int, int> > pq, adj[n];
	for (int i = 0; i < n; ++i) {
		scanf("%d", &P[i]);
		pq.push(make_pair(P[i], i));
	}
	for (int i = 0; i < n - 1; ++i) {
		int u, v; scanf("%d %d", &u, &v);
		--u; --v;
		adj[u].push(make_pair(P[v], v));
		adj[v].push(make_pair(P[u], u));
	}
	for (int i = 0; i < n; ++i) {
		adj[i].push(make_pair(P[i], i));
	}
	for (int i = 0; i < n; ++i) {
		if (i > 0) printf(" ");
		v.clear();
		while (!pq.empty() and !adj[i].empty()) {
			pair<int, int> p1 = pq.top();
			pair<int, int> p2 = adj[i].top();
			if (p1.second == p2.second) {
				v.push_back(p1);
				pq.pop();
			}
			adj[i].pop();
		}
		if (!pq.empty()) {
			printf("%d", pq.top().second + 1);
		}  else {
			printf("0");
		}
		for (int j = 0; j < (int) v.size(); ++j) {
			pq.push(v[j]);
		}
	}
	printf("\n");
}

int main() {
	int tc; scanf("%d", &tc);
	for (int c = 1; c <= tc; ++c)	{
		testCase();
	}
	return 0;
}
