# v0.1

Šioje versijoje prašoma vartotojo įvesti vardą, pavardę, namų darbų ir egzamino rezultatus. Įvesdamas duomenis, vartotojas turi galimybę pasirinkti egzamino bei namų darbų rezultatų atsitiktinį sugeneravimą. Programoje įvedimas veikia tol, kol vartotojas įveda prie vardo 0.  Pasibaigus duomenų įvedimui, yra skaičiuojami kiekvieno studento galutiniai balai. Vartotojas gali pasirinkti, pagal ką nori, kad galutinis balas būtų skaičiuojamas: pagal medianą ar pagal vidurkį. Rezultatai parodomi ekrane. Iš viso programa yra realizuota dviem būdais, saugant duomenis masyve ir vektoriuje. Be to, studentų duomenų saugojimui naudojamos struktūros.

# v0.2

Programa realizuota tik su vektoriaus tipo konteineriu. Šioje versijoje vartotojas jau gali ne tik pats įvesti duomenis, tačiau ir pasirinkti juos nuskaityti iš failo. Pasirinkus nuskaitymą iš failo, nuskaityti duomenys yra apdorojami: suskaičiuojami galutiniai rezultatai pagal medianą ir vidurkį. Galiausiai studentai yra išrūšiuojami pagal vardus (jei jie sutampa, pagal pavardes) ir studento vardas, pavardė, galutiniai rezultatai išvedami į failą. Programa buvo suskaidyta į kelis “.cpp” ir antraštinius failus. Programos veikimas buvo apsaugotas nuo vartotojo klaidingų įvesčių naudojant išimtis.

# v0.4

V0.4 versijoje yra papildytos programos testavimo parinktys. Vartotojas pačioje pradžioje gali pasirinkti ar nori, jog programa būtų testuojama. Pasirinkus programos testavimą yra galimybė sugeneruoti 5 atstiktinius duomenų failus, susidedančius iš 1000, 10000, 100000, 1000000, 10000000 duomenų. Nepasirinkus šios funkcijos duomenys yra testuojami su jau sukurtais 5 failais. Galiausiai vartotojas gali rinktis ar nori, jog būtų palyginti duomenų nuskaitymo ir surūšiavimo greičiai tarp vektoriaus ir list. Nepasirinkus šios funkcijos yra skaičiuojamas failo sukūrimo, nuskaitymo, surūšiavimo ir išvedimo į failą laikas naudojant vektorių.


**Nuskaitymo greičio palyginimas** (namų darbų skaičius: 5)
|  | Vector | List |
| :---         |     :---:      |          :---: |
| 1000 duomenų   | 0.0346628s     | 0.0407722s   |                                
| 10000 duomenų    | 0.347568s       | 0.324748s      |
| 100000 duomenų    | 3.58709s      | 3.18747s     |
| 1000000 duomenų    | 35.0725s      | 31.914s      |
| 10000000 duomenų    | 356.754s       | 318.079s          |

**Surūšiavimo greičio palyginimas** (namų darbų skaičius: 5)
|  | Vector | List |
| :---         |     :---:      |          :---: |
| 1000 duomenų   | 0.007319s | 0.0047511s  |
| 10000 duomenų    | 0.0684899s       | 0.052476s      |
| 100000 duomenų    | 0.912451s      | 0.517059s    |
| 1000000 duomenų    | 10.6915s     |  5.29333s     |
| 10000000 duomenų    | 88.8615s      | 53.5549s          |

Tiek surūšiuojant (padalijant į dvi grupes), tiek nuskaitant "list" konteineris buvo greitesnis už "vector"

**Sistemos parametrai:**

**CPU:** AMD Ryzen 5 5600H with Radeon Graphics 3.30 GHz
**RAM:** 2x8 GB, speed: 3200 MHz
**SSD:** 1TB, sequential read: 3500 MB/s, sequential write: 3200MB/s, random read: 250,000 IOPS, random write: 440,000 IOPS
