#include "../headers/main.h"

string toHexString(const vector<uint8_t>& bytes) {
    stringstream ss;
    for (const auto& byte : bytes) {
        ss << hex << setw(2) << setfill('0') << (int)byte;
    }
    return ss.str();
}
// Paprasta maišos funkcija
vector<uint8_t> simpleHash(const string& input) {
    // Fiksuotas išėjimo dydis - 256 bitai arba 32 baitai
    const size_t hashSize = 32;
    vector<uint8_t> hash(hashSize, 0); // Inicializuojame nulių masyvą

    for (size_t i = 0; i < input.length(); ++i) {
        // Paprastas algoritmas: kiekvienas simbolis prisideda prie kiekvieno baito maišos
        hash[i % hashSize] ^= input[i] + i;
        // Maišymas: paslinkiame bito vietas kiekvienam baitui, kad simbolių pozicija turėtų įtakos
        hash[i % hashSize] = ((hash[i % hashSize] << 5) | (hash[i % hashSize] >> 3));
    }
    
    return hash;
}