#include "vars.h"



//Copy Constructor
Studentas::Studentas(const Studentas& source){
	name = source.name;
	surname = source.surname;
	n = source.n;
	nd_rezultatas = source.nd_rezultatas;
	egzamino_rezultatas = source.egzamino_rezultatas;
	bendras_pazymys = source.bendras_pazymys;
}

//Overloaded Assignment Operator
Studentas& Studentas::operator=(const Studentas& source){
	if(this == &source){
		return *this;
	}
	name = source.name;
	surname = source.surname;
	n = source.n;
	nd_rezultatas = source.nd_rezultatas;
	egzamino_rezultatas = source.egzamino_rezultatas;
	bendras_pazymys = source.bendras_pazymys;
	return *this;
}

//Custom Print operator
std::ostream& operator<<(std::ostream& os, const Studentas& c){

	os << c.name << " " << c.surname << std::endl;
	os << "Namu darbu rezultatai: ";
	for(int i=0; i<c.nd_rezultatas.size(); i++){ 
		os << c.nd_rezultatas[i] << " | ";
	}
	os << std::endl;
	os << "Egzamino Rezultatas: " << c.egzamino_rezultatas << std::endl;
	os << "Bendras Pazymys: " << c.bendras_pazymys << std::endl;
	return os << std::endl;
}

//Custom Input operator
std::istream& operator>>(std::istream& is, Studentas& c){
	int count;
	std::cout << "Iveskite studento varda ir pavarde: " << std::endl;
	is >> c.name >> c.surname;
	while(is.fail()){
		is.clear();
		is.ignore();
		std::cout << "Neteisingai ivedete varda ir pavarde, bandykite dar karta: " << std::endl;
		is >> c.name >> c.surname;
	}
	std::cout << std::endl;
	std::cout << "Iveskite namu darbu kieki:  " << std::endl;
	is >> c.n;
	while(is.fail() || c.n < 0){
		is.clear();
		is.ignore();
		std::cout << "Neteisingai ivedete namu darbu kieki, bandykite dar karta: " << std::endl;
		is >> c.n;
	}
	std::cout << std::endl;
	std::cout << "Iveskite namu darbu rezultatus: " << std::endl;
	for(int i=0; i<c.n; i++){
		c.nd_rezultatas.push_back(int());
		std::cout << i+1 << " - ";
		is >> c.nd_rezultatas[i];
		while(is.fail() || c.nd_rezultatas[i] > 10 || c.nd_rezultatas[i] < 0){
			is.clear();
			is.ignore();
			std::cout << "Neteisingai ivedete, bandykite dar karta: " << std::endl;
			std::cout << i+1 << " - ";
			is >> c.nd_rezultatas[i];
		}
	}
	std::cout << std::endl;
	std::cout << "Iveskite egzamino rezultata: " << std::endl;
	is >> c.egzamino_rezultatas;
	while(is.fail() || c.egzamino_rezultatas > 10 || c.egzamino_rezultatas < 0){
		is.clear();
		is.ignore();
		std::cout << "Neteisingai ivedete, bandykite dar karta: " << std::endl;
		is >> c.egzamino_rezultatas;
	}
	std::cout << std::endl;
	return is;
	
}

//Naudojama namu darbu rezultatu rusiavimui, jei skaiciavimui pasirinktas Medianos budas
void bubbleSort(Vec<int> nd, int n) {
	bool exchanges;
	do {
		exchanges = false;
		for (int c = 0; c < n - 1; c++) {
			if (nd[c] > nd[c+1]) {
				int temp = nd[c];
				nd[c] = nd[c];
				nd[c+1] = temp;
				exchanges = true;
			}
		}
	} while (exchanges);
}

template <typename T>

//Tikrinama ar buvo ivestas skaicius (galima naudoti ir double, ir int ivedimui)
void validityCheck(T &n) {
	std::cin >> n;
	while (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		std::cout << "Neteisinga reiksme, iveskite skaiciu: " << std::endl;
		std::cin >> n;
	}
}
//Funkcija naudojama plocio skaiciavimui (kai generuojamas failas)
int digitCounter(int no){
		int a = 0;
		if(no == -1){
				a = 0;
		}
		else if(no==0){
				no=1;
		}
		while(no>0){
				no=no/10;
				a++;
		}
		return a;
}

