/*  
 *  @tags brute force with pruning
 *  @idea 
 * 		- Se plantea la inecuación: s1*x + s2*y <= n, debemos hallar: M = max(v1*x + v2*y).
 * 		- Si n/s2 es grande, recorremos todos los posibles 'y' (0, 1, ..., n/s2) y con ello hallamos M, nos daría TLE.
 * 		Necesitamos reducir el espacio de búsqueda de 'y'.
 * 		- La inecuación es equivalente a la ecuación: s1*x + s2*y + rem = n, donde rem >= 0 y rem es mínimo.
 * 		- Supongamos sin pérdida de generalidad que s1 <= s2.
 * 		- Como rem debe ser mínimo => rem es un residuo de n mod s1, es decir, rem está en el rango: [0, s1-1].
 * 		- Dado un rem especifico y recorremos en orden sus posibles 'y' que cumpla la ecuación => sus valores (v1*x + v2*y) estarían en algún orden.
 * 		- Entonces M sería uno de los extremos de dicho orden resultante y 'y' sería uno de los extremos de los 'y' recorridos.
 * 		- Por otra parte, si recorremos todos los posibles 'y' (0, 1, ..., n/s2) en ese orden, cada rem obtenido se repite cada s1 nros.
 *  	- Entonces solo hay que recorrer s1 nros 'y' en cada extremo de 0, 1, ..., n/s2.
 * 		- Sin embargo, s1 puede ser grande que nos daría TLE, pero como s1 <= s2 => s2 es grande y el máximo 'y' = n/s2 seria pequeño.
 * 		- Por lo tanto, se recorre min(s1, n/s2 + 1) <= sqrt(INT_MAX) nros 'y' en cada extremo de 0, 1, ..., n/s2.
 *  
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

ll n;
ll s1, v1;
ll s2, v2;

void solve() {
	scanf("%lld", &n);
	scanf("%lld %lld", &s1, &v1);
	scanf("%lld %lld", &s2, &v2);
	if (s1 > s2) {
		swap(s1, s2);
		swap(v1, v2);
	}
	ll mx = 0;
	ll sz = min(s1, n/s2 + 1);
	ll y = 0;
	for (int i = 0; i < sz; ++i) {
		ll x = (n - s2*y) / s1;
		mx = max(mx, v1*x + v2*y);
		++y;
	}
	y = n/s2;
	for (int i = 0; i < sz; ++i) {
		ll x = (n - s2*y) / s1;
		mx = max(mx, v1*x + v2*y);
		--y;
	}
	printf("%lld\n", mx);
}

int main() {
	int tc; cin >> tc;
	for (int c = 1; c <= tc; ++c)	{
		printf("Case #%d: ", c);
		solve();
	}
	return 0;
}
