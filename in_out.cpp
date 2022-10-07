#include "structure.h"
#include "in_out.h"
#include "functions.h"

duomenys ivedimas()
{ 
    duomenys asmuo;
    asmuo.nd_rez.reserve(1000);
    int nd_rezultatai = 0;
    int random_sk;
    string choice;
    cout << "Parasykite varda (iveskite 0, jei norite baigti ivedima): ";
    cin >> asmuo.vardas;
    tikrinti_str(asmuo.vardas);

    if (asmuo.vardas == "0")
        return asmuo;

    cout << "Parasykite pavarde: ";
    cin >> asmuo.pavarde;
    tikrinti_str(asmuo.pavarde);
    cout << "Ar norite, kad namu darbu rezultatai butu ivedami uz jus atsitiktinai?(Jei taip, iveskite t, jei ne - n) ";
    cin >> choice;
    const string t = "t"; const string n = "n";
    string pasirinkimas = tikrinti_ivesti(choice, t, n);
    
    if (pasirinkimas == "t")
    {
        cout << "Kiek atsitiktiniu namu darbu rezultatu norite, kad butu sukurta? ";
        cin >> random_sk;
        tikrinti_int(random_sk);
        random_paz_generavimas(asmuo, random_sk);
    }
           
    if (pasirinkimas == "n")
    {
        cout << "Atskirdami su enter parasykite namu darbu rezultatus (noredami uzbaigti namu darbu rez. ivedima, irasykite 0) " << endl;
        while (true)
        {
            if (pasirinkimas == "n")
            {
                cin >> nd_rezultatai;
                tikrinti_int(nd_rezultatai);
                if (nd_rezultatai == 0)
                    break;
            }

            if (nd_rezultatai >= 1 && nd_rezultatai <= 10)
            {
                asmuo.nd_rez.push_back(nd_rezultatai);
            }
            else
                cout << "Balas turi buti desimtbaleje sistemoje! Iveskite is naujo" << endl;
        }
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

vector<string> isskaidymas(string eil)
{
    stringstream ss(eil);
    string word;
    vector<string> my_vector;
    while (ss >> word) 
        my_vector.push_back(word);
    
    return my_vector;
}

string read_line(ifstream& open_f) 
{
    string eil;
    try
    {
        getline(open_f, eil);
    }
    catch (const ifstream::failure& e) 
    {
        cout << "Klaida nuskaitant duomenis is failo: " << e.what() << endl;
        exit(0);
    }
    return eil;
}

int get_nd_count(ifstream& open_f) 
{
    string temp;
    vector<string> first_line;
    temp = read_line(open_f);
    first_line = isskaidymas(temp);
    int count = 0;
    for (string str : first_line) 
    {
        if (str.find("ND") != string::npos)
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

void read_and_fill(vector<duomenys>& data) 
{
    int nd_count = 0;
    string eil;
    ifstream open_f;
    string file_name;
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

    nd_count = get_nd_count(open_f);

    while (open_f) 
    {
        if (!open_f.eof())
        {
            eil = read_line(open_f);
            vector<string>eil_iskaidyta = isskaidymas(eil);
            duomenys temp_data;

            temp_data.vardas = eil_iskaidyta[0];
            temp_data.pavarde = eil_iskaidyta[1];
            temp_data.nd_rez.reserve(nd_count);

            for (int idx = 0; idx < nd_count; idx++)
            {
                tikrinti_faila(eil_iskaidyta[idx + 2]);
                temp_data.nd_rez.push_back(stoi(eil_iskaidyta[idx + 2]));
                 
            }
            tikrinti_faila(eil_iskaidyta[eil_iskaidyta.size() - 1]);
            temp_data.egz_rez = stoi(eil_iskaidyta[eil_iskaidyta.size() - 1]);
                 
            temp_data.mediana = mediana(temp_data.nd_rez, temp_data.egz_rez);
            temp_data.vidurkis = vidurkis(temp_data.nd_rez, temp_data.egz_rez);
            data.push_back(temp_data);
        }
        else 
            break;
    }
    open_f.close();
}

void fill_buffer(vector<duomenys> data, stringstream& buffer) 
{
    buffer << std::left << std::setw(20) << "Vardas" << std::setw(20) << "Pavarde" << std::setw(20) << "Galutinis (Vid.)" << std::setw(20) << "Galutinis (Med.)" << endl;
    buffer << "-----------------------------------------------------------------------" << endl;
    for (duomenys& entry : data) 
        buffer << std::left << std::setw(20) << entry.vardas << std::setw(20) << entry.pavarde << std::setw(20) << fixed << setprecision(2) << entry.vidurkis << std::setw(20) << entry.mediana << endl;  
}

void write_buffer(stringstream& buffer) 
{
    ofstream out_f("rezultatai.txt");
    out_f << buffer.str();
    out_f.close();
}

void read_file()
{
    stringstream out_buff;
    vector<duomenys> data;
    read_and_fill(data);
    sort(data.begin(), data.end(), compareAscending);
    fill_buffer(data, out_buff);
    write_buffer(out_buff);
}

void isvedimas_i_ekrana(vector <duomenys>& st_sar, string txt)
{
    cout << std::left << std::setw(20) << "Pavarde" << std::setw(20) << "Vardas" << std::setw(20) << fixed << setprecision(2) << txt << endl;
    cout << "-----------------------------------------------------------------------" << endl;
    for (int i = 0; i < st_sar.size(); i++)
        cout << std::left << std::setw(20) << st_sar[i].pavarde << std::setw(20) << st_sar[i].vardas << std::setw(20) << st_sar[i].galutinis << endl;
}