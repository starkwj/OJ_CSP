#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <algorithm>

using namespace std;

typedef struct {
	int year;
	int month;
	int day;
	int hour;
	int minute;
	int weekday;
} TIME;

bool isLeapYear(int year) {
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
		return true;
	} else {
		return false;
	}
}

string Month[13] = {
	"", "jan", "feb", "mar", "apr", "may", "jun", "jul", "aug", "sep", "oct", "nov", "dec"
};
string WeekDay[7] = {
	"sun", "mon", "tue", "wed", "thu", "fri", "sat"
};

int monthToNum(string & s) {
	for (int i = 0; i < s.length(); i++) {
		s[i] = tolower(s[i]);
	}
	int i = 1;
	for (; i < 13; i++) {
		if (s == Month[i]) {
			return i;
		}
	}
	return 0;
}

int weekdayToNum(string & s) {
	for (int i = 0; i < s.length(); i++) {
		s[i] = tolower(s[i]);
	}
	int i = 0;
	for (; i < 7; i++) {
		if (s == WeekDay[i]) {
			break;
		}
	}
	return i;
}

int strToInt(const string &s) {
	stringstream ss(s);
	int res;
	ss >> res;
	return res;
}

string to_string(int n) {
	stringstream ss;
	ss << n;
	return ss.str();
}

// 转换时间至数组，年、月、日、时、分 
void timeFormat(const string &t, set<string> &dest) {
	int pos = 0;
	while (pos < t.length()) {
		int commapos = t.find(',', pos);
		if (commapos == string::npos) {
			commapos = t.length();
		}
		string curstr = t.substr(pos, commapos - pos);
		pos = commapos + 1;
		int dashpos = curstr.find('-');
		// 单值 
		if (dashpos == string::npos) {
			if (curstr[0] > '9') {
				int m = monthToNum(curstr);
				curstr = to_string(m);
			}
			if (curstr.length() == 1) {
				curstr.insert(0, "0");
			}
			dest.insert(curstr);
		} else {
			// 连续
			string curbegin = curstr.substr(0, dashpos);
			string curend = curstr.substr(dashpos + 1);

			int begin = curbegin[0] > '9' ? monthToNum(curbegin) : strToInt(curbegin);
			int end = curend[0] > '9' ? monthToNum(curend) : strToInt(curend);
			
			while (begin <= end) {
				if (begin < 10) {
					dest.insert("0" + to_string(begin));
				} else {
					dest.insert(to_string(begin));
				}			
				begin++;
			}
							
		}
	}	
}

void weekdayFormat(const string & t, set<int> & dest) {
	int pos = 0;
	while (pos < t.length()) {
		int commapos = t.find(',', pos);
		if (commapos == string::npos) {
			commapos = t.length();
		}
		
		string curstr = t.substr(pos, commapos - pos);
		pos = commapos + 1;
		int dashpos = curstr.find('-');
		// 单值 
		if (dashpos == string::npos) {
			if (curstr[0] > '9') {
				dest.insert(weekdayToNum(curstr));
			} else {
				dest.insert(strToInt(curstr));
			}
		} else {
			// 连续
			string curbegin = curstr.substr(0, dashpos);
			string curend = curstr.substr(dashpos + 1);
			int begin = curbegin[0] > '9' ? weekdayToNum(curbegin) : strToInt(curbegin);
			int end = curend[0] > '9' ? weekdayToNum(curend) : strToInt(curend);

			while (begin <= end) {
				dest.insert(begin);		
				begin++;
			}					
		}
	}
}

int dayOfMonth[13] = {
	0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
}; 

// 计算星期几 
int getWeekdayOfDate(int y, int m, int d) {
	if (isLeapYear(y)) {
		dayOfMonth[2] = 29;
	} else {
		dayOfMonth[2] = 28;
	}
	if (d > dayOfMonth[m]) {
		return -1;
	}
	
	int w = 4;
	int ybegin = 1970;
	while (ybegin < y) {
		w += isLeapYear(ybegin) ? 366 : 365;
		ybegin++;
	}
	int mbegin = 1;
	while (mbegin < m) {
		w += dayOfMonth[mbegin];
		mbegin++;
	}
	w += d - 1;
	return w % 7;
}



int main()
{
	map<string, vector<string> > res;
	int n;
	string begin, end;
	cin >> n >> begin >> end;
	
	// 处理任务
	while (n--) {
		string minutes, hours, day, mon, weekday, command;
		set<string> vmin, vhour, vday, vmon;
		set<int> vweekday;
		cin >> minutes >> hours >> day >> mon >> weekday >> command;
		if (minutes == "*") {
			minutes = "0-59";
		}
		if (hours == "*") {
			hours = "0-23";
		}
		if (day == "*") {
			day = "1-31";
		}
		if (mon == "*") {
			mon = "1-12";
		}
		if (weekday == "*") {
			weekday = "0-6";
		}
		timeFormat(minutes, vmin);
		timeFormat(hours, vhour);
		timeFormat(day, vday);
		timeFormat(mon, vmon);
		weekdayFormat(weekday, vweekday);

		int ybegin = strToInt(begin.substr(0, 4));
		int yend = strToInt(end.substr(0, 4));
		
		while (ybegin <= yend) {
			// month
			for (set<string>::iterator mit = vmon.begin(); mit != vmon.end(); mit++) {
				for (set<string>::iterator dit = vday.begin(); dit != vday.end(); dit++) {
					int w = getWeekdayOfDate(ybegin, strToInt(*mit), strToInt(*dit));
					if (w == -1) {
						continue;
					}
					for (set<string>::iterator hit = vhour.begin(); hit != vhour.end(); hit++) {
						for (set<string>::iterator minit = vmin.begin(); minit != vmin.end(); minit++) {
							string time = to_string(ybegin) + *mit + *dit + *hit + *minit;
							if (time >= begin && time < end) {
								set<int>::iterator wit = find(vweekday.begin(), vweekday.end(), w);
								if (wit != vweekday.end()) {
									vector<string>::iterator tit = find(res[time].begin(), res[time].end(), command);
									if (tit == res[time].end()) {
										res[time].push_back(command);
									}
								}
							}
						}
					}
				}
			}
			
			ybegin++;
		}
	}
	
	for (map<string, vector<string> >::iterator it = res.begin(); it != res.end(); it++) {
		for (vector<string>::iterator cit = it->second.begin(); cit != it->second.end(); cit++) {
			cout << it->first << " " << *cit << endl;
		}
	}

	
	return 0;
	
}

