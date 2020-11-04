/**
 * @file ruleta.cc
 * @author Marcos Rivera Gavilán (i92rigam@uco.es)
 * @brief Cuerpo de los métodos de la clase ruleta.
 * @version 1.0
 * @date 2020-10-07
 */

#include "ruleta.h"
#include <iostream>
#include <fstream>
#include <vector>

bool Ruleta::setBanca(int const &saldo)
{
  if (saldo > 0)//Comprobamos que el saldo que le vamos a asignar a la banca sea positivo
  {
    banca_=saldo;//Como es positivo lo asignamos
    return true;//Como se ha podido realizar la asignación devolvemos true
  }
  return false;//Como no se ha podido realizar la asignación devolvemos false
}

bool Ruleta::setBola(int const &valor)
{
  if (valor>-1 && valor<37)//Comprobamos que el valor que le vamos a asignar a la ruleta esté entre 0 y 36
  {
    bola_=valor;//Como está en ese rango, asignamos el valor
    nLanzamientosBola_++;//Sumamos 1 al numero total de lanzamientos de la bola
    return true;//Como la asignación ha podido realizarse correctamente devolvemos true
  }
  return false;//Como la asignación no ha podido realizarse devolvemos false
}

bool Ruleta::aciertaColor(std::string const &color)
{
  std::vector<int> rojo = {1,3,5,7,9,12,14,16,18,19,21,23,25,27,30,32,34,36};
  std::vector<int> negro = {2,4,6,8,10,11,13,15,17,20,22,24,26,28,29,31,33,35};
  if (bola_==0)//Como el cero no se corresponde con ningún color si la bola cae aquí el jugador que haya apostado pierde
  {
    return false;//Devolvemos false pues ha perdido su apuesta
  }
  else if (color=="rojo")//Si el jugador a apostado al rojo
  {
    for (int i = 0; i < (int) rojo.size(); i++)
    {
      if (bola_ == rojo[i])//Y la bola ha caido en un rojo
      {
        return true;//Devolvemos true pues ha ganado
      } 
    }
  }
  else if (color=="negro")//Si el jugador a apostado al negro
  {
    for (int i = 0; i < (int) negro.size(); i++)
    {
      if (bola_ == negro[i])//Y la bola ha caido en un rojo
      {
        return true;//Devolvemos true pues ha ganado
      } 
    }
  }
  return false;//Como no se ha dado ninguna de las condiciones anteriores el jugador ha perdido y devolvemos false
}

bool Ruleta::aciertaParidad(std::string const &paridad)
{
  std::vector<int> impar = {1,3,5,7,9,13,13,15,17,19,21,23,25,27,29,31,33,35};
  std::vector<int> par = {2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36};
  if (bola_==0)//Como el cero no es par o impar si la bola cae aquí el jugador que haya apostado pierde
  {
    return false;//Devolvemos false pues ha perdido su apuesta
  }
  else if (paridad=="par")//Si el jugador a apostado a par
  {
    for (int i = 0; i < (int) par.size(); i++)
    {
      if (bola_ == par[i])//Y la bola ha caido en un par
      {
        return true;//Devolvemos true pues ha ganado
      } 
    }
  }
  else if (paridad=="impar")//Si el jugador a apostado a impar
  {
    for (int i = 0; i < (int) impar.size(); i++)
    {
      if (bola_ == impar[i])//Y la bola ha caido en un impar
      {
        return true;//Devolvemos true pues ha ganado
      } 
    }
  }
  return false;//Como no se ha dado ninguna de las condiciones anteriores el jugador ha perdido y devolvemos false
}

bool Ruleta::aciertaZona(std::string const &zona)
{
  std::vector<int> bajo = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18};
  std::vector<int> alto = {19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36};
  if (bola_==0)//Como el cero no es alto o bajo si la bola cae aquí el jugador que haya apostado pierde
  {
    return false;//Devolvemos false pues ha perdido su apuesta
  }
  else if (zona=="bajo")//Si el jugador a apostado a bajo
  {
    for (int i = 0; i < (int) bajo.size(); i++)
    {
      if (bola_ == bajo[i])//Y la bola ha caido en un bajo
      {
        return true;//Devolvemos true pues ha ganado
      } 
    }
  }
  else if (zona=="alto")//Si el jugador a apostado a alto
  {
    for (int i = 0; i < (int) alto.size(); i++)
    {
      if (bola_ == alto[i])//Y la bola ha caido en un alto
      {
        return true;//Devolvemos true pues ha ganado
      } 
    }
  }
  return false;//Como no se ha dado ninguna de las condiciones anteriores el jugador ha perdido y devolvemos false
}

