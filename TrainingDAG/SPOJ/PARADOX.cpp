#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = (1e2) + 5;
vector<int> adj[N], say[N];
int color[N], contradiction;
int vis[N];
int n;

void DFSinit(int n) {
	for (int i = 0; i < n; ++i) {
		vis[i] = 0;
		color[i] = 0;
	}
	contradiction = 0;
}

bool DFS(int u, int c, int flag) {
	vis[u] = flag;
	color[u] = c;
	bool diffColor = 0;
	for (int i = 0; i < (int) adj[u].size(); ++i) {
		int v = adj[u][i];
		int c = (color[u] == 1? say[u][i] : -say[u][i]);
		if (vis[v] == flag - 1) {
			diffColor |= DFS(v, c, flag);
		} else {
			if (color[v] != c) {
				diffColor = 1;
			}
		}
	}
	return diffColor;
}

void graphInit(int n) {
	for (int i = 0; i < n; ++i) {
		adj[i].clear();
		say[i].clear();
	}
}

void testCase() {
	graphInit(n);
	for (int u = 0; u < n; ++u) {
		int v; scanf("%d", &v);
		--v;
		string s; cin >> s;
		adj[u].push_back(v);
		if (s == "true") {
			say[u].push_back(1);
		} else {
			say[u].push_back(-1);
		}
	}
	DFSinit(n);
	for (int i = 0; i < n; ++i) {
		if (vis[i] == 0) {
			contradiction = DFS(i, 1, 1) and DFS(i, -1, 2);
			if (contradiction) break;
		}
	}
	printf(!contradiction? "NOT PARADOX" : "PARADOX");
	printf("\n");
}

int main() {
	int c = 1;
	while (scanf("%d", &n) != EOF) {
		if (n == 0) break;
		testCase(); ++c;
	}
	return 0;
}
