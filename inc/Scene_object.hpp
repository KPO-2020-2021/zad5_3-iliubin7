#pragma once

#include <string>
#include <memory>
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
virtual bool check_collision(shared_ptr <Scene_object> ob)=0;
/*! 
*  Metoda wirtualna get_name.
*/
virtual std::string get_name() const=0;
/*! 
*  Metoda wirtualna write_to_file.
*/
virtual void write_to_file()=0;
/*! 
*  Metoda wirtualna get_center.
*/
virtual Vector3D get_center() const=0;
/*! 
*  Metoda wirtualna radius.
*/
virtual double radius()=0;
};


