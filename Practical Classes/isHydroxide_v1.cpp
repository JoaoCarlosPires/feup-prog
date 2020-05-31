#include <iostream>
#include <string.h>

using namespace std;

bool isHydroxide(char compound[]) 
{
	int size;
	size = sizeof(compound) / sizeof(compound[0]);
	if (size < 2)
		return false;
	if (compound[size - 3] == 'O' && compound[size - 2] == 'H')
		return true;
	return false;
}

int main()
{
	char s[30];
	cin >> s;
	cout << isHydroxide(s);
	// KOH, H2O2, NaCl, NaOH, C9H8O4 e MgOH
	return 0;
}
