/*  
 *  @tags meet-in-the-middle
 *  @idea Dividir en 2 grupos de 2 listas, hallar todas las sumas por grupo, encontrarse los 2 grupos de sumas.
 *  
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int N = (2500) + 5;
int Sum1[N*N], Sum2[N*N];
int A[N], B[N], C[N], D[N];
int n;

void sum(int X[], int Y[], int Sum[], int sz) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			Sum[i*n + j] = X[i] + Y[j];
		}
	}
	sort(Sum, Sum + sz);
}

int meetInTheMiddle() {
	int sz = n*n;
	sum(A, B, Sum1, sz);
	sum(C, D, Sum2, sz);
	int cnt = 0;
	int l = 0, r = 0;
	for (int i = sz-1; i >= 0; --i) {
		l = lower_bound(Sum2 + l, Sum2 + sz, -Sum1[i]) - Sum2;
		r = upper_bound(Sum2 + l, Sum2 + sz, -Sum1[i]) - Sum2;
		cnt += r - l;
	}
	return cnt;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d %d %d %d", &A[i], &B[i], &C[i], &D[i]);
	}
	printf("%d\n", meetInTheMiddle());
	return 0;
}
