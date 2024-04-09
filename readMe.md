# V1.0 Versija
## Ka si programa sugeba padaryti
1. Programa apdoroja duomenys ir isspausdina studentu rezultatus surusiavus ir apskaiciavus galutini bala.
2. Vartotojas gali ivesti duomenys pats arba pasirinkti, kad duomenys butu automatiskai sugeneruoti.
3. Duomenys galima sugeneruoti i faila, nuskaityti is failo ir irasyti i faila.
4. Studentu duomenys galima suskirstyti i dvi skirtingas grupes, gerus studentus ir blogus studentus.
## Kas nauja 1.0 versjoje
1. Sukurti papildomi failai, kurie realizuoja programos veikima su skirtingais konteineriais.
2. Gauti nauji testavimo laikai.
3. Sutaisyta keleta klaidu ir istrintos nereikalingos kodo vietos.
4. Labiau optimizuotas kodas.


# Kompiuterio specifikacijos
* procesor - AMD Ryzen 5 3600X 6-Core 3.80 GHz
* RAM - 16.0 GB
* SSD - Samsung SSD 970 EVO Plus 250GB

Visi testavimai yra atlikti su failais, kuriuose namu darbu balu kiekis yra 10.
# Testavimai
|Kontaineris        |Failo dydis        |Duomenu nuskaitymas|Studentu skirstymas|Rusiavimas uztruko |Visas darbo laikas |
|-------------------|-------------------|-------------------|-------------------|-------------------|-------------------|
|Vector             |1000.txt           |0.0045569 s.       |0.0003589 s.       |0.0005984 s.       |0.0055142 s.       |
|Vector             |10000.txt          |0.0273343 s.       |0.0031984 s.       |0.006994 s.        |0.0375267 s.       |
|Vector             |100000.txt         |0.244252 s.        |0.0324432 s.       |0.0954053 s.       |0.3721005 s.       |
|Vector             |1000000.txt        |2.440562 s.        |0.3336525 s.       |1.194114 s.        |3.968329 s.        |
|Vector             |10000000.txt       |25.04966 s.        |3.242979 s.        |14.93185 s.        |43.22449 s.        |
|Vector -O3 comp    |10000000.txt       |15.65705 s.        |1.883964 s.        |2.607147 s.        |20.14816 s.        |
|Deque              |1000.txt           |0.0038703 s.       |0.0011585 s.       |0.0013087 s.       |0.0063375 s.       |
|Deque              |10000.txt          |0.0368431 s.       |0.0090515 s.       |0.0163642 s.       |0.0622588 s.       |
|Deque              |100000.txt         |0.345228 s.        |0.1054952 s.       |0.2280989 s.       |0.6788221 s.       |
|Deque              |1000000.txt        |3.463133 s.        |1.071153 s.        |3.122757 s.        |7.657043 s.        |
|Deque              |10000000.txt       |35.15262 s.        |38.02795 s.        |42.39097 s.        |115.5715 s.        |
|Deque  -O3 comp    |10000000.txt       |34.46072 s.        |20.91489 s.        |40.60071 s.        |95.97631 s.        |
|List               |1000.txt           |0.0072829 s.       |0.0016077 s.       |0.0002648 s.       |0.0091554 s.       |
|List               |10000.txt          |0.0662241 s.       |0.0160479 s.       |0.0028182 s.       |0.0850902 s.       |
|List               |100000.txt         |0.6588872 s.       |0.169634 s.        |0.0427512 s.       |0.8712724 s.       |
|List               |1000000.txt        |6.528909 s.        |1.718614 s.        |0.797603 s.        |9.045125 s.        |
|List               |10000000.txt       |66.34136 s.        |19.00224 s.        |12.86155 s.        |98.20515 s.        |
|List   -O3 comp    |10000000.txt       |64.97077 s.        |18.25886 s.        |12.50814 s.        |95.73778 s.        |

## Is siu rezultatu galime sakyti
* Vektorius yra vienas is greitesniu konteineriu
* Listai ir dekai turi papildomu funkciju negu vektorius bet yra letesni
* Visi kontaineriai saugo duomenys skirtingai ir tai turi savu privalumu ir minusu

