#include "crupier.h"
#include <fstream>
#include <list>
#include "jugador.h"
#include "gtest/gtest.h"
using namespace std;

/*
--------------------- Mis test Jugador(Marcos) ----------------
*/


TEST(Jugador, Constructor) {
  Jugador j("77XX", "9A");
  
  EXPECT_EQ("77XX", j.getDNI());
  EXPECT_EQ("9A", j.getCodigo());
  EXPECT_EQ("", j.getNombre());
  EXPECT_EQ("", j.getApellidos());
  EXPECT_EQ("", j.getDireccion());
  EXPECT_EQ("", j.getLocalidad());
  EXPECT_EQ("", j.getProvincia());
  EXPECT_EQ("", j.getPais());
  EXPECT_EQ(", ", j.getApellidosyNombre());
}

TEST(Jugador, ConstructorCompleto) {
  Jugador j("95XX", "3A", "Marcos", "Rivera",19, "C/ Silla 1", "Córdoba", "Córdoba", "España");
  
  EXPECT_EQ("95XX", j.getDNI());
  EXPECT_EQ("3A", j.getCodigo());
  EXPECT_EQ("Marcos", j.getNombre());
  EXPECT_EQ("Rivera", j.getApellidos());
  EXPECT_EQ(19, j.getEdad());
  EXPECT_EQ("C/ Silla 1", j.getDireccion());
  EXPECT_EQ("Córdoba", j.getLocalidad());
  EXPECT_EQ("Córdoba", j.getProvincia());
  EXPECT_EQ("España", j.getPais());
  EXPECT_EQ("Rivera, Marcos", j.getApellidosyNombre());
}

TEST(Jugador, Dinero) {
  Jugador j("95XX", "2A");

  EXPECT_EQ(1000, j.getDinero());
  j.setDinero(-3);
  EXPECT_EQ(-3, j.getDinero());
  j.setDinero(0);
  EXPECT_EQ(0, j.getDinero());
  j.setDinero(4000);
  EXPECT_EQ(4000, j.getDinero());
}

TEST(Jugador, Codigo) {
  Jugador j("33XX", "4A");

  EXPECT_EQ("4A", j.getCodigo());
  j.setCodigo("3A");
  EXPECT_EQ("3A", j.getCodigo());
  
}

TEST(Jugador, Apuestas) {
  Jugador j("44XX", "1");
  list<Apuesta> l;
  l= j.getApuestas();
  EXPECT_TRUE(l.empty());
}

/*
--------------------- Mis test Crupier(Marcos) ----------------
*/

TEST(Crupier, Constructor) {
  Crupier c("44XX", "7B");
  
  EXPECT_EQ("44XX", c.getDNI());
  EXPECT_EQ("7B", c.getCodigo());
  EXPECT_EQ("", c.getNombre());
  EXPECT_EQ("", c.getApellidos());
  EXPECT_EQ("", c.getDireccion());
  EXPECT_EQ("", c.getLocalidad());
  EXPECT_EQ("", c.getProvincia());
  EXPECT_EQ("", c.getPais());
  EXPECT_EQ(", ", c.getApellidosyNombre());
}

TEST(Crupier, ConstructorCompleto) {
  Crupier c("95XX", "9A", "Marcos", "Rivera",19, "C/ Silla 1", "Córdoba", "Córdoba", "España");
  
  EXPECT_EQ("95XX", c.getDNI());
  EXPECT_EQ("9A", c.getCodigo());
  EXPECT_EQ("Marcos", c.getNombre());
  EXPECT_EQ("Rivera", c.getApellidos());
  EXPECT_EQ(19, c.getEdad());
  EXPECT_EQ("C/ Silla 1", c.getDireccion());
  EXPECT_EQ("Córdoba", c.getLocalidad());
  EXPECT_EQ("Córdoba", c.getProvincia());
  EXPECT_EQ("España", c.getPais());
  EXPECT_EQ("Rivera, Marcos", c.getApellidosyNombre());
}

TEST(Crupier, ConstructorCopia) {
  Crupier p("95XX", "9A", "Marcos", "Rivera",19, "C/ Silla 1", "Córdoba", "Córdoba", "España");
  Crupier c(p);

  EXPECT_EQ("95XX", c.getDNI());
  EXPECT_EQ("9A", c.getCodigo());
  EXPECT_EQ("Marcos", c.getNombre());
  EXPECT_EQ("Rivera", c.getApellidos());
  EXPECT_EQ(19, c.getEdad());
  EXPECT_EQ("C/ Silla 1", c.getDireccion());
  EXPECT_EQ("Córdoba", c.getLocalidad());
  EXPECT_EQ("Córdoba", c.getProvincia());
  EXPECT_EQ("España", c.getPais());
  EXPECT_EQ("Rivera, Marcos", c.getApellidosyNombre());
}

TEST(Crupier, Igual) {
  Crupier p("95XX", "9A", "Marcos", "Rivera",19, "C/ Silla 1", "Córdoba", "Córdoba", "España");
  Crupier c("99XX","7a");
  c=p;
  EXPECT_EQ("95XX", c.getDNI());
  EXPECT_EQ("9A", c.getCodigo());
  EXPECT_EQ("Marcos", c.getNombre());
  EXPECT_EQ("Rivera", c.getApellidos());
  EXPECT_EQ(19, c.getEdad());
  EXPECT_EQ("C/ Silla 1", c.getDireccion());
  EXPECT_EQ("Córdoba", c.getLocalidad());
  EXPECT_EQ("Córdoba", c.getProvincia());
  EXPECT_EQ("España", c.getPais());
  EXPECT_EQ("Rivera, Marcos", c.getApellidosyNombre());
}
