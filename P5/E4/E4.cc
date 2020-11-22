#include <iostream>
#include <vector>
#include <algorithm>

bool descendente(int i, int j){return i>j;}

int main(int argc, char const *argv[])
{
   int t;
   
   std::cout << "Ejemplo 1. Uso de  la plantilla de clase 'vector' de la STL de C++"<<std::endl;
   std::cout << std::endl;

   std::cout << "Introduce el tam. del vector: " ;
   std::cin >> t;
   std::cout << std::endl;
   
   std::vector <int> x(t);
   std::cout << "Introducir datos al vector de enteros "<<std::endl;
   std::cout << std::endl;
   
   for (int i=0 ; i<x.size() ; i++) 
   {
      std::cout << "Introduce un numero: ";
      std::cin >> x[i];	
   }
   std::cout << std::endl;
   
   int select = 1;
   while (select !=0 )
   {
      system("clear");
      std::cout<<" ______________________________________________________ \n";
      std::cout<<"|                                                      |\n";
      std::cout<<"|----------------- Menu de selección: -----------------|\n";
      std::cout<<"|______________________________________________________|\n";
      std::cout<<"|                                                      |\n";
      std::cout<<"|Pulsa 1 para ordenar el vector en orden ascendente.   |\n";
      std::cout<<"|Pulsa 2 para ordenar el vector en orden descendente.  |\n";
      std::cout<<"|Pulsa 0 para salir del programa.                      |\n";
      std::cout<<"|______________________________________________________|\n";
      std::cout<<"\n El estado actual del vector introducido es: ";
      for (int i=0 ; i<x.size() ; i++) std::cout << x[i] << " ";
      std::cout << std::endl;
      std::cout<<"\nSu elección: ";
      std::cin >> select;
      getchar();

      if(select==0)
      {
        std::cout<<"Hasta la próxima.\n";
      }
      
      else if (select==1)
      {
         std::sort(x.begin(), x.end());
      }
      else if (select==2)
      {
         std::sort(x.begin(), x.end(), descendente);
      }
      else//Es el default si se introduce un número que no equivale a ninguna opción
      {
        system("clear");
        std::cout<<"Error seleccione una opción valida.\n";
        std::cout<<"Pulse enter para volver al menu principal...\n";
        getchar();//Recogemos el enter
      }
   }  
  
  return 0;//Fin del programa
}