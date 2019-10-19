#include <iostream>
#include <sstream>

using namespace std;

bool readFracc(int &numerator, int &denominator)
{
	string user_num;
	cout << "What is your fraction number? ";
	getline(cin, user_num);
	istringstream user;
	user.str(user_num);
	int a, b;
	char c;
	user >> a >> c >> b;
	if (user.fail())
		return false;
	return true;

}

int main()
{
	int numerator, denominator;
	cout << readFracc(numerator, denominator);
	return 0;
}
