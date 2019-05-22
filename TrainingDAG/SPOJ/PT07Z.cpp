#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = (1e4) + 5;
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
		for (int i = 0; i < (int) adj[u].size(); ++i) {
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

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n - 1; ++i) {
		int u, v; scanf("%d %d", &u, &v);
		--u; --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	printf("%d\n", diamTree());
	return 0;
}
