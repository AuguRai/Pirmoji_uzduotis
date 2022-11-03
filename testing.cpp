#include "testing.h";
#include "structure.h"
#include "in_out.h"
#include "functions.h"

void failu_sukurimas_test(string file_name, int size)
{
    auto start = std::chrono::high_resolution_clock::now();
    failu_sukurimas(file_name, size);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    cout << "Failo sukurimas truko: " << diff.count() << endl;
}

void nuskaitymo_test_vec(string file_name, vector<duomenys> &duom_sar)
{
    auto start = std::chrono::high_resolution_clock::now();
    read_and_fill_vector(duom_sar, file_name);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;   
    cout << "Failo nuskaitymas truko: " << diff.count() << endl;
}

void nuskaitymo_test_list(string file_name, list<duomenys> &duom_sar)
{
    auto start = std::chrono::high_resolution_clock::now();
    read_and_fill_list(duom_sar, file_name);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    cout << "Failo nuskaitymas truko: " << diff.count() << endl;
}

void grouping_test_vec(vector <duomenys> &vargsiukai, vector <duomenys> &stud_sar)
{
    auto start = std::chrono::high_resolution_clock::now();
    vargsiukai = grouping_by_vec(stud_sar);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    cout << "Failo surusiavimas truko: " << diff.count() << endl;
}

void grouping_test_list(list <duomenys>& vargsiukai, list <duomenys>& stud_sar)
{
    auto start = std::chrono::high_resolution_clock::now();
    vargsiukai = grouping_by_list(stud_sar);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    cout << "Failo surusiavimas truko: " << diff.count() << endl;
}

void isvedimas_i_failus_test(vector <duomenys> &vargsiukai, vector <duomenys> &stud_sar)
{
    int size = stud_sar.size() + vargsiukai.size();
    auto start = std::chrono::high_resolution_clock::now();
    write_to_file(stud_sar, "Galvociai" + std::to_string(size) + ".txt");
    write_to_file(vargsiukai, "Vargsiukai" + std::to_string(size) + ".txt");
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    cout << "Isvedimas i 2 naujus failus truko: " << diff.count() << endl;
}

void testavimas(string file_name, string lyginimo_choice, string data_gen_choice, int size)
{
    vector <duomenys> stud_sar;
    vector <duomenys> vargsiukai;

    if (lyginimo_choice == "t")
    {
        if(data_gen_choice == "t")
            failu_sukurimas(file_name, size);

        list <duomenys> list_stud_sar;
        list <duomenys> list_vargsiukai;

        cout << "Su list: " << endl;
        nuskaitymo_test_list(file_name, list_stud_sar);
        grouping_test_list(list_vargsiukai, list_stud_sar);
        list_stud_sar.clear();
        list_vargsiukai.clear();
        cout << endl;

        cout << "Su vektorium: " << endl;
        nuskaitymo_test_vec(file_name, stud_sar);
        grouping_test_vec(vargsiukai, stud_sar);
        cout << endl;
        
        write_to_file(stud_sar, "Galvociai" + std::to_string(size) + ".txt");
        write_to_file(vargsiukai, "Vargsiukai" + std::to_string(size) + ".txt");
    }
    else
    {
        if (data_gen_choice == "t")
            failu_sukurimas_test(file_name, size);

        nuskaitymo_test_vec(file_name, stud_sar);
        grouping_test_vec(vargsiukai, stud_sar);
        isvedimas_i_failus_test(vargsiukai, stud_sar);
        cout << endl;
    }
}