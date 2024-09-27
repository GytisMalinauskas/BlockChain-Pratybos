#include "../headers/main.h"

string toHexString(const vector<uint8_t>& bytes) {
    stringstream ss;
    for (const auto& byte : bytes) {
        ss << hex << setw(2) << setfill('0') << (int)byte;
    }
    return ss.str();
}
// Patobulinta maišos funkcija su daugiau maišymo
vector<uint8_t> betterHash(const string& input) {
    // Fiksuotas išėjimo dydis - 256 bitai arba 32 baitai
    const size_t hashSize = 32;
    vector<uint8_t> hash(hashSize, 0xAA); // Inicializuojame su pradinėmis reikšmėmis
    
    // Pradinė vertė
    uint8_t salt = 0xAB;

    for (size_t i = 0; i < input.length(); ++i) {
        // Pirmiausia modifikuojame kiekvieną baitą
        for (size_t j = 0; j < hashSize; ++j) {
            // Naudojame XOR su simbolio verte, jo pozicija, salt ir baito pozicija
            hash[j] ^= (input[i] + salt + i * 31 + j * 17);
            // Pasukame baitus, kad įtakotume viso masyvo baitus
            hash[j] = ((hash[j] << 7) | (hash[j] >> 1)) ^ (salt * (i + 1));
        }
        salt = (salt * 33) + input[i]; // Modifikuojame salt, kad kiekvienas simbolis įtakotų tolimesnius ciklus
    }

    // Papildomas maišymas po pagrindinio ciklo
    for (size_t i = 0; i < hashSize; ++i) {
        hash[i] ^= (salt + i * 31);  // Dar daugiau chaoso
        hash[i] = ((hash[i] << 5) | (hash[i] >> 3)) ^ salt;
    }

    return hash;
}

double compareHash(string h1, string h2)
{
     if (h1.size() != h2.size()) {
        std::cerr << "[WARNING] Hash'ai turi būti vienodo ilgio!" << std::endl;
        return 0.0;
    }
     // XOR tarp hash'ų ir skaičiuojame skirtumus
    int totalBits = 0;
    int differingBits = 0;
    for (size_t i = 0; i < h1.size(); ++i) {
        // Konvertuojame kiekvieną hash'o simbolį į sveikąjį skaičių (nuo hex iki int)
        int hash1 = std::stoi(std::string(1, h1[i]), nullptr, 16); // Hex -> int
        int hash2 = std::stoi(h2.substr(i, 1), nullptr, 16); // Hex -> int
        
        // XOR tarp dviejų hex simbolių, gauname skirtumus tarp bitų
        int xorResult = hash1 ^ hash2;
        
        // Paverskite XOR rezultatą į bitus ir suskaičiuokite, kiek bitų skiriasi
        std::bitset<4> bits(xorResult); // Hex skaičiuje yra 4 bitai
        differingBits += bits.count();  // Suskaičiuojame kiek „1“ bitų
        totalBits += 4;                 // Kiekvienas hex simbolis yra 4 bitai
    }
double percentageDifference = (static_cast<double>(differingBits) / totalBits) * 100.0;
    return percentageDifference;
}