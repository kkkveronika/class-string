//Menu.cpp
#include "Menu.h"

void Menu() {
	int Count_symbols{};
	int Count_words{};
	int Count_line{};
	int Count_paragraph{};
	vector<string> text;
	bool exit = true;
	while (exit == true) {
		cout << "Look test - 1\nEnter the text from keyboard - 2\nAdd the text from file - 3\nView text - 4\nView table - 5\nExit - 6\nChoose: ";
		int user_choice{};
		user_choice = GetInt();
		switch (user_choice) {
		case(Test): {
			test();
		}break;
		case(Manual_input_text): {
			cout << "Text must end '*'" << endl;
			text=InputString(text, &Count_symbols, &Count_words, &Count_line, &Count_paragraph);
			cout << "Symbols: " << Count_symbols << "\n" << "Words: " << Count_words<< "\n" << "Line: " << Count_line << "\n" << "Paragraph: " << Count_paragraph << endl;
		}break;
		case(Text_from_file): {
			cout << "Text must end '*'" << endl;
			text=OfFileText(text, &Count_symbols, &Count_words, &Count_line, &Count_paragraph);
			cout << "Symbols: " << Count_symbols << "\n" << "Words: " << Count_words<< "\n" << "Line: " << Count_line << "\n" << "Paragraph: " << Count_paragraph << endl;
		}break;
		case(Look_text): {
			for (int i = 0; i< static_cast<int>(text.size()); i++) {
				cout << text[i] << endl;
			}
		}break;
		case(Look_table): {
			vector<int> table;
			table=Table(text);
			int max_count_words = *max_element(table.begin(), table.end());
			cout << "Count words in sentences\t\t Count sentences" << endl;
			for (int j = 1; j <= max_count_words; j++) {
				for (int i = 0; i< static_cast<int>(table.size()); i++) {
					if (table[i] == j) {
						cout << j << "\t\t\t\t\t\t" << count(begin(table), end(table), j) << endl << endl;
						break;
					}
				}
			}
		}break;
		case(Exit): {
			exit = false;
		}break;
		default: {
			cout << "Error, try again\n";
		}break;
		}
	}
}
