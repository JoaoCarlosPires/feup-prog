#include <iostream>

using namespace std;

int main()
{
	double A, B, C, media, a_med, b_med, c_med;
	cout << "A ? ";
	cin >> A;
	cout << "B ? ";
	cin >> B;
	cout << "C ? ";
	cin >> C;
	
	media = (A + B + C) / 3;
	a_med = A - media;
	b_med = B - media;
	c_med = C - media;

	cout << "media = " << media << endl;
	cout << "A-media = " << a_med << endl;
	cout << "B-media = " << b_med << endl;
	cout << "C-media = " << c_med << endl;
	
	return 0;
}
