#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
  srand(time(NULL));
  int nrand = (rand() % 10)+1;
  int numero;
  while (numero != nrand)
  {
    cout << "Introduce un numero: ";
    cin >> numero;
    if (numero > nrand)
    {
      cout << "\nEs menor\n";
    }
    else if(numero < nrand)
    {
      cout << "\nEs mayor\n";
    }
    cout<<"-----------------\n";
  }
  cout << "\nCorrecto, el numero es: " << nrand <<"\n";
  
  return 0;
}
