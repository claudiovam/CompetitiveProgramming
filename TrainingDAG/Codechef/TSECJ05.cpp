#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int k, n;

void testCase() {
	priority_queue<int, vector<int>, greater<int> > pq; 
	scanf("%d %d", &k, &n);
	for (int i = 1; i <= n; ++i) {
		int a; scanf("%d", &a);
		pq.push(a);
		if (i > 1) printf(" ");
		if (i < k) {
			printf("-1");
		} else if (i == k) {
			printf("%d", pq.top());
		} else {
			pq.pop();
			printf("%d", pq.top());
		}
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
