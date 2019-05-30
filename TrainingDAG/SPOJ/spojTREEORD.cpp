#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = (8e3) + 5;
int preorder[N], postorder[N], inorder[N];
int n;

bool isSameTree(int l_pre, int r_pre, int l_in, int r_in, int l_post, int r_post) {
  if (r_pre - l_pre + 1 == 0 and r_in - l_in + 1 == 0 and r_post - l_post + 1 == 0) return 1;
  if (preorder[l_pre] != postorder[r_post]) return 0;
  for (int i = l_in; i <= r_in; ++i) {
    if (inorder[i] == preorder[l_pre]) {
      int len = i - l_in;
      bool isSameSubtreeL = isSameTree(l_pre + 1, l_pre + len, l_in, i - 1, l_post, l_post + len - 1);
      bool isSameSubtreeR = isSameTree(l_pre + len + 1, r_pre, i + 1, r_in, l_post + len, r_post - 1);
      return isSameSubtreeL and isSameSubtreeR;
    }
  }
  return 0;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &preorder[i]);
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &postorder[i]);
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &inorder[i]);
  }
  printf(isSameTree(0, n - 1, 0, n - 1, 0, n - 1)? "yes" : "no");
  printf("\n");
  return 0;
}
