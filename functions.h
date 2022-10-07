#pragma once
#include <iostream>
#include <algorithm>
#include <chrono>
#include <random>

void random_paz_generavimas(duomenys& asmuo, int random_sk);
string to_lower(string input);
bool ar_skaicius(string s);
bool ar_raide(string s);
void tikrinti_faila(string eil_isskaidyta);
string tikrinti_ivesti(string ats, const string yes, const string no);
void tikrinti_str(string& input);
void tikrinti_int(int& input);
double vidurkis(vector <int> nd_rez, int egz_rez);
double mediana(vector <int> nd_rez, int egz_rez);

using std::cout;
using std::cin;
using std::sort;
using std:: endl;