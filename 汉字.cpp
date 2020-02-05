#include <bits/stdc++.h> // 万能头文件 
using namespace std;
int toint(string value) { // toint函数将 汉字 转成 整数 
	if (value == "零") return 0; 
	if (value == "一") return 1; 
	if (value == "二") return 2; 
	if (value == "三") return 3; 
	if (value == "四") return 4; 
	if (value == "五") return 5; 
	if (value == "六") return 6; 
	if (value == "七") return 7; 
	if (value == "八") return 8; 
	if (value == "九") return 9; 
	if (value == "十") return 10; 
}
int main() {
	string var, value;
	string num[12] = {"零", "一", "二", "三", "四", "五", "六", "七", "八", "九", "十"};
	for (int i = 0; i < 2; ++i) cin >> var; // 输入两遍，保留第二个变量名 
	for (int i = 0; i < 2; ++i) cin >> value; // 输入两遍，保留第二个数字值 
	int sum = toint(value); // 将value转换成整数 
	
	string some, oper, cmp;
	while (cin >> some) { // 输入一个单词，判断是否等于变量名或“看看”或“如果” 
		if (some == var) {
			cin >> oper >> value;
			if (oper == "减少") {
				sum -= toint(value); 
			} else if (oper == "增加") {
				sum += toint(value); 
			} 
		} else if (some == "看看") {
			cin >> var;
			int temp = abs(sum);
			if (sum < 0) cout << "负"; 
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
			string digit, sent1, sent2, other;
			cin >> other >> cmp >> digit >> other;
			cin >> other >> sent1 >> other >> other >> sent2;
			int len1 = sent1.size()-2; // 减去头尾两个双引号的长度 
			int len2 = sent2.size()-2;
			if (cmp == "大于") {
				if (sum > toint(digit)) cout << sent1.substr(1, len1) << endl;
				else cout << sent2.substr(1, len2) << endl; // 输出去掉头尾的子串 
			} else if (cmp == "小于") {
				if (sum < toint(digit)) cout << sent1.substr(1, len1) << endl;
				else cout << sent2.substr(1, len2) << endl;
			}  
		} 
	}
	return 0;
} 
