// ten lab jest wyjątkowo bogaty w moje notatki dla samego siebie, które pewnie są mało merytorycznie poprawne, bo pisane na bazie mojego rozumienia i pojedynczych konsultacji z czatem gpt xD


/* 
zad 1 - Napisz program, który narysuje na ekranie choinkę z gwiazdek * o wysokości n. Wykorzystaj funkcję
rekurencyjną do wypisywania linii.


#include <iostream>
using namespace std;
int choinka(int n, int i);

int main() {
	int n, i = 1;
	cout << "Podaj wysokosc choinki: ";
	cin >> n;
	choinka(n,i);
	return 0;
}

int choinka(int n, int i) {
	if (i > n)
		return 0; //warunek zakończenia rekurencji
	else {
		for (int j = 1; j <= n - i; j++) // spacje po lewej stronie każdej linii choinki, j <= wysokość-i
			//np dla n=3: i=1 -> 2 spacje, i=2 -> 1 spacja, i=3 -> 0 spacji
			cout << " ";
		for (int k = 1; k <= (2 * i - 1); k++) // liczba gwiazdek w danej linii = 2*i-1
			//np dla n=3: i=1 -> 1 gwiazdka, i=2 -> 3 gwiazdki, i=3 -> 5 gwiazdek
			cout << "*";
		cout << endl;
		choinka(n, i + 1);
		return 0;
	}
}
*/
  

/* zad 2 - Napisz program, który obliczy sumę cyfr liczby naturalnej podanej przez użytkownika. Zaimplementuj
dwie wersje funkcji: iteracyjną i rekurencyjną. 

#include <iostream>
using namespace std;
int s_iteracyjna(int n);
int s_rekurencyjna(int n);

int main() {
		int n;
	cout << "Podaj liczbe naturalna: ";
	cin >> n;
	// cout << "Suma cyfr (iteracyjnie): " << s_iteracyjna(n) << endl;
	cout << "Suma cyfr (rekurencyjnie): " << s_rekurencyjna(n) << endl;
	return 0;
}

int s_rekurencyjna(int n) {
	int suma = 0;
	if (n == 0)
		return 0;
	else {
		suma = (n % 10) + s_rekurencyjna(n / 10);
		// n%10 daje ostatnia cyfre n , s_rekurencyjna(n/10) wywoluje funkcje dla n bez ostatniej cyfry
		// typ int, więc liczby od 1-9 podzielone na 10 dają n=0
		return suma;
	}
}

int s_iteracyjna(int n) {
	int suma = 0;
	while (n > 0) { 
		suma = suma + (n % 10); //n%10 daje ostatnia cyfre n
		n = n / 10; //usuwamy ostatnia cyfre n
	}
	return suma;
}

 */




/* zad 3 -  Napisz program, który odwróci napis (string) podany przez użytkownika. Wykorzystaj do tego funkcję
rekurencyjną. 

#include <iostream>
#include <string>
using namespace std;

string odwroc(string str);

int main() {
	string str;
	cout << "Podaj napis: ";
	getline(cin, str);
	cout << "Napis odwrocony: " << odwroc(str) << endl;
	return 0;
}

string odwroc(string str) {
	if (str.length() == 0) {
		return "";
	}
	else {
		return odwroc(str.substr(1)) + str[0];
		// zwraca funkcje wywolana dla napisu bez pierwszego znaku + pierwszy znak napisu na końcu
	}
}
*/


