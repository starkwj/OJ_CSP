#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	n /= 10;
	int i = n;
	i += (n / 5) * 2;
	if ((n % 5) > 2)
		i++;
	cout << i;
	return 0;
}
