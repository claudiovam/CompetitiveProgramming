#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = (1e4) + 5;
int n, k1, k2, k3;
int a[N], ac[N];

void accumulate(int arr[], int n) {
	ac[0] = arr[0];
	for (int i = 1; i < n; ++i) {
		ac[i] = ac[i - 1] + arr[i];
	}
}

void testCase() {
	scanf("%d %d %d %d", &n, &k1, &k2, &k3);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	accumulate(a, n);
	priority_queue<int, vector<int>, greater<int> > pq; 
	priority_queue<int, vector<int>, greater<int> > tmp;
	for (int i = n - 1; i >= 0; --i) {
		if ((int) tmp.size() == k3) {
			tmp.push(ac[i]);
			tmp.pop();
		} else {
			tmp.push(ac[i]);
		}
		vector<int> v(tmp.size());
		copy(&tmp.top(), &tmp.top() + tmp.size(), &v[0]);
		for (int j = 0; j < (int) v.size(); ++j) {
			int x = v[j] - (i - 1 >= 0? ac[i - 1] : 0);
			if (pq.size() == k3 and x < pq.top()) continue;
			if (pq.size() == k3) {
				pq.push(x);
				pq.pop();
			} else {
				pq.push(x);
			}
		}
	}
	int ans3 = pq.top();
	for (int i = 0; i < k3 - k2; ++i) {
		pq.pop();
	}
	int ans2 = pq.top();
	for (int i = 0; i < k2 - k1; ++i) {
		pq.pop();
	}
	int ans1 = pq.top();
	printf("%d %d %d\n", ans1, ans2, ans3);
}

int main() {
	int tc; scanf("%d", &tc);
	for (int c = 1; c <= tc; ++c)	{
		testCase();
	}
	return 0;
}
