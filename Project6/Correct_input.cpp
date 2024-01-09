//Correct_input.cpp
#include"Correct_input.h"

int GetInt() {
	int input{};
	cin >> input;
	while (!(input >= 1)) {
		cout << "Error, try again" << endl;
		cin.clear();
		cin.sync();
		cin.ignore(INT_MAX, '\n');
		cin >> input;
	}
	return input;
}