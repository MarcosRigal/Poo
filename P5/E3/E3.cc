#include <iostream>
#include <vector>    // necesario para el contenedor vector
#include <cstdlib>   //necesario para rand() y srand()
#include <algorithm>

using namespace std;

int main(void)
{
   int t;
   
   cout << "Ejemplo 1. Uso de  la plantilla de clase 'vector' de la STL de C++"<<endl;
   cout << endl;

   cout << "Introduce el tam. del vector: " ;
   cin >> t;
   cout << endl;
   
   vector <int> x(t);
   cout << "Introducir datos al vector de enteros "<<endl;
   cout << endl;
   
   for (int i=0 ; i<x.size() ; i++) 
   {
      cout << "Introduce un numero: ";
      cin >> x[i];	
   }
   cout << endl;
   
   cout<<"El vector introducido es: ";
   for (int i=0 ; i<x.size() ; i++) cout << x[i] << " ";
   cout << endl;

   std::sort(x.begin(), x.end());

   cout<<"El vector introducido ordenado es: ";
   for (int i=0 ; i<x.size() ; i++) cout << x[i] << " ";
   cout << endl;
}