//Failo generavimo funkcija
void random_gen(){
		int n, kiekis;
		int temp = -1;
		std::string pavadinimas;
		std::string name = "Vardas";
		std::string surname = "Pavarde";
		std::string nd = "ND";
		srand(time(NULL));
		std::cout << "Iveskite namu darbu kieki: ";
		std::cin >> n;
		std::cout << "\nIveskite irasu kieki: ";
		std::cin >> kiekis;
		std::cout << std::endl;
		std::cout << "Iveskite naujo failo pavadinima: " << std::endl;
		std::cin >> pavadinimas;
		std::cout << std::endl;

		auto paradzia = std::chrono::steady_clock::now( );

		std::ofstream failas;
		failas.open(pavadinimas + ".txt");
		failas << std::setw(20) << std::left << name << std::setw(20) << std::left << surname;
		for(int i=1; i< n+1; i++){
				failas << std::setw(5) << std::right << nd << i ;
		}
		failas << std::setw(10) << std::right << "Egz_Rez" << std::endl;
		for(int i=0; i<kiekis; i++){
				failas << std::right <<  name << i;

				failas << std::setw(20-digitCounter(i)) << std::right;

				failas << surname << i;

				for(int j=0; j<n; j++){
						
						if(j==0){
								failas << std::setw(18-digitCounter(i)) << std::right;
						}
						else{
								failas << std::setw(7) << std::right;
								}
						
						failas  << rand() % 10 + 1;
				}
				
				failas << std::setw(6) << std::right << rand() % 10 + 1 ;
				if(i!=kiekis-1){
					failas << std::endl;
				}
		}

		auto pbaiga = std::chrono::duration_cast<std::chrono::milliseconds>( std::chrono::steady_clock::now( ) - paradzia );

		std::cout << "Failo generavimas uztruko: " << pbaiga.count() << " ms" << std::endl;
}

//Atskira funkcija galutinio balo skaiciavimo budo pasirinkimui (del rekursijos)
void ivedimas(int &pvz) {
	std::string pavyzdys;
	std::cin >> pavyzdys;
	if (pavyzdys == "Vidurkis" || pavyzdys == "vidurkis") {
		pvz = 0;
	} else if (pavyzdys == "Mediana" || pavyzdys == "mediana") {
		pvz = 1;
	} else {
		std::cout << "Neteisingai ivedete, iveskite Vidurkis arba Mediana: ";
		ivedimas(pvz);
	}
}
//Funkcija Namu Darbu Rezultatu ivedimui
void Studentas :: input() {
	int indeksas = 0;
	while (indeksas <  n) {
		nd_rezultatas.push_back(int());
		std::cout << indeksas + 1 << " - ";
		validityCheck( nd_rezultatas[indeksas]);
		try {
			if( nd_rezultatas[indeksas] > 10 ||  nd_rezultatas[indeksas] < 0){
				throw nd_rezultatas[indeksas];
			}
			else{ 
				indeksas++;
			}
		}
		catch(int x){
			std::cout <<"\n" << x << " netelpa i intervala nuo 0 iki 10";
		}

	}
	indeksas = 0;
}

//Atskira funkcija nustatymui ar vartotojas nori prideti nauja irasa (del rekursijos)
void naujasIrasas(char &rankis, int &numeriukas){
	if(numeriukas == 0){
		std::cout << "Ar norite prideti nauja irasa ? (Y/N)" << std::endl;
	}
	else if(numeriukas > 0){
		std::cout << "Neteisingai ivedete - iveskite Y arba N" << std::endl;
	}
	std::cin >> rankis;
	numeriukas++;
}

//Galutinio Balo skaiciavimas
void Studentas :: galutinioSkaiciavimas(int porankis){

	int suma = 0;
	for (int a = 0; a < nd_rezultatas.size() ; a++) {
		suma += nd_rezultatas[a];
	}

	double mediana;
	// jei porankis == 1, galutinis balas skaiciuojamas su mediana
	if (porankis == 1) {

		if (nd_rezultatas.size()% 2 != 0) {
			int abc = round(nd_rezultatas.size() / 2);
			mediana = nd_rezultatas[abc];
		}

		else if ( nd_rezultatas.size() % 2 == 0) {
			mediana = ( nd_rezultatas[nd_rezultatas.size() / 2 - 1] + nd_rezultatas[ nd_rezultatas.size() / 2] )/2;
		}
		bendras_pazymys = (0.4 * mediana) + (0.6 * egzamino_rezultatas);
	}
	// jei porankis == 0, galutinis balas skaiciuojamas su vidurkiu
	else if(porankis == 0){
		bendras_pazymys = (0.4 * ( suma / nd_rezultatas.size() ) ) + (0.6 * egzamino_rezultatas );
	}

}

