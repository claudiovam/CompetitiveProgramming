#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = (1e5) + 5;
vector<int> adj[N];
int vis[N];
int nCC;
int n, m;

void DFSinit(int n) {
	for (int i = 0; i < n; ++i) {
		vis[i] = 0;
	}
	nCC = 0;
}

void DFS(int u) {
	vis[u] = 1;
	for (int i = 0; i < (int) adj[u].size(); ++i) {
		int v = adj[u][i];
		if (vis[v] == 0) {
			DFS(v);
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
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	DFSinit(n);
	for (int i = 0; i < n; ++i) {
		if (!vis[i]) {
			nCC++;
			DFS(i);
		}
	}
	printf("%d\n", cc);
}

int main() {
	int tc; scanf("%d", &tc);
	for (int c = 1; c <= tc; ++c)	{
		testCase();
	}
	return 0;
}