bool Ruleta::addJugador(Jugador &jugador)
{
  std::list<Jugador>::iterator j;//Creamos un iterador de tipo jugador para la lista de jugadores
  j =jugadores_.begin();//Hacemos que apunte al incio de la lista
  for (int i = 0; i < (int) jugadores_.size(); i++)//Este bucle se repetirá mientras haya jugadores
  {
    if (jugador.getDNI()==(*j).getDNI())//Y comprobamos si el jugador que nos han pasado como parámetro se encuentra ya en la lista
    {
      return false;//Como el jugador ya está en la lista no lo añadimos por eso devolvemos false
    }
    j++;//Incrementamos el iterador de la lista
  }
  jugadores_.push_back(jugador);//Como el jugador no estaba en la lista lo añadimos al final
  std::fstream f((jugador.getDNI()+".txt"),std::fstream::app);//Comprobamos si teníamos ya una ficha con sus datos y si no la creamos
  if (!f)
  {
    std::cout<<"Error al abrir el archivo\n"; //Como no se ha abierto correctamente informamos al usuario de que ha habido un error
    return false;
  }
  return true;//Como el jugador ha sido añadido correctamente devolvemos true
}

int Ruleta::deleteJugador(std::string const &dni)
{
  if (jugadores_.empty())
  {
    return -1;//Si la lista de jugadores está vacía devolvemos -1
  }
  
  std::list<Jugador>::iterator j;//Creamos un iterador de tipo jugador para la lista de jugadores
  j =jugadores_.begin();//Hacemos que apunte al incio de la lista
  for (int i = 0; i < (int) jugadores_.size(); i++)//Este bucle se repetirá mientras haya jugadores
  {
    if (dni==(*j).getDNI())//Vamos comparando el dni que quermos borrar con el dni de todos los jugadores
    {
      j = jugadores_.erase(j);//Si coincide lo eliminamos
      return 1;//Como lo hemos eliminado devolvemos 1
    }
    j++;//Incrementamos el iterador
  }

  return -2;//Como no lo hemos podido borrar porque no estaba devolvemos -2
}

int Ruleta::deleteJugador(Jugador &jugador)
{
  if (jugadores_.empty())
  {
    return -1;//Si la lista de jugadores está vacía devolvemos -1
  }
  
  std::list<Jugador>::iterator j;//Creamos un iterador de tipo jugador para la lista de jugadores
  j =jugadores_.begin();//Hacemos que apunte al incio de la lista
  for (int i = 0; i < (int) jugadores_.size(); i++)//Este bucle se repetirá mientras haya jugadores
  {
    if (jugador.getDNI()==(*j).getDNI())//Vamos comparando el dni del jugador que quermos borrar con el dni de todos los jugadores
    {
      j = jugadores_.erase(j);//Si coincide lo eliminamos
      return 1;//Como lo hemos eliminado devolvemos 1
    }
    j++;//Incrementamos el iterador
  }

  return -2;//Como no lo hemos podido borrar porque no estaba devolvemos -2
}

void Ruleta::escribeJugadores()
{
  std::ofstream f("jugadores.txt"); //Creamos el puntero para abrir el fichero en modo escritura y lo abrimos introduciendo el nombre del fichero que queremos abrir
  if (!f) //comprobamos que el fichero se haya abierto correctamente
  {
    std::cout<<"Error al abrir el archivo\n"; //Como no se ha abierto correctamente informamos al usuario de que ha habido un error
    EXIT_FAILURE; //Salimos y devolviendo una señal de error
  }
  std::list<Jugador>::iterator j;//Creamos un iterador de tipo jugador para la lista de jugadores
  j =jugadores_.begin();//Hacemos que apunte al incio de la lista
  for (int i = 0; i < (int) jugadores_.size(); i++)//Este bucle se repetirá mientras haya jugadores
  {//Añadimos al fichero los datos de cada jugador separandolos con ,
    f<<(*j).getDNI()<<','<<(*j).getCodigo()<<','<<(*j).getNombre()<<','<<(*j).getApellidos()<<','<<(*j).getDireccion()<<','<<(*j).getLocalidad()<<','<<(*j).getProvincia()<<','<<(*j).getPais()<<','<<(*j).getDinero()<<'\n';
    j++;//Incrementamos el iterador
  }
  f.close();//Como ya hemos acabado con el fichero lo cerramos
}

