#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = (1e6) + 5;
vector<int> adj[N];
int color[N];
int vis[N], isBipartite;
int n, m;

void DFSinit(int n) {
	for (int i = 0; i < n; ++i) {
		vis[i] = 0;
		color[i] = 0;
	}
	isBipartite = 1;
}

void DFS(int u, int c) {
	vis[u] = 1;
	color[u] = c;
	for (int i = 0; i < (int) adj[u].size(); ++i) {
		int v = adj[u][i];
		if (!vis[v]) {
			DFS(v, -c);
		} else {
			if (color[v] == color[u]) {
				isBipartite = 0;
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
	graphInit(n);
	for (int i = 0; i < m; ++i) {
		int u, v; scanf("%d %d", &u, &v);
		--u; --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	DFSinit(n);
	for (int i = 0; i < n; ++i) {
		if (!vis[i]) {
			DFS(i, 1);
		}
	}
	printf(isBipartite? "No suspicious bugs found!" : "Suspicious bugs found!");
	printf("\n");
}

int main() {
	int tc; scanf("%d", &tc);
	for (int c = 1; c <= tc; ++c)	{
		printf("Scenario #%d:\n", c);
		testCase();
	}
	return 0;
}
