// ten lab jest wyj¹tkowo bogaty w moje notatki dla samego siebie, które pewnie s¹ ma³o merytorycznie poprawne, bo pisane na bazie mojego rozumienia i pojedynczych konsultacji z czatem gpt xD


/* 
zad 1 - Napisz program, który narysuje na ekranie choinkê z gwiazdek * o wysokoœci n. Wykorzystaj funkcjê
rekurencyjn¹ do wypisywania linii.


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
		return 0; //warunek zakoñczenia rekurencji
	else {
		for (int j = 1; j <= n - i; j++) // spacje po lewej stronie ka¿dej linii choinki, j <= wysokoœæ-i
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
  

/* zad 2 - Napisz program, który obliczy sumê cyfr liczby naturalnej podanej przez u¿ytkownika. Zaimplementuj
dwie wersje funkcji: iteracyjn¹ i rekurencyjn¹.

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

int s_iteracyjna(int n) {
	int suma = 0;
	while (n > 0) {
		suma = suma + (n % 10); //n%10 daje ostatnia cyfre n
		n = n / 10; //usuwamy ostatnia cyfre n
	}
	return suma;
}


int s_rekurencyjna(int n) {
	int suma = 0;
	if (n == 0)
		return 0;
	else {
		suma = (n % 10) + s_rekurencyjna(n / 10);
		// n%10 daje ostatnia cyfre n , s_rekurencyjna(n/10) wywoluje funkcje dla n bez ostatniej cyfry
		return suma;
	}
}

 */

/* zad 3 -  Napisz program, który odwróci napis (string) podany przez u¿ytkownika. Wykorzystaj do tego funkcjê
rekurencyjn¹. 

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
		// zwraca funkcje wywolana dla napisu bez pierwszego znaku + pierwszy znak napisu na koñcu
	}
}
*/

/* zad 4 - Napisz program, który sprawdzi, czy dany napis jest palindromem (czytany od przodu i od ty³u jest
taki sam). Wykorzystaj funkcjê rekurencyjn¹.

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
		// zwraca funkcje wywolana dla napisu bez pierwszego znaku + pierwszy znak napisu na koñcu
	}
}

void porownaj(string str, string odwrocony) {
	if (str == odwrocony)
		cout << "Napis jest palindromem." << endl;
	else
		cout << "Napis nie jest palindromem." << endl;
}

 */

/* zad 5 - Napisz program, który znajdzie najwiêkszy element w tablicy liczb ca³kowitych (rozmiar i elementy
wprowadza u¿ytkownik). Zaimplementuj dwie wersje funkcji: iteracyjn¹ i rekurencyjn¹.
 

#include <iostream>
using namespace std;
int max_iteracyjna(int arr[], int n);	
int max_rekurencyjna(int arr[], int n);

int main() {
	int s;
	cout << "Podaj wielkosc tablicy: ";
	cin >> s;
	int* tab = new int[s];
	for (int i = 0; i < s; i++) {
		tab[i] = i;
	}

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
	if (n == 1) // jeœli jest tylko jeden element
		return arr[0]; 
	else {
		int max = max_rekurencyjna(arr, n - 1); // znajdz max z {n, n-1}
		// n-1 staje siê "nowym n" dla kolejnej rekurencji, a¿ dotrze do tego, ¿e n==1 - to ostatnie powtórzenie zwaraca wartoœæ z arr[0], która jest wtedy przypisana do max
		// i jak po schodach wykonuje siê "if" poni¿ej dla rosn¹cych n: arr[1]>max?, arr[2]>max_z_poprzedniej_rekurencji? itd.

		if (arr[n - 1] > max) { //jeœli pierwszy element (tab[0]) jest wiêkszy od maxa
			return arr[n - 1];
		}
		else {
			return max;
		}
		// mo¿na te¿ skróciæ do jednej linijki:
		// return (arr[n - 1] > max) ? arr[n - 1] : m; // (condition) ? value_if_true : value_if_false
	}
}
*/

/* zad 6 - Napisz program, który obliczy n-t¹ liczbê ci¹gu Fibonacciego (zaimplementuj dwie funkcje: iteracyjn¹
i rekurencyjn¹). Program prosi u¿ytkownika o podanie wartoœci liczby n, gdzie n mo¿e byæ dowoln¹ liczb¹
naturaln¹.


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
		return b; // równowa¿ne z return c
	}
}

int fib_rec(int n) {
	if (n == 0)
		return 0; //przypadek F(0)
	else if (n == 1)
		return 1; //przypadek F(1)
	else {
		return fib_rec(n - 1) + fib_rec(n - 2); // ka¿da liczba to suma dwóch poprzednich, wiêc liczba n to suma liczb (n-1) i (n-2)
	}
}

*/


/* zad 7 - Napisz program, który obliczy potêgê zadanej liczby, zarówno podstawa jak i wyk³adnik powinny byæ
liczbami naturalnymi okreœlonymi przez u¿ytkownika (zaimplementuj dwie funkcje: iteracyjn¹ i rekurencyjn¹). 

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
		return 1; // ka¿da liczba do potêgi 0 to 1, warunek zakoñczenia rekurencji
	else {
		return b * power_rec(b, e - 1); 
	}
}

*/

/* zad 8 - Napisz program, który obliczy silniê liczby naturalnej n. Program prosi u¿ytkownika o podanie wartoœci
liczby n (zaimplementuj dwie funkcje: iteracyjn¹ i rekurencyjn¹). 

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
		return 1; // 0! i 1! daj¹ 1, warunek zakoñczenia rekurencji
	else {
		return n * factorial_rec(n - 1); // n! = n * (n-1)!
	}
}

*/

/* zad 9 - Napisz program, który obliczy sumê wszystkich liczb naturalnych od 1 do n. Program prosi u¿ytkownika
o podanie wartoœci n. Zaimplementuj dwie wersje funkcji: iteracyjn¹ i rekurencyjn¹. 
*/