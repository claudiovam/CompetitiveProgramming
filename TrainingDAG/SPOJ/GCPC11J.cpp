#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = (1e5) + 5;
vector<int> adj[N];
int dist[N];
int n;

int BFS(int s) {
	for (int i = 0; i < n; ++i) {
		dist[i] = -1;
	}
	deque<int> q;
	dist[s] = 0;
	q.push_back(s);
	int u;
	while (!q.empty()) {
		u = q.front(); q.pop_front();
		for (int i = 0; i < adj[u].size(); ++i) {
			int v = adj[u][i];
			if (dist[v] == -1) {
				dist[v] = dist[u] + 1;
				q.push_back(v);
			}
		}
	}
	return u;
}

int diamTree() {
  int s = BFS(0);
  int e = BFS(s);
  return dist[e];
}

void graphInit(int n) {
	for (int i = 0; i < n; ++i) {
		adj[i].clear();
	}
}

void testCase() {
	scanf("%d", &n);
	graphInit(n);
	for (int i = 0; i < n - 1; ++i) {
		int u, v; scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int diam = diamTree();
	printf("%d\n", diam / 2 + (diam % 2));
}

int main() {
	int tc; scanf("%d", &tc);
	for (int c = 1; c <= tc; ++c)	{
		testCase();
	}
	return 0;
}
