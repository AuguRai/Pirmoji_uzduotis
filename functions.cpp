#include "structure.h"
#include "functions.h"
#include "in_out.h"


void random_paz_generavimas(duomenys& asmuo, int random_sk)
{
    using hrClock = std::chrono::high_resolution_clock;
    std::mt19937 mt(static_cast<long unsigned int> (hrClock::now().time_since_epoch().count()));
    std::uniform_int_distribution<int> dist(0, 10);
    for (int i = 0; i < random_sk; i++)
    {
        asmuo.nd_rez.push_back(dist(mt));
    }
    asmuo.egz_rez = dist(mt);
}

int get_nd_count(ifstream& open_f)
{
    string temp, word;
    temp = read_line(open_f);
    stringstream ss(temp);
    int count = 0;
    while (ss >> word)
    {
        if (word.find("ND") != string::npos)
            count++;
    }
    return count;
}

bool compareAscending(const duomenys& data1, const duomenys& data2)
{
    if (data1.vardas.compare(data2.vardas) == 0)
    {
        if (data1.pavarde.compare(data2.pavarde) <= 0)
            return true;

        else
            return false;
    }
    if (data1.vardas.compare(data2.vardas) < 0)
        return true;

    else
        return false;

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

bool ar_skaicius(string s)
{
    for (int i = 0; i < s.length(); i++)
        if (isdigit(s[i]) == 0)
            return false;
    return true;
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

void tikrinti_failo_vidu(string eil_isskaidyta)
{
    string msg = "Neteisingai ivesti duomenys faile ";
    try
    {
        if (ar_skaicius(eil_isskaidyta) == false)
        {
            throw msg;
        }
        else
            return;
    }
    catch (string msg)
    {
        cout << msg;
        exit(0);
    }
}

void ivesti_ir_tikrinti_failo_pav(string& file_name)
{
    ifstream open_f;
    open_f.exceptions(ifstream::failbit | ifstream::badbit);

    try
    {
        cout << "Iveskite failo pavadinima ";
        cin >> file_name;
        open_f.open(file_name);
    }
    catch (const ifstream::failure& e)
    {
        cout << "Neatidare failo. Klaida: " << e.what() << endl;
        exit(0);
    }
    open_f.close();
}

void tikrinti_failo_pav(string file_name)
{
    ifstream open_f;
    open_f.exceptions(ifstream::failbit | ifstream::badbit);
    try
    {
        open_f.open(file_name);
    }
    catch (const ifstream::failure& e)
    {
        cout << "Neatidare failo. Klaida: " << e.what() << endl;
        exit(0);
    }
    open_f.close();
}

string tikrinti_ivesti(string ats, const string var_1, const string var_2)
{
    string maz_raid;
    string msg = "Ivedete neteisingai! Iveskite tik ";
    while (true)
    {
        try
        {
            if (to_lower(ats).compare(var_1) == 0 || to_lower(ats).compare(var_2) == 0)
            {
                maz_raid = to_lower(ats);
                return maz_raid;
            }
            else
            {
                cin.clear();
                throw msg;
            }
        }
        catch (string msg)
        {
            cout << msg << var_1 << " arba " << var_2 << endl;
            cin >> ats;
        }
    }
}

void tikrinti_str(string& input)
{
    bool tikrinti;
    string msg = "Pasitikrinkite savo ivesta atsakyma!";
    while (true)
    {
        try
        {
            if (input == "0")
                break;
            tikrinti = ar_raide(input);
            if (tikrinti == true)
            {
                cin.clear();
                throw msg;
            }
            if (tikrinti == false)
                break;
        }
        catch (string msg)
        {
            cout << msg << endl;
            cin >> input;
        }
    }
}

void tikrinti_int(int& input)
{
    string msg = "Pasitikrinkite savo ivesta atsakyma!";
    while (true)
    {
        try
        {
            if (cin.fail() || input < 0)
            {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                throw msg;
            }
            if (!cin.fail())
                break;
        }
        catch (string msg)
        {
            cout << msg << endl;
            cin >> input;
        }
    }
}

double vidurkis(vector <int> nd_rez, int egz_rez)
{
    double rez = 0;
    double vid = 0;
    double galutinis = 0;

    if (nd_rez.size() == 0)
        return 0;

    for (int j = 0; j < nd_rez.size(); j++)
        rez = rez + nd_rez[j];


    vid = rez / nd_rez.size();
    galutinis = 0.4 * vid + 0.6 * egz_rez;

    return galutinis;
}

double mediana(vector <int> nd_rez, int egz_rez)
{
    double rez = 0;
    double med = 0;
    double galutinis = 0;

    if (nd_rez.size() == 0)
        return 0;

    sort(nd_rez.begin(), nd_rez.end());
    med = int(nd_rez.size() / 2);

    if (nd_rez.size() % 2 != 0)
        med = nd_rez[med];

    else
        med = double(nd_rez[med] + nd_rez[med - 1]) / 2;

    galutinis = 0.4 * med + 0.6 * egz_rez;
    return galutinis;
}