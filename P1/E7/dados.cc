//Cuerpo de los metodos de la clase Dados

#include <ctime>
#include <cstdlib>
#include "dados.h"

Dados::Dados()
{
  srand(time(NULL));
  d1_=1;
  d2_=1;
  lanz1_=0;
  lanz2_=0;
  sum1_=0;
  sum2_=0;
  for (int i = 0; i < 5; i++)
  {
    v1[i]=0;
    v2[i]=0;
  }
  
}

void Dados::lanzamiento()
{
  d1_=(rand()%6)+1;
  d2_=(rand()%6)+1;
  lanz1_++;
  lanz2_++;
  sum1_ += d1_;
  ordena1();
  sum2_ += d2_;
  ordena2();
}

int Dados::getDado1()
{
  return d1_;
}

int Dados::getDado2()
{
  return d2_;
}

bool Dados::setDado1(int v)
{
  if (v > 0 && v < 7)
  {
    d1_ = v;
    lanz1_++;
    sum1_ += d1_;
    ordena1();
    return true;
  }
  return false;
}

bool Dados::setDado2(int v)
{
  if (v > 0 && v < 7)
  {
    d2_ = v;
    lanz2_++;
    sum2_ += d2_;
    ordena2();
    return true;
  }
  return false;
}

int Dados::getSuma()
{
  return (d1_+d2_);
}

int Dados::getDiferencia()
{
  return (abs(d1_-d2_));
}

int Dados::getLanzamientos1()
{
  return lanz1_;
}

int Dados::getLanzamientos2()
{
  return lanz2_;
}

float Dados::getMedia1()
{
  float media = 0;
  if (lanz1_ == 0)
  {
    return media;
  }
  media = sum1_/lanz1_;
  return media;
}

float Dados::getMedia2()
{
  float media = 0;
  if (lanz2_ == 0)
  {
    return media;
  }
  media = sum2_/lanz2_;
  return media;
}

void Dados::ordena1()
{
  v1[4]=v1[3];
  v1[3]=v1[2];
  v1[2]=v1[1];
  v1[1]=v1[0];
  v1[0]=d1_;
}

void Dados::ordena2()
{
  v2[4]=v2[3];
  v2[3]=v2[2];
  v2[2]=v2[1];
  v2[1]=v2[0];
  v2[0]=d2_;
}

void Dados::getUltimos1(int ultimos[])
{
  ultimos[4]=v1[4];
  ultimos[3]=v1[3];
  ultimos[2]=v1[2];
  ultimos[1]=v1[1];
  ultimos[0]=v1[0];
}

void Dados::getUltimos2(int ultimos[])
{
  ultimos[4]=v2[4];
  ultimos[3]=v2[3];
  ultimos[2]=v2[2];
  ultimos[1]=v2[1];
  ultimos[0]=v2[0];
}
