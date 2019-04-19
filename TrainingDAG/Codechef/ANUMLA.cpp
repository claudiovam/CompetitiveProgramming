#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = (15) + 5;
vector<int> v, ans;
int n;

void iep(int n, vector<int>& S, vector<int>& ret) {
	for (int mask = 0; mask < (1 << n); ++mask) {
		ll inters = 0;
		for (int i = 0; i < n; ++i) {
			if ((mask >> i) & 1) {
				inters += S[i];
			}
		}
		ret.push_back(inters);
	}
}

void testCase() {
	priority_queue<int, vector<int>, greater<int> > pq;
	scanf("%d", &n);
	for (int i = 0; i < (1 << n); ++i) {
		int a; scanf("%d", &a);
		pq.push(a);
	}
	pq.pop();
	int cnt = 1;
	ans.clear();
	for (int i = 0; i < n; ++i) {
		v.clear();
		iep(ans.size(), ans, v);
		sort(v.begin(), v.end());
		for (int j = cnt; j < (int) v.size(); ++j) {
			if (v[j] == pq.top()) {
				pq.pop();
				cnt++;
			}
		}
		ans.push_back(pq.top());
		pq.pop();
		cnt++;
	}
	for (int i = 0; i < n; ++i) {
		if (i > 0) printf(" ");
		printf("%d", ans[i]);
	}
	printf("\n");
}

int main() {
	int tc; scanf("%d", &tc);
	for (int c = 1; c <= tc; ++c)	{
		testCase();
	}
	return 0;
}
