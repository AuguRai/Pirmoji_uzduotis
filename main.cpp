#include "structure.h"
#include "in_out.h"
#include "functions.h"

int main()
{
    int st_sk = 0;
    string txt, choice, frst_choice;
    vector <duomenys> stud_sar;
    cout << "Ar norite ivesti duomenis, ar juos nuskaityti? Jei nuskaityti - Iveskite n, jei ivesti - iveskite i " << endl;
    cin >> frst_choice;
    const string nusk = "n"; string iv = "i";
    choice = tikrinti_ivesti(frst_choice, nusk, iv);
  
    if (to_lower(choice) == "n")
        read_file();

    if (to_lower(choice) == "i")
    {
        while (true)
        {
            stud_sar.push_back(ivedimas());
            if (stud_sar[st_sk].vardas == "0")
            {
                stud_sar.erase(stud_sar.begin() + st_sk);
                break;
            }
            st_sk++;
        }
        if (st_sk != 0)
        {
            cout << "Pasirinkite, koki galutini rezultata norite suzinoti. Iveskite mediana arba vidurkis " << endl;
            while (true)
            {
               cin >> choice;
               if (to_lower(choice) == "mediana" || to_lower(choice) == "vidurkis")
                   break;
               else
                   cout << "Ivedete neteisingai! Iveskite tik 'mediana' arba 'vidurkis'" << endl;
            }
            if (to_lower(choice) == "vidurkis")
            {
                txt = "Galutinis vidurkis";
                for (int i = 0; i < stud_sar.size(); i++)
                    stud_sar[i].galutinis = mediana(stud_sar[i].nd_rez, stud_sar[i].egz_rez);         
            }
            if (to_lower(choice) == "mediana")
            {
                txt = "Galutinis mediana";
                for (int i = 0; i < stud_sar.size(); i++)
                    stud_sar[i].galutinis = vidurkis(stud_sar[i].nd_rez, stud_sar[i].egz_rez);
            }
            isvedimas_i_ekrana(stud_sar, txt);
        }
        else
            cout << "Programos pabaiga" << endl;
    }   
    return 0;
}