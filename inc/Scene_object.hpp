#pragma once

#include <string>
/*!
* \file Scene_object.hpp
*
*/

/*! \class Scene_object
*
*/
class Scene_object
{

public:
/*! 
*  Metoda wirtualna check_collision
*  Sprawdza, czy wystepuje kolizja.
*/
virtual bool check_collision(){};
/*! 
*  Metoda wirtualna get_name.
*/
virtual std::string get_name() const=0;
/*! 
*  Metoda wirtualna write_to_file
*/
virtual void write_to_file()=0;
};


