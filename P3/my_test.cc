#include <fstream>
#include <list>
#include "crupier.h"
#include "ruleta.h"
#include "gtest/gtest.h"

//En estos test se prueban tanto la clase crupier como la clase ruleta

using namespace std;

TEST(Ruleta, Constructor) {
  Crupier c("78XX","c1");
  Ruleta r(c);
  
  EXPECT_EQ("78XX", r.getCrupier().getDNI());
  EXPECT_EQ("c1", r.getCrupier().getCodigo());
  EXPECT_EQ(-1, r.getBola());
  EXPECT_EQ(1000000, r.getBanca());
  EXPECT_TRUE(r.getJugadores().empty());
}

TEST(Ruleta, Bola) {
  Crupier c("78XX","c1");
  Ruleta r(c);
  EXPECT_TRUE(r.setBola(30));
  EXPECT_EQ(30, r.getBola());
  EXPECT_FALSE(r.setBola(80));
  EXPECT_EQ(30, r.getBola());
}

TEST(Ruleta, Banca) {
  Crupier c("87XX","c1");
  Ruleta r(c);
  EXPECT_TRUE(r.setBanca(4000000));
  EXPECT_EQ(4000000, r.getBanca());
  EXPECT_FALSE(r.setBanca(-5));
  EXPECT_EQ(4000000, r.getBanca());
}

TEST(Ruleta, EqualCrupier) {
  Crupier c("87XX","c1");
  Crupier d("a","a");
  Ruleta r(c);
  d=r.getCrupier();
  EXPECT_EQ("87XX", d.getDNI());
  EXPECT_EQ("c1", d.getCodigo());
}

TEST(Ruleta, addJugador) {
  Crupier c("95XX","c1");
  Jugador j("78XX","j");
  Ruleta r(c);
  EXPECT_TRUE(r.addJugador(j));
}

TEST(Ruleta, deleteJugador) {
  Crupier c("49CA","c1");
  Jugador j1("78XX","j1");
  Jugador j2("89XX","j2");
  Ruleta r(c);
  r.addJugador(j1);
  r.addJugador(j2);
  EXPECT_EQ(1,r.deleteJugador(j1));
  EXPECT_EQ(1, r.getJugadores().size());
}

TEST(Ruleta, lanzaBola) {
  Crupier c("33XX","crupier1");
  Ruleta r(c);
  r.giraRuleta();
  EXPECT_GT(r.getBola(), -1);
  EXPECT_LT(r.getBola(), 37);
}