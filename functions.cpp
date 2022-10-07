#include "structure.h"
#include "functions.h"


void random_paz_generavimas(duomenys& asmuo, int random_sk)
{
    using hrClock = std::chrono::high_resolution_clock;
    std::mt19937 mt(static_cast<long unsigned int> (hrClock::now().time_since_epoch().count()));
    std::uniform_int_distribution<int> dist(1, 10);
    for (int i = 0; i < random_sk; i++)
    {
        asmuo.nd_rez.push_back(dist(mt));
    }
    asmuo.egz_rez = dist(mt);
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

void tikrinti_faila(string eil_isskaidyta)
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

string tikrinti_ivesti(string ats, const string yes, const string no)
{
    string maz_raid;
    string msg = "Ivedete neteisingai! Iveskite tik ";
    while (true)
    {
        try
        {
            if (to_lower(ats).compare(yes) == 0 || to_lower(ats).compare(no) == 0)
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
            cout << msg << yes << " arba " << no << endl;
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
        catch(string msg)
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
        catch(string msg)
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
    
    rez = 0;
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

    if (nd_rez.size() % 2 != 0 && nd_rez.size() != 1)
        med = nd_rez[med];
    if (nd_rez.size() == 1)
        med = nd_rez[0];
    if (nd_rez.size() % 2 == 0)
        med = double(nd_rez[med] + nd_rez[med - 1]) / 2;

    galutinis = 0.4 * med + 0.6 * egz_rez;

    return galutinis;
}
