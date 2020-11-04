/**
 * @file ruleta-ppal.cc
 * @author Marcos Rivera Gavilán (i92rigam@uco.es)
 * @brief Programa principal prueba el funcionamiento de la clase Ruleta
 * @version 1.0
 * @date 2020-10-07
 */

#include "ruleta.h"
#include "jugador.h"
#include "crupier.h"
#include <iostream>
#include <vector>


int main()
{
  system("clear");
  std::cout<<" ___________________________________________________\n";
  std::cout<<"|                                                   |\n";
  std::cout<<"|---------------  Datos del crupier: ---------------|\n";
  std::cout<<"|___________________________________________________|\n";
  Crupier crupier("a","a");//Creamos un crupier para ir añadiendo los datos
  std::string cadena;//Creamos una cadena para almacenar las lecturas de getline
  std::cout<<"\nIntroduzca el DNI del crupier: ";
  getline(std::cin, cadena,'\n');//Leemos el dni del crupier
  crupier.setDNI(cadena);//Guardamos el dni en la estructura auxiliar
  std::cout<<"\nIntroduzca el codigo del crupier: ";
  getline(std::cin, cadena,'\n');//Leemos el código
  crupier.setCodigo(cadena);//Guardamos el código en la estructura auxiliar
  std::cout<<"\nIntroduzca el nombre del crupier: ";
  getline(std::cin, cadena,'\n');//Leemos el nombre
  crupier.setNombre(cadena);//Guardamos el nombre en la estructura auxiliar
  std::cout<<"\nIntroduzca los apellidos del crupier: ";
  getline(std::cin, cadena,'\n');//Leemos los apellidos
  crupier.setApellidos(cadena);//Guardamos los apellidos en la estructura auxiliar
  std::cout<<"\nIntroduzca la edad del crupier: ";
  getline(std::cin, cadena,'\n');//Leemos la edad
  crupier.setEdad(std::stoi(cadena));//Guardamos la edad en la estructura auxiliar
  std::cout<<"\nIntroduzca la dirección del crupier: ";
  getline(std::cin, cadena,'\n');//Leemos la dirección
  crupier.setDireccion(cadena);//Guardamos la dirección en la estructura auxiliar
  std::cout<<"\nIntroduzca la localidad del crupier: ";
  getline(std::cin, cadena,'\n');//Leemos la localidad
  crupier.setLocalidad(cadena);//Guardamos la localidad en la estructura auxiliar
  std::cout<<"\nIntroduzca la provincia del crupier: ";
  getline(std::cin, cadena,'\n');//Leemos la provincia
  crupier.setProvincia(cadena);//Guardamos la provincia en la estructura auxiliar
  std::cout<<"\nIntroduzca el pais del crupier: ";
  getline(std::cin, cadena,'\n');//Leemos el pais
  crupier.setPais(cadena);//Guardamos el pais en la estructura auxiliar
  Ruleta r(crupier);
  int select = 1;
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
    getchar();
    if(select==0)
    {
      std::cout<<"Hasta la próxima.\n";
    }
    else if (select==1)
    {
      system("clear");
      r.leeJugadores();
      std::cout<<"La lectura se completó satisfactoriamente\n";
      std::cout<<"Pulse enter para volver al menu principal...\n";
      getchar();
    }
    else if (select==2)
    {
      system("clear");
      r.escribeJugadores();
      std::cout<<"La escritura se completó satisfactoriamente\n";
      std::cout<<"Pulse enter para volver al menu principal...\n";
      getchar();
    }
    else if (select==3)
    {
      system("clear");
      int njugadores, dineroMesa, nLanzamientosBola, beneficioBanca;//Creamos las variables necesarias para llamar a la función getEstadoRuleta
      r.getEstadoRuleta(njugadores, dineroMesa, nLanzamientosBola, beneficioBanca);//Consultamos el estado de la ruleta y lo almacenamos en las variables
      std::cout<<"En la mesa hay: "<<njugadores<<" jugadores\n";
      std::cout<<"En la mesa hay: "<<dineroMesa<<"€\n";
      std::cout<<"La bola ha sido lanzada: "<<nLanzamientosBola<<" veces\n";
      std::cout<<"El beneficio de la banca en esta mesa es de: "<<beneficioBanca<<"€\n";
      std::cout<<"La bola ha caido en: "<<r.getBola()<<"\n";
      std::cout<<"La banca tiene: "<<r.getBanca()<<"\n";
      std::list<Jugador> jugadores; //Creamos una lista auxiliar de jugadores
      std::list<Jugador>::iterator j;//Creamos un iterador de tipo jugador para la lista de jugadores
      jugadores = r.getJugadores();//Copiamos los jugadores a la lista auxiliar
      j =jugadores.begin();//Hacemos que apunte al incio de la lista
      for (int i = 0; i < (int) jugadores.size(); i++)//Este bucle se repetirá mientras haya jugadores
      {
        std::cout<<"El jugador con DNI: "<<(*j).getDNI()<<" tiene: "<<(*j).getDinero()<<"\n";
        j++;
      }
      std::cout<<"Pulse enter para volver al menu principal...\n";
      getchar();
    }
    else if (select==4)
    {
      system("clear");
      int beneficioBanca = r.getBanca();//Almacenamos el valor actual de la banca para calcular su beneficio
      std::list<Jugador> jugadores; //Creamos una lista auxiliar de jugadores
      jugadores = r.getJugadores();//Copiamos los jugadores a la lista auxiliar
      std::vector<int> beneficioJugadores((int) jugadores.size());//Creamos un vector de enteros que almacenará el beneficio individual de cada jugador
      std::list<Jugador>::iterator j;//Creamos un iterador de tipo jugador para la lista de jugadores
      j =jugadores.begin();//Hacemos que apunte al incio de la lista
      for (int i = 0; i < (int) jugadores.size(); i++)//Este bucle se repetirá mientras haya jugadores
      {
        beneficioJugadores[i] = (*j).getDinero();//Almacenamos el dinero actual de los jugadores para calcular el beneficio
        j++;//Incrementamos el iterador
      }
      r.giraRuleta();//Giramos la ruleta
      std::cout<<"La bola ha caido en la posición: "<<r.getBola()<<"\n";//Indicamos la posición en la que ha caido la bola
      r.getPremios();//Actualizamos los premios en base a este nuevo lanzamiento
      beneficioBanca = r.getBanca() - beneficioBanca;//Calculamos el benefico de la banca en base a su saldo actual
      std::cout<<"El beneficio de la banca ha sido: "<<beneficioBanca<<"\n";//Mostramos cual ha sido el beneficio de la banca en esta tirada
      jugadores = r.getJugadores();//Actualizamos los valores de los jugadores de la lista auxiliar
      j =jugadores.begin();//Hacemos que apunte al incio de la lista
      for (int i = 0; i < (int) jugadores.size(); i++)//Este bucle se repetirá mientras haya jugadores
      {
        beneficioJugadores[i] = (*j).getDinero() - beneficioJugadores[i];//Calculamos los beneficios que han obtenido los jugadores en esta tirada
        std::cout<<"El beneficio del jugador: "<<(*j).getDNI()<<" ha sido de: "<<beneficioJugadores[i]<<"€\n";//Mostramos por pantalla los resultados obtenidos
        j++;//Incrementamos el iterador
      }
      std::cout<<"Pulse enter para volver al menu principal...\n";
      getchar();//Recojemos el enter
    }
    else if (select==5)
    {
      system("clear");
      std::cout<<"Introduce el DNI: del jugador que deseas eliminar: ";
      getline(std::cin, cadena,'\n');
      int res = r.deleteJugador(cadena);
      if (res == 1)
      {
       std::cout<<"El borrado se completó satisfactoriamente\n";
      }
      else if (res == -1)
      {
        std::cout<<"Error, no se pudo borrar porque la lista de jugadores está vacía\n";
      }
      else if (res ==-2)
      {
        std::cout<<"Error, no se pudo borrar porque el jugador no se encuentra en el sistema\n";
      }
      std::cout<<"Pulse enter para volver al menu principal...\n";
      getchar();
    }
    else if (select==6)
    {
      system("clear");
      std::cout<<" ___________________________________________________\n";
      std::cout<<"|                                                   |\n";
      std::cout<<"|---------------  Datos del jugador: ---------------|\n";
      std::cout<<"|___________________________________________________|\n";
      Jugador jugador("a","a");//Creamos un jugador auxiliar para ir añadiendo los datos y hacer el push
      std::cout<<"\nIntroduzca el DNI del juagador: ";
      getline(std::cin, cadena,'\n');//Leemos el dni del jugador
      jugador.setDNI(cadena);//Guardamos el dni en la estructura auxiliar
      std::cout<<"\nIntroduzca el codigo del juagador: ";
      getline(std::cin, cadena,'\n');//Leemos el código
      jugador.setCodigo(cadena);//Guardamos el código en la estructura auxiliar
      std::cout<<"\nIntroduzca el nombre del juagador: ";
      getline(std::cin, cadena,'\n');//Leemos el nombre
      jugador.setNombre(cadena);//Guardamos el nombre en la estructura auxiliar
      std::cout<<"\nIntroduzca los apellidos del juagador: ";
      getline(std::cin, cadena,'\n');//Leemos los apellidos
      jugador.setApellidos(cadena);//Guardamos los apellidos en la estructura auxiliar
      std::cout<<"\nIntroduzca la edad del juagador: ";
      getline(std::cin, cadena,'\n');//Leemos la edad
      jugador.setEdad(std::stoi(cadena));//Guardamos la edad en la estructura auxiliar
      std::cout<<"\nIntroduzca la dirección del juagador: ";
      getline(std::cin, cadena,'\n');//Leemos la dirección
      jugador.setDireccion(cadena);//Guardamos la dirección en la estructura auxiliar
      std::cout<<"\nIntroduzca la localidad del juagador: ";
      getline(std::cin, cadena,'\n');//Leemos la localidad
      jugador.setLocalidad(cadena);//Guardamos la localidad en la estructura auxiliar
      std::cout<<"\nIntroduzca la provincia del juagador: ";
      getline(std::cin, cadena,'\n');//Leemos la provincia
      jugador.setProvincia(cadena);//Guardamos la provincia en la estructura auxiliar
      std::cout<<"\nIntroduzca el pais del juagador: ";
      getline(std::cin, cadena,'\n');//Leemos el pais
      jugador.setPais(cadena);//Guardamos el pais en la estructura auxiliar
      if(r.addJugador(jugador))//Si el jugador no existía y se pudo añadir con exito
      {
        std::cout<<"El jugador se añadió satisfactoriamente\n";
      }
      else//Si el jugador ya existia o no se pudo añadir
      {
        std::cout<<"El jugador no se ha podido añadir porque ya estaba en la mesa\n";
      }
      std::cout<<"Pulse enter para volver al menu principal...\n";
      getchar();//Recojemos el enter
    }
    else//Es el default si se introduce un número que no equivale a ninguna opción
    {
      std::cout<<"Error seleccione una opción valida.";
      std::cout<<"Pulse enter para volver al menu principal...\n";
      getchar();//Recogemos el enter
    }
  }

  return 0;//Fin del programa
}