/* zad 1 - Napisz program, który narysuje na ekranie choinkê z gwiazdek * o wysokoœci n. Wykorzystaj funkcjê
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
 */

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
		// n-1 staje siê "nowym n" dla kolejnej rekurencji, a¿ dotrze do tego, ¿e  ?

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


