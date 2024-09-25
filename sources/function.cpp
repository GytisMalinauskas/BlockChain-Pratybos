#include "../headers/main.h"

string toHexString(const vector<uint8_t>& bytes) {
    stringstream ss;
    for (const auto& byte : bytes) {
        ss << hex << setw(2) << setfill('0') << (int)byte;
    }
    return ss.str();
}
// Patobulinta maišos funkcija
vector<uint8_t> simpleHash(const string& input) {
    // Fiksuotas išėjimo dydis - 256 bitai arba 32 baitai
    const size_t hashSize = 32;
    vector<uint8_t> hash(hashSize, 0); // Inicializuojame nulių masyvą
    
    // Papildomas maišymas su pradine verte
    uint8_t salt = 0xAB;  // Paprastas "salt", kuris padeda maišyti pradines reikšmes

    for (size_t i = 0; i < input.length(); ++i) {
        // Kiekvienas simbolis prisideda prie kiekvieno baito maišos
        hash[i % hashSize] ^= (input[i] + salt + i * 31); // Naudojame daugiau matematikos, kad įvestis maišytųsi geriau
        // Daugiau maišymo: paslinkimas ir XOR
        hash[i % hashSize] = ((hash[i % hashSize] << 5) | (hash[i % hashSize] >> 3)) ^ salt;
        salt = (salt * 31) + input[i]; // Modifikuojame salt, kad įvestis daugiau maišytųsi
    }

    return hash;
}