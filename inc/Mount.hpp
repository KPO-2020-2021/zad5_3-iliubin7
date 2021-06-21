#pragma once

#include "Block.hpp"
/*!
* \file Mount.hpp
*
*/

/*! \class Mount (dziedziczy klas Block)
*
*/
class Mount : public Block
{

public:
/*!
* Konstruktor parametryczny gory z ostrym szczytem
*/
Mount(Vector3D center=Vector3D(), double x=50,double y=50, double z=50,std::string name="../datasets/Mount.dat");
/*!
* Konstruktor parametryczny gory z ostrym szczytem
*/
Mount(Mount& pr);
/*!
* Przeciazenie operatora = klasy Mount (Gora z ostrym szczytem)
*/
Mount &operator=(const Mount &other)
    {
     sizes_of_block=other.sizes_of_block;
     vertex=other.vertex;
     center=other.center;
     name=other.name;
     return *this;
    }
};