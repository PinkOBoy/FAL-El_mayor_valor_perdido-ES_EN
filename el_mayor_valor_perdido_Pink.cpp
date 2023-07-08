/*
* USUARIO DEL JUEZ: G04
* NOMBRE Y APELLIDOS: JAIME BENEDI GALDEANO
*/
#include <iostream>
#include <vector>
using namespace std;

//--ENGLISH--------------------------------------------------------------------------
/**RECURRENCE EQUATIONS
* For every call, the size of the problem gets halved,
* that is, in each call does some calculations (O(1)) on a number
* of one digit lesser than the previous call.
*
* Defining:
*
*   n::= number of elements of the visible subvector from v.
*
* We know, thanks to the Generalitation techniques for recursive
* algorithms, that, in case the problem gets reduced in a specific
* amount of data (a constant is subtracted from thesize of the problem
* in each call), its recurrence equations will be:
* 
*        | c0                       0 <= n <= n0
*   T(n)=|
*        | a * T(n / b) + c1 * n^k  n >= n0
*
* Where:
*
*   a::= number of recursive calls inside of the algorithm.
*   b::= subtrahend
*   k::= a number so n^k represents the complexity of the non-recursive code
*        of our algorithm.
*
* Therefore, we can affirm that the recurrence equations of our algorithm are:
* 
*          | c0                         n = 1
*    T(n)= |
*          | 1 * T(n / 2) + c1 * n^0    n > 1
*/
/** COMPLEXITY OF THE ALGORITHM
 * Thanks to the previosly defined information and to the Generalitation
 * techniques for recursive algorithms, we know that, when the recurrence
 * equations look like:
 * 
 *        | c0                       0 <= n <= n0
 *   T(n)=|
 *        | a * T(n / b) + c1 * n^k  n >= n0
 *
 * The following assumptions are correct:
 * 
 *  a < b^k -> T(n) belongs to O(n ^ k)
 *  a = b^k -> T(n) belongs to O(n^k * ln(n))
 *  a > b^k -> T(n) belongs to O(n ^ logb(a))
 * 
 * Applying it to our recurrence equations:
 * 
 *  1 = 2^0
 * 
 * Therefore, T(n) belongs to O(n^0 * ln(n)) = O(ln(n)).
*/

//--SPANISH----------------------------------------------------------------------------------
/*ECUACIONES DE RECURRENCIA:
* Observamos que nuestro problema coge el tamaño original
* del problema y lo va reduciendo en subproblemas mas pe
* queños de menor tamaño.
* 
* Dada la generalizacion de las ecuaciones de recurrencia
* de algoritmos recursivos y el estudio de su coste, sabemos
* que la ecuacion de recurrencia de un algoritmo recursivo
* donde se reduce el tamaño del problema, es:
* 
*		| c0						0 <= n <= n0
*	T(n)|
*		| a * T(n / b) + c1 * n^k	n0 <= n
* 
* Donde:
*	n ::= el tamaño del problema en la llamada actual
*	a ::= numero de llamadas recursivas dentro del algoritmo
*	b ::= elementos quitados del tamaño del problema
*	k ::= numero tal que n^k representa la complejidad del codigo no recursivo del algoritmo
* 
* Aplicandolo a nuestro caso particular, si definimos:
* 
*	n::= tamaño del vector visible en la llamada actual
* 
* Concluimos que la ecuacion de recurrencia es:
* 
*		| c0					  n = 1
*	T(n)|
*		| 1 * T(n / 2) + c1 * n^0 n > 1
*/
/*COMPLEJIDAD DEL ALGORITMO:
* Dada la generalizacion de las ecuaciones de recurrencia de
* algoritmos recursivos y el estudio de coste, sabemos que
* bajo las condiciones del problema, y con los datos anteriores,
* la complejidad del algoritmo seguira la siguiente regla:
* 
*	a < b^k -> T(n) pertenece a O(n ^ k)
*	a = b^k -> T(n) pertenece a 0(n^k * ln(n))
*	a > b^k -> T(n) pertenece a O(n ^ logb(a))
* 
* Efectivamente, en nuestro caso 1 = 2^0 = 1, por lo tanto:
* 
*	T(n) pertenece a O(n^0 ln(n)) = O(ln(n))
*/
int maxLostVal(
	const vector<int>& v,
	int a,
	int b
) {
	if (a + 1 == b)
		return v[b] - 1;
	else {
		int m = (a + b) / 2;

		if (v[b] - v[m] > b - m)
			return maxLostVal(v, m + 1, b);
		else 
			return maxLostVal(v, a, m);
	}
}

bool solve() {
	int n, q;
	cin >> n >> q;

	if ((n == 0 && q == 0) || n < 2)
		return false;

	vector<int> v(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i];

	int a, b;
	for (int i = 0; i < q; ++i){
		cin >> a >> b;
		cout << maxLostVal(v, a, b) << endl;
	}
	return true;
}

int main() {
	while (solve());
	return 0;
}