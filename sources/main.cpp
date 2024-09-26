#include "../headers/main.h"

int main(int argc, char* argv[]) 
{
    string input;
    vector <string> input2;
    if (argc==1)
    {
    cout << "Įveskite eilutę: ";
    getline(cin, input);

    // Sugeneruojame maišą
    vector<uint8_t> hashValue = betterHash(input);

    // Konvertuojame maišą į hexadecimal formato eilutę
    string hexHash = toHexString(hashValue);

    cout << "Maišos reikšmė (hash): " << hexHash << endl;
    }
    if (argc>1)
    {
      cout<<"[WARNING] Tinka tik failai, kurie baigiasi (.txt)"<<endl;
      string failas = argv[1], line;
      ifstream fd(failas);
      
      if(fd.is_open())
      {
        while(fd >> line)
        {
          input2.push_back(line);
        }
        fd.close();
      }
      for(const auto& in : input2)
      {
        // Sugeneruojame maišą
    vector<uint8_t> hashValue = betterHash(in);
    string hexHash = toHexString(hashValue);
    cout <<"Maišos reikšmė (hash): " << hexHash << endl;
      }
    }
    return 0;   
}
