#include <bits/stdc++.h> // 万能头文件 
using namespace std;
map<string, int> mp; 
string num[11] = {"零", "一", "二", "三", "四", "五", "六", "七", "八", "九", "十"};
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
void int_to_string(string var) { // int 转成 汉字 
	int temp = abs(mp[var]);
	if (mp[var] < 0) cout << "负"; 
	if (temp <= 10) {
		cout << num[temp] << endl;	
	} else { // 大于10的情况 
		int sum = 0, cnt = 0;
		while (temp) { // 逆置temp，用sum保存 
			sum = sum * 10 + temp % 10;
			temp /= 10;
			++cnt;
		} 
		while (cnt--) { // 输出每一位数 
			cout << num[sum%10];
			sum /= 10;
		}
		cout << endl;
	}
}
void add_or_sub(string var, string oper, string value) { // 加减法 
	if (oper == "减少") {
		mp[var] -= toint(value); 
	} else if (oper == "增加") {
		mp[var] += toint(value); 
	} 
}
int main() {
	string var, value, word, oper, cmp, other;
	while (cin >> word) { // 输入一个单词，判断是否等于“整数”或“看看”或“如果”或变量名 
		if (word == "整数") { // 1. 整数 
			cin >> var >> other >> value; // 保留var和value 
			mp[var] = toint(value);
		} else if (word == "看看") { // 2.看看 
			cin >> var;
			if (!mp.count(var)) {
				if (var[0] == '"' && var[var.size()-1] == '"') 
					cout << var.substr(1,var.size()-2) << endl;
				else if (var.substr(0,2) == "“" && var.substr(var.size()-2,2) == "”") 
					cout << var.substr(2,var.size()-4) << endl; 
				else cout << "无此变量：" << var << endl; 
				continue; // 跳过计算步骤 
			}
			int_to_string(var);
		} else if (word == "如果") { // 3. 如果 
			string digit, then, s1, s2, s3, s4, s5;
			cin >> var >> cmp >> digit;
			cin >> then >> s1 >> s2 >> s3 >> s4 >> s5;
			if (!mp.count(var)) {
				cout << "无此变量：" << var << endl; 
				continue;
			}
			if (s1 == "看看") { // 3.1 看看 
				int len1, len2, start;
				if (s2[0] == '"' && s2[s2.size()-1] == '"') {
					len1 = s2.size()-2; // 减去头尾两个英文双引号的长度 
					len2 = s5.size()-2;
					start = 1; 
				} else if (s2.substr(0,2) == "“" && s2.substr(s2.size()-2,2) == "”") {
					len1 = s2.size()-4; // 减去头尾两个中文双引号的长度 
					len2 = s5.size()-4;
					start = 2; 
				}
				if (cmp == "大于") {
					if (mp[var] > toint(digit)) cout << s2.substr(start, len1) << endl;
					else cout << s5.substr(start, len2) << endl; // 输出去掉头尾的子串 
				} else if (cmp == "小于") {
					if (mp[var] < toint(digit)) cout << s2.substr(start, len1) << endl;
					else cout << s5.substr(start, len2) << endl;
				} 
			} else { // 3.2  
				if (!mp.count(s1)) {
					cout << "无此变量：" << s1 << endl; 
					continue;
				}
				if (cmp == "大于") {
					if (mp[var] > toint(digit)) {
						add_or_sub(s1, s2, s3); // 变量名，操作，值 
					} else; 
				} else if (cmp == "小于") {
					if (mp[var] < toint(digit)) {
						add_or_sub(s1, s2, s3); 
					} else;
				} 
			}		 
		} else if (mp.count(word)) { // 4.已存在的变量 
			cin >> oper >> value;
			add_or_sub(word, oper, value);
		} else { // 5. 其他 
			cout << "请输入正确的格式\n";
		}
	}
	return 0;
} 
