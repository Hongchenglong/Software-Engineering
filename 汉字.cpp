#include <bits/stdc++.h> // ����ͷ�ļ� 
using namespace std;
int toint(string value) { // toint������ ���� ת�� ���� 
	if (value == "��") return 0; 
	if (value == "һ") return 1; 
	if (value == "��") return 2; 
	if (value == "��") return 3; 
	if (value == "��") return 4; 
	if (value == "��") return 5; 
	if (value == "��") return 6; 
	if (value == "��") return 7; 
	if (value == "��") return 8; 
	if (value == "��") return 9; 
	if (value == "ʮ") return 10; 
}
int main() {
	string var, value;
	string num[12] = {"��", "һ", "��", "��", "��", "��", "��", "��", "��", "��", "ʮ"};
	for (int i = 0; i < 2; ++i) cin >> var; // �������飬�����ڶ��������� 
	for (int i = 0; i < 2; ++i) cin >> value; // �������飬�����ڶ�������ֵ 
	int sum = toint(value); // ��valueת�������� 
	
	string some, oper, cmp;
	while (cin >> some) { // ����һ�����ʣ��ж��Ƿ���ڱ������򡰿������������ 
		if (some == var) {
			cin >> oper >> value;
			if (oper == "����") {
				sum -= toint(value); 
			} else if (oper == "����") {
				sum += toint(value); 
			} 
		} else if (some == "����") {
			cin >> var;
			int temp = abs(sum);
			if (sum < 0) cout << "��"; 
			if (temp <= 10) {
				cout << num[temp] << endl;	
			} else { // ����10����� 
				int ssum = 0, cnt = 0;
				while (temp) { // ����sum����ssum���� 
					ssum = ssum * 10 + temp % 10;
					temp /= 10;
					++cnt;
				} 
				while (cnt--) { // ���ÿһλ�� 
					cout << num[ssum%10];
					ssum /= 10;
				}
				cout << endl;
			}
		} else if (some == "���") {
			string digit, sent1, sent2, other;
			cin >> other >> cmp >> digit >> other;
			cin >> other >> sent1 >> other >> other >> sent2;
			int len1 = sent1.size()-2; // ��ȥͷβ����˫���ŵĳ��� 
			int len2 = sent2.size()-2;
			if (cmp == "����") {
				if (sum > toint(digit)) cout << sent1.substr(1, len1) << endl;
				else cout << sent2.substr(1, len2) << endl; // ���ȥ��ͷβ���Ӵ� 
			} else if (cmp == "С��") {
				if (sum < toint(digit)) cout << sent1.substr(1, len1) << endl;
				else cout << sent2.substr(1, len2) << endl;
			}  
		} 
	}
	return 0;
} 
