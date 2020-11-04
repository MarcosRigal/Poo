#ifndef CONTADOR_H
#define CONTADOR_H

#include <vector>

class Contador
{

private:

  int valor_;
  int min_;
  int max_;
  std::vector<int> history_;
  void controlIntervalo();

public:

  Contador(int valor = 0, int min = 0, int max = 1000);
  Contador operator=(const int &n);
  Contador operator=(const Contador &contador);
  Contador operator++(void);
  Contador operator++(int);
  Contador operator--(void);
  Contador operator--(int);
  Contador operator+(const int &n);
  friend Contador operator+(const int &n, const Contador &contador);
  Contador operator-(const int &n);
  friend Contador operator-(const int &n, const Contador &contador);
  bool undo(int const &n = 1);
  inline int get() const {return valor_;}
};


#endif