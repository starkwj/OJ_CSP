#include <iostream>
using namespace std;
int main()
{
	int year, d;
	cin >> year >> d;
	int a[12];
	a[0] = 31;
	a[1] = 28;
	a[2] = 31;
	a[3] = 30;
	a[4] = 31;
	a[5] = 30;
	a[6] = 31;
	a[7] = 31;
	a[8] = 30;
	a[9] = 31;
	a[10] = 30;
	a[11] = 31;
	if ((!(year % 4) && (year % 100)) || !(year % 400))
		a[1]++;
	int i = 0;
	while (d > a[i])
	{
		d -= a[i];
		i++;
	}
	i++;
	cout << i << endl << d << endl;
	return 0;
}
