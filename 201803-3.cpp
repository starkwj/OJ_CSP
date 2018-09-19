#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	string numbers = "0123456789";
	
	int n, m;
	cin >> n >> m;
	string rules[n], rname[n];
	for (int i = 0; i < n; i++) {
		cin >> rules[i] >> rname[i];
	}
	
	
	while (m--)
	{
		string url;
		cin >> url;
		
		int i;
		for (i = 0; i < n; i++)
		{
			int p1 = 0, q1 = 0, p2 = 0, q2 = 0;
			vector<string> res;
			
			while ((p1 = q1 + 1) < rules[i].length())
			{	
				if ((p2 = q2 + 1) < url.length())
				{
					// q1 = pos of '/' or length
					q1 = rules[i].find('/', p1);
					if (q1 == string::npos) {
						q1 = rules[i].length();
					}
					string currule = rules[i].substr(p1, q1 - p1);
					if (currule == "<path>") {
						res.push_back(url.substr(p2));
						q2 = url.length();
						p1 = rules[i].length();
						break;
					}
					else {
						q2 = url.find('/', p2);
						if (q2 == string::npos) {
							if (q1 != rules[i].length()) {
								break;
							} else {
								q2 = url.length();
							}
						} else if (q1 == rules[i].length()) {
							break;
						}
						
						string cururl = url.substr(p2, q2 - p2);
						
						if (currule == "<int>") {
							if (cururl.find_first_not_of(numbers) == string::npos) {
								int nzpos = cururl.find_first_not_of("0");
								res.push_back(cururl.substr(nzpos));
							} else {
								break;
							}
						} else if (currule == "<str>") {
							res.push_back(cururl);
						} else {
							if (currule != cururl) {
								break;
							}
						}
					}				
				}
				else {
					break;
				}
			}
			if (p1 >= rules[i].length() && (q2 + 1) >= url.length()) {
				cout << rname[i];
				for (int k = 0; k < res.size(); k++) {
					cout << " " << res[k];
				}
				cout << endl;
				break;
			}
		}
		if (i == n) {
			cout << "404" << endl;
		}
	}
	return 0;
}

