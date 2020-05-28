#include "vars.h"


int main() {
  int *rod;
  Vec<Studentas> studentai;
  int pasirinkimas;
  char taipArbaNe;
  int i = 0;
  int ivestiesBudas_int;
  char ived;
  int ka;
  double skirtumas;
  
  zmogus pirmas;

  // Custom operatoriu demonstracija
  
  /* Studentas pavyzdinis;
  std::cin >> pavyzdinis;
  pavyzdinis.galutinioSkaiciavimas(0);
  std::cout << pavyzdinis;
  */

  std::cout << "Ar norite sukurti nauja faila ? Y/N" << std::endl;
  std::cin >> ived;

  if(ived == 'Y' || ived == 'y'){
    random_gen();
  }
  
  std::cout << std::endl;
  std::cout << "Pasirinkite kas turetu buti isvedama: Vidurkis ar Mediana: ";
  ivedimas(pasirinkimas);
  std::cout << std::endl;
  
  std::cout << "Kaip ivesite irasus:" << std::endl;
  std::cout << "0 - Irasai ivedami ranka" << std::endl;
  std::cout << "1 - Irasai nuskaitomi is failo" << std::endl;

  std::cin >> ivestiesBudas_int;

  ivedimoBudas(studentai, pasirinkimas, i, ivestiesBudas_int, taipArbaNe);

  
  Vec<Studentas> kietekai;
  Vec<Studentas> vargsiukai;

  sort(studentai.begin(), studentai.end(), comparation);

  auto pradzia = std::chrono::steady_clock::now( );
  splitOutput(studentai, kietekai, vargsiukai);
  auto pabaiga = std::chrono::duration_cast<std::chrono::milliseconds>( std::chrono::steady_clock::now( ) - pradzia );

  std::cout << "Skirstymas i atskiras kategorijas uztruko: " << pabaiga.count() << " ms" << std::endl;
  
  

  std::cout << "\nAr norite isvesti i konsole ar i atskira faila ?" << std::endl;
  std::cout << "0 - i konsole" << std::endl;
  std::cout << "1 - i faila" << std::endl;
  std::cin >> ka;

  if(ka == 0){
    print(studentai, vargsiukai, kietekai, pasirinkimas);
  }
  else if(ka==1){
    auto start = std::chrono::steady_clock::now( );
    
    outputToFile(kietekai, vargsiukai, pasirinkimas);

    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>( std::chrono::steady_clock::now( ) - start );

    std::cout << std::endl;
    std::cout << "Isvedimas i failus uztruko: " << elapsed.count() << " ms" << std::endl;
    std::cout << std::endl;
  }

}