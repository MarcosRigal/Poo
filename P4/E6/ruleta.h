/**
 * @file ruleta.h
 * @author Marcos Rivera Gavilán (i92rigam@uco.es)
 * @brief La clase ruleta representa el juego de la ruleta del casino.
 * @version 1.0
 * @date 2020-11-02
 */

#ifndef RULETA_H
#define RULETA_H

#include <list>
#include "crupier.h"
#include "jugador.h"

class Ruleta //Definición de la clase ruleta
{
private:

  int banca_;//Saldo de la banca
  int beneficioBanca_;//Beneficio de la banca
  int bola_;//Numero en el que ha caido la bola
  int nLanzamientosBola_;//Numero de lanzamientos de la bola
  std::list<Jugador> jugadores_;//Lista de jugadores que juegan actualmente en la ruleta
  Crupier crupier_;//Crupier encargado de la ruleta
  
  /**
   * @brief Comprueba si el jugador ha ganado su apuesta
   * 
   * @param color al que ha apostado el jugador
   * @return true si el color coincide con el resultado
   * @return false si el color no coincide con el resultado
   */
  
  bool aciertaColor(std::string const &color);
  
  /**
   * @brief Comprueba si el jugador ha ganado su apuesta
   * 
   * @param paridad a la que ha apostado el jugador
   * @return true si la paridad coincide con el resultado
   * @return false si la paridad no coincide con el resultado
   */
  
  bool aciertaParidad(std::string const &paridad);
  
  /**
   * @brief Comprueba si el jugador ha ganado su apuesta
   * 
   * @param zona a la que ha apostado el jugador
   * @return true si la zona coincide con el resultado
   * @return false si la zona no coincide con el resultado
   */
  
  bool aciertaZona(std::string const &zona);

public:

  /**
   * @brief Crea un nuevo objeto ruleta
   * 
   * @param crupier encargado de la ruleta
   */

  inline Ruleta(Crupier const & crupier) : crupier_(crupier.getDNI(), crupier.getCodigo()){srand(time(NULL)); banca_=1000000; bola_=-1; nLanzamientosBola_=0; beneficioBanca_=0;}
  
  /**
   * @brief Devuelve el saldo de la banca
   * 
   * @return int 
   */
  
  inline int getBanca() const {return banca_;}
  
  /**
   * @brief Devuelve el número en el que ha caido la bola
   * 
   * @return int 
   */
  
  inline int getBola() const {return bola_;}
  
  /**
   * @brief Modifica el saldo de la banca
   * 
   * @param saldo que queremos asignarle a la banca
   * @return true si se ha podido asignar
   * @return false si no se ha podido asignar
   */
  
  bool setBanca(int const &saldo);
  
  /**
   * @brief Asigna un valor a la bola
   * 
   * @param valor que se desea asignar a la bola
   * @return true si se ha podido asignar el valor
   * @return false si no se ha podido asignar el valor
   */
  
  bool setBola(int const &valor);
  
  /**
   * @brief Devuelve el crupier encargado de la ruleta
   * 
   * @return Crupier 
   */
  
  inline Crupier getCrupier() const {return crupier_;}
  
  /**
   * @brief Asigna el crupier pasado como parametro a la ruleta
   * 
   * @param crupier que se desea asignar
   */
  
  inline void setCrupier(Crupier const &crupier) {crupier_=crupier;}
  
  /**
   * @brief Devuelve una lista con los jugadores que se encuentran actualmente jugando a la ruleta
   * 
   * @return std::list<Jugador> 
   */
  
  inline std::list<Jugador> getJugadores() const {return jugadores_;}
  
  /**
   * @brief Añade el jugador pasado como parámetro a la ruleta
   * 
   * @param jugador que deseamos añadir
   * @return true si se ha podido añadir
   * @return false si no se ha podido añadir
   */
  
  bool addJugador(Jugador &jugador);
  
  /**
   * @brief Borra el jugador cuyo dni coincide con el dni pasado como parámetro
   * 
   * @param dni del jugador que queremos borrar
   * @return 1 si el jugador se ha eliminado con exito
   * @return -1 si la lista de jugadores está vacía
   * @return -2 si el jugador no se encuentra en la lista
   */
  
  int deleteJugador(std::string const &dni);
  
  /**
   * @brief Borra el jugador pasado como parámetro
   * 
   * @param jugador que queremos borrar
   * @return 1 si el jugador se ha eliminado con exito
   * @return -1 si la lista de jugadores está vacía
   * @return -2 si el jugador no se encuentra en la lista
   */
  
  int deleteJugador(Jugador &jugador);
  
  /**
   * @brief Escribe los datos de la lista de jugadores en el fichero: jugadores.txt
   */
  
  void escribeJugadores();
  
  /**
   * @brief Lee los datos de los jugadores del fichero: jugadores.txt y los pasa a la lista jugadores_
   */
  
  void leeJugadores();
  
  /**
   * @brief Simula el lanzamiento de la bola en la ruleta en el casino devolviendo un numero aleatorio entre 0 y 36
   */
  
  inline void giraRuleta(){setBola(((rand()%37)));};
  
  /**
   * @brief Se ejecuta despues de cada tirada y se encarga de actualizar el saldo de la banca y de los jugadores en base a las apuestas realizadas 
   */

  void getPremios();

  /**
   * @brief Devuelve el estado en el que se encuentra la ruleta
   * 
   * @param njugadores que hay en la mesa
   * @param dineroMesa suma del dinero de la banca y del de los jugadores que hay en la mesa
   * @param nLanzamientosBola numero de veces que se ha lanzado la bola
   * @param beneficioBanca beneficio que ha obtenido la banca
   */

  void getEstadoRuleta(int &njugadores, int &dineroMesa, int &nLanzamientosBola, int &beneficioBanca);
};


#endif