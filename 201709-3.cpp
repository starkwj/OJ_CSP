#include <bits/stdc++.h>
using namespace std;

map<string, string> json;

void parse(string &name, string &value, bool &state)
{
	if (value.empty()) {
		return;
	}
	
	for (int i = 0; i < value.length(); i++)
	{
		if (value[i] == ' ') {
			continue;
		}
		
		if (value[i] == '{') {
			if (!name.empty()) {
				json[name] = "OBJECT";
				state = true;	// ɨ��� 
			}
		} else if (value[i] == '}') {
			// ����Ƕ�ף����ҵ����һ��'.'ɾȥ���沿�� 
			int k = name.rfind('.');
			if (k != string::npos) {
				name = name.substr(0, k);
			} else {
				name = "";
			}
		} else if (value[i] == ':') {
			state = false;	// ɨ��ֵ 
		} else if (value[i] == ',') {
			state = true;
		} else if (value[i] == '"') {
			string temp;
			for (i = i + 1; i < value.length(); i++)
			{
				if (value[i] == '\\') {
					temp += value[++i];
				} else if (value[i] == '"') {
					break;
				} else {
					temp += value[i];
				}
			}
			
			if (state) {
				// temp�Ǽ� 
				if (name == "") {
					name = temp;
				} else {
					name += '.' + temp;	// ���Ƕ�� 
				}
			} else {
				// temp��ֵ
				json[name] = "STRING " + temp;
				int k = name.rfind('.');
				if (k != string::npos) {
					name = name.substr(0, k);
				} else {
					name = "";
				}
			}
		}
	}
}


int main()
{
	int n, m;
	cin >> n >> m;
	cin.ignore();
	string name = "";
	bool state = true;
	for (int i  = 0; i < n; i++)
	{
		string val;
		getline(cin, val);
		
		parse(name, val, state);
	}
	
	for (int i = 0; i < m; i++)
	{
		string t;
		cin >> t;
		map<string, string>::iterator it;
		it = json.find(t);
		if (it == json.end()) {
			cout << "NOTEXIST" << endl;
		} else {
			cout << json[t] << endl;
		}
	}
	
	return 0;
}

