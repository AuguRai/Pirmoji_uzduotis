#pragma once
#include <random>
#include <chrono>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <chrono>
#include <list>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::setprecision;
using std::fixed;
using std::ifstream;
using std::getline;
using std::ofstream;
using std::stringstream;
using std::to_string;
using std::list;
using std::remove_if;

duomenys ivedimas();
string read_line(ifstream& open_f);
duomenys read_and_calc(ifstream& open_f, int nd_count);
void read_and_fill_vector(vector<duomenys>& data, string file_name);
void read_and_fill_list(list <duomenys>& data, string file_name);
void random_data_gen(int sar_size, stringstream& buffer);
void fill_buffer(vector<duomenys> data, stringstream& buffer);
void write_buffer(stringstream& buffer, string pavadinimas);
void write_to_file(vector<duomenys>& data, string result_file);
vector<duomenys> grouping_by_vec(vector<duomenys>& visi);
list <duomenys> grouping_by_list(list<duomenys>& visi);
vector<duomenys> grouping_by_vec_1_strategija(vector<duomenys>& visi);
list <duomenys> grouping_by_list_1_strategija(list<duomenys>& visi);
vector<duomenys> grouping_by_vec_2_strategija(vector<duomenys>& visi);
list <duomenys> grouping_by_list_2_strategija(list<duomenys>& visi);
vector<duomenys> grouping_by_vec_3_strategija(vector<duomenys>& visi);
void failu_sukurimas(string file_name, int file_size);
void isvedimas_i_ekrana(vector <duomenys>& st_sar, string txt);



