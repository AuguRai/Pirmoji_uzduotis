#pragma once
#include <iostream>
#include <list>
#include <vector>
#include "structure.h"

using std::cout;
using std::cin;
using std::endl;
using std::list;
using std::string;
using std::vector;

void failu_sukurimas_test(string file_name, int size);
void nuskaitymo_test_vec(string file_name, vector<duomenys> &duom_sar);
void grouping_test_list(list <duomenys>& vargsiukai, list <duomenys>& stud_sar);
void grouping_test_vec(vector <duomenys>& vargsiukai, vector <duomenys>& stud_sar);
void isvedimas_i_failus_test(vector <duomenys> &vargsiukai, vector <duomenys> &stud_sar);
void testavimas(string file_name, string lyginimo_choice, string data_gen_choice, int size);