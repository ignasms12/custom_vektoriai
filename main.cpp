#include "vector.h"
#include <vector>
#include <chrono>
 
using namespace std;

void efektyvumoMatavimas(){

    int sz;
    cout << endl;
    cout << "Iveskite elementu kieki: " << endl;
    cin >> sz;
    cout << endl;

    // Pradėti v1 užpildymo laiko matavimą
    std::vector<int> v1;
    int j = 0;
    auto pradzia = chrono::steady_clock::now( );
    for (int i = 1; i <= sz; ++i){
        if(v1.size() == v1.capacity() ){
            j++;
        }
        v1.push_back(i);
    }
    auto pabaiga = chrono::duration_cast<chrono::milliseconds>( chrono::steady_clock::now( ) - pradzia );
    cout << endl;
    cout << "std::vector klases vektoriuje ivyko " << j << " perskirstymu" << endl;
    cout << endl;
    // Baigti v1 užpildymo laiko matavimą

    // Pradėti v2 užpildymo laiko matavimą
    Vec<int> v2;
    auto pradzia2 = chrono::steady_clock::now( );
    for (int i = 1; i <= sz; ++i){
        v2.push_back(i);
    }
    auto pabaiga2 = chrono::duration_cast<chrono::milliseconds>( chrono::steady_clock::now( ) - pradzia2 );
    cout << endl;
    // Baigti v2 užpildymo laiko matavimą

    cout << "Klases std::vector vektoriaus uzpildymas " << sz << " elementu - " << pabaiga.count() << " ms" << endl;
    cout << "Klases Vec vektoriaus uzpildymas " << sz << " elementu - " << pabaiga2.count() << " ms" << endl;

    cout << endl;
    cout << endl;

    char ats;
    cout << "Ar norite atlikti matavima su kitokiu irasu kiekiu ?" << endl;
    cout << "Y/y - Taip" << endl;
    cout << "N/n - Ne" << endl;
    cin >> ats;
    if(ats == 'Y' || ats == 'y'){

        efektyvumoMatavimas();
    }
}

int main(){

    Vec<int> vektorius;
    vector<int> vektorius2;

    for(int i=0; i< 5; i++){
        vektorius.push_back(int());
        vektorius2.push_back(int());
        vektorius[i] = i;
        vektorius2[i] = i;
    }
    cout << "Klasiu Vec ir std::vector nariai (o taip pat ir [] operatoriaus funkcionalumo atvaizdavimas): " << endl;
    cout << endl;
    for(int i=0; i< 5; i++){
        cout << vektorius[i] << " - " << vektorius2[i] << endl;
    }

    cout << endl;
    cout << endl;

    cout << "Klasiu Vec vs std::vector size() funkciju atvaizdavimas: " << endl;
    cout << endl;
    cout << vektorius.size() << " - " << vektorius2.size() << endl;

    cout << endl;
    cout << endl;

    cout << "Klasiu Vec vs std::vector push_back() funkciju atvaizdavimas: " << endl;
    cout << endl;
    vektorius.push_back(int());
    vektorius2.push_back(int());

    cout << vektorius.size() << " - " << vektorius2.size() << endl;

    cout << endl;
    cout << endl;

    cout << "Klasiu Vec vs std::vector = operatoriaus atvaizdavimas: " << endl;
    cout << endl;

    Vec<int> v1;
    Vec<int> v2;

    for(int i=0; i<5; i++){
        v2.push_back(int());
        v2[i]=i;
    }

    v1 = v2;
    
    cout << endl;
    cout << endl;

    cout << "Klasiu Vec vs std::vector funkciju begin() atvaizdavimas: " << endl;
    cout << endl;

    cout << "Vektoriaus Vec v1 pradzios adresas: " << v1.begin() << endl;

    cout << "Vektoriaus std::vector vektorius2 pradzios adresas: " << &*vektorius2.begin() << endl;

    cout << endl;
    cout << endl;


    efektyvumoMatavimas();

}