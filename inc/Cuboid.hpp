#pragma once

#include "Block.hpp"
/*!
* \file Cuboid.hpp
*
*/

/*! \class Cuboid (dziedziczy klas Block)
*
*/
class Cuboid : public Block
{

public:
/*!
* Konstruktor parametryczny prostopadloscianu
*/
Cuboid(Vector3D center=Vector3D(), double x=50,double y=50, double z=50,std::string name="../datasets/cuboid.dat");
/*!
* Konstruktor parametryczny prostopadloscianu
*/
Cuboid(Cuboid& pr);
/*!
* Przeciazenie operatora = klasy Block (Prostopadloscian)
*/
Cuboid &operator=(const Cuboid &other)
    {
  sizes_of_block=other.sizes_of_block;
  vertex=other.vertex;
  center=other.center;
  name=other.name;
  return *this;
    }
};
