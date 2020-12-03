#include "dados.h"
#include "gtest/gtest.h"

/*
--------------------- Mis test(Marcos) ----------------
Estos test se han incluido en los ficheros de test correspondientes a cada apartado pero aquí los junto 
todos para facilitar su correción
*/

TEST(Dados, getDiferencia) {
  Dados d;
  d.setDado1(4);//Comprobamos que devuelva bien la diferencia cuando d1 es mayor que d2
  d.setDado2(2);
  EXPECT_EQ(2, d.getDiferencia());
  d.setDado1(2);//Comprobamos que devuelva bien la diferencia cuando d2 es mayor que d1
  d.setDado2(4);
  EXPECT_EQ(2, d.getDiferencia());
  d.setDado1(2);//Comprobamos que devuelva bien la diferencia cuando d1 es igual que d2
  d.setDado2(2);
  EXPECT_EQ(0, d.getDiferencia());
}

TEST(Dados, getLanzamientos){
  Dados d;
  EXPECT_EQ(0, d.getLanzamientos1());
  EXPECT_EQ(0, d.getLanzamientos2());
  for (int i = 0; i < 7; i++)
  {
    d.lanzamiento();
  }
  EXPECT_EQ(7, d.getLanzamientos1());
  EXPECT_EQ(7, d.getLanzamientos2());
}

TEST(Dados, getMedias){
  Dados d;
  EXPECT_EQ(0, d.getMedia1());
  EXPECT_EQ(0, d.getMedia2());
}

TEST(Dados, setDados){
  Dados d;
  d.setDado1(4);
  d.setDado2(3);
  EXPECT_EQ(4, d.getMedia1());
  EXPECT_EQ(3, d.getMedia2());
}

TEST(Dados, getUltimos){
  Dados d;
  int v1[5], v2[5];
  for (int i = 1; i < 6; i++)
  {
    d.setDado1(i);
    d.setDado2(i);
  }
  d.getUltimos1(v1);
  d.getUltimos2(v2);
  int j = 5;
  for (int i = 0; i < 5; i++)
  {
    EXPECT_EQ(j, v1[i]);
    EXPECT_EQ(j, v1[i]);
    --j;
  }
}