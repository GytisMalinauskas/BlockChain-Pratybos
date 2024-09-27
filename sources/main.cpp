#include "../headers/main.h"

int main(int argc, char* argv[]) 
{
    string input;
    vector <string> input2, input3;
    vector <string> hash, hash2;
    vector <double> proc;
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
      string failas = argv[1], line,line2;
      ifstream fd(failas);
      
      if(fd.is_open())
      {
        while(fd >> line >> line2)
        {
          input2.push_back(line);
          input3.push_back(line2);
        }
        fd.close();
      }
      for(const auto& in : input2)
      {
        // Sugeneruojame maišą
    vector<uint8_t> hashValue = betterHash(in);
    string hexHash = toHexString(hashValue);
    hash.push_back(hexHash);
    
    //cout <<"Maišos reikšmė (hash): " << hexHash << endl;
      
      }
      for(const auto& in : input3)
      {
        // Sugeneruojame maišą
    vector<uint8_t> hashValue = betterHash(in);
    string hexHash = toHexString(hashValue);
    hash2.push_back(hexHash);
    
    //cout <<"Maišos reikšmė (hash): " << hexHash << endl;
      
      }
      for(const auto& h : hash)
      {
        int i=0;
        string hashas=h;
        string hashas2=hash2[i];
        proc.push_back(compareHash(hashas,hashas2));
        i++;
      }
      double min=proc[0], sum=0, max=proc[0];
      for(const auto& p : proc)
      {
        if(p<min)
        {
          min=p;
          }
          if(p>max)
          {
            max=p;
          }
          sum+=p;
      }
      double avg=sum/proc.size();
      cout << "Min: " << min << endl;
      cout << "Max: " << max << endl;
      cout << "Avg: " << avg << endl;
      
      /*
      int m=1,k=0;
      for(const auto& h : hash)
      {
        for(long unsigned int i=m; i<h.size(); i++)
        {
          if(h==hash[i])
          {
            cout <<"[WARNING] aptikta kolizija"<<endl;
            k++;
          }
        }
        m++;
      }
      cout <<"[INFO] Kolizijų skaičius: "<<k<<endl;
      */
    }
    return 0;   
}