/* zad 4 - Napisz program, który sprawdzi, czy dany napis jest palindromem (czytany od przodu i od tyłu jest
taki sam). Wykorzystaj funkcję rekurencyjną.

#include <iostream>
#include <string>
using namespace std;

string odwroc(string str);
void porownaj(string str, string odwrocony);

int main() {
	string str;
	cout << "Podaj napis: ";
	getline(cin, str);
	cout << "Napis odwrocony: " << odwroc(str) << endl;
	porownaj(str, odwroc(str));
	return 0;
}

string odwroc(string str) {
	if (str.length() == 0) {
		return "";
	}
	else {
		return odwroc(str.substr(1)) + str[0];
		// zwraca funkcje wywolana dla napisu bez pierwszego znaku + pierwszy znak napisu na końcu
	}
}

void porownaj(string str, string odwrocony) {
	if (str == odwrocony)
		cout << "Napis jest palindromem." << endl;
	else
		cout << "Napis nie jest palindromem." << endl;
}

 */

/* zad 5 - Napisz program, który znajdzie największy element w tablicy liczb całkowitych (rozmiar i elementy
wprowadza użytkownik). Zaimplementuj dwie wersje funkcji: iteracyjną i rekurencyjną. 
 

#include <iostream>
using namespace std;
int max_iteracyjna(int arr[], int n);	
int max_rekurencyjna(int arr[], int n);

int main() {
	int s; //size
	cout << "Podaj wielkosc tablicy: ";
	cin >> s;
	int* tab = new int[s];
	for (int i = 0; i < s; i++) {
		tab[i] = i;
	}
	//^tablica dynamiczna, rozmiar podany przez użytkownika

	for (int i = 0; i < s; i++) {
		cout << "Podaj " << i+1 << " element tablicy: ";
			cin >> tab[i];
	}

	cout << "Wprowadzona tablica: "; 
	for (int i = 0; i < s; i++)
		cout << tab[i] << " ";
	cout << endl;

	// cout << "Najwiekszy element (iteracyjnie): " << max_iteracyjna(tab, s) << endl;
	cout << "Najwiekszy element (rekurencyjnie): " << max_rekurencyjna(tab, s) << endl;

}

int max_iteracyjna(int arr[], int n) {
	int max = arr[0];
	for (int i = 1; i < n; i++) {
		if (arr[i] > max)
			max = arr[i];
	}
	return max;
}

int max_rekurencyjna(int arr[], int n) {
	if (n == 1) // jeśli jest tylko jeden element
		return arr[0]; 
	else {
		int max = max_rekurencyjna(arr, n - 1); 
		// n-1 staje się "nowym n" dla kolejnej rekurencji, maleje aż dotrze do tego, że n==1 
		// to ostatnie powtórzenie zwaraca wartość z arr[0], która jest wtedy przypisana do max
		// i jak po schodach wykonuje się "if" poniżej dla rosnących n: 
		// arr[1]>max?, arr[2]>max_z_poprzedniej_rekurencji? itd.

		if (arr[n - 1] > max) { //jeśli pierwszy element (tab[0]) jest większy od maxa
			return arr[n - 1];
		}
		else {
			return max;
		}
		// można też skrócić do jednej linijki:
		// return (arr[n - 1] > max) ? arr[n - 1] : m; // (condition) ? value_if_true : value_if_false
	}
}

*/


/* zad 6 - Napisz program, który obliczy n-tą liczbę ciągu Fibonacciego (zaimplementuj dwie funkcje: iteracyjną
i rekurencyjną). Program prosi użytkownika o podanie wartości liczby n, gdzie n może być dowolną liczbą
naturalną.


#include <iostream>
using namespace std;
int fib_it(int n);
int fib_rec(int n);

int main() {
	int n;
	cout << "Enter a natural number (n) to find the n-th number of the Fibonacci sequence: ";
	cin >> n;
	//cout << "The " << n << "-th Fibonacci number is " << fib_it(n) << endl;
	cout << "The " << n << "-th Fibonacci number is " << fib_rec(n) << endl;
}

int fib_it(int n) {
	if (n == 1)
		return 1;
	else {
		int a = 0;
		int b = 1;
		int c;
		for (int i = 2; i <= n; i++) {
			c = a + b;
			a = b;
			b = c;
		}
		return b; // równoważne z return c
	}
}

int fib_rec(int n) {
	if (n == 0)
		return 0; //przypadek F(0)
	else if (n == 1)
		return 1; //przypadek F(1)
	else {
		return fib_rec(n - 1) + fib_rec(n - 2); // każda liczba to suma dwóch poprzednich, więc liczba n to suma liczb (n-1) i (n-2)
	}
}

*/


