// El problema explica que el grafo es DAG?
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = (1e4) + 5;
const ll MOD = 1000000007;
vector<int> adj[N];
int vis[N];
int memo[N];
int n, m, s, t;

void BFSinit(int n) {
	for (int i = 0; i < n; ++i) {
		vis[i]  = 0;
		memo[i] = 0;
	}
}

void BFS(int s) {
	deque<int> q;
	vis[s]  = 1;
	memo[s] = 1;
	q.push_back(s);
	while (!q.empty()) {
		int u = q.front(); q.pop_front();
		for (int i = 0; i < adj[u].size(); ++i) {
			int v = adj[u][i];
			memo[v] += memo[u];
			memo[v] %= MOD;
			if (!vis[v]) {
				vis[v]  = 1;
				q.push_back(v);
			}
		}
	}
}

void graphInit(int n) {
	for (int i = 0; i < n; ++i) {
		adj[i].clear();
	}
}

void testCase() {
	scanf("%d %d", &n, &m);
	scanf("%d %d", &s, &t);
	--s; --t;
	graphInit(n);
	for (int i = 0; i < m; ++i) {
		int u, v; scanf("%d %d", &u, &v);
		--u; --v;
		adj[u].push_back(v);
	}
	BFSinit(n);
	BFS(s);
	printf("%d\n", memo[t]);
}

int main() {
	int tc; scanf("%d", &tc);
	for (int c = 1; c <= tc; ++c)	{
		testCase();
	}
	return 0;
}
