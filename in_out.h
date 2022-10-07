#pragma once
#include <random>
#include <chrono>
#include <iomanip>
#include <fstream>
#include <sstream>

duomenys ivedimas();
vector<string> isskaidymas(string eil);
bool compareAscending(const duomenys& data1, const duomenys& data2);
void read_and_fill(vector<duomenys>& data);
void read_file();
void isvedimas_i_ekrana(vector <duomenys>& st_sar, string txt);

using std::cout;
using std::cin;
using std::endl;
using std::setprecision;
using std::fixed;
using std::ifstream;
using std::getline;
using std::ofstream;
using std::stringstream;