#pragma once
#include <random>
#include <chrono>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <chrono>

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

duomenys ivedimas();
vector<string> isskaidymas(string eil);
string read_line(ifstream& open_f);
int get_nd_count(ifstream& open_f);
bool compareAscending(const duomenys& data1, const duomenys& data2);
void read_and_fill(vector<duomenys>& data, ifstream& open_f);
void random_data_gen(int sar_size, stringstream& buffer);
void fill_buffer(vector<duomenys> data, stringstream& buffer);
void write_buffer(stringstream& buffer, string pavadinimas);
void write_to_file(vector<duomenys>& data, string result_file);
vector<duomenys> grouping(vector<duomenys>& visi);
void failu_sukurimas(string file_name, int file_size);
void failu_nuskaitymas(string file_name, vector <duomenys>& stud_sar);
void isvedimas_i_ekrana(vector <duomenys>& st_sar, string txt);


