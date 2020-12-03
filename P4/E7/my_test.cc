#include "contador.h"
#include "gtest/gtest.h"

TEST(Contador, Constructor) {
  Contador c;
  EXPECT_EQ(0, c.get());
  Contador c1(8);
  EXPECT_EQ(8, c1.get());
  Contador c2(-9);
  EXPECT_EQ(0, c2.get());
  Contador c3(9000);
  EXPECT_EQ(0, c3.get());
}

TEST(Contador, ContadorPlusPlus) {
  Contador c;
  EXPECT_EQ(0, c.get());
  c++;
  EXPECT_EQ(1, c.get());
  c++;
  EXPECT_EQ(2, c.get());
}

TEST(Contador, PlusPlusContador) {
  Contador c;
  EXPECT_EQ(0, c.get());
  ++c;
  EXPECT_EQ(1, c.get());
  ++c;
  EXPECT_EQ(2, c.get());
}

TEST(Contador, ContadorMinusMinus) {
  Contador c(3);
  EXPECT_EQ(3, c.get());
  c--;
  EXPECT_EQ(2, c.get());
}

TEST(Contador, MinusMinusContador) {
  Contador c(3);
  EXPECT_EQ(3, c.get());
  --c;
  EXPECT_EQ(2, c.get());
}

TEST(Contador, Undo) {
  Contador c;
  EXPECT_FALSE(c.undo());
  EXPECT_EQ(0,c.get());
  c++;
  EXPECT_EQ(1,c.get());
  EXPECT_TRUE(c.undo());
  EXPECT_EQ(0, c.get());
}

TEST(Contador, Asignacion) {
  Contador c;
  c=60;
  EXPECT_EQ(60, c.get());
  c=-9;
  EXPECT_EQ(0, c.get());
  c=7000;
  EXPECT_EQ(1000, c.get());
}

TEST(Contador, EqualPlusMinusContador) {
  Contador c, d;
  c=77;
  EXPECT_EQ(77, c.get());
  d=++c;
  EXPECT_EQ(78, c.get());
  EXPECT_EQ(78, d.get());
  d=--c;
  EXPECT_EQ(77, c.get());
  EXPECT_EQ(77, d.get());
}

TEST(Contador, EqualContadorPlusMinus) {
  Contador c, d;
  c=77;
  EXPECT_EQ(77, c.get());
  d=c++;
  EXPECT_EQ(78, c.get());
  EXPECT_EQ(77, d.get());
  d=c--;
  EXPECT_EQ(77, c.get());
  EXPECT_EQ(78, d.get());
}


TEST(Contador, Suma) {
  Contador c,d;
  c=d+50;
  EXPECT_EQ(50, c.get());
  c=c+8;
  EXPECT_EQ(58, c.get());
}

TEST(Contador, Resta) {
  Contador c, d(10);
  c=d-5;
  EXPECT_EQ(5, c.get());
  c=c-1;
  EXPECT_EQ(4, c.get());
}