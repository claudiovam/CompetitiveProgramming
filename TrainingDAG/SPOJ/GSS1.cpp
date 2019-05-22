#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = (1e5) + 5;
const ll oo = 1e9;
ll n, a[N];
int q;
 
struct node {
  ll sumx;
  ll l, r;
  ll sumt;
} st[4*N];
const node NEUTRAL = {-oo, -oo, -oo, 0};
 
node fusion(node &p, node &q) {
  node ret;
  ret.sumx = max(p.sumx, max(q.sumx, p.r+q.l));
  ret.l = max(p.sumt + q.l, p.l);
  ret.r = max(q.sumt + p.r, q.r);
  ret.sumt = p.sumt + q.sumt;
  return ret;
}

void build(int l = 0, int r = n-1, int id = 1) {
  if (l == r) {
    st[id] = {a[r], a[r], a[r], a[r]};
    return;
  }
  int mid = (l+r)/2;
  build( l,  mid, 2*id);
  build(mid+1, r, 2*id+1);
  st[id] = fusion(st[2*id], st[2*id+1]);
}
 
node query(int a, int b, int l = 0, int r = n-1, int id = 1) {
  if (b < l or r < a) return NEUTRAL;    
  if (a <= l and r <= b) return st[id];
  int mid = (l+r)/2;
  node L = query(a, b,  l,  mid, 2*id);
  node R = query(a, b, mid+1, r, 2*id+1);
  return fusion(L, R);
}

int main() {
	scanf("%lld", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%lld", &a[i]);
	}
	build();
	scanf("%d", &q);
	for (int i = 0; i < q; ++i) {
		int l, r; scanf("%d %d", &l, &r);
		l--; r--;
		printf("%lld\n", query(l, r).sumx);
	}
	return 0;
}
