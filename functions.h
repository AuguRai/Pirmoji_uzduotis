#pragma once
#include <iostream>
#include <algorithm>
#include <chrono>
#include <random>
#include <fstream>
#include <numeric>


using std::cout;
using std::cin;
using std::sort;
using std::endl;
using std::ifstream;

void random_paz_generavimas(duomenys& asmuo, int random_sk);
string to_lower(string input);
bool ar_skaicius(string s);
bool ar_raide(string s);
void tikrinti_failo_vidu(string eil_isskaidyta);
string tikrinti_ivesti(string ats, const string yes, const string no, const string gen);
void tikrinti_str(string& input);
void ivesti_ir_tikrinti_failo_pav(string& file_name);
void tikrinti_int(int& input);
double vidurkis(vector <int> nd_rez, int egz_rez);
double mediana(vector <int> nd_rez, int egz_rez);

