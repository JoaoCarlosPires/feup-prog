#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

int main()
{
	int ang, a;
	float pi = 3.141592;
	float min, max, intervalo;
	cout << "Qual o limite minimo? ";
	cin >> min;
	cout << "Qual o limite maximo? ";
	cin >> max;
	cout << "Qual o incremento? ";
	cin >> intervalo;
	cout << "\n";
	cout << "ang \t \t sen \t \t cos \t \t tan" << endl;

	for (float i = min; i <= max; i += intervalo)
	{
		float ang = (i * pi) / 180;
		if (i == 90)
		{
			cout << setprecision(6) << fixed << i << "\t" << setprecision(6) << fixed 
				<< sin(ang) << "\t" << setprecision(6) << fixed << cos(ang) << "\t infinito" << endl;
		}
		else
		{
			cout << setprecision(6) << fixed << i << "\t" << setprecision(6) << fixed 
				<< sin(ang) << "\t" << setprecision(6) << fixed << cos(ang) << "\t" << setprecision(6) 
				<< fixed << tan(ang) << endl;
		}
	}

	return 0;
}
