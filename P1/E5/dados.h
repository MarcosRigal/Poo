//La clase dados representa el lanzamiento de 2 dados.

#ifndef DADOS_H
#define DADOS_H

class Dados
{
private:
  int d1_;
  int d2_;
public:
  Dados();//El constructor no devuelve nada
  void lanzamiento();//El metodo no devuelve nada
  int getDado1();//El metodo devuelve un entero
  int getDado2();//El metodo devuelve un entero
  bool setDado1(int v);//El metodo devuelve un booleano
  bool setDado2(int v);//El metodo devuelve un booleano
  int getSuma();//El metodo devuelve un entero
  int getDiferencia();//El metodo devuelve un entero
};

#endif