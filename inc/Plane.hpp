#pragma once

#include "Block.hpp"
/*!
* \file Plane.hpp
*
*/

/*! \class Plane (dziedziczy klas Block)
*
*/
class Plane : public Block
{

public:
/*!
* Konstruktor parametryczny gory z grania
*/
Plane(Vector3D center=Vector3D(), double x=50,double y=50, double z=50,std::string name="../datasets/Plane.dat");
/*!
* Konstruktor parametryczny gory z grania
*/
Plane(Plane& pr);
/*!
* Przeciazenie operatora = klasy Plane (gora z grania)
*/
Plane &operator = (const Plane &other)
    {
     sizes_of_block=other.sizes_of_block;
     vertex=other.vertex;
     center=other.center;
     name=other.name;
     return *this;
    }
};