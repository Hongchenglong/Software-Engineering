#include <bits/stdc++.h> // ����ͷ�ļ� 
using namespace std;
int toint(string value) { // toint������ ���� ת�� ����
	int len = value.size(), ret = 0; 
	for (int i = 0; i < len; i+=2) {
		if (value.substr(i, 2) == "��") ret = ret*10 + 0; 
		if (value.substr(i, 2) == "һ") ret = ret*10 + 1; 
		if (value.substr(i, 2) == "��") ret = ret*10 + 2; 
		if (value.substr(i, 2) == "��") ret = ret*10 + 3; 
		if (value.substr(i, 2) == "��") ret = ret*10 + 4; 
		if (value.substr(i, 2) == "��") ret = ret*10 + 5;  
		if (value.substr(i, 2) == "��") ret = ret*10 + 6; 
		if (value.substr(i, 2) == "��") ret = ret*10 + 7; 
		if (value.substr(i, 2) == "��") ret = ret*10 + 8;  
		if (value.substr(i, 2) == "��") ret = ret*10 + 9; 
		if (value.substr(i, 2) == "ʮ") ret = ret*10 + 10;  
	}
	return ret;
}
int main() {
	map<string, int> mp; 
	string var, value, word, oper, cmp, other;
	string num[12] = {"��", "һ", "��", "��", "��", "��", "��", "��", "��", "��", "ʮ"};
	while (cin >> word) { // ����һ�����ʣ��ж��Ƿ���ڡ��������򡰿������������������� 
		if (word == "����") {
			cin >> var >> other >> value; // ����var��value 
			mp[var] = toint(value);
		} else if (word == "����") {
			cin >> var;
			if (!mp.count(var)) {
				if (var[0] == '"' && var[var.size()-1] == '"') 
					cout << var.substr(1,var.size()-2) << endl;
				else if (var.substr(0,2) == "��" && var.substr(var.size()-2,2) == "��") 
					cout << var.substr(2,var.size()-4) << endl; 
				else cout << "�޴˱�����" << var << endl; 
				continue; // �������㲽�� 
			}
			int temp = abs(mp[var]);
			if (mp[var] < 0) cout << "��"; 
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
		} else if (word == "���") {
			string digit, then, s1, s2, s3, s4, s5;
			cin >> var >> cmp >> digit;
			cin >> then >> s1 >> s2 >> s3 >> s4 >> s5;
			if (!mp.count(var)) {
				cout << "�޴˱�����" << var << endl; 
				continue;
			}
			if (s1 == "����") {
				int len1, len2, start;
				if (s2[0] == '"' && s2[s2.size()-1] == '"') {
					len1 = s2.size()-2; // ��ȥͷβ����Ӣ��˫���ŵĳ��� 
					len2 = s5.size()-2;
					start = 1; 
				} else if (s2.substr(0,2) == "��" && s2.substr(s2.size()-2,2) == "��") {
					len1 = s2.size()-4; // ��ȥͷβ��������˫���ŵĳ��� 
					len2 = s5.size()-4;
					start = 2; 
				}
				if (cmp == "����") {
					if (mp[var] > toint(digit)) cout << s2.substr(start, len1) << endl;
					else cout << s5.substr(start, len2) << endl; // ���ȥ��ͷβ���Ӵ� 
				} else if (cmp == "С��") {
					if (mp[var] < toint(digit)) cout << s2.substr(start, len1) << endl;
					else cout << s5.substr(start, len2) << endl;
				} 
			} else {
				if (!mp.count(word)) {
					cout << "�޴˱�����" << s1 << endl; 
					continue;
				}
				if (cmp == "����") {
					if (mp[var] > toint(digit)) {
						if (s2 == "����") {
							mp[s1] -= toint(s3); 
						} else if (s2 == "����") {
							mp[s1] += toint(s3); 
						} 
					} else; 
				} else if (cmp == "С��") {
					if (mp[var] < toint(digit)) {
						if (s2 == "����") {
							mp[s1] -= toint(s3); 
						} else if (s2 == "����") {
							mp[s1] += toint(s3); 
						} 
					} else;
				} 
			}		 
		} else if (mp.count(word)) { // ������Ѵ��ڵı��� 
			cin >> oper >> value;
			if (oper == "����") {
				mp[word] -= toint(value); 
			} else if (oper == "����") {
				mp[word] += toint(value); 
			} 
		} else { //�����ڵı��� 
			cout << "�޴˱�����" << var << endl; 
		}
	}
	return 0;
} 
