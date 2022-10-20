#include "structure.h"
#include "in_out.h"
#include "functions.h"

int main()
{
    int st_sk = 0;
    string txt, choice, frst_choice;
    vector <duomenys> stud_sar;
    vector <duomenys> vargsiukai;
    cout << "Ar norite ivesti duomenis, juos nuskaityti is failo ar automatiskai sugeneruoti failus su atsitiktiniais duomenimis? Jei nuskaityti - Iveskite n, jei ivesti - iveskite i, jei automatiskai - a " << endl;
    cin >> frst_choice;
    const string nusk = "n"; string iv = "i"; string gen = "a";
    choice = tikrinti_ivesti(frst_choice, nusk, iv, gen);
  
    if (to_lower(choice) == "a")
    {
        string first_file = "Kursiokai1000.txt";
        string second_file = "Kursiokai10000.txt";
        string third_file = "Kursiokai100000.txt";
        string fourth_file = "Kursiokai1000000.txt";
        string fifth_file = "Kursiokai10000000.txt";

        cout << first_file << endl;
        failu_sukurimas(first_file, 1000);
        failu_nuskaitymas(first_file, stud_sar);
        vargsiukai = grouping(stud_sar);
        auto start = std::chrono::high_resolution_clock::now();
        write_to_file(stud_sar, "Kursiokai1000kietieji.txt");
        write_to_file(vargsiukai, "Kursiokai1000vargsiukai.txt");
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = end - start;
        cout << "Isvedimas i 2 naujus failus truko: " << diff.count() << endl;
        cout << endl;

        cout << second_file << endl;
        failu_sukurimas(second_file, 10000);
        failu_nuskaitymas(second_file, stud_sar);
        vargsiukai = grouping(stud_sar);
        start = std::chrono::high_resolution_clock::now();
        write_to_file(stud_sar, "Kursiokai10000kietieji.txt");
        write_to_file(vargsiukai, "Kursiokai10000vargsiukai.txt");
        end = std::chrono::high_resolution_clock::now();
        diff = end - start;
        cout << "Isvedimas i 2 naujus failus truko: " << diff.count() << endl;
        cout << endl;

        cout << third_file << endl;
        failu_sukurimas(third_file, 100000);
        failu_nuskaitymas(third_file, stud_sar);
        vargsiukai = grouping(stud_sar);
        start = std::chrono::high_resolution_clock::now();
        write_to_file(stud_sar, "Kursiokai100000kietieji.txt");
        write_to_file(vargsiukai, "Kursiokai100000vargsiukai.txt");
        end = std::chrono::high_resolution_clock::now();
        diff = end - start;
        cout << "Isvedimas i 2 naujus failus truko: " << diff.count() << endl;
        cout << endl;
      
        cout << fourth_file << endl;
        failu_sukurimas(fourth_file, 1000000);
        failu_nuskaitymas(fourth_file, stud_sar);
        vargsiukai = grouping(stud_sar);
        start = std::chrono::high_resolution_clock::now();
        write_to_file(stud_sar, "Kursiokai1000000kietieji.txt");
        write_to_file(vargsiukai, "Kursiokai1000000vargsiukai.txt");
        end = std::chrono::high_resolution_clock::now();
        diff = end - start;
        cout << "Isvedimas i 2 naujus failus truko: " << diff.count() << endl;
        cout << endl;
        
        cout << fifth_file << endl;
        failu_sukurimas(fifth_file, 10000000);
        failu_nuskaitymas(fifth_file, stud_sar);
        vargsiukai = grouping(stud_sar);
        start = std::chrono::high_resolution_clock::now();
        write_to_file(stud_sar, "Kursiokai10000000kietieji.txt");
        write_to_file(vargsiukai, "Kursiokai10000000avargsiukai.txt");
        end = std::chrono::high_resolution_clock::now();
        diff = end - start;
        cout << "Isvedimas i 2 naujus failus truko: " << diff.count() << endl;
        cout << endl;
    }

    if (to_lower(choice) == "n")
    {
        string file_name = "";
        ivesti_ir_tikrinti_failo_pav(file_name);
        failu_nuskaitymas(file_name, stud_sar);
        sort(stud_sar.begin(), stud_sar.end(), compareAscending);
        write_to_file(stud_sar, "Rezultatai.txt");
    }
        
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
