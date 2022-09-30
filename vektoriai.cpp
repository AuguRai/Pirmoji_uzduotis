#include "MyLib.h"

struct duomenys
{
  string vardas;
  string pavarde;
  vector <int> nd_rez;
  int egz_rez;
  double galutinis;
};

duomenys ivedimas();
string to_lower(string input);
bool ar_raide(string s);
void tikrinti_str(string& input);
void tikrinti_int(int& input);
void galutinis_bal(vector <duomenys> &stud_sar, string& txt);
void isvedimas(vector <duomenys> &stud_sar, string txt);
string to_lower(string input);

int main()
{
  int st_sk = 0;
  string txt;
  vector <duomenys> stud_sar;
  while (true)
  {
    stud_sar.push_back(ivedimas());
    if(stud_sar[st_sk].vardas == "0")
    {
      stud_sar.erase(stud_sar.begin()+st_sk);
      break;
    }      
    st_sk++;
  }
  if(st_sk != 0)
  {
    galutinis_bal(stud_sar, txt);
    isvedimas(stud_sar, txt);
  }
  else
    cout << "Programos pabaiga" << endl;
  return 0;
}

duomenys ivedimas()
{
  using hrClock = std::chrono::high_resolution_clock;
  std::mt19937 mt(static_cast<long unsigned int> (hrClock::now().time_since_epoch().count()));
  std::uniform_int_distribution<int> dist(1,10);
  duomenys asmuo;
  asmuo.nd_rez.reserve(1000);
  int nd_rezultatai = 0;
  int random_sk;
  string ats;
  cout << "Parasykite varda (iveskite 0, jei norite baigti ivedima): ";
  cin >> asmuo.vardas;
  tikrinti_str(asmuo.vardas);
  if (asmuo.vardas == "0")
    return asmuo;
  cout << "Parasykite pavarde: ";
  cin >> asmuo.pavarde;
  tikrinti_str(asmuo.pavarde);
  cout << "Ar norite, kad namu darbu rezultatai butu ivedami uz jus atsitiktinai?(Iveskite Taip/Ne) ";
  while (true)
  {
    cin >> ats;
    if (to_lower(ats) == "taip" || to_lower(ats) == "ne")
      break;
    else
      cout << "Ivedete neteisingai! Iveskite tik 'taip' arba 'ne'" << endl;
  }
  string pasirinkimas = to_lower(ats);

  if (pasirinkimas == "taip")
  {
    cout << "Kiek atsitiktiniu namu darbu rezultatu norite, kad butu sukurta? ";
    cin >> random_sk;
    tikrinti_int(random_sk);
  }
  if (pasirinkimas == "ne")
    cout << "Atskirdami su enter parasykite namu darbu rezultatus (noredami uzbaigti namu darbu rez. ivedima, irasykite 0) " << endl;

  while (true)
  {
    if (pasirinkimas == "ne")
    {
      cin >> nd_rezultatai;
      tikrinti_int(nd_rezultatai);
      if (nd_rezultatai == 0)
        break;
    }
    if (pasirinkimas == "taip")
    {
      if (asmuo.nd_rez.size() == random_sk)
        break;
      nd_rezultatai = dist(mt);
    }

    if (nd_rezultatai >= 1 && nd_rezultatai <= 10)
    {
      asmuo.nd_rez.push_back(nd_rezultatai);
    }
    else
      cout << "Balas turi buti desimtbaleje sistemoje! Iveskite is naujo" << endl;
  }
  
  if (pasirinkimas == "taip")
  {
    asmuo.egz_rez = dist(mt);
  }
  else
  {
    cout << "Parasykite egzamino rezultata: ";
    while (true)
    {
      cin >> asmuo.egz_rez;
      if (asmuo.egz_rez >= 1 && asmuo.egz_rez <= 10)
      {
        tikrinti_int(asmuo.egz_rez);
        break;
      }
      else
        cout << "Balas turi buti desimtbaleje sistemoje! Iveskite is naujo" << endl;
    }
  }
    asmuo.nd_rez.shrink_to_fit();
    return asmuo;
}

string to_lower(string input)
{
  string choice = "";
  for (int i = 0; i < input.length(); i++)
  {
    choice.push_back(tolower(input[i]));
  }
  return choice;
}

bool ar_raide(string s)
{
  int count = 0;
  for (int i = 0; i < s.length(); i++)
    if (isalpha(s[i]) != 0)
        count++;
  
  if (count == s.length())
    return false;
  
  return true;
}

void tikrinti_str(string& input)
{
  bool tikrinti;
  while (true)
  {
    if(input == "0")
      break;
    tikrinti = ar_raide(input);
    if (tikrinti == true)
    {
      cin.clear();
      cout << "Pasitikrinkite savo ivesta atsakyma!" << endl;
      cin >> input;
    }
    if (tikrinti == false)
      break;
  }
}

void tikrinti_int(int& input)
{
  while (true)
  {
    if (cin.fail() || input < 0)
    {
      cin.clear();
      cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      cout << "Pasitikrinkite savo ivesta atsakyma!" << endl;
      cin >> input;
    }
    if (!cin.fail())
      break;
  }
}

void galutinis_bal(vector <duomenys> &stud_sar, string& txt)
{
  double vid;
  string choice;
  double rez, vidurys;
  cout << "Pasirinkite, koki galutini rezultata norite suzinoti. Iveskite mediana arba vidurkis " << endl;
  while (true)
  {
    cin >> choice;
    if (to_lower(choice) == "mediana" || to_lower(choice) == "vidurkis")
      break;
    else
      cout << "Ivedete neteisingai! Iveskite tik 'mediana' arba 'vidurkis'" << endl;
  }

  for (int i = 0; i < stud_sar.size(); i++)
  {
    if (stud_sar[i].nd_rez.size() == 0)
    {
      stud_sar[i].galutinis = 0;
      return;
    }
    if (to_lower(choice) == "vidurkis")
    {
      txt = "Galutinis (Vid.)";
      rez = 0;
      for (int j = 0; j < stud_sar[i].nd_rez.size(); j++)
        rez = rez + stud_sar[i].nd_rez[j];
      vid = rez / stud_sar[i].nd_rez.size();
    }
    if (to_lower(choice) == "mediana")
    {
      txt = "Galutinis (Med.)";
      sort(stud_sar[i].nd_rez.begin(), stud_sar[i].nd_rez.end());
      vidurys = int(stud_sar[i].nd_rez.size() / 2);
      if (stud_sar[i].nd_rez.size() % 2 != 0 && stud_sar[i].nd_rez.size() != 1)
        vid = stud_sar[i].nd_rez[vidurys];
      if (stud_sar[i].nd_rez.size() == 1)
        vid = stud_sar[i].nd_rez[0];
      if (stud_sar[i].nd_rez.size() % 2 == 0)
        vid = double(stud_sar[i].nd_rez[vidurys] + stud_sar[i].nd_rez[vidurys - 1]) / 2;
    }
    stud_sar[i].galutinis = 0.4 * vid + 0.6 * stud_sar[i].egz_rez;
  }
}

void isvedimas(vector <duomenys> &st_sar, string txt)
{
  cout << std::left << std::setw(20) << "Pavarde" << std::setw(20) << "Vardas" << std::setw(20) << fixed << setprecision(2) << txt << endl;
  cout << "-----------------------------------------------------------------------" << endl;
  for (int i = 0; i < st_sar.size(); i++)
    cout << std::left << std::setw(20) << st_sar[i].pavarde << std::setw(20) << st_sar[i].vardas << std::setw(20) << st_sar[i].galutinis << endl;
}
