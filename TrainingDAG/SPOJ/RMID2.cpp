#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1000000007;
int n;

void testCase() {
	priority_queue<int> pq1;
	priority_queue<int, vector<int>, greater<int> > pq2; 
	int cnt = 0;
	while (scanf("%d", &n) == 1) {
		if (n == 0) break;
		if (n == -1) {
			printf("%d\n", pq1.top());
			pq1.pop();
			if (cnt % 2 == 0) {
				pq1.push(pq2.top());
				pq2.pop();
			}
			cnt--;
		} else {
			if (cnt == 0) {
				pq1.push(n);
			} else {
				if (cnt % 2 == 1) {
					pq1.push(n);
					pq2.push(pq1.top());
					pq1.pop();
				} else {
					pq2.push(n);
					pq1.push(pq2.top());
					pq2.pop();
				}
			}
			cnt++;
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
