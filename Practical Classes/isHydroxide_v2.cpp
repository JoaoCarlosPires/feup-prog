#include <iostream>
#include <string.h>

using namespace std;

bool isHydroxide(string compound) 
{
	int size = compound.length();
	if (size < 2)
		return false;
	if (compound.at(size - 2) == 'O' && compound.at(size - 1) == 'H')
		return true;
	return false;
}

int main()
{
	string s;
	s = "KOH";
	cout << isHydroxide(s);
	// KOH, H2O2, NaCl, NaOH, C9H8O4 e MgOH
	return 0;
}

