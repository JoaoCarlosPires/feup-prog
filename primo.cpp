#include <iostream>

using namespace std;

char isPrime(int n) {
	int divider = 0, i;
	if (n == 0 || n == 1)
		return 'Y';
	for (i = 1; i <= n; i++) {
		if (n % i == 0)
			divider += 1;
	}
	if (divider == 2)
		return 'Y';
	else
		return 'N';
}

int main()
{
	int user_num;
	cout << "Qual o seu numero? ";
	cin >> user_num;
	if (isPrime(user_num) == 'Y')
		cout << "O seu numero e primo.";
	else
		cout << "O seu numero nao e primo.";

	return 0;
}