void Ruleta::leeJugadores()
{
  std::ifstream f("jugadores.txt"); //Creamos el puntero para abrir el fichero en modo lectura y lo abrimos introduciendo el nombre del fichero que queremos abrir
  if (!f) //comprobamos que el fichero se haya abierto correctamente
  {
    std::cout<<"Error al abrir el archivo\n"; //Como no se ha abierto correctamente informamos al usuario de que ha habido un error
    EXIT_FAILURE; //Salimos y devolviendo una señal de error
  }
  jugadores_.clear(); //Vaciamos la lista de apuestas del jugador
  Jugador jugador("a","a");//Creamos un jugador auxiliar para ir añadiendo los datos y hacer el push
  std::string cadena;//Creamos una cadena para almacenar las lecturas de getline
  getline(f, cadena,',');//Leemos el dni del jugador
  while (!f.eof()) //Este bucle se repetirá hasta que hallamos llegado al final del fichero y no hay nada mas que leer
  { //Cunado leemos con getline poniendo una condición del tipo ',' el puntero de lectura se queda justo después
    jugador.setDNI(cadena);//Guardamos el dni en la estructura auxiliar
    getline(f, cadena,',');//Leemos el código
    jugador.setCodigo(cadena);//Guardamos el código en la estructura auxiliar
    getline(f, cadena,',');//Leemos el nombre
    jugador.setNombre(cadena);//Guardamos el nombre en la estructura auxiliar
    getline(f, cadena,',');//Leemos los apellidos
    jugador.setApellidos(cadena);//Guardamos los apellidos en la estructura auxiliar
    getline(f, cadena,',');//Leemos la dirección
    jugador.setDireccion(cadena);//Guardamos la dirección en la estructura auxiliar
    getline(f, cadena,',');//Leemos la localidad
    jugador.setLocalidad(cadena);//Guardamos la localidad en la estructura auxiliar
    getline(f, cadena,',');//Leemos la provincia
    jugador.setProvincia(cadena);//Guardamos la provincia en la estructura auxiliar
    getline(f, cadena,',');//Leemos el pais
    jugador.setPais(cadena);//Guardamos el pais en la estructura auxiliar
    getline(f, cadena,'\n');//Leemos el dinero
    jugador.setDinero(std::stoi(cadena));//Guardamos el dinero en la estructura auxiliar
    jugadores_.push_back(jugador);//Añadimos el jugador a la lista
    getline(f, cadena,',');//Leemos el dni
  }
  f.close(); //Como ya no hay nada mas que leer cerramos el fichero
}

