#pragma once

#include "Vector3D.hpp"
#include "Matrix3D.hpp"
#include <fstream>
#include <vector>
/*!
* \file Surface.hpp
*
*/

/*! \class Surface
*
*/
class Surface
{
protected:
    std::vector<Vector3D> vertex;
    std::string name;
    /*!
    * zmienna potrzebna do zliczenia prostych (zmienna tak naprawde okresla ile musimy dac ENTER, bo zapisujemy liniami)
    */
    int straight_counter;
public:
    /*!
    * Konstruktor parametryczny plaszczyzny
    * Argumenty:
    * sizes - wymiary wektora3D
    * mesh_density - gestosc siatki (domyslnie ustalmy na 10)
    * Zwraca:
    * Plaszczyzne o wymiarach 300x300 (wspolrzedna z = 0)
    */
    Surface(Vector3D sizes=Vector3D(),int mesh_density=10, std::string name="../datasets/surface.dat");

    Vector3D &operator[](int index);
    Vector3D operator[](int index) const;

    void set_name(std::string name);
    std::string get_name() const;
    /*!
    * Metoda do zapisu danych do pliku
    */
    void write_to_file();
};
