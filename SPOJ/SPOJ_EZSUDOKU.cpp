/*  
 *  Variacion del problema clásico Sudoku
 *  @tags Complete Search: Backtracking
 *  
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int N = 8;
bool Fixed[N][N];
int uRow[N][1+N];
int uCol[N][1+N];
int uQuad[N/4][N/4][1+N];
int Board[N][N];
bool validBoard;
int cntSol;
int n = N;

void showSudoku() {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (j > 0) printf(" ");
			printf("%d", Board[i][j]);
		}	printf("\n");
	}
}

bool isValid(int num, int r, int c) {
	return uRow[r][num] == 0 and uCol[c][num] == 0 and uQuad[r/4][c/4][num] <= 1;
}

void solveSudoku(int r, int c) {
	if (cntSol == 1) return;
	if (r == n) {
		printf("YES\n");
		showSudoku();
		++cntSol;
		return;
	}
	if (c == n) {
		solveSudoku(r + 1, 0);
		return;
	}
	if (Fixed[r][c]) {
		solveSudoku(r, c + 1);
		return;
 	 }
	for (int num = 1; num <= n; ++num) {
		if (cntSol == 1) break;
		if (isValid(num, r, c)) {
			Board[r][c] = num;
			++uRow[r][num]; ++uCol[c][num]; ++uQuad[r/4][c/4][num];
			solveSudoku(r, c + 1);
			--uRow[r][num]; --uCol[c][num]; --uQuad[r/4][c/4][num];
		}
	}
}

void solve() {
	cntSol = 0;
	validBoard = true;
  	memset(Fixed, 0, sizeof Fixed);
  	memset(uRow,  0, sizeof uRow);
  	memset(uCol,  0, sizeof uCol);
  	memset(uQuad, 0, sizeof uQuad);
	for (int i = 0; i < n; ++i) {
    	for (int j = 0; j < n; ++j) {
			int num; scanf("%d", &num);
			Board[i][j] = num;
			if (Board[i][j] != 0) {
				if ((1 <= num and num <= n) and isValid(num, i, j)) {
					Fixed[i][j] = true;
					++uRow[i][num]; ++uCol[j][num]; ++uQuad[i/4][j/4][num];
				} else {
					validBoard = false;
				}
			}
    	}
  	}
	if (validBoard) {
		solveSudoku(0, 0);
		if (cntSol == 0) {
			printf("NO\n");
		}
	} else {
		printf("NO\n");
	}
}

int main() {
	int tc; scanf("%d", &tc);
	for (int c = 1; c <= tc; ++c)	{
		printf("Test case #%d: ", c);
		solve();
	}
	return 0;
}