/* zad 7 - Napisz program, który obliczy potęgę zadanej liczby, zarówno podstawa jak i wykładnik powinny być
liczbami naturalnymi określonymi przez użytkownika (zaimplementuj dwie funkcje: iteracyjną i rekurencyjną). 

#include <iostream>
using namespace std;
int power_it(int b, int e);
int power_rec(int b, int e);

int main() {
	int base, exp;

	cout << "Enter a natural number: ";
	cin >> base;
	cout << "Enter the exponent: ";
	cin >> exp;

	//cout << base << " to the power of " << exp << " equals " << power_it(base,exp);
	cout << base << " to the power of " << exp << " equals " << power_rec(base, exp);
}

int power_it(int b, int e) {
	if (e==0)
		return 1;
	else {
		int result = 1;
		for (int i = 1; i <= e; i++) { // petla powtarza sie e razy
			result = result * b; // 1*b, b*b, b*b*b...
		}
		return result;
	}
}

int power_rec(int b, int e) {
	if (e == 0)
		return 1; // każda liczba do potęgi 0 to 1, warunek zakończenia rekurencji
	else {
		return b * power_rec(b, e - 1); 
	}
}

*/

/* zad 8 - Napisz program, który obliczy silnię liczby naturalnej n. Program prosi użytkownika o podanie wartości
liczby n (zaimplementuj dwie funkcje: iteracyjną i rekurencyjną). 

#include <iostream>
using namespace std;
int factorial_it(int n);
int factorial_rec(int n);
int main() {
	int n;
	cout << "Enter a natural number to calculate its factorial: ";
	cin >> n;
	//cout << "Factorial of " << n << " is " << factorial_it(n) << endl;
	cout << "Factorial of " << n << " is " << factorial_rec(n) << endl;
}

int factorial_it(int n) {
	for (int i = n - 1; i >= 1; i--) {
		n = n * i;
	}
	return n;
}

int factorial_rec(int n) {
	if (n == 0 || n == 1) // || to OR logiczny
		return 1; // 0! i 1! dają 1, warunek zakończenia rekurencji
	else {
		return n * factorial_rec(n - 1); // n! = n * (n-1)!
	}
}

*/

/* zad 9 - Napisz program, który obliczy sumę wszystkich liczb naturalnych od 1 do n. Program prosi użytkownika
o podanie wartości n. Zaimplementuj dwie wersje funkcji: iteracyjną i rekurencyjną. 


#include <iostream>
using namespace std;
int sum_it(int n);
int sum_rec(int n);
int main() {
	int n;
	cout << "Enter a natural number (n) tp calculate the sum of all natural numbers from 1 to n: ";
	cin >> n;
	//cout << "The sum of all natural numbers from 1 to " << n << " is " << sum_it(n) << endl;
	cout << "The sum of all natural numbers from 1 to " << n << " is " << sum_rec(n) << endl;
}

int sum_it(int n) {
	int suma = 0;
	for (int i =1; i <= n; i++) {
		suma = suma + i;
	}
	return suma;
}


int sum_rec(int n) {
	if(n == 0) {
		return 0;
	}
	else {
		return n + sum_rec(n - 1); // suma od 1 do n to n + suma od 1 do (n-1)
	}
}

*/

