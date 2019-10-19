#include <iostream>

using namespace std;

int mdc(int m, int n) 
{
	if (m % n == 0)
		return n;
	return mdc(n, m % n);
}

int main()
{
	int user_num1, user_num2;
	cout << "What are your numbers? ";
	cin >> user_num1 >> user_num2;
	cout << mdc(user_num1, user_num2);
	return 0;
}