//Palyginimo funkcija skirta studentu irasu rusiavimui pagal varda ir pavarde
bool comparation(Studentas &a, Studentas &b){
	return (a.get_vardas() < b.get_vardas() || (a.get_vardas() == b.get_vardas() && a.get_pavarde() < b.get_pavarde()));
}

//Funkcija skirta atskirti studentu irasus pagal Galutini Bala i dvi atskiras dalis 
void splitOutput(Vec<Studentas> &vektoriux, Vec<Studentas> &kietekai, Vec<Studentas> &vargsiukai){
	int count = 0;
	int kitasCount = 0;
	for(int k=0; k<vektoriux.size(); k++){
		if(vektoriux[k].get_final() >= 5){
			kietekai.push_back(Studentas());
			kietekai[count] = vektoriux[k];
			count++;
		}
		else if(vektoriux[k].get_final() < 5){
			vargsiukai.push_back(Studentas());
			vargsiukai[kitasCount] = vektoriux[k];
			kitasCount++;
		}
	}
	
}

//Funkcija skirta isspausdinti studentu irasus i konsole - bendrai visus arba pagal atskiras kategorijas
void print(Vec<Studentas> printeris, Vec<Studentas> vargsiukai, Vec<Studentas> kietekai, int pasirinkimas){
	std::cout << std::endl;
	int hehehey;
	std::cout << "Ar norite isvesti visus studentus ar sukategorizuotus ?" << std::endl;
	std::cout << "0 - Isvedami visi studentai" << std::endl;
	std::cout << "1 - Isvedami sukategorizuoti studentai" << std::endl;
	std::cin >> hehehey;
	std::cout << std::endl;

	

	if(hehehey == 0){

		std::cout<< std::endl;
		std::cout.width(15);
		std::cout << std::left << "Vardas";
		std::cout.width(15);
		std::cout << std::left << "Pavarde";
		std::cout.width(16);

		if (pasirinkimas == 0) {
			std::cout << std::left << "Galutinis (Vid.)" << std::endl;
		}

		else if (pasirinkimas == 1) {
			std::cout << std::left << "Galutinis (Med.)" << std::endl;
		}

		for (int n = 0; n < 60; n++) std::cout << "-";

		for(int sup=0; sup < printeris.size(); sup++) {
			std::cout << std::endl;
			std::cout.width(15);
			std::cout << std::left << printeris[sup].get_vardas();
			std::cout.width(20);
			std::cout << std::left << printeris[sup].get_pavarde();
			std::cout << std::fixed << std::setprecision(2) << printeris[sup].get_final() << std::endl;
		}

	}

	else if(hehehey == 1){
		std::cout << "                         " << "VARGSIUKAI:" << std::endl;

		std::cout.width(15);
		std::cout << std::left << "Vardas";
		std::cout.width(15);
		std::cout << std::left << "Pavarde";
		std::cout.width(16);

		if (pasirinkimas == 0) {
			std::cout << std::left << "Galutinis (Vid.)" << std::endl;
		}

		else if (pasirinkimas == 1) {
			std::cout << std::left << "Galutinis (Med.)" << std::endl;
		}

		for (int n = 0; n < 60; n++) std::cout << "-";

		for(int sup=0; sup < vargsiukai.size(); sup++) {
			std::cout << std::endl;
			std::cout.width(15);
			std::cout << std::left << vargsiukai[sup].get_vardas();
			std::cout.width(20);
			std::cout << std::left << vargsiukai[sup].get_pavarde();
			std::cout << std::fixed << std::setprecision(2) << vargsiukai[sup].get_final() << std::endl;
		}
		std::cout<< std::endl;
		std::cout<< std::endl;
		
		std::cout << "                         " << "KIETEKAI:" << std::endl;

		std::cout<< std::endl;
		std::cout.width(15);
		std::cout << std::left << "Vardas";
		std::cout.width(15);
		std::cout << std::left << "Pavarde";
		std::cout.width(16);

		if (pasirinkimas == 0) {
			std::cout << std::left << "Galutinis (Vid.)" << std::endl;
		}

		else if (pasirinkimas == 1) {
			std::cout << std::left << "Galutinis (Med.)" << std::endl;
		}

		for (int n = 0; n < 60; n++) std::cout << "-";

		for(int sup=0; sup < kietekai.size(); sup++) { 
			std::cout << std::endl;
			std::cout.width(15);
			std::cout << std::left << kietekai[sup].get_vardas();
			std::cout.width(20);
			std::cout << std::left << kietekai[sup].get_pavarde();
			std::cout << std::fixed << std::setprecision(2) << kietekai[sup].get_final() << std::endl;
	}

	}

	std::cout << std::endl;
}

