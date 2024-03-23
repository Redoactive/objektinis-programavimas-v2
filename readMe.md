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



Visi testavimai yra atlikti su failais, kuriuose namu darbu balu kiekis yra 10.

# 1000 dydzio failas
## Vektorius
|Kontaineris        |Failo dydis        |Duomenu nuskaitymas|Studentu skirstymas|Rusiavimas uztruko |Visas darbo laikas |
|-------------------|-------------------|-------------------|-------------------|-------------------|-------------------|
|Vector             |1000.txt           |0.0045569 s.       |0.0003589 s.       |0.0005984 s.       |0.0055142 s.       |
|Vector  -o3 comp   |1000.txt           |0.0029968 s.       |0.0003394 s.       |0.0005833 s.       |0.0039195 s.       |
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




# studentai10000.txt
|Darbas                          |Laikas      |
|--------------------------------|------------|
|Failu kurimas                   |0.0694658 s.|
|Duomenu nuskaitymas is failo    |0.0365163 s.|
|Rusiavimas uztruko              |0.0063748 s.|
|Studentu skirstymas i dvi grupes|0.0037312 s.|
|Surusiuotu studentu isvedimas   |0.0594699 s.|
|Visos programos veikimo laikas  |0.1755581 s.|



# studentai1000000.txt
|Darbas                          |Laikas      |
|--------------------------------|------------|
|Failu kurimas                   |4.5448 s.   |
|Duomenu nuskaitymas is failo    |1.93674 s.  |
|Rusiavimas uztruko              |1.10117 s.  |
|Studentu skirstymas i dvi grupes|0.347281 s. |
|Surusiuotu studentu isvedimas   |5.10791 s.  |
|Visos programos veikimo laikas  |13.0379 s.  |

![Nuotrauka testo su 1000000.txt failo rezultatu](image.png)

![Nuotrauka kurioje buvo kurta 9999999 x 10 (balu kiekio) failo dydis rezultatai](image-1.png)
