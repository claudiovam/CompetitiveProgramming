#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = (1e6) + 5;
int vis[N];
int dist[N];
int f, s, g, up, d;

void BFS(int s) {
	deque<int> q;
	vis[s]  = 1;
	dist[s] = 0;
	q.push_back(s);
	while (!q.empty()) {
		int u = q.front(); q.pop_front();
		int adj[] = {u - d, u + up};
		for (int i = 0; i < 2; ++i) {
			int v = adj[i];
			if (!(0 <= v and v < f)) continue;
			if (vis[v] == 0) {
				vis[v]  = 1;
				dist[v] = dist[u] + 1;
				q.push_back(v);
			}
		}
	}
}

int main() {
	scanf("%d %d %d", &f, &s, &g);
	--s; --g;
	scanf("%d %d", &up, &d);
	BFS(s);
	if (vis[g]) {
		printf("%d\n", dist[g]);
	} else {
		printf("use the stairs\n");
	}
	return 0;
}
