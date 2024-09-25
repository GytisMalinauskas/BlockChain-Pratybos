#include "../headers/main.h"

#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    string input;
    cout << "Įveskite eilutę: ";
    getline(cin, input);

    // Sugeneruojame maišą
    vector<uint8_t> hashValue = betterHash(input);

    // Konvertuojame maišą į hexadecimal formato eilutę
    string hexHash = toHexString(hashValue);

    cout << "Maišos reikšmė (hash): " << hexHash << endl;

    return 0;
}
