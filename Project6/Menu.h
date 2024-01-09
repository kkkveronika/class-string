//Menu.h
#pragma once
#include<iostream>
#include<vector>
#include <algorithm>
#include"Test.h"
#include"Function.h"

using namespace std;

enum {
	Test=1,
	Manual_input_text,
	Text_from_file,
	Look_text,
	Look_table,
	Exit,
};

void Menu();