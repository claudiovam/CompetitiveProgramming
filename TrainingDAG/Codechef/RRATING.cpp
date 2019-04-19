#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;

int main() {
	priority_queue<int> pq1; 
	priority_queue<int, vector<int>, greater<int> > pq2;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int cmd; scanf("%d", &cmd);
		if (cmd == 1) {
			int x; scanf("%d", &x);
			if ((int) pq1.size() + (int) pq2.size() == 0) {
				pq1.push(x);
			} else {
				if (((int) pq2.size() + 1) * 2 == (int) pq1.size()) {
					pq1.push(x);
					pq2.push(pq1.top());
					pq1.pop();
				} else {
					pq2.push(x);
					pq1.push(pq2.top());
					pq2.pop();
				}
			}
		} else {
			if (pq2.empty()) {
				printf("No reviews yet\n");
			} else {
				printf("%d\n", pq2.top());
			}
		}
	}
	return 0;
}
