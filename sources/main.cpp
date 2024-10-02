#include "../headers/main.h"

int main(int argc, char* argv[]) 
{
    string input;
    vector <string> input2, input3;
    vector <string> hash, hash2;
    vector <double> proc;
    if (argc==1)
    {
    cout << "[INPUT] Įveskite eilutę: ";
    getline(cin, input);

    // Sugeneruojame maišą
    vector<uint8_t> hashValue = betterHash(input);

    // Konvertuojame maišą į hexadecimal formato eilutę
    string hexHash = toHexString(hashValue);

    cout << "[OUTPUT] Maišos reikšmė (hash): " << hexHash << endl;
    }
    if (argc>1)
    {
      cout<<"[INFO] Tinka tik failai, kurie baigiasi (.txt)"<<endl;
      string failas = argv[1], line;
      ifstream fd(failas);
      int n;
      cout<<"[INPUT] Iveskite eiluciu skaiciu: ";
      cin>>n;
      if(fd.is_open())
      {
        for(int i=0; i<n; i++)
        {
          getline(fd,line);
          input2.push_back(line);
        }
        fd.close();
      }
      else
      {
        cout<<"[ERROR] Failas nerastas"<<endl;
        return 1;
      }
      string sum;
      for(const auto& in : input2)
      {
        sum+=in;
      }
    auto startPoint = chrono::high_resolution_clock::now();
    vector<uint8_t> hashValue = betterHash(sum);
    string hexHash = toHexString(hashValue);
    auto endPoint = chrono::high_resolution_clock::now();
    auto procedureTime = chrono::duration_cast<chrono::microseconds>(endPoint - startPoint).count();
    cout<<"[INFO] Maišos funkcijos veikimo trukmė: " << procedureTime/1000000.0<< " sekundes"<<endl;
    cout <<"[OUTPUT] Maišos reikšmė (hash): " << hexHash << endl;
      /*
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
      */
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
    cout<<"[INFO] programos veikimo pabaiga"<<endl; 
    return 0;
}