# Testavimai su optimizacijos metodais
## Testavimui bus naudojamas 1.000 failo dydis
|Kontaineris        |Strategija         |Duomenu nuskaitymas|Studentu skirstymas|Rusiavimas uztruko |Visas darbo laikas |
|-------------------|-------------------|-------------------|-------------------|-------------------|-------------------|
|Vector  10.000     |1                  |0.0269764 s.       |0.0033208 s.       |0.0064506 s.       |0.0367478 s.       |
|Vector  10.000     |2                  |0.0275273 s.       |0.0090442 s.       |0.0044791 s.       |0.0410506 s.       |
|Vector  10.000     |3                  |0.026953 s.        |0.0044797 s.       |0.0069189 s.       |0.0383516 s.       |
|Vector  1.000.000  |1                  |2.532907 s.        |0.3432265 s.       |1.1939 s.          |4.070033 s.        |
|Vector  1.000.000  |2                  |2.533474 s.        |1.541128 s.        |0.9576085 s.       |5.032211 s.        |
|Vector  1.000.000  |3                  |2.542337 s.        |0.4323943 s.       |1.190902 s.        |4.165633 s.        |
|Deque   10.000     |1                  |0.0368623 s.       |0.0094675 s.       |0.0163046 s.       |0.0626344 s.       |
|Deque   10.000     |2                  |0.036124 s.        |0.0227182 s.       |0.0114677 s.       |0.0703099 s.       |
|Deque   10.000     |3                  |0.0351636 s.       |0.0086578 s.       |0.017318 s.        |0.0611394 s.       |
|Deque   1.000.000  |1                  |3.434506 s.        |1.045713 s.        |3.144669 s.        |7.624887 s.        |
|Deque   1.000.000  |2                  |3.438642 s.        |3.748723 s.        |2.450265 s.        |9.63763 s.         | 
|Deque   1.000.000  |3                  |3.42583 s.         |0.9512969 s.       |3.041881 s.        |7.419007 s.        |
|List    10.000     |1                  |0.0659041 s.       |0.0191355 s.       |0.0027349 s.       |0.0877745 s.       |
|List    10.000     |2                  |0.0669853 s.       |0.0124238 s.       |0.0020257 s.       |0.0814348 s.       |
|List    10.000     |3                  |0.0672824 s.       |0.0222125 s.       |0.0027245 s.       |0.0922194 s.       |
|List    1.000.000  |1                  |6.628845 s.        |1.756177 s.        |0.8006361 s.       |9.185658 s.        |
|List    1.000.000  |2                  |6.630354 s.        |2.245418 s.        |0.4769576 s.       |9.35273 s.         |
|List    1.000.000  |3                  |6.616246 s.        |2.230498 s.        |0.6920817 s.       |9.538825 s.        |

Analize
* Nors saugojimas i atskirus konteinerius uzima daugiau vietos, tai dazniausiai lemia geresnius laikus
* Greiciausiai i konteineri duomenys saugo vektorius, o listas leciausiai
* Rusiavimas listuose greiciausiai vyksta ypac 2 strategijoje kur konteineris padalintas i du.

# Instaliacijos ir naudojimosi instrukcija (windows)
## 1. Instaliuoti Chocolatey 
Chocolatey yra paketu tvarkykle, skirta Windows, kuri supaprastina programines irangos diegimo procesa.
1. Atidarykite komandine eilute kaip administratorius
2. Nukopijuokite ir iklijuokite sia komanda:

`Set-ExecutionPolicy Bypass -Scope Process -Force; [System.Net.ServicePointManager]::SecurityProtocol = [System.Net.ServicePointManager]::SecurityProtocol -bor 3072; iex ((New-Object System.Net.WebClient).DownloadString('https://community.chocolatey.org/install.ps1'))`

3. Patikrinkite instaliacija parasydami i konsole choco
Daugiau informacijos galite rasti [cia](https://chocolatey.org/install)
## 2. Instaliuoti make
1. Tame paciame komandu eilutes lange (kaip administratorius) iveskite:
`choco install make`
2. Galite patikrinti ar pavyko rasydami tai:
`make -v`
Daugiau informacijos galite rasti [cia](https://community.chocolatey.org/packages/make)
## 3. Kompiliuoti ir paleisti programa
1. Nueikite i projekto direktyva konsoleje.
Tai galima padaryti su cd komanda
2. Sukompiliuokite programa rasydami `make`
3. Paleiskite programa rasydami `make run`

Testavimo rezulatu pavizdys ![Tekstas](/images/image.png)

3 Strategija su vektoriais ir naudojama potimizacija -o3 ![Tekstas](/images/3strat-o3.png)