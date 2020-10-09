//La clase dados representa el lanzamiento de 2 dados.

#ifndef DADOS_H
#define DADOS_H

class Dados
{
private:
  int d1_;
  int d2_;
  int lanz1_;
  int lanz2_; 
  int sum1_;
  int sum2_;
  int v0_1_;
  int v1_1_;
  int v2_1_;
  int v3_1_;
  int v4_1_;
  int v0_2_;
  int v1_2_;
  int v2_2_;
  int v3_2_;
  int v4_2_;
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