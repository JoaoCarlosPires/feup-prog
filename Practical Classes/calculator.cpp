#include <iostream>

using namespace std;

int main()
{
	double operand1, operand2, result;
	char operation;

	cin >> operand1 >> operation >> operand2;

	if (operation == '+')
		result = operand1 + operand2;
	else if (operation == '-')
		result = operand1 - operand2;
	else if (operation == '*')
		result = operand1 * operand2;
	else if (operation == '/')
		result = operand1 / operand2;

	cout << operand1 << ' ' << operation << ' ' << operand2 << " = " << result;

	return 0;
}
