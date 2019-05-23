#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = (1e5) + 5;
pair<ll, pair<int, int> > edges[N];
int par[N], rnk[N];
int n, m;

void DSU_init(int n) {
  for (int i = 0; i < n; ++i) {
    par[i] = i;
    rnk[i] = 0;
  }
}

int Find(int x) {
  if (par[x] == x) return x;
  return par[x] = Find(par[x]);
}

void Union(int x, int y) {
  x = Find(x);
  y = Find(y);
  if (x == y) return;
  if (rnk[x] > rnk[y]) {
    par[y] = x;
  } else {
	  par[x] = y;
    if (rnk[x] == rnk[y]) ++rnk[y];
  }
}

bool sameSet(int x, int y) {
  return Find(x) == Find(y);
}

ll kruskal(int n, int m) {
  DSU_init(n);
  sort(edges, edges + m);
  ll MST_cost = 0;
  int cntEdges = 0;
	for (int i = 0; i < m; ++i) {
		if (cntEdges == n - 1) break;
		int u = edges[i].second.first;
		int v = edges[i].second.second;
		ll  w = edges[i].first;
		if (!sameSet(u, v)) {
			Union(u, v);
			MST_cost += w;
			++cntEdges;
		}
	}
	return MST_cost;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int u, v; scanf("%d %d", &u, &v);
		--u; --v;
		ll w; scanf("%lld", &w);
		edges[i] = make_pair(w, make_pair(u, v));
	}
	ll MST_cost = kruskal(n, m);
	printf("%lld\n", MST_cost);
	return 0;
}
