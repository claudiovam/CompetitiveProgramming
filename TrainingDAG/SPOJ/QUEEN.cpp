#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int di[] = {0, -1, -1, -1, 0, 1, 1, 1};
const int dj[] = {1, 1, 0, -1, -1, -1, 0, 1};
const int N = (1e3) + 3;
int dist[N][N];
bool uDir[N][N][8];
char M[N][N];
int si, sj, ei, ej;
int n, m;

bool val(int i, int n) {
	return 0 <= i and i < n;
}

void BFSinit(int n, int m) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			dist[i][j] = -1;
			for (int k = 0; k < 8; ++k) {
				uDir[i][j][k] = 0;
			}
		}
	}
}

void BFS(int si, int sj) {
 	deque<pair<int, int> > q;
  dist[si][sj] = 0;
	q.push_back(make_pair(si, sj));
	while (!q.empty()) {
		int i = q.front().first;
		int j = q.front().second;
		q.pop_front();
		for (int k = 0; k < 8; ++k) {
			for (int l = 1; l < max(n, m); ++l) {
				int ni = i + l * di[k];
				int nj = j + l * dj[k];
				if (!val(ni, n) or !val(nj, m)) break;
				if (M[ni][nj] == 'X') break;
				if (uDir[ni][nj][k]) break;
				if (dist[ni][nj] == -1) {
					dist[ni][nj] = dist[i][j] + 1;
					if (ni == ei and nj == ej) return;
				 	q.push_back(make_pair(ni, nj));
				} else if (dist[ni][nj] == dist[i][j] + 1) {
					uDir[ni][nj][k] = 1;
				} else {
					break;
				}
			}
   	}
	}
}

void testCase() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%s", M[i]);
		for (int j = 0; j < m; ++j) {
			if (M[i][j] == 'S') {
				si = i;
				sj = j;
			}
			if (M[i][j] == 'F') {
				ei = i;
				ej = j;
			}
		}
	}
	BFSinit(n, m);
	BFS(si, sj);
	printf("%d\n", dist[ei][ej]);
}

int main() {
	int tc; scanf("%d", &tc);
	for (int c = 1; c <= tc; ++c)	{
		testCase();
	}
	return 0;
}
