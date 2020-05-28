# Studentų pažymių skaičiavimo programa
## Versijos:
---
  * ### v0.1
  1. Programa nuskaito įvestus duomenis:
  *Studentų vardus ir pavardes*
  *Namų darbų ir egzamino rezultatus*

  2. Išveda studento galutinį balą

  3. Galima pasirinkti galutinio balo skaičiavimo būdą: vidurkis arba mediana

  4. Balai gali būti generuojami atsitiktinai

 Įkeltos dvi versijos: su vektoriais ir su dinaminiu masyvu

  ---
  * ### v0.2
 **Pridėta:** 
 * studentų duomenu nuskaitymas iš failo,
 * surūšiuotas studentų irašų išvedimas

---
  * ### v0.3
  **Atliktas refactoring'as:** 
  * funkcijų apsirašymai, naujų duomenų tipų įvedimai perkelti į header failą, 
  * įvestas išimčių valdymas

---
  * ### v0.4
  **Pridėta:** 
* failų generavimas (įvedamas namų darbų kiekis ir įrašų kiekis), 
* išvedimo rūšiavimas pagal galutinį rezultatą (mažiau nei 5 - vargšiukai; 5 ir daugiau - kietekai),
* pridėta programos veikimo spartos matavimo galimybė (matuojama: failų kūrimo greitis, duomenų nuskaitymo iš failo greitis, studentų rūšiavimo greitis, surūšiuotų studentų išvedimo į failus greitis)
  *  [Nuoroda į programos veikimo analizę](https://github.com/ignasms12/antraUzduotis/releases/download/v0.4/v0.4.ataskaita.pdf)

---
  * ### v0.5
  #### Konteinerių testavimas
*laikai atvaizduoti milisekundėmis*

**Vektoriai:**

<center>

|Studentų kiekis|1 000|10 000|100 000|1 000 000|10 000 000|
|---|:-:|---|---|---|---|
|Duomenų nuskaitymas iš failų|11|65|613|6124|109989|
|Studentų rūšiavimas į dvi kategorijas|1|9|91|1079|16222|

</center>

**Sąrašai:**

<center>

|Studentų kiekis|1 000|10 000|100 000|1 000 000|10 000 000|
|---|:-:|---|---|---|---|
|Duomenų nuskaitymas iš failų|11|65|615|6231|80340|
|Studentų rūšiavimas į dvi kategorijas|4|399|133829|N/A|N/A|

</center>

**Dekos:**

<center>

|Studentų kiekis|1 000|10 000|100 000|1 000 000|10 000 000|
|---|:-:|---|---|---|---|
|Duomenų nuskaitymas iš failų|12|72|707|8454|116547|
|Studentų rūšiavimas į dvi kategorijas|3|32|330|9832|N/A|

</center>


#### Kompiuterio specifikacijos:

**CPU** - Intel Core m3-7Y32 1.2 GHz Dual-Core

**RAM** - 8 GB 1867 MHz LPDDR3

**Storage Device** - SSD

---
  * ### v1.0
  
Pritaikytos dvi skirtingos studentų dalinimo į kategorijas strategijos:

  * **1 strategija** - Bendro studentų konteinerio elementai rūšiuojami į du naujus konteinerius
  * **2 strategija** - Bendro studentų konteinerio elementai, atitinkantys nustatyta sąlygą, yra perkeliami į naują konteinerį ir pašalinami iš originalaus konteinerio

  **1 strategija**
  
  *laikai atvaizduoti milisekundėmis*

  | Duomenų tipas | Nuskaitymas iš failo | Skirstymas į kategorijas |
|:-------------:|:--------------------:|:------------------------:|
|   Vektoriai   |          65          |             9            |
|      Deka     |          73          |            34            |
|    List'as    |          66          |            393           |

**2 strategija**

*laikai atvaizduoti milisekundėmis*
c
| Duomenų tipas | Nuskaitymas iš failo | Skirstymas į kategorijas |
|:-------------:|:--------------------:|:------------------------:|
|   Vektoriai   |          65          |           4302           |
|      Deka     |          74          |           2846           |
|    List'as    |          67          |            284           |

---
  * ### v1.1

* Sukurta nauja git repozitorija
* Programos kodas perrašytas, pakeitus struktūras klasėmis

**Programos veikimo laikai, naudojant efektyviausią strategiją ir konteinerį:**

*laikai atvaizduoti milisekundėmis*

|            	| 100 000 įrašų 	| 1 000 000 įrašų 	|
|:----------:	|:-------------:	|:---------------:	|
| Struktūros 	|      2138     	|      22 363     	|
|   Klasės   	|      2154     	|      21 916     	|

**Programos veikimo laikai naudojant skirtingus optimizavimo flag'us:**

*laikai atvaizduoti milisekundėmis*

|    	| 100 000 įrašų 	| 1 000 000 įrašų 	|
|:--:	|:-------------:	|:---------------:	|
| O1 	|     1 769     	|      18 267     	|
| O2 	|     1 569     	|      16 001     	|
| O3 	|     1 616     	|      16 436     	|

* ### v1.2

* Sukurti custom operatoriai:
1. Priskyrimo operatorius (Overloaded assignment): =
2. Įvesties operatorius: >>
3. Išvesties operatorius: <<

* ### v1.5

* Sukurta bazinė klasė: žmogus ir iš šios klasės, klasė Studentas paversta į *derived* klasę
* Bazinė klasė - žmogus - paversta abstrakčiąja klasę - negalima sukurti klasės žmogus objektų, tik objektus iš išvestinių klasių

* ### v2.0

* Dokumentacija sukurta naudojant Doxygen
* Atliktas unit testing'as: mainTest.cpp
* Papildytas README.md

## Diegimo instrukcija:
1. Atsidarę šį puslapį, spauskite "Clone or Download" mygtuką, kad parsisiųstumėte programą
2. Parsisiuntę Zip failą, išarchyvuokite jį sau patogiu įrankiu
3. Atsidarykite komandinės eilutės įrankį ir nueikite į išarchyvuotą aplanką
4. Išarchyvuotame aplanke naudokite šią komandą, kad paruoštumėte programą naudojimui:
    * **make**
5. Naudokite šią komandą programos paleidimui:
    * **make run** 
6. Komanda skirta aplanko išvalymui:
    * **make clear**

*

## Naudojimosi instrukcija:
1. Komanda - "make run" - paleiskite programą
2. Paleidus programą, pasirinkite ar norėsite sugeneruoti naują failą ar naudoti esamą
    * Pasirinkus naujo failo generavimą, įveskite namų darbų skaičių, bendrą įrašų skaičių ir failo pavadinimą (programa skaito tik failus pavadinimu kursiokai.txt) - paspaudus Enter, programa išves failo generavimo trukmę.
3. Pasirinkite galutinio balo skaičiavimo metodą: namų darbų rezultatų skaičiavimas pagal medianą arba vidurkį
4. Pasirinkite įrašų įvesties būdą: ranka arba iš failo
    * Pasirinkus ranka:
    * Įveskite studento vardą ir pavardę
    * Pasirinkite ar norite rezultatus generuoti atsitiktinai
      * Pasirinkus rezultatų įvedimą ranka:
      * Įveskite studento egzamino rezultatą
      * Įveskite namų darbų užduočių kiekį ir jų rezultatus
5. Pasirinkite ar norite pridėti naują įrašą
6. Pasirinkite išvesties būdą: į konsolę arba į failą
    * Pasirinkus išvedimą į konsolę, nurodykite išvedimo formatą: visi studentai ar kategorizuoti studentai