# V3 Versija
## Kas nauja 3 versjoje
1. Sukurta nuosava vektoriaus klase - myVector
2. Patikrintos funkcijos
3. Atlikti laiko testavimai
4. Sukurta Dokumentacija
5. Supakuotas projektas


# Funkciju testavimas
## Vektoriu palyginimai
![](images/Comparison.png)
## Clear, pop, erase
![](images/clear.png)
## empty, getsize, get capacity
![](images/functions.png)
## first, last, begin, end
![](images/first.png)
## [], at, pop
![](images/popat.png)

# myVector ir std::vector spartos testavimas

|Elementu kiekis|std::vector|myVector |
|---------------|-----------|---------|
|10000          |0.0001257  |0.0001122|
|100000         |0.0008885  |0.000937 |
|1000000        |0.0077361  |0.0071594|
|10000000       |0.078231   |0.0986152|
|100000000      |0.725096   |0.785338 |
1. myVector veikia greičiau su mažesniais skaičaiais (Vidutiniškai 10% - 15% greičiau)
2. Su dideliais skaičiais myVector veikia lėčiau (Vidutiniškai 5% - 10% lėčiau)

# Resize Kiekis
![](images/ResizeKiekis.png)

Atminties perskirstymas myVector konteineryje yra 1 mažesnins del to, kad default myVector sukuriamas su 1 capacity

# Programos veikimo laikas su konteineriais
## 100.000.txt
|Darbas                 |std::vector|myVector |
|-----------------------|-----------|---------|
|Duomenu nuskaitymas    |0.2695445  |0.2869592|
|skirstymas i dvi grupes|0.0452824  |0.1115644|
|Rusiavimas             |0.2883375  |0.3545991|
|Visas laikas           |0.6031644  |0.7531227|
## 1.000.000.txt
|Darbas                 |std::vector|myVector |
|-----------------------|-----------|---------|
|Duomenu nuskaitymas    |2.609202   |2.738449 |
|skirstymas i dvi grupes|0.5331666  |1.227727 |
|Rusiavimas             |3.764685   |4.563468 |
|Visas laikas           |6.907054   |8.529645 |
## 10.000.000.txt
|Darbas                 |std::vector|myVector |
|-----------------------|-----------|---------|
|Duomenu nuskaitymas    |27.49252   |30.6472  |
|skirstymas i dvi grupes|4.522078   |11.05496 |
|Rusiavimas             |46.87415   |58.14309 |
|Visas laikas           |78.88875   |99.84526 |





## Papildomas testavimas
![](images/extra.png)