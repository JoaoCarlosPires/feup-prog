#include <iostream>

using namespace std;

int main()
{
	char operation;
	double a, b;

	cout << "What is your first number? ";
	cin >> a;

	cout << "What is your second number? ";
	cin >> b;

	cout << "What is the opertation you want to perform with " << a << " and " << b << "? ";
	cin >> operation;

	if (operation == '*') {
		cout << "The result of the operation is " << a * b;
	}
	if (operation == '/') {
		cout << "The result of the operation is " << a / b;
	}
	if (operation == '+') {
		cout << "The result of the operation is " << a + b;
	}
	if (operation == '-') {
		cout << "The result of the operation is " << a - b;
	}
			
	return 0;
}
