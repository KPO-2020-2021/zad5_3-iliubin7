#pragma once

#include "Block.hpp"
/*!
* \file Prism.hpp
*
*/

/*! \class Prism (dziedziczy klas Block)
*   Klasa opisuje graniastoslup szesciokatny.
*/
class Prism : public Block
{
    public:
    /*!
    * \brief Konstruktor parametryczny klasy Prism.
    * center - wektor3D potrzebny dla srodka graniastoslupa (wartosc zostaje przypisana z kontruktora, czyli)
    * radius - promien potrzebny dla okreslenia granistoslupa (domyslnie jest rowny 15)
    * z - potrzebna dla okreslenia grubosci graniastoslupa (domyslne jest rowna 10)
    * name - nazwa pliku, do ktorego zostana zapisane wspolrzedne graniastoslupa
    * Zwraca:
    * Graniastoslup
    */
    Prism(Vector3D center=Vector3D(),double z=10,double radius=15,std::string name = "../datasets/prism.dat");
};