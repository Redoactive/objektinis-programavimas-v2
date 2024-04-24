# V1.5 Versija
## Kas nauja 1.5 versjoje
1. Klase atskirta i dvi
2. sukurtas papildomas failas perkelt funkciju definitions
3. Bazine klase padaryta abstrakcia

## Bazine klase
![](images/baze.png)

## Derrived klase
![](images/derrived.png)

## Bazine klase yra abstrakti
![](images/funkcijaAbstrakti.png)

Bazines klases negalima kurti, kadangi joje yra naudojama gryna virtuali funkcija

## testavimas pries sutvarkant klases
![](images/beVirtual.png)

Matosi, kad neteisingai, kadangi po move komandos, rodykle nera nullptr. Tai parodo, kad funkcija naudoja default konstruktorius
## testavimas po virtualiu funkciju
![](images/suVirtual.png)

Tai parodo, kad derrived klase teisingai naudoja overloadintus konstruktorius ir operatorius