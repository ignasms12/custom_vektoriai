# Custom vektorių klasė, jos tyrimai ir pritaikymas Studentų pažymių skaičiavimo programoje #

## Pirma užduotis ##

* **Įsitikinti, kad custom Vector konteineris veikia taip kaip std::vector konteineris**

5 skirtingos funkcijos, įrodančios viršuje aprašytą sąlygą:

* Operatorius []
```
cout << "Klasiu Vec ir std::vector nariai (o taip pat ir [] operatoriaus funkcionalumo atvaizdavimas): " << endl;
cout << endl;
for(int i=0; i< 5; i++){
    cout << vektorius[i] << " - " << vektorius2[i] << endl;
}
```
* Funkcija size()
```
cout << "Klasiu Vec vs std::vector size() funkciju atvaizdavimas: " << endl;
cout << endl;
cout << vektorius.size() << " - " << vektorius2.size() << endl;
```
* Funkcija push_back
```
cout << "Klasiu Vec vs std::vector push_back() funkciju atvaizdavimas: " << endl;
cout << endl;
vektorius.push_back(int());
vektorius2.push_back(int());

cout << vektorius.size() << " - " << vektorius2.size() << endl;
```
* Operatorius =
```
cout << "Klasiu Vec vs std::vector = operatoriaus atvaizdavimas: " << endl;
cout << endl;

Vec<int> v1;
Vec<int> v2;

for(int i=0; i<5; i++){
    v2.push_back(int());
    v2[i]=i;
}

    v1 = v2;
```
* Funkcija begin()
```
cout << "Klasiu Vec vs std::vector funkciju begin() atvaizdavimas: " << endl;
cout << endl;

cout << "Vektoriaus Vec v1 pradzios adresas: " << v1.begin() << endl;

cout << "Vektoriaus std::vector vektorius2 pradzios adresas: " << &*vektorius2.begin() << endl;
```

## Antra užduotis ##

**Spartos analizė**

*laikai atvaizduoti milisekundėmis*

|           	| std::vector 	|  Vec 	|
|:---------:	|:-----------:	|:----:	|
|   10000   	|      1      	|   0  	|
|   100000  	|      11     	|   2  	|
|  1000000  	|      58     	|  19  	|
|  10000000 	|     652     	|  238 	|
| 100000000 	|     6699    	| 2317 	|


## Trečia užduotis ##

**Kiek kartų vyksta perskirstymai užpildant 100000 elementų ?**

Pildant 100 000 elementų, įvyksta po 18 perskirstymų ir std::vector, ir Vec klasėse

## Ketvirta užduotis ##

**Spartos analizė, naudojant std::vector ir Vec klases Studentų pažymių skaičiavimo programoje, naudojant failą su 5 namų darbų rezultatais ir 100 000 įrašų**

***Naudojant std::vector klasę***

> * Failo generavimas užtruko: 660 ms
>
> * Nuskaitymas iš failo užtruko: 703 ms
>
> * Skirstymas į atskiras kategorijas užtruko: 171 ms
>
> * Išvedimas į failus užtruko: 988 ms


***Naudojant Vec klasę:***

> * Failo generavimas užtruko: 666 ms
>
> * Nuskaitymas iš failo užtruko: 504 ms
>
> * Skirstymas į atskiras kategorijas užtruko: 108 ms
>
> * Išmvedimas į failus užtruko: 1005 ms





