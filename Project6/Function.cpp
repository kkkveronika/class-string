//Function.cpp
#include"Function.h"
#include<algorithm>

vector<string> InputString(vector<string> Text, int* count_symb, int* count_words, int* count_line, int* count_paragraph) {
	string str;
	while (getline(cin, str, '\n') && str!="*")
	{
		Text.push_back(str);
		CountSymbols(str, count_symb);
		CountWords(str, count_words);
		CountParagraph(str, count_paragraph);
	}
	CountLine(Text, count_line);
	return Text;
}

vector<string> OfFileText(vector<string> Text, int* count_symb, int* count_words, int* count_line, int* count_paragraph) {
	cout << "Enter the name of file(without file permission!): ";
	string name_file = "";
	cin >> name_file;
	ifstream file;
	file.open(name_file);
	if (!file.is_open()) {
		cout << "File opening error" << endl;
	}
	else {
		while (!file.eof()) {
			string str{};
			while (getline(file, str, '\n')&&str != "*")
			{
				Text.push_back(str);
				CountSymbols(str, count_symb);
				CountWords(str, count_words);
				CountParagraph(str, count_paragraph);
				//Table(str);
			}
		CountLine(Text, count_line);
		}
	}
	file.close();
	return Text;
}

int CountSymbols(string line, int* count_symb) {
	*count_symb +=  static_cast<int>(line.size());
	return *count_symb;
}

int CountWords(string line, int* count_words) {
	int pos = line.find(' ');
	int posit = line.find('\t');
	while (posit + 1) {
		++*count_words;
		line.erase(0, posit + 1);
		posit = line.find('\t');
	}
	while (pos+1) {
		++*count_words;
		line.erase(0, pos + 1);
		pos = line.find(' ');
	}
	return *count_words;
}

int CountLine(vector<string> Text, int* count_line) {
	*count_line =  static_cast<int>(Text.size());
	return *count_line;
}

int CountParagraph(string line, int* count_paragraph) {
	int pos = line.find('\t');
	while (pos + 1) {
		++*count_paragraph;
		line.erase(0, pos + 1);
		pos = line.find('\t');
	}
	return *count_paragraph;
}

vector<int> Table(vector<string> Text) {
	int Words{};
	vector<int> table;
	string line;
	for (int j = 0; j< static_cast<int>(Text.size()); j++) {
		int pos_point = Text[j].find('.');
		int pos_exclamation_mark = Text[j].find('!');
		int pos_question_mark = Text[j].find('?');
		while ((pos_point + 1 || pos_exclamation_mark + 1 || pos_question_mark + 1)) {
			pos_point = Text[j].find('.');
			pos_exclamation_mark = Text[j].find('!');
			pos_question_mark = Text[j].find('?');
			if (pos_exclamation_mark + 1) {
				if (((pos_exclamation_mark + 1) && (pos_point == -1) && (pos_question_mark == -1)) || ((pos_question_mark + 1) && (pos_point == -1) && (pos_exclamation_mark + 1 < pos_question_mark + 1)) || ((pos_point + 1) && (pos_question_mark == -1) && (pos_exclamation_mark + 1 < pos_point + 1)) || ((pos_question_mark + 1) && (pos_point + 1) && (pos_exclamation_mark + 1 < pos_question_mark + 1) && (pos_exclamation_mark + 1 < pos_point + 1))) {
					line.append(Text[j], 0, pos_exclamation_mark + 1);
					Words = CountWords(line, &Words);
					table.push_back(Words);
					Words = 0;
					Text[j].erase(0, pos_exclamation_mark + 1);
					pos_exclamation_mark = Text[j].find('!');
					line.erase(0);
				}
			}
			pos_point = Text[j].find('.');
			pos_exclamation_mark = Text[j].find('!');
			pos_question_mark = Text[j].find('?');
			if (pos_question_mark + 1) {
				if (((pos_point + 1) && (pos_exclamation_mark + 1) && (pos_question_mark + 1 < pos_point + 1) && (pos_question_mark + 1 < pos_exclamation_mark + 1)) || ((pos_question_mark + 1) && (pos_point == -1) && (pos_exclamation_mark == -1)) || ((pos_exclamation_mark + 1) && (pos_question_mark + 1 < pos_exclamation_mark + 1) && (pos_point == -1)) || ((pos_point + 1) && (pos_question_mark + 1 < pos_point + 1) && (pos_exclamation_mark == -1))) {
					line.append(Text[j], 0, pos_question_mark + 1);
					Words = CountWords(line, &Words);
					table.push_back(Words);
					Words = 0;
					Text[j].erase(0, pos_question_mark + 1);
					pos_question_mark = Text[j].find('?');
					line.erase(0);
				}
			}
			pos_point = Text[j].find('.');
			pos_exclamation_mark = Text[j].find('!');
			pos_question_mark = Text[j].find('?');
			if (pos_point + 1) {
				if (((pos_exclamation_mark + 1) && (pos_question_mark + 1) && (pos_point + 1 < pos_question_mark + 1) && (pos_point + 1 < pos_exclamation_mark + 1)) || ((pos_point + 1) && (pos_question_mark == -1) && (pos_exclamation_mark == -1)) || (pos_exclamation_mark + 1 && pos_question_mark == -1 && pos_point + 1 < pos_exclamation_mark + 1) || (pos_question_mark + 1 && pos_exclamation_mark == -1 && pos_point + 1 < pos_question_mark + 1)) {
					line.append(Text[j], 0, pos_point + 1);
					Words = CountWords(line, &Words);
					table.push_back(Words);
					Words = 0;
					Text[j].erase(0, pos_point + 1);
					pos_point = Text[j].find('.');
					line.erase(0);
				}
			}
			pos_point = Text[j].find('.');
			pos_exclamation_mark = Text[j].find('!');
			pos_question_mark = Text[j].find('?');
		}
	}
	return table;
}
