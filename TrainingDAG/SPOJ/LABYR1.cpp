#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int di[] = {0, -1, -1, -1, 0, 1, 1, 1};
const int dj[] = {1, 1, 0, -1, -1, -1, 0, 1};
const int N = (1e3) + 3;
int dist[N][N];
char M[N][N];
int n, m;

bool val(int i, int n) {
	return 0 <= i and i < n;
}

pair<int, int> BFS(int si, int sj) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			dist[i][j] = -1;
		}
	}
	deque<pair<int, int> > q;
  dist[si][sj] = 0;
	q.push_back(make_pair(si, sj));
	pair<int, int> u;
	while (!q.empty()) {
		u = q.front(); q.pop_front();
		int i = u.first;
		int j = u.second;
		for (int k = 0; k < 8; k += 2) {
			int ni = i + di[k];
			int nj = j + dj[k];
			if (!val(ni, n) or !val(nj, m)) continue;
			if (M[ni][nj] == '#') continue;
			if (dist[ni][nj] == -1) {
			  dist[ni][nj] = dist[i][j] + 1;
			 	q.push_back(make_pair(ni, nj));
			}
   	}
	}
	return u;
}

int diamTree(int i, int j) {
  pair<int, int> s = BFS(i, j);
  pair<int, int> e = BFS(s.first, s.second);
  return dist[e.first][e.second];
}

void testCase() {
	scanf("%d %d", &m, &n);
	for (int i = 0; i < n; ++i) {
		scanf("%s", M[i]);
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (M[i][j] == '.') {
				printf("Maximum rope length is %d.\n", diamTree(i, j));
				return;
			}
		}
	}
}

int main() {
	int tc; scanf("%d", &tc);
	for (int c = 1; c <= tc; ++c)	{
		testCase();
	}
	return 0;
}
