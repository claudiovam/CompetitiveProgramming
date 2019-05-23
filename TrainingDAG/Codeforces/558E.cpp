#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = (1e5) + 5;
const int ALPH = 26;
const ll  NEUTRAL = 0;
int st[ALPH][4*N], lazy[ALPH][4*N];
int n, freq[ALPH][N];
char s[N];
int q;

int fusion(int p, int q) {
  return p + q;
}

void upd(int ind, int val, int l, int r, int id) {
	if (val == 1) {
		lazy[ind][id] = val;
		st[ind][id] = 0;
	} else if (val == 2) {
		lazy[ind][id] = val;
		st[ind][id] = r - l + 1;
	}
}

void shift(int ind, int l, int r, int id) {
  int mid = (l+r)/2;
  upd(ind, lazy[ind][id],  l,  mid, 2*id);
	upd(ind, lazy[ind][id], mid+1, r, 2*id+1);
	lazy[ind][id] = 0;
}

void build(int ind, int l = 0, int r = n-1, int id = 1) {
  if (l == r) {
    st[ind][id] = freq[ind][r];
    return;
  }
  int mid = (l+r)/2;
  build(ind,  l,  mid, 2*id);
  build(ind, mid+1, r, 2*id+1);
  st[ind][id] = fusion(st[ind][2*id], st[ind][2*id+1]);
}

void update(int ind, int a, int b, int val, int l = 0, int r = n-1, int id = 1) {
	if (b < l or r < a) return;
  if (a <= l and r <= b) {
    upd(ind, val, l, r, id);
    return;
  }
  shift(ind, l, r, id);
	int mid = (l+r)/2;
	update(ind, a, b, val,  l,  mid, 2*id);
	update(ind, a, b, val, mid+1, r, 2*id+1);
	st[ind][id] = fusion(st[ind][2*id], st[ind][2*id+1]);
}

int query(int ind, int a, int b, int l = 0, int r = n-1, int id = 1) {
  if (b < l or r < a) return NEUTRAL;
  if (a <= l and r <= b) return st[ind][id];
  shift(ind, l, r, id);
	int mid = (l+r)/2;
  int L = query(ind, a, b,  l,  mid, 2*id);
	int R = query(ind, a, b, mid+1, r, 2*id+1);
  return fusion(L, R);
}

int main() {
	scanf("%d %d", &n, &q);
	scanf("%s", s);
	for (int i = 0; i < n; ++i) {
		freq[s[i] - 'a'][i] = 1;
	}
	for (int i = 0; i < ALPH; ++i) {
		build(i);
	}
	for (int i = 0; i < q; ++i) {
		int l, r; scanf("%d %d", &l, &r);
		l--; r--;
		int cmd; scanf("%d", &cmd);
		if (cmd == 1) {
			int tot = 0;
			for (int j = 0; j < ALPH; ++j) {
				int cnt = query(j, l, r);
				if (cnt > 0) {
					if (l <= l + tot - 1) {
						update(j, l, l + tot - 1, 1);
					}
					update(j, l + tot, l + tot + cnt - 1, 2);
					if (l + tot + cnt <= r) {
						update(j, l + tot + cnt, r, 1);
					}
				}
				tot += cnt;
			}
		} else {
			int tot = 0;
			for (int j = ALPH - 1; j >= 0; --j) {
				int cnt = query(j, l, r);
				if (cnt > 0) {
					if (l <= l + tot - 1) {
						update(j, l, l + tot - 1, 1);
					}
					update(j, l + tot, l + tot + cnt - 1, 2);
					if (l + tot + cnt <= r) {
						update(j, l + tot + cnt, r, 1);
					}
				}
				tot += cnt;
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < ALPH; ++j) {
			if (query(j, i, i) == 1) {
				char c = 'a' + j;
				printf("%c", c);
				break;
			}
		}
	}
	printf("\n");
	return 0;
}
