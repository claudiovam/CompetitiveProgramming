#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;

void testCase() {
	priority_queue<int> pq1;
	priority_queue<int, vector<int>, greater<int> > pq2; 
	while (scanf("%d", &n) == 1) {
		if (n == 0) break;
		if (n == -1) {
			printf("%d\n", pq1.top());
			pq1.pop();
			if ((int) pq1.size() + 1 == (int) pq2.size()) {
				pq1.push(pq2.top());
				pq2.pop();
			}
		} else {
			if ((int) pq1.size() + (int) pq2.size() == 0) {
				pq1.push(n);
			} else {
				if ((int) pq2.size() + 1 == (int) pq1.size()) {
					pq1.push(n);
					pq2.push(pq1.top());
					pq1.pop();
				} else {
					pq2.push(n);
					pq1.push(pq2.top());
					pq2.pop();
				}
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
