#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = (1e5) + 3;
const int LOG_N = (16) + 1;
vector<int> adj[N];
int anc[N][LOG_N], lev[N];
vector<int> peoples[N][LOG_N];
vector<int> ans;
int n, m, q;

vector<int> merge(vector<int>& A, vector<int>& B) {
	vector<int> M;
	int szA = A.size();
	int szB = B.size();
	int i = 0, j = 0;
	while (i < szA and j < szB) {
		if ((int) M.size() == 10) return M;
		if (A[i] < B[j]) {
			M.emplace_back(A[i++]);
		} else {
			M.emplace_back(B[j++]);
		}
	}
	while (i < szA) {
		if ((int) M.size() == 10) return M;
		M.emplace_back(A[i++]);
	}
	while (j < szB) {
		if ((int) M.size() == 10) return M;
		M.emplace_back(B[j++]);
	}
	return M;
}

void DFS(int u, int l = 0) {
	lev[u] = l;
	for (int i = 0; i < (int) adj[u].size(); ++i) {
		int v = adj[u][i];
		if (v != anc[u][0]) {
			anc[v][0] = u;
			DFS(v, l + 1);
		}
	}
}

void LCA_preprocess(int n) {
	for (int k = 1; (1 << k) < n; ++k) {
		for (int i = 0; i < n; ++i) {
			anc[i][k] = -1;
		}
	}
	for (int k = 1; (1 << k) < n; ++k) {
		for (int i = 0; i < n; ++i) {
			if (anc[i][k - 1] != -1) {
				anc[i][k] = anc[anc[i][k - 1]][k - 1];
				peoples[i][k] = merge(peoples[i][k - 1], peoples[anc[i][k - 1]][k - 1]);
			}
		}
	}
}

int ancestor(int u, int dist) {
	for (int i = 0; i < LOG_N; ++i) {
    if ((dist >> i) & 1) {
    	u = anc[u][i];
  	}
  }
  return u;
}

int LCA(int u, int v) {
	if (lev[u] < lev[v]) swap(u, v);
	u = ancestor(u, lev[u] - lev[v]);
	if (u == v) return u;
	for (int i = LOG_N - 1; i >= 0; i--) {
		if (anc[u][i] != anc[v][i]) {
			u = anc[u][i]; v = anc[v][i];
		}
	}
	return anc[u][0];
}

void mergePath(int u, int dist) {
	for (int i = 0; i < LOG_N; ++i) {
		if ((dist >> i) & 1) {
			ans = merge(ans, peoples[u][i]);
			u = anc[u][i];
		}
  }
}

int main() {
	scanf("%d %d %d", &n, &m, &q);
	for (int i = 0; i < n - 1; ++i) {
		int u, v; scanf("%d %d", &u, &v);
		--u; --v;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}
	for (int i = 0; i < m; ++i) {
		int c; scanf("%d", &c);
		peoples[--c][0].emplace_back(i);
	}
	for (int i = 0; i < n; ++i) {
		sort(peoples[i][0].begin(), peoples[i][0].end());
		peoples[i][0].resize(min(10, (int) peoples[i][0].size()));
	}
	int root = 0;
	anc[root][0] = -1;
	DFS(root);
	LCA_preprocess(n);
	for (int i = 0; i < q; ++i) {
		int u, v; scanf("%d %d", &u, &v);
		--u; --v;
		int a; scanf("%d", &a);
		ans.clear();
		int lca = LCA(u, v);
		mergePath(u, lev[u] - lev[lca]);
		mergePath(v, lev[v] - lev[lca]);
		ans = merge(ans, peoples[lca][0]);
		int k = min((int) ans.size(), a);
		printf("%d ", k);
		for (int j = 0; j < k; ++j) {
			printf("%d ", ans[j] + 1);
		}
		printf("\n");
	}
	return 0;
}
