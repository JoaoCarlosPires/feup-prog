#include <iostream>

using namespace std;

int main()
{
	double a, b, c;
	
	cout << "Qual o seu primeiro numero? ";
	cin >> a;
	
	cout << "Qual o seu segundo numero? ";
	cin >> b;
	
	cout << "Qual o seu terceiro numero? ";
	cin >> c;

	cout << "\n";

	if (a >= b) {
		if (a >= c) {
			cout << "O maior numero e o " << a << endl;
			if (b >= c) {
				cout << "O menor numero e o " << c << endl;
			}
			else {
				cout << "O menor numero e o " << b << endl;
			}
		}
		else {
			cout << "O maior numero e o " << c << endl;
			if (a >= b) {
				cout << "O menor numero e o " << b << endl;
			}
			else {
				cout << "O menor numero e o " << a << endl;
			}
		}
	}
	else {
		if (b >= c) {
			cout << "O maior numero e o " << b << endl;
			if (a >= c) {
				cout << "O menor numero e o " << c << endl;
			}
			else {
				cout << "O menor numero e o " << a << endl;
			}
		}
		else {
			cout << "O maior numero e o " << c << endl;
			if (a >= b) {
				cout << "O menor numero e o " << b << endl;
			}
			else {
				cout << "O menor numero e o " << a << endl;
			}
		}
	}
	
	return 0;
}
