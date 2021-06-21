#pragma once

#include <iostream>
#include "Matrix.hpp"


typedef Matrix<3>  Matrix3D;

/*!
* \brief Tworzenie macierzy obrotu dla obrotu w 3D.
* Argumenty:
* anlge - kat obrotu (podany w stopniach)
* Zwraca:
* rotated - macierz obrotu.
*/
Matrix3D matrix_rot_x(double angle);
Matrix3D matrix_rot_y(double angle);
Matrix3D matrix_rot_z(double angle);
