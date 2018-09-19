#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef struct obj {
	int hp;
	int at;
} OBJ;

int main()
{
	const string sum = "summon";
	const string att = "attack";
	const string end = "end";
	int n;
	cin >> n;
	vector<OBJ> fir;
	vector<OBJ> sec;
	OBJ hero;
	hero.hp = 30;
	hero.at = 0;
	fir.push_back(hero);
	sec.push_back(hero);
	vector<OBJ> *vec = &fir;
	vector<OBJ> *ano = &sec;
	for (int i = 0; i < n; i++)
	{
		string order;
		cin >> order;
		if (order == sum)
		{
			int p, a, h;
			cin >> p >> a >> h;
			OBJ o;
			o.at = a;
			o.hp = h;
			vec->insert(vec->begin() + p, o);
		}
		else if (order == att)
		{
			int a, d;
			cin >> a >> d;
			(*vec)[a].hp -= (*ano)[d].at;
			(*ano)[d].hp -= (*vec)[a].at;
			if ((*vec)[a].hp <= 0)
			{
				if (a != 0)
					vec->erase(vec->begin() + a);
			}
			if ((*ano)[d].hp <= 0)
			{
				if (d != 0)
					ano->erase(ano->begin() + d);
			}
		}
		else if (order == end)
		{
			vector<OBJ> *temp = vec;
			vec = ano;
			ano = temp;
		}
	}
	
	if (fir[0].hp <= 0 && sec[0].hp > 0)
		cout << -1 << endl;
	else if (fir[0].hp > 0 && sec[0].hp <= 0)
		cout << 1 << endl;
	else
		cout << 0 << endl;
	
	cout << fir[0].hp << endl;
	cout << fir.size() - 1;
	for (vector<OBJ>::iterator it = fir.begin() + 1; it != fir.end(); it++)
	{
		cout << " " << it->hp;
	}
	cout << endl;
	cout << sec[0].hp << endl;
	cout << sec.size() - 1;
	for (vector<OBJ>::iterator it = sec.begin() + 1; it != sec.end(); it++)
	{
		cout << " " << it->hp;
	}
	cout << endl;
	
	return 0;
}
