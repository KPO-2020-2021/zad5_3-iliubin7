#pragma once

#include <iostream>
#include <cmath>
using namespace std;
/*!
* \file Vector.hpp
*
*/


/*! \class Vector
* \brief opisuje wektor o Size-wierszach
*/
template <int Size>
class Vector
{
    static int all_objects;
    static int actual_objects;
    /*!
    * Tablica wektora
    */
    double cord[Size];

public:
   /*! 
   * \brief Konstruktor bezparametryczny klasy Vector

   * Argumenty:
   *     Brak argumentow. 
   * Zwraca:
   *      Tablice wypelniona wartoscia 0.
   */
    Vector();
    /*! 
   * Konstruktor parametryczny klasy Vector
   */
    Vector(Vector<Size> &vec)
    {
        for (int i = 0; i < Size; i++)
            cord[i] = vec.cord[i];

        actual_objects++;
    }
    /*! 
   * Konstruktor parametryczny klasy Vector
   */
    constexpr Vector(const Vector &other)
    {
        for (int i = 0; i < Size; i++)
            cord[i] = other.cord[i];
        actual_objects++;
    }
     /*! 
   * Przeciazenie operatora =
   */
    Vector &operator = (const Vector &other)
    {
        for (int i = 0; i < Size; i++)
            cord[i] = other.cord[i];
        return *this;
    }
    /*! 
     * Przeciazenie operatora =
     */
    Vector &operator = (const float &other)
    {
        for (int i = 0; i < Size; i++)
            cord[i] = other;
        return *this;
    }
    
    /*! 
   * \brief Destruktor klasy Vector

   * Argumenty:
   *     Brak argumentow.  
   * Zwraca:
   *      Usuwa wektor.
   */
    ~Vector();
    /*! 
   * Konstruktor parametryczny klasy Vector
   */
    Vector(double cord[Size]); 
    /*! 
   * \brief Realizuje dodawanie dwoch wektorow. 

   * Argumenty:
   *     this - pierwszy skladnik dodawania,                                   |
 |       arg - drugi skladnik dodawania. 
   * Zwraca:
   *      Sume dwoch skladnikow przekazanych jako wskaznik                      |
 |        na parametr. 
   */
    Vector<Size> operator + (Vector<Size> &arg);
    /*! 
   * \brief Realizuje odejmowanie dwoch wektorow. 

   * Argumenty:
   *    this - pierwszy skladnik odejmowania,                                 |
 |      arg - drugi skladnik odejmowania.  
   * Zwraca:
   *      Roznice dwoch skladnikow przekazanych jako wskaznik                   |
 |        na parametr.  
   */
    Vector<Size> operator - (Vector<Size> &arg);
  /*! 
   * \brief Przeciazenie operatora == (sprawdza czy wektory sa rowne) 

   * Argumenty:
   *   this - pierwszy wektor                           |
 |      v - drugi wektor
   * Zwraca:
   *      wartosc 1 gdy wektory sa rowne,
          a w przypadku przeciwnym zwraca wartosc 0  
   */
   bool operator == (const Vector &v) const;
   /*! 
   * \brief Funktor wektora. 

   * Argumenty:
   *   index - index wektora.
   * Zwraca:
   *      Wartosc wektora w danym miejscu tablicy jako stala.
   */
    double operator[](int index) const;
    /*! 
   * \brief Funktor wektora. 

   * Argumenty:
   *   index - index wektora.
   * Zwraca:
   *      Wartosc wektora w danym miejscu tablicy.
   */
    double &operator[](int index);
    /*!
    * \brief Metoda wypisujaca ilosc obiektow (aktualnych i wszystkich)
    *
    * Argumenty:
    * Brak.
    * Zwraca:
    * actual_objects -  Akturalna ilosc obiektow Vector3D
    * all_objects - Laczna ilosc obiektow Vector3D
    */
    void info();
};

#include "../src/Vector.ipp"
