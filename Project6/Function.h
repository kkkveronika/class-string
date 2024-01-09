//Function.h
#pragma once

#include"Correct_input.h"
#include<string>
#include<vector>
#include<fstream>

vector<string> InputString(vector<string> Text, int* count_symb, int* count_words, int* count_line, int* count_paragraph);

vector<string> OfFileText(vector<string> Text, int* count_symb, int* count_words, int* count_line, int* count_paragraph);

int CountSymbols(string line, int* count_symb);

int CountWords(string line, int* count_words);

int CountLine(vector<string> Text, int* count_line);

int CountParagraph(string line, int* count_paragraph);

vector<int> Table(vector<string> Text);