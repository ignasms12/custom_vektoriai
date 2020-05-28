#include "vars.h"
#include <gtest/gtest.h>

TEST(count, final_res){
    Studentas testas;
    
    testas.set_vardas("Vardenis");
    testas.set_pavarde("Pavardenis");
    testas.set_exam(8);
    testas.set_kiekis(5);
    for(int i = 0; i < testas.get_kiekis(); i++){
        testas.set_nd(i, i);
    }
    
    //passinamas 0 kad skaiciuotu vidurki o ne mediana
    testas.galutinioSkaiciavimas(0);

    EXPECT_EQ( testas.get_final(), 5.6);
}

TEST(count, digitcounter){
    int b = 3;
    EXPECT_EQ(digitCounter(b), 1);
}

TEST(count, digitcounter2){
    int c = 23;
    EXPECT_EQ( digitCounter(c), 2);
}

int main(int argc, char **argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}