//Programa principal prueba el funcionamiento de la clase Ruleta

#include "ruleta.h"
#include "ruleta.cc"
#include "jugador.h"
#include "crupier.h"
#include <iostream>

int main()
{
  Crupier crupier("a","a");
  std::string cadena;
  Ruleta r(crupier);
  int njugadores, dineroMesa, nLanzamientosBola, beneficioBanca, select = 1;
  while (select !=0 )
  {
    system("clear");
    std::cout<<" _____________________________________________________________________________________\n";
    std::cout<<"|                                                                                     |\n";
    std::cout<<"|--------------------------------  Menu de selección: --------------------------------|\n";
    std::cout<<"|_____________________________________________________________________________________|\n";
    std::cout<<"|                                                                                     |\n";
    std::cout<<"|Pulsa 1 para cargar los jugadores del fichero jugadores.txt                          |\n";
    std::cout<<"|Pulsa 2 para guardar los jugadores en jugadores.txt.                                 |\n";
    std::cout<<"|Pulsa 3 para ver el estado de la ruleta, el dinero de la banca y el de los jugadores.|\n";
    std::cout<<"|Pulsa 4 para hacer girar la ruleta.                                                  |\n";
    std::cout<<"|Pulsa 5 para eliminar un jugador de la mesa.                                         |\n";
    std::cout<<"|Pulsa 6 para añadir un jugador a la mesa.                                            |\n";
    std::cout<<"|Pulsa 0 para salir del programa.                                                     |\n";
    std::cout<<"|_____________________________________________________________________________________|\n";
    std::cout<<"\nSu elección: ";
    std::cin >> select;
    if(select==0)
    {
      std::cout<<"Hasta la próxima.\n";
    }
    else if (select==1)
    {
      r.leeJugadores();
    }
    else if (select==2)
    {
      r.escribeJugadores();
    }
    else if (select==3)
    {
      system("clear");
      r.getEstadoRuleta(njugadores, dineroMesa, nLanzamientosBola, beneficioBanca);
      std::cout<<"En la mesa hay: "<<njugadores<<" jugadores\n";
      std::cout<<"En la mesa hay: "<<dineroMesa<<"€\n";
      std::cout<<"La bola ha sido lanzada: "<<nLanzamientosBola<<" veces\n";
      std::cout<<"El beneficio de la banca en esta mesa es de: "<<beneficioBanca<<"€\n";
      std::cout<<"La bola ha caido en: "<<r.getBola()<<"\n";
      std::cout<<"La banca tiene: "<<r.getBanca()<<"\n";
      std::cout<<"Los jugadores tienen: "<<"\n";
      std::list<Jugador> jugadores; //Creamos una lista auxiliar de jugadores
      std::list<Jugador>::iterator j;//Creamos un iterador de tipo jugador para la lista de jugadores
      jugadores = r.getJugadores();//Copiamos los jugadores a la lista auxiliar
      j =jugadores.begin();//Hacemos que apunte al incio de la lista
      for (int i = 0; i < (int) jugadores.size(); i++)//Este bucle se repetirá mientras haya jugadores
      {
        std::cout<<"El jugador con DNI: "<<(*j).getDNI()<<" tiene: "<<(*j).getDinero()<<"\n";
        j++;
      }
    }
    else if (select==4)
    {
        r.giraRuleta();
        r.getEstadoRuleta(njugadores, dineroMesa, nLanzamientosBola, beneficioBanca);

    }
    else if (select==5)
    {
      system("clear");
      std::cout<<"Introduce el DNI: del jugador que deseas eliminar: ";
      std::string dni;
      std::cin>>dni;
      r.deleteJugador(dni);
    }
    else if (select==6)
    {

    }
    else
    {
      std::cout<<"Error seleccione una opción valida.";
      break;
    }
  }

  return 0;
}