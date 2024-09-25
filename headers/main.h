#ifndef MAIN_H
#define MAIN_H
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <vector>

using namespace std;
string toHexString(const vector<uint8_t>& bytes);
vector<uint8_t> simpleHash(const string& input);

#endif