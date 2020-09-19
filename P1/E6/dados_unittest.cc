// dados_unittest.cc: Juan A. Romero
// A sample program demonstrating using Google C++ testing framework.
//


// This sample shows how to write a more complex unit test for a class
// that has multiple member functions.
//
// Usually, it's a good idea to have one test for each method in your
// class.  You don't have to do that exactly, but it helps to keep
// your tests organized.  You may also throw in additional tests as
// needed.

#include "dados.h"
#include "gtest/gtest.h"

// Tests the constructor.
TEST(Dados, Constructor) {
  Dados d;
  
  EXPECT_EQ(1, d.getDado1());
  EXPECT_EQ(1, d.getDado2());
  EXPECT_EQ(2, d.getSuma());
  EXPECT_EQ(0,d.getDiferencia());
  EXPECT_EQ(0, d.getLanzamientos1());
  EXPECT_EQ(0, d.getLanzamientos2());
}

// Tests operación lanzamiento
TEST(Dados, Lanzamiento) {
  Dados d;
  for (int i=0; i<100; i++){
    d.lanzamiento();
    EXPECT_GT(d.getDado1(), 0);
    EXPECT_LT(d.getDado1(), 7);
    EXPECT_GT(d.getDado2(), 0);
    EXPECT_LT(d.getDado2(), 7);
    }
  EXPECT_EQ(100, d.getLanzamientos1());
  EXPECT_EQ(100, d.getLanzamientos2());
}

// Tests operación suma
TEST(Dados, Suma) {
  Dados d;
  
  EXPECT_EQ(d.getDado1()+d.getDado2(), d.getSuma());
}

// Tests modificadores
TEST(Dados, Modificadores) {
  Dados d;
  EXPECT_FALSE(d.setDado1(9));
  EXPECT_EQ(1,d.getDado1());
  EXPECT_FALSE(d.setDado1(-9));
  EXPECT_EQ(1,d.getDado1());
  EXPECT_FALSE(d.setDado2(9));
  EXPECT_EQ(1,d.getDado2());
  EXPECT_FALSE(d.setDado2(-9));
  EXPECT_EQ(1,d.getDado2());
  EXPECT_TRUE(d.setDado1(3));
  EXPECT_EQ(3, d.getDado1());
  EXPECT_TRUE(d.setDado2(2));
  EXPECT_EQ(2, d.getDado2());
  EXPECT_EQ(5, d.getSuma());
}

// Test operación diferencia
TEST(Dados, Diferencia) {
  Dados d;

  EXPECT_EQ(abs(d.getDado1()-d.getDado2()), d.getDiferencia());
}

TEST(Dados, Media){
  Dados d;
  EXPECT_EQ(0,d.getMedia1());
  EXPECT_EQ(0,d.getMedia2());
  d.setDado1(3);
  EXPECT_EQ(3, d.getMedia1());
  d.setDado2(2);
  EXPECT_EQ(2, d.getMedia2());
  for (int i=0; i<100; i++){
    d.lanzamiento();
    EXPECT_GT(d.getMedia1(), 0);
    EXPECT_LT(d.getMedia1(), 7);
    EXPECT_GT(d.getMedia2(), 0);
    EXPECT_LT(d.getMedia2(), 7);
  }
}

TEST(Dados, Ultimos){
  Dados d;
  int ultimos[5];
  d.getUltimos1(ultimos);
  for (int i = 0; i < 5; i++)
  {
    EXPECT_EQ(ultimos[i],0);
  }
  d.getUltimos2(ultimos);
  for (int i = 0; i < 5; i++)
  {
    EXPECT_EQ(ultimos[i],0);
  }
  d.setDado1(6);
  d.setDado1(5);
  d.setDado1(4);
  d.setDado1(3);
  d.setDado1(2);
  d.setDado1(1);
  d.getUltimos1(ultimos);
  for (int i = 0; i < 5; i++)
  {
    EXPECT_EQ(ultimos[i],(i+1));
  }
  d.setDado2(6);
  d.setDado2(5);
  d.setDado2(4);
  d.setDado2(3);
  d.setDado2(2);
  d.setDado2(1);
  d.getUltimos2(ultimos);
  for (int i = 0; i < 5; i++)
  {
    EXPECT_EQ(ultimos[i],(i+1));
  }
}