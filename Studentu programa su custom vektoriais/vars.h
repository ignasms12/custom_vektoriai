#pragma once

#include <cmath>
#include <iomanip>
#include <climits>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <chrono>
#include "vector.h"

class zmogus {
  protected:
    std::string name;
    std::string surname;
  public:
    virtual int show() { return 0; }
};
  

class Studentas: public zmogus {

  //Custom Print Operator
  friend std::ostream& operator<<(std::ostream&, const Studentas&);
  friend std::istream& operator>>(std::istream&, Studentas&);

  private:
    int n;
    Vec<int> nd_rezultatas;
    double egzamino_rezultatas;
    double bendras_pazymys;

  public:
    //Copy Constructor
    Studentas(const Studentas&);

    //Overloaded Assignment Operator
    Studentas& operator=(const Studentas& );


    Studentas() : egzamino_rezultatas(0) { }
    inline std::string get_vardas() const {return name;} // get'eriai
    inline std::string get_pavarde() const {return surname;} // get'eriai
    inline int get_nd(int a) {return nd_rezultatas[a] ; } // get'eriai
    inline double get_exam() const {return egzamino_rezultatas;} // get'eriai
    inline double get_final() const {return bendras_pazymys;} //get'eriai
    inline int get_kiekis() const {return n;} //get'eriai
    inline void set_vardas(std::string vardas) {name = vardas;} // set'eriai
    inline void set_pavarde(std::string pavarde) {surname = pavarde;} // set'eriai
    inline void set_nd(int a, int nd) {nd_rezultatas.push_back(int()); nd_rezultatas[a] = nd ; } // set'eriai
    inline void set_exam(double exam) {egzamino_rezultatas = exam;} // set'eriai
    inline void set_final(double final) {bendras_pazymys = final;} //set'eriai
    inline void set_kiekis(int kiekis) { n = kiekis;} //set'eriai
    void galutinioSkaiciavimas(int);
    void readStudent(int, std::ifstream&, int);
    void input();
    void vienoStudentoIvedimas(int &, int& , int , char );

};



void bubbleSort(Studentas , int );

template <typename T>

void validityCheck(T&);

int digitCounter(int);

void random_gen();

void compare(Studentas&);

void ivedimas(int&);

void input_result(Studentas*);

void naujasIrasas(char*, int*);

bool comparation(Studentas&, Studentas&);

void splitOutput(Vec<Studentas> &, Vec<Studentas>& , Vec<Studentas>& );

void print(Vec<Studentas> , Vec<Studentas>, Vec<Studentas>, int );

void outputToFile(Vec<Studentas>, Vec<Studentas>, int);

void readFile(Vec<Studentas> &, int, int, std::string );

void ivedimoBudas(Vec<Studentas>&, int&, int , int , char );