#ifndef MAIN_H
#define MAIN_H
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <vector>
#include <fstream>
#include <vector>
#include <bitset>

using namespace std;
string toHexString(const vector<uint8_t>& bytes);
vector<uint8_t> betterHash(const string& input);
double compareHash(string h1, string h2);

#endif