#include <bits/stdc++.h> // 万能头文件 
using namespace std;
int toint(string value) { // toint函数将 汉字 转成 整数
	int len = value.size(), ret = 0; 
	for (int i = 0; i < len; i+=2) {
		if (value.substr(i, 2) == "零") ret = ret*10 + 0; 
		if (value.substr(i, 2) == "一") ret = ret*10 + 1; 
		if (value.substr(i, 2) == "二") ret = ret*10 + 2; 
		if (value.substr(i, 2) == "三") ret = ret*10 + 3; 
		if (value.substr(i, 2) == "四") ret = ret*10 + 4; 
		if (value.substr(i, 2) == "五") ret = ret*10 + 5;  
		if (value.substr(i, 2) == "六") ret = ret*10 + 6; 
		if (value.substr(i, 2) == "七") ret = ret*10 + 7; 
		if (value.substr(i, 2) == "八") ret = ret*10 + 8;  
		if (value.substr(i, 2) == "九") ret = ret*10 + 9; 
		if (value.substr(i, 2) == "十") ret = ret*10 + 10;  
	}
	return ret;
}
int main() {
	map<string, int> mp; 
	string var, value, some, oper, cmp, other;
	string num[12] = {"零", "一", "二", "三", "四", "五", "六", "七", "八", "九", "十"};
	for (int i = 0; i < 2; ++i) cin >> var; // 输入两遍，保留第二个变量名 
	for (int i = 0; i < 2; ++i) cin >> value; // 输入两遍，保留第二个数字值 
	mp[var] = toint(value); // 将value转换成整数, 并存入mp[var]中 
	
	while (cin >> some) { // 输入一个单词，判断是否等于“整数”或“看看”或“如果”或变量名 
		if (some == "整数") {
			cin >> var >> other >> value; // 保留var和value 
			mp[var] = toint(value);
		} else if (some == "看看") {
			cin >> var;
			if (!mp[var]) continue; // 如果变量名不存在，则跳过 
			int temp = abs(mp[var]);
			if (mp[var] < 0) cout << "负"; 
			if (temp <= 10) {
				cout << num[temp] << endl;	
			} else { // 大于10的情况 
				int ssum = 0, cnt = 0;
				while (temp) { // 逆置sum，用ssum保存 
					ssum = ssum * 10 + temp % 10;
					temp /= 10;
					++cnt;
				} 
				while (cnt--) { // 输出每一位数 
					cout << num[ssum%10];
					ssum /= 10;
				}
				cout << endl;
			}
		} else if (some == "如果") {
			string digit, then, s1, s2, s3, s4, s5;
			cin >> var >> cmp >> digit;
			cin >> then >> s1 >> s2 >> s3 >> s4 >> s5;
			if (s1 == "看看") {
				int len1 = s2.size()-2; // 减去头尾两个双引号的长度 
				int len2 = s5.size()-2;
				if (cmp == "大于") {
					if (mp[var] > toint(digit)) cout << s2.substr(1, len1) << endl;
					else cout << s5.substr(1, len2) << endl; // 输出去掉头尾的子串 
				} else if (cmp == "小于") {
					if (mp[var] < toint(digit)) cout << s2.substr(1, len1) << endl;
					else cout << s5.substr(1, len2) << endl;
				} 
			} else {
				if (cmp == "大于") {
					if (mp[var] > toint(digit)) {
						if (s2 == "减少") {
							mp[s1] -= toint(s3); 
						} else if (s2 == "增加") {
							mp[s1] += toint(s3); 
						} 
					} else; 
				} else if (cmp == "小于") {
					if (mp[var] < toint(digit)) {
						if (s2 == "减少") {
							mp[s1] -= toint(s3); 
						} else if (s2 == "增加") {
							mp[s1] += toint(s3); 
						} 
					} else;
				} 
			}		 
		} else if (mp[some]) { // 如果是已存在的变量 
			cin >> oper >> value;
			if (oper == "减少") {
				mp[some] -= toint(value); 
			} else if (oper == "增加") {
				mp[some] += toint(value); 
			} 
		} 
	}
	return 0;
} 
