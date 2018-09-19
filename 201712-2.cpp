#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	
	vector<int> vec;
	for (int i = 0; i < n; i++)
	{
		vec.push_back(i + 1);
	}
	int i = 1;
	vector<int>::iterator it = vec.begin();
	while (vec.size() > 1)
	{
		if (i % k == 0 || i % 10 == k) {
			it = vec.erase(it);
		}
		else {
			it++;
		}
		i++;
		if (it == vec.end()) {
			it = vec.begin();
		}
	}
	cout << *it << endl;
	return 0;
}