//Funkcija skirta isspausdinti studentu irasus i failus
void outputToFile(Vec<Studentas> kiec,Vec<Studentas> vargs, int pasirinkimas){
	std::ofstream vargsiukai;
	std::ofstream kietekai;
	vargsiukai.open("vargsiukai.txt");
	kietekai.open("kietekai.txt");

	//vargsiuku outputas
		vargsiukai.width(15);
		vargsiukai << std::left << "Vardas";
		vargsiukai.width(15);
		vargsiukai << std::left << "Pavarde";
		vargsiukai.width(16);

		if (pasirinkimas == 0) {
			vargsiukai << std::left << "Galutinis (Vid.)" << std::endl;
		}

		else if (pasirinkimas == 1) {
			vargsiukai << std::left << "Galutinis (Med.)" << std::endl;
		}
		for (int n = 0; n < 60; n++) vargsiukai << "-";

	//kieteku outputas
		kietekai.width(15);
		kietekai << std::left << "Vardas";
		kietekai.width(15);
		kietekai << std::left << "Pavarde";
		kietekai.width(16);

		if (pasirinkimas == 0) {
			kietekai << std::left << "Galutinis (Vid.)" << std::endl;
		}

		else if (pasirinkimas == 1) {
			kietekai << std::left << "Galutinis (Med.)" << std::endl;
		}
		for (int n = 0; n < 60; n++) kietekai << "-";

	
		for(int sup=0; sup < kiec.size(); sup++) {
			
				kietekai << std::endl;
				kietekai.width(15);
				kietekai << std::left << kiec[sup].get_vardas();
				kietekai.width(20);
				kietekai << std::left << kiec[sup].get_pavarde();
				kietekai << std::fixed << std::setprecision(2) << kiec[sup].get_final() << std::endl;
		}
		for(int b=0; b<vargs.size(); b++){
				vargsiukai << std::endl;
				vargsiukai.width(15);
				vargsiukai << std::left << vargs[b].get_vardas();
				vargsiukai.width(20);
				vargsiukai << std::left << vargs[b].get_pavarde();
				vargsiukai << std::fixed << std::setprecision(2) << vargs[b].get_final() << std::endl;
		}
}

//Funkcija skirta nuskaityti studentu duomenis is failo
void readFile(Vec<Studentas> &printeris, int k, int pasirinkimas, std::string file){
		
	std::string Value = "";
	int count = 0;
	std::ifstream failas(file);
	

	try{
			failas.exceptions(std::ifstream::failbit);
	}
	catch(std::ios_base::failure& fail){
			std::cerr <<"\n Failas - "<< file <<" - nerastas; ikelkite faila i programos vykdymo aplanka ir paspauskite Enter mygtuka"; 
			std::cin.ignore();
			std::cin.get();
			readFile(printeris, k, pasirinkimas, file);
	}
	
	failas >> Value >> Value >> Value;
	
	while(Value[0] == 'N'){
			failas >> Value;
			count++;
	}

	while(!failas.eof()){
		printeris.push_back(Studentas());
		printeris[k].readStudent(pasirinkimas, failas, count);
		k++;
		if(k%1000 == 0){
				std::cout << k << std::endl;
		}
	}
	
	failas.close();
		
}

