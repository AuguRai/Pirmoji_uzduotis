#include "structure.h"
#include "in_out.h"
#include "functions.h"
#include "testing.h"

int main()
{
	string ats1;
	vector <duomenys> stud_sar;

	cout << "Ar norite, kad programos veikimas butu testuojamas? Jei taip - iveskite t, jei ne - n ";
	cin >> ats1;
	ats1 = tikrinti_ivesti(ats1, "t", "n");
	if (ats1 == "t")
	{
		string ats3, ats4;
		cout << "Ar norite, kad butu sukuriami 5 atsitiktinai sugeneruoti failai? Jei taip, iveskite t, jei ne - n ";
		cin >> ats3;
		ats3 = tikrinti_ivesti(ats3, "t", "n");
		cout << "Ar norite, kad list ir vector tipo konteineriai butu palyginti? Jei norite, kad butu testuojamas tik vektorius, iveskite n, jei norite, kad butu atliktas vector ir list palyginimas, iveskite t ";
		cin >> ats4;
		ats4 = tikrinti_ivesti(ats4, "t", "n");
		cout << endl;

		cout << "1000 duomenu" << endl;
		testavimas("Kursiokai1000.txt", ats4, ats3, 1000);
		cout << "10000 duomenu" << endl;
		testavimas("Kursiokai10000.txt", ats4, ats3, 10000);
		cout << "100000 duomenu" << endl;
		testavimas("Kursiokai100000.txt", ats4, ats3, 100000);
		cout << "1000000 duomenu" << endl;
		testavimas("Kursiokai1000000.txt", ats4, ats3, 1000000);
		cout << "10000000 duomenu" << endl;
		testavimas("Kursiokai10000000.txt", ats4, ats3, 10000000);
	}
	else
	{
		string ats2;
		cout << "Ar norite ivesti duomenis, ar juos nuskaityti is failo? Jei nuskaityti - iveskite n, jei ivesti - iveskite i " << endl;
		cin >> ats2;
		ats2 = tikrinti_ivesti(ats2, "i", "n");
		if (to_lower(ats2) == "n")
		{
			string file_name = "";
			ivesti_ir_tikrinti_failo_pav(file_name);
			read_and_fill_vector(stud_sar, file_name);
			sort(stud_sar.begin(), stud_sar.end(), compareAscending);
			write_to_file(stud_sar, "Rezultatai.txt");
		}
		if (to_lower(ats2) == "i")
		{
			int st_sk = 0;
			string txt, galut_choice;
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
			        cin >> galut_choice;
			        if (to_lower(galut_choice) == "mediana" || to_lower(galut_choice) == "vidurkis")
			            break;
			        else
			            cout << "Ivedete neteisingai! Iveskite tik 'mediana' arba 'vidurkis'" << endl;
			    }
			    if (to_lower(galut_choice) == "vidurkis")
			    {
			        txt = "Galutinis vidurkis";
			        for (int i = 0; i < stud_sar.size(); i++)
			            stud_sar[i].galutinis = mediana(stud_sar[i].nd_rez, stud_sar[i].egz_rez);
			    }
			    if (to_lower(galut_choice) == "mediana")
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
	}
}