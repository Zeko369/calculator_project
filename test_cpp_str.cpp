#include <iostream>

using namespace std;

string a;

int main()
{
	cin >> a;
	cout << a << " " << a.size() << endl;
	
	a[2] = 0;
	
	cout << a << " " << a.size() << endl;
	cout << "'" << a << "'" << endl;
	cout << a.length() << " " << a.size() << endl;
	
	return 0;
}
