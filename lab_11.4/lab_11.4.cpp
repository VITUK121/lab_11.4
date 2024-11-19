#include <fstream>
#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

void doesFileExists(string t) {
	ifstream file(t);
	if (!file) {
		file.close();
		ofstream file_w(t);
		file_w.close();
	}
	else {
		file.close();
	}
}

string findLongestWord(string& line) {
	string longestWord;
	string currentWord;

	for (char c : line) {
		if (c == ' ') {
			if (currentWord.length() > longestWord.length()) {
				longestWord = currentWord;
			}
			currentWord = "";
		}
		else {
			currentWord += c;
		}
	}

	if (currentWord.length() > longestWord.length()) {
		longestWord = currentWord;
	}

	return " " + longestWord;
}

void parseFile(string _from, string _to) {
	ifstream file_r(_from);

	if (!file_r) {
		cerr << "������� ��� ������� �����\n";
		file_r.close();
		return;
	}

	ofstream file_w(_to);

	string line;
	string word;
	int i = 1;

	while (getline(file_r, line)) {
		if (i % 2 == 0) {
			word = findLongestWord(line);
			file_w << line << endl;
		}
		else {
			file_w << line << word << endl;
		}
		i++;
	}

	file_w.close();
	file_r.close();
}

void menu(string _from, string _to) {
	int option;

	while (true) {
		cout << "����:\n[1]������� �����\n[2]�����\n : "; cin >> option;
		switch (option){

			case 1:
				parseFile(_from, _to);
				break;

			case 2:
				return;

			default:
				cerr << "������������ ���\n\n";
				break;
		}
	}
}

int main(){
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string _from;
	string _to;

	cout << "������ ��'� �������� ����� �����: "; cin >> _from;
	cout << "������ ��'� ��������� �����: "; cin >> _to;

	doesFileExists(_from);
	menu(_from, _to);
}