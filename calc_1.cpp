#include <iostream>

using namespace std;

int main()
{
	double a, b, c, d, e, f, x, y;
	cout << "A = ? ";
	cin >> a;
	cout << "B = ? ";
	cin >> b;
	cout << "C = ? ";
	cin >> c;
	cout << "D = ? ";
	cin >> d;
	cout << "E = ? ";
	cin >> e;
	cout << "F = ? ";
	cin >> f;

	x = (c*e - b*f) / (a*e - b*d);
	y = (a*f - c*d) / (a*e - b*d);
	
	cout << endl << "x = " << x << endl;
	cout << "y = " << y;
	
	return 0;
}
