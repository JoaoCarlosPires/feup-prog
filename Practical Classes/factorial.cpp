#include <iostream>

using namespace std;

int factorial_rec(int n) {
	if (n == 1 || n == 0)
		return 1;
	else
		return n*factorial_rec(n - 1);
}


int main()
{
	int n;
	cout << "Qual o fatorial que pretende calcular? ";
	cin >> n;
	cout << n << "! = " << factorial_rec(n);
	return 0;
}
