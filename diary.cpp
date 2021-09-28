#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
  int num_days[12]{31,28,31,30,31,30,31,31,30,31,30,31};
  int month = 1;
  vector<vector<string>> diary;
  int q;
  cin >> q;
  for (int j=0; j < q; j++)
  {
    int i;
    string comd, work;
    cin >> comd;
    if (comd == "DUMP")
    { 
      cin >> i;
      int num_works = diary[i-1].size();
      cout << num_works << ' ';
      for (int j = 0; j < num_works; j++)
      {
        cout << diary[i-1][j] << ' ';
      }
      cout << '\n';
    }
    else if (comd == "ADD")
    {
      cin >> i >> work;
      diary[i-1].push_back(work);
    }
    else 
    {
      int next_month = (month + 1) / 12;
      int ndn = num_days[next_month];
      if (ndn < num_days[month])
      {
        for (j = ndn - 1; j < num_days[month]; j++)
        {
          diary[ndn - 1].insert(end(diary[ndn - 1]), begin(diary[j]), end(diary[j]));
          diary[j].clear();
        }
      }
      else
      {
        diary.resize(num_days[month] - ndn);
      }
    }
  }   
  return 0;
}