#pragma once 

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Block.hpp"
#include "lacze_do_gnuplota.hpp"
#include "Dron.hpp"
#include "Surface.hpp"
#include "Plateau.hpp"
#include "Mount.hpp"
#include "Plane.hpp"
#include <list>  // dla listy
#include <memory> // dla wskaznikow wspoldzielonych
#include "Scene_object.hpp"

#define N 2
/*!
* \file Scene.hpp
*
*/

/*! \class Scene
*
*/
class Scene
{
 /*!
 * Lista obiektow Sceny
 */
 std::list<std::shared_ptr<Scene_object>> List_of_elements;
 PzG::LaczeDoGNUPlota Lacze;
 /*!
 * Lista obiektow typu Dron
 */
 std::list<std::shared_ptr<Dron>> List_of_drons;
 /*!
 * zmienna dla odwolywania do poszczegolnych elementow na scenie (plaskowyz, gora i td.).
 */
  int nr_elem;
  /*!
 * zmienna dla odwolywania do konkretnego drona na scenie.
 */
  int nr_dron;
 /*!
 * Dno plaszczyzny
 */
 Surface *bottom;

 public:
 /*! 
 * Konstruktor klasy Scene
 */
 Scene();
 /*!
 * Metoda do rysowania calej Sceny
 */
 void draw();
 bool interface();
 /*!
 * Destruktor klasy Scene
 * Argumenty:
    Brak argumentow.
* Zwraca:
*   Usuwa dynamicznie zaalokowane obiekty.
 */
 ~Scene();
};
