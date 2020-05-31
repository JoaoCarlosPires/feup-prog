#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	double M, p, r;
	const double pi=3.14;
	
	cin >> p >> r;

	M = (4/3)*(p * pi * pow(r, 3));
	
	cout << M;

	return 0;
