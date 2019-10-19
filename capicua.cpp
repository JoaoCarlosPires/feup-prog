#include <iostream>

using namespace std;

char capicua(int n) 
{
	int c, d, u;
	c = n / 100;
	d = (n - 100 * c) / 10;
	u = n - c * 100 - d * 10;
	if (c == u)
		return 'Y';
	else
		return 0;
}

int main()
{
	int user_num;
	cout << "Qual o seu numero? ";
	cin >> user_num;
	if (capicua(user_num) != 0)
		cout << "O seu numero e uma capicua.";
	else
		cout << "O seu numero nao e uma capicua.";
	return 0;
}

