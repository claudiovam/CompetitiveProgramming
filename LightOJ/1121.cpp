/*  
 *  Problema clásico: 15-Puzzle Game
 *  @tags IDA*, DFS
 *  @idea
 *  - Para no obtener TLE, se analiza estado start si existe una solución.
 * 	- Heurísticas Admisibles: Distancia de Manhattan, Conflictos Lineales.
 * 	- Para no obtener TLE, en DFS se evita ciclos de 2 estados (volver a visitar el estado padre).
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int dr[] = {1, 0, 0, -1};
const int dc[] = {0, -1, 1, 0};
const char dir[] = {'D', 'L', 'R', 'U'}; // orden lexicográfico
const int oo = 35 + 1;
const int N = 4;
int puzzle[N][N];
int steps[oo];
int threshold;
int MOVES;
int n = N;

void showSteps(int n) {
	for (int i = 0; i < n; ++i) {
		printf("%c", dir[steps[i]]);
	} printf("\n");
}

bool isValid(int i, int n) {
	return 0 <= i and i < n;
}

int heuristic() {
	int ManhattanDist = 0;
	int linearConflicts = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (puzzle[i][j] == 0 or puzzle[i][j] == i*n + j + 1) continue;
			int num = puzzle[i][j] - 1;
			ManhattanDist += abs(num / n - i) + abs(num % n - j);
			if (i*n + j + 1 == puzzle[num / n][num % n] and (i == num / n or j == num % n)) {
				++linearConflicts;
			}
		}
	}
	return ManhattanDist + linearConflicts;
}

int DFS(int g, int r, int c, int prestep) {
	int h = heuristic();
	int f = g + h;
	if (f > threshold) return f;
	if (h == 0) return MOVES = g;
	int mn = oo;
	for (int i = 0; i < 4; ++i) {
		if (i + prestep == 3) continue;
		int nr = r + dr[i];
		int nc = c + dc[i];
		if (isValid(nr, n) and isValid(nc, n)) {
			swap(puzzle[r][c], puzzle[nr][nc]);
			steps[g] = i;
			int tmp = DFS(g + 1, nr, nc, i);
			if (tmp == MOVES) return MOVES;
			swap(puzzle[r][c], puzzle[nr][nc]);
			mn = min(mn, tmp);
		}
	}
	return mn;
}

int IDA_Star(int r, int c) {
	MOVES = -1;
	threshold = heuristic();
	while (1) {
		int tmp = DFS(0, r, c, -1);
		if (tmp == MOVES) return MOVES;
		if (tmp == oo) return oo;
		threshold = tmp;
	}
}

bool existSol(int r, int c) {
	int inv = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      for (int k = 0; k < i*n + j; ++k) {
			  if (puzzle[i][j] != 0 and puzzle[k / n][k % n] != 0 and puzzle[k / n][k % n] > puzzle[i][j]) {
			    ++inv;
      	}
      }
    }
  }
  int row = (r*n + c) / n;
  return (inv + row) & 1;
}

void solve() {
	int r, c;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf("%d", &puzzle[i][j]);
			if (puzzle[i][j] == 0) {
				r = i; c = j;
			}
		}
	}
	if (existSol(r, c) and IDA_Star(r, c) != oo) {
		showSteps(MOVES);
	} else {
		printf("This puzzle is not solvable.\n");
	}
}

int main() {
	int tc; scanf("%d", &tc);
	for (int c = 1; c <= tc; ++c)	{
		printf("Case %d: ", c);
		solve();
	}
  return 0;
}
