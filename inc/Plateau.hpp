#pragma once

#include "Block.hpp"
/*!
* \file Plateau.hpp
*
*/

/*! \class Plateau (dziedziczy klas Block)
*
*/
class Plateau : public Block
{
public:
/*!
* Konstruktor parametryczny plaskowyzu
*/
Plateau(Vector3D center=Vector3D(), double x=50,double y=50, double z=50,std::string name="../datasets/plateau.dat");
/*!
* Konstruktor parametryczny plaskowyzu
*/
Plateau(Plateau& pr);
/*!
* Przeciazenie operatora = klasy Plateua (Plaskowyz)
*/
Plateau &operator=(const Plateau &other)
    {
  sizes_of_block=other.sizes_of_block;
  vertex=other.vertex;
  center=other.center;
  name=other.name;
  return *this;
    }
};
