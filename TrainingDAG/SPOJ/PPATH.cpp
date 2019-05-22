#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = (1e4) + 5;
int factP[N];
int dist[N];
int s, e;

void extSieve(int n) {
	for (int i = 2; i*i <= n; ++i) {
		if (factP[i] == 0) {
			for (int j = i*i; j <= n; j += i) {
				factP[j] = i;
			}
		}
	}
	for (int i = 2; i <= n; ++i) {
		if (factP[i] == 0) {
			factP[i] = i;
		}
	}
}

void BFSinit(int n) {
	for (int i = 0; i < n; ++i) {
		dist[i] = -1;
	}
}

void BFS(int s) {
	deque<int> q;
	dist[s] = 0;
	q.push_back(s);
	while (!q.empty()) {
		int u = q.front(); q.pop_front();
		for (int i = 10; i <= 10000; i *= 10) {
			for (int j = 0; j <= 9; ++j) {
				int v = u - ((u % i) - (u % (i / 10))) + j * (i / 10);
				if (!(v >= 1000 and v != u and factP[v] == v)) continue;
				if (dist[v] == -1) {
					dist[v] = dist[u] + 1;
					if (v == e) return;
					q.push_back(v);
				}
			}
		}
	}
}

void testCase() {
	scanf("%d %d", &s, &e);
	BFSinit(N - 5);
	BFS(s);
	if (dist[e] != -1) {
		printf("%d\n", dist[e]);
	} else {
		printf("Impossible\n");
	}
}

int main() {
	extSieve(N - 5);
	int tc; scanf("%d", &tc);
	for (int c = 1; c <= tc; ++c)	{
		testCase();
	}
	return 0;
}
