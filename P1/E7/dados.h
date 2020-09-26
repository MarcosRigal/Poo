//La clase dados representa el lanzamiento de 2 dados.

#ifndef DADOS_H
#define DADOS_H

class Dados
{
private:
  int d1_;
  int d2_;
  float lanz1_;
  float lanz2_; 
  float sum1_;
  float sum2_;
  int v1[5];
  int v2[5];
public:
  Dados();//El constructor no devuelve nada
  void lanzamiento();//El metodo no devuelve nada
  int getDado1();//El metodo devuelve un entero
  int getDado2();//El metodo devuelve un entero
  bool setDado1(int v);//El metodo devuelve un booleano
  bool setDado2(int v);//El metodo devuelve un booleano
  int getSuma();//El metodo devuelve un entero
  int getDiferencia();//El metodo devuelve un entero
  int getLanzamientos1();//El metodo devuelve un entero
  int getLanzamientos2();//El metodo devuelve un entero
  float getMedia1();//El metodo devuelve un flotante
  float getMedia2();//El metodo devuelve un flotante
  void ordena1();//El metodo no devuelve nada
  void ordena2();//El metodo no devuelve nada
  void getUltimos1(int ultimos[]);//El metodo no devuelve nada
  void getUltimos2(int ultimos[]);//El metodo no devuelve nada
};

#endif