void Ruleta::getPremios()
{
  std::list<Apuesta> apuestas;//Creamos una lista auxiliar para las apuestas de los jugadores
  std::list<Apuesta>::iterator a;//Creamos un iterador de tipo apuesta para la lista de apuestas
  std::list<Jugador>::iterator j;//Creamos un iterador de tipo jugador para la lista de jugadores
  j =jugadores_.begin();//Hacemos que apunte al incio de la lista
  for (int i = 0; i < (int) jugadores_.size(); i++)//Este bucle se repetirá mientras haya jugadores
  {
    (*j).setApuestas();//Cargamos en el sistema las apuestas de los jugadores
    j++;//Incrementamos el iterador
  }
  j =jugadores_.begin();//Hacemos que apunte al incio de la lista
  for (int i = 0; i < (int) jugadores_.size(); i++)//Este bucle se repetirá mientras haya jugadores
  {
    apuestas = (*j).getApuestas();//Copiamos la lista de apuestas del jugador a la lista auxiliar
    a = apuestas.begin();//Hacemos que apunte el iterador al incio de la lista
    for (int m = 0; m < (int) apuestas.size(); m++)//Este bucle se repetirá mientras haya apuestas
    {
      switch ((*a).tipo)//En función del tipo de apuesta entraremos a una opción u otra
      {
      case 1://Apuesta a un numero
        if (std::stoi((*a).valor)==bola_)//Si el numero al que ha apostado coincide con el valor de la bola
        {
          (*j).setDinero(((*j).getDinero()+((*a).cantidad*35)));//El jugador gana y su dinero pasa a ser lo que tenía antes +35 veces la cantidad apostada
          beneficioBanca_+= (-((*a).cantidad*35));
          setBanca((getBanca()-((*a).cantidad*35)));//La banca pierde y su dinero pasa a ser su dinero - 35 veces la cantidad apostada por el jugador
          break;
        }//Como no se ha cumplido la primera condición el jugador a perdido
        (*j).setDinero(((*j).getDinero()-(*a).cantidad));//Su dinero pasa a ser su dinero menos la cantidad apostada
        beneficioBanca_+= ((*a).cantidad);
        setBanca((getBanca()+(*a).cantidad));//El dinero de la banca se actualiza y pasa a ser su dinero mas la cantidad apostada por el jugador
        break;
      
      case 2://Apuesta a un color
        if (aciertaColor((*a).valor))//Si el color al que el jugador ha apostado coincide con el que ha salido en la ruleta
        {
          (*j).setDinero(((*j).getDinero()+(*a).cantidad));//Su dinero pasa a ser su dinero mas la cantidad apostada
          beneficioBanca_+= (-((*a).cantidad));
          setBanca((getBanca()-(*a).cantidad));//El dinero de la banca se actualiza y pasa a ser su dinero menos la cantidad apostada por el jugador
          break;
        }//Como no se ha cumplido la primera condición el jugador a perdido
        (*j).setDinero(((*j).getDinero()-(*a).cantidad));//Su dinero pasa a ser su dinero menos la cantidad apostada
        beneficioBanca_+= ((*a).cantidad);
        setBanca((getBanca()+(*a).cantidad));//El dinero de la banca se actualiza y pasa a ser su dinero mas la cantidad apostada por el jugador
        break;
      
      case 3://Apuesta a la paridad
        if (aciertaParidad((*a).valor))//Si la paridad a la que el jugador ha apostado coincide con la que ha salido en la ruleta
        {
          (*j).setDinero(((*j).getDinero()+(*a).cantidad));//Su dinero pasa a ser su dinero mas la cantidad apostada
          beneficioBanca_+= (-((*a).cantidad));
          setBanca((getBanca()-(*a).cantidad));//El dinero de la banca se actualiza y pasa a ser su dinero mas la cantidad apostada por el jugador
          break;
        }//Como no se ha cumplido la primera condición el jugador a perdido
        (*j).setDinero(((*j).getDinero()-(*a).cantidad));//Su dinero pasa a ser su dinero menos la cantidad apostada
        beneficioBanca_+= ((*a).cantidad);
        setBanca((getBanca()+(*a).cantidad));//El dinero de la banca se actualiza y pasa a ser su dinero mas la cantidad apostada por el jugador
        break;

      case 4://Apuesta a una zona
        if (aciertaZona((*a).valor))//Si la zona a la que el jugador ha apostado coincide con el que ha salido en la ruleta
        {
          (*j).setDinero(((*j).getDinero()+(*a).cantidad));//Su dinero pasa a ser su dinero mas la cantidad apostada
          beneficioBanca_+= (-((*a).cantidad));
          setBanca((getBanca()-(*a).cantidad));//El dinero de la banca se actualiza y pasa a ser su dinero mas la cantidad apostada por el jugador
          break;
        }//Como no se ha cumplido la primera condición el jugador a perdido
        (*j).setDinero(((*j).getDinero()-(*a).cantidad));//Su dinero pasa a ser su dinero menos la cantidad apostada
        beneficioBanca_+= ((*a).cantidad);
        setBanca((getBanca()+(*a).cantidad));//El dinero de la banca se actualiza y pasa a ser su dinero mas la cantidad apostada por el jugador
        break;
      }
      a++;
    }
    j++;
  }
}

void Ruleta::getEstadoRuleta(int &njugadores, int &dineroMesa, int &nLanzamientosBola, int &beneficioBanca)
{
  njugadores = (int) jugadores_.size();//Igualamos el numero de jugadores a la longitud de la lista de jugadores
  dineroMesa = banca_;//Sumamos el dinero de la banca al dinero de la mesa
  std::list<Jugador>::iterator j;//Creamos un iterador de tipo jugador para la lista de jugadores
  j =jugadores_.begin();//Hacemos que apunte al incio de la lista
  for (int i = 0; i < (int) jugadores_.size(); i++)//Este bucle se repetirá mientras haya jugadores
  {
    dineroMesa += (*j).getDinero();//Sumamos al dinero de la mesa el dinero de cada uno de los jugadores
  }
  nLanzamientosBola=nLanzamientosBola_;//Le pasamos el numero de lanzamientos de la bola
  beneficioBanca = beneficioBanca_;
}