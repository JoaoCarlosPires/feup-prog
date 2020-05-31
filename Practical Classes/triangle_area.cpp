#include <iostream>
#include <cmath>

using namespace std;

double my_distance(double x1, double y1, double x2, double y2)
{
	return sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
}

double area(double x1, double y1, double x2, double y2, double x3, double y3)
{
	double a, b, c, s, result;
	a = my_distance(x1, y1, x2, y2);
	b = my_distance(x1, y1, x3, y3);
	c = my_distance(x2, y2, x3, y3);
	s = a + b + c;
	result = sqrt(s*(s - a)*(s - b)*(s - c));
	return result;
}

int main()
{
	double x1, y1, x2, y2, x3, y3;
	cout << "First dot? ";
	cin >> x1 >> y1;
	cout << "Second dot? ";
	cin >> x2 >> y2;
	cout << "Third dot? ";
	cin >> x3 >> y3;
	cout << "The area of your triangle is " << area(x1, y1, x2, y2, x3, y3);
	return 0;
}
