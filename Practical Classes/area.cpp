#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	int x1, y1, x2, y2, x3, y3;
	double a, b, c, s, result;

	cout << "First Dot ? ";
	cin >> x1 >> y1;
	cout << "Second Dot ? ";
	cin >> x2 >> y2;
	cout << "Third Dot ? ";
	cin >> x3 >> y3;

	a = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
	b = sqrt(pow((x1 - x3), 2) + pow((y1 - y3), 2));
	c = sqrt(pow((x2 - x3), 2) + pow((y2 - y3), 2));
	s = a + b + c;

	result = sqrt(s*(s - a)*(s - b)*(s - c));

	cout << endl << "The area is " << result;

	return 0;
}
