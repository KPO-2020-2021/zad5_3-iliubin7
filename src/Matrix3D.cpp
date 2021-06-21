#include "../inc/Matrix3D.hpp"

/*!
* \brief Tworzenie macierzy obrotu dla obrotu w 3D.
* Argumenty:
* anlge - kat obrotu (podany w stopniach)
* Zwraca:
* rotated - macierz obrotu.
*/

Matrix3D matrix_rot_x(double angle)
{
    double angle_radian = angle * M_PI / 180;
    Matrix3D rotated;
    rotated(0, 0) = 1;
    rotated(0, 1) = 0;
    rotated(0, 2) = 0;

    rotated(1, 0) = 0;
    rotated(1, 1) = cos(angle_radian);
    rotated(1, 2) = -sin(angle_radian);

    rotated(2, 0) = 0;
    rotated(2, 1) = sin(angle_radian);
    rotated(2, 2) = cos(angle_radian);
    return rotated;
}
Matrix3D matrix_rot_y(double angle)
{
    double angle_radian = angle * M_PI / 180;
    Matrix3D rotated;
    rotated(0, 0) = cos(angle_radian);;
    rotated(0, 1) = 0;
    rotated(0, 2) = sin(angle_radian);

    rotated(1, 0) = 0;
    rotated(1, 1) = 1;
    rotated(1, 2) = 0;

    rotated(2, 0) = -sin(angle_radian);
    rotated(2, 1) = 0;
    rotated(2, 2) = cos(angle_radian);
    return rotated;
}
Matrix3D matrix_rot_z(double angle)
{
    double angle_radian = angle * M_PI / 180;
    Matrix3D rotated;
    rotated(0, 0) = cos(angle_radian);;
    rotated(0, 1) = -sin(angle_radian);
    rotated(0, 2) = 0;

    rotated(1, 0) = sin(angle_radian);
    rotated(1, 1) = cos(angle_radian);
    rotated(1, 2) = 0;

    rotated(2, 0) = 0;
    rotated(2, 1) = 0;
    rotated(2, 2) = 1;
    return rotated;
}