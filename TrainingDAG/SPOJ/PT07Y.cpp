#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = (1e4) + 5;
vector<int> adj[N];
int nCC, cycle;
int vis[N];
int n, m;

void DFS(int u, int p = -1) {
	vis[u] = 1;
	for (int i = 0; i < (int) adj[u].size(); ++i) {
		int v = adj[u][i];
		if (vis[v] == 0) {
			DFS(v, u);
		} else if (v != p) {
			cycle = 1;
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int u, v; scanf("%d %d", &u, &v);
		--u; --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 0; i < n; ++i) {
		if (vis[i] == 0) {
			nCC++;
			DFS(i);
		}
	}
	bool isTree = (!cycle and nCC == 1);
	printf(isTree? "YES" : "NO");
	printf("\n");
	return 0;
}