//Funkcija skirta nuskaityti vieno studento duomenis is failo
void Studentas :: readStudent(int pasirinkimas, std::ifstream& nuskaitymas, int count){
	nuskaitymas >> name >> surname;
	for(int l=0; l < count; l++){
		nd_rezultatas.push_back(int());
		nuskaitymas >> nd_rezultatas[l];
	}
	nuskaitymas >> egzamino_rezultatas;
	galutinioSkaiciavimas(pasirinkimas);
}

//Funkcija skirta nustatyti studentu irasu ivedimo buda - konsole arba is failo
void ivedimoBudas(Vec<Studentas> &printeris, int &pasirinkimas, int k, int ivestiesBudas_int, char option){

	if(ivestiesBudas_int == 0){
		char rodyklius;
		int rodiklius = 0;
		printeris.push_back(Studentas());
		while ( k >= 0 ) {
			if (k > 0){
				naujasIrasas(rodyklius, rodiklius);

				if(rodyklius == 'y' || rodyklius == 'Y'){
					printeris.push_back(Studentas());
				}
				else if(rodyklius == 'n' || rodyklius == 'N'){
					break;
				}
				else{
					naujasIrasas(rodyklius, rodiklius);
				}
			}
			printeris[k].vienoStudentoIvedimas(pasirinkimas, k, ivestiesBudas_int, option);
			k++;
			rodiklius = 0;
		}

		
		
	}

	else if(ivestiesBudas_int == 1){
		std::string fileName = "kursiokai.txt";
		auto startas = std::chrono::steady_clock::now( );
		readFile(printeris, k, pasirinkimas, fileName);
		auto finisas = std::chrono::duration_cast<std::chrono::milliseconds>( std::chrono::steady_clock::now( ) - startas );
		std::cout << std::endl;
		std::cout << "Nuskaitymas is failo uztruko: " << finisas.count() << " ms" << std::endl;
		std::cout << std::endl;

	}
}

//Funkcija skirta vieno studento ivedimui per konsole - ranka arba atsitiktiniu budu
void Studentas :: vienoStudentoIvedimas(int &pasirinkimas, int& k, int isvedimoPorank, char option){

	std::cout << "Iveskite studento varda" << std::endl;
	std::cin >> name;
	std::cin >> surname;
	
	std::cout << "Ar norite rezultatus sugeneruoti atsitiktinai ? Y/N" << std::endl;
	std::cin >> option;

	if (option == 'Y' || option == 'y') {

		srand(time(0));
		n = rand() % 15 + 1;
		for (int a = 0; a < n; a++) {
			nd_rezultatas.push_back(int());
			nd_rezultatas[a] = rand() % 10 + 1;
		}
		egzamino_rezultatas = rand() % 10 + 1;
		std::cout << std::endl;
		std::cout << std::endl;
		bubbleSort(nd_rezultatas, n);
		std::cout << "Namu darbu rezultatai: " << std::endl;
		for (int a = 0; a < n; a++) {
			std::cout << nd_rezultatas[a] << std::endl;
		}
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << "Egzamino rezultatas: " << std::endl;
		std::cout << egzamino_rezultatas << std::endl;
		std::cout << std::endl;
	} 

	else if (option == 'N' || option == 'n') {
		std::cout << "Iveskite studento egzamino rezultata: " << std::endl;

		validityCheck(egzamino_rezultatas);
		while( egzamino_rezultatas > 10 || egzamino_rezultatas < 1) {
			std::cout << "Egzamino rezultatas privalo buti intervale nuo 1 iki 10, iveskite tinkama rezultata:" << std::endl;
		}

		std::cout << std::endl;

		std::cout << "Iveskite studento namu darbu uzduociu kieki ir kiekvienos uzduoties ivertinima:" << std::endl;
		std::cout << std::endl;

		std::cout << "Namu darbu uzduociu kiekis: ";

		validityCheck(n);
		while(n<0){
			std::cout << "Uzduociu kiekis negali buti 0 ar maziau" << std::endl;
			std::cout << "Iveskite uzduociu kieki: " << std::endl;
			validityCheck(n);
		}
		std::cout << std::endl;

		std::cout << "Namu darbu uzduociu ivertinimai: " << std::endl << std::endl;
		input();

	}

	else {
		std::cout << "Iveskite Y arba N:" << std::endl;
		std::cin >> option;
	}

	galutinioSkaiciavimas(pasirinkimas);

	
}