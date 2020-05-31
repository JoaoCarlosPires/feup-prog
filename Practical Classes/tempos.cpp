#include <iostream>

using namespace std;

int main()
{
	int tmp1_h, tmp1_m, tmp1_s;
	int tmp2_h, tmp2_m, tmp2_s;
	int tmpf_d, tmpf_h, tmpf_m, tmpf_s;
	
	cout << "Tempo 1 (horas minutos segundos) ? ";
	cin >> tmp1_h >> tmp1_m >> tmp1_s;
	cout << "Tempo 2 (horas minutos segundos) ? ";
	cin >> tmp2_h >> tmp2_m >> tmp2_s;
	
	tmpf_s = tmp1_s + tmp2_s;
	tmpf_m = tmp1_m + tmp2_m;
	tmpf_h = tmp1_h + tmp2_h;
	tmpf_d = 0;

	if (tmpf_s >= 60)
		tmpf_m += 1;
		
	if (tmpf_m >= 60)
		tmpf_h += 1;

	if (tmpf_h >= 24)
	  tmpf_d += tmpf_h / 24;
	  tmpf_h -= tmpf_d * 24;

	cout << "Soma dos tempos : " << tmpf_d << " dia, " << tmpf_h << " horas, " << tmpf_m << " minutos e " << tmpf_s << " segundos";
	
	return 0;
}