/* zad 10 - Napisz program, który obliczy największy wspólny dzielnik (NWD) dwóch liczb całkowitych dodatnich
(> 0). Program prosi użytkownika o podanie wartości tych liczb (zaimplementuj dwie funkcje: iteracyjną i
rekurencyjną).

#include <iostream>
using namespace std;
int gcd_it(int a, int b);
int gcd_rec(int a, int b);

int main() {
	int a, b;
	cout << "Enter two positive integers to calculate their greatest common divisor (GCD): ";
	cin >> a >> b;
	// cout << "The GCD of " << a << " and " << b << " is " << gcd_it(a, b) << endl;
	cout << "The GCD of " << a << " and " << b << " is " << gcd_rec(a, b) << endl;
}


//funkcje wykorzystują algorytm Euklidesa z wykorzystaniem modulo
// Wikipedia: 
// 1) oblicz c jako resztę z dzielenia a przez b
// 2) zastąp a liczbą b, następnie b liczbą c
// 3) jeżeli wartość b wynosi 0, to a jest szukaną wartością NWD, w przeciwnym wypadku przejdź do kroku 1


int gcd_it(int a, int b) {
	int c = a % b;
	while (c != 0) { 
		a=b; 
		b = c; 
		c = a % b;
	}
	return b;
}

int gcd_rec(int a, int b) {
	if (b == 0)
		return a;
	else
		return gcd_rec(b, a % b);
}

// np dla a=99, b=81

// 1) gcd_rec(99, 81)
//    b != 0 (b = 81)
//    99 % 81 = 18
//    > wywołanie gcd_rec(81, 18)

// 2) gcd_rec(81, 18)
//    b != 0 (b = 18)
//    81 % 18 = 9
//    > wywołanie gcd_rec(18, 9)

// 3) gcd_rec(18, 9)
//    b != 0 (b = 9)
//    18 % 9 = 0
//    > wywołanie gcd_rec(9, 0)

// 4) gcd_rec(9, 0)
//    b == 0 > zwróć a = 9

 */

/* zad 11 - Wykorzystaj kod z zadania 4 (??????) i przerób go tak aby obliczał najmniejszą wspólną wielokrotność (NWW)
dwóch liczb całkowitych dodatnich (> 0). Program prosi użytkownika o podanie wartości tych liczb (zaimplementuj
dwie funkcje: iteracyjną i rekurencyjną). 


#include <iostream>
using namespace std;
int lcm_it(int a, int b);
int lcm_rec(int a, int b);

int main() {
	int a, b;
	cout << "Enter two positive integers to calculate their least common multiple (LCM): ";
	cin >> a >> b;
	cout << "The LCM of " << a << " and " << b << " is " << lcm_it(a, b) << endl;
	cout << "The LCM of " << a << " and " << b << " is " << lcm_rec(a, b) << endl;
}

// NWW(a, b) = (a * b) / NWD(a, b)


int lcm_it(int a, int b) {
	int ab = a * b;
	int c = a % b;
	while (c != 0) {
		a = b;
		b = c;
		c = a % b;
	}
	int gcd = b; // po zakończeniu pętli b to NWD(a,b)
	return ab / gcd;
}

int gcd_rec(int a, int b) {
	if (b == 0)
		return a;
	return gcd_rec(b, a % b);
}

int lcm_rec(int a, int b) {
	int gcd = gcd_rec(a, b);
	return (a * b) / gcd;
}

*/

/* zad 12 - Wykorzystaj poniższy kod, aby sprawdzić czas działania dla funkcji iteracyjnej i rekurencyjnej z zadań
1-3. Przetestuj odpowiednio duże wartości aby zauważyć różnicę w czasie, która z funkcji działa szybciej? 

#include <iostream> 
#include <stdlib.h>
#include <time.h>
using namespace std;

int main() { //kod 07_03
	double czas;
	clock_t start, koniec;

	start = clock(); //rozpoczecie odliczania czasu

	for (int i = 0; i < 10000; i++)
		cout << i << " ";

	koniec = clock();  //zakonczenie odliczania czasu
	czas = (double)(koniec - start) / CLOCKS_PER_SEC; //zwrocenie czasu dzialania
	cout << endl << endl << "Czas dzialania = " << czas << endl;

	return 0;
}


*/