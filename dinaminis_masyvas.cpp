#include "MyLib.h"

struct duomenys
{
  string vardas;
  string pavarde;
  int* nd_rez;
  int egz_rez;
  int nd_sk;
  double galutinis;
};

duomenys ivedimas();
string to_lower(string input);
bool ar_raide(string s);
void tikrinti_str(string& input);
void tikrinti_int(int& input);
void galutinis_bal(duomenys stud_sar[], int st_sk, string& txt);
void isvedimas(duomenys stud_sar[], int st_sk, string txt);
string to_lower(string input);

int main()
{
  int st_sk = 0;
  int nd_sk = 0;
  string txt;
  duomenys temp2;
  duomenys *stud_sar = nullptr;

  while(true)
  {
    temp2 = ivedimas();
    if (temp2.vardas == "0")
      break;
    st_sk++;

    if (stud_sar == nullptr) 
    {
      stud_sar = new duomenys[st_sk];
      stud_sar[st_sk - 1] = temp2;
    } 
    else 
    {
      duomenys* temp_stud_sar = new duomenys[st_sk];
      
      for (int idx = 0; idx < st_sk - 1; idx++)
        temp_stud_sar[idx] = stud_sar[idx];
      
      temp_stud_sar[st_sk - 1] = temp2;
      delete[] stud_sar;
      stud_sar = temp_stud_sar;
    }
  }
  if(st_sk != 0)
  {
    galutinis_bal(stud_sar, st_sk, txt);
    isvedimas(stud_sar, st_sk, txt);
  }
  else
    cout << "Programos pabaiga" << endl;
  
  for (int j = 0; j < st_sk; j++)
  {
    if (stud_sar[j].nd_rez != nullptr)
        delete[] stud_sar[j].nd_rez;
  }
  delete[] stud_sar;
}

duomenys ivedimas()
{
  duomenys asmuo;
  using hrClock = std::chrono::high_resolution_clock;
  std::mt19937 mt(static_cast<long unsigned int> (hrClock::now().time_since_epoch().count()));
  std::uniform_int_distribution<int> dist(1,10);
  int nd_rezultatai = 0;
  int nd_sk = 0;
  int random_sk;
  string ats;
  asmuo.nd_rez = nullptr;
  cout << "Parasykite varda (noredami uzbaigti duomenu ivedima, parasykite 0) ";
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
      if (nd_sk == random_sk)
        break;
      nd_rezultatai = dist(mt);
    }
    if (nd_rezultatai >= 1 && nd_rezultatai <= 10)
    {
      nd_sk++;
      if (asmuo.nd_rez == nullptr)
      {
        asmuo.nd_rez = new int[nd_sk];
        asmuo.nd_rez[0] = nd_rezultatai;
        asmuo.nd_sk = nd_sk;
      }
      else
      {
        int* temp = new int[nd_sk];
        for (int i = 0; i < nd_sk - 1; i++)
          temp[i] = asmuo.nd_rez[i];
        temp[nd_sk - 1] = nd_rezultatai;
        delete[] asmuo.nd_rez;
        asmuo.nd_rez = temp;
        asmuo.nd_sk = nd_sk;
      }
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

void galutinis_bal(duomenys stud_sar[], int st_sk, string& txt)
{
  double vid;
  string choice;
  int kiek;
  double rez;
  int vidurys;
  cout << "Pasirinkite, koki galutini rezultata norite suzinoti. Iveskite mediana arba vidurkis " << endl;
  while (true)
  {
    cin >> choice;
    if (to_lower(choice) == "mediana" || to_lower(choice) == "vidurkis")
      break;
    else
      cout << "Ivedete neteisingai! Iveskite tik 'mediana' arba 'vidurkis'" << endl;
  }
  for (int i = 0; i < st_sk; i++)
  {
    kiek = stud_sar[i].nd_sk;
    if (kiek == 0)
    {
      stud_sar[i].galutinis = 0;
    }
    else
    {
      if (to_lower(choice) == "vidurkis")
      {
        txt = "Galutinis (Vid.)";
        rez = 0;
        for (int j = 0; j < kiek; j++)
          rez = rez + stud_sar[i].nd_rez[j];
        
        vid = rez / kiek;
      }
      if (to_lower(choice) == "mediana")
      {
        txt = "Galutinis (Med.)";
        sort(stud_sar[i].nd_rez, stud_sar[i].nd_rez + kiek);
        vidurys = kiek / 2;
        if (kiek % 2 != 0 && kiek != 1)
          vid = stud_sar[i].nd_rez[int(vidurys)];
        if (kiek == 1)
          vid = stud_sar[i].nd_rez[0];
        if (kiek % 2 == 0)
          vid = double(stud_sar[i].nd_rez[int(vidurys)] + stud_sar[i].nd_rez[int(vidurys) - 1]) / 2;
      }
      stud_sar[i].galutinis = 0.4 * vid + 0.6 * stud_sar[i].egz_rez;
    }     
  }
}

void isvedimas(duomenys st_sar[], int st_sk, string txt)
{
  cout << std::left << std::setw(20) << "Pavarde" << std::setw(20) << "Vardas" << std::setw(20) << fixed << setprecision(2) << txt << endl;
  cout << "-----------------------------------------------------------------------" << endl;
  for (int i = 0; i < st_sk; i++)
    cout << std::left << std::setw(20) << st_sar[i].pavarde << std::setw(20) << st_sar[i].vardas << std::setw(20) << st_sar[i].galutinis << endl;
}
