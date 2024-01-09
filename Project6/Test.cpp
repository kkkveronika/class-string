//Test.cpp
#include "Test.h"

void test() {
	vector<string> TextTest;
	vector<int> TestTable;
	vector<int> ResultTable = { 3, 5, 3, 3, 3, 4, 3, 2, 3, 3};
	int count_symb_result = 169;
	int count_words_result = 32;
	int count_paragraph_result = 3;
	int count_line_result = 3;
	int count_symb{};
	int count_words{};
	int count_paragraph{};
	int count_line{};
	int count_symb_test{};
	int count_words_test{};
	int count_paragraph_test{};
	int count_line_test{};
	string name_file = "";
	name_file= "text";
	ifstream file;
	file.open(name_file);
	if (!file.is_open()) {
		cout << "File opening error" << endl;
	}
	else {
		while (!file.eof()) {
			string str{};
			while (getline(file, str, '\n') && str != "*")
			{
				TextTest.push_back(str);
				count_symb_test = CountSymbols(str, &count_symb);
				count_words_test = CountWords(str, &count_words);
				count_paragraph_test = CountParagraph(str, &count_paragraph);
			}
			count_line_test = CountLine(TextTest, &count_line);
		}
	}
	file.close();

	TestTable = Table(TextTest);

	if (TestTable == ResultTable && (count_symb_test == count_symb_result) && (count_words_test== count_words_result) && (count_paragraph_test== count_paragraph_result) && (count_line== count_line_result) ) {
		cout << endl << "Test passed" << endl << endl;
	}
	else {
		cout << "Test is not passed" << endl;
		cout << "The result of the work:" << endl;
		int max_count_words = *max_element(TestTable.begin(), TestTable.end());
		cout << "Count words in sentences\t\t Count sentences" << endl;
		for (int j = 1; j <= max_count_words; j++) {
			for (int i = 0; i< static_cast<int>(TestTable.size()); i++) {
				if (TestTable[i] == j) {
					cout << j << "\t\t\t\t\t\t" << count(begin(TestTable), end(TestTable), j) << endl << endl;
					break;
				}
			}
		}
		cout << endl << "Expected result:" << endl;
		max_count_words = *max_element(ResultTable.begin(), ResultTable.end());
		cout << "Count words in sentences\t\t Count sentences" << endl;
		for (int j = 1; j <= max_count_words; j++) {
			for (int i = 0; i< static_cast<int>(ResultTable.size()); i++) {
				if (ResultTable[i] == j) {
					cout << j << "\t\t\t\t\t\t" << count(begin(ResultTable), end(ResultTable), j) << endl << endl;
					break;
				}
			}
		}

	}
}

//   uedsf sdiiuf dfiu.spdfjo ajkfb sdkf sakfj vksd.podsf kasj fskdjv.
//   IOSdf kdjf k!KJds fkjs d ? SLdf sdlkf lsf blf!
//   jKd sdjk fsjd.Sdjf skd.KSDjf ksdj f.KSDjf kblkd v.
//*