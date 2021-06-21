#pragma once

#include "Vector3D.hpp"
#include "Matrix3D.hpp"
#include <fstream>
#include <vector>
#include <memory>
/*!
* \file Block.hpp
*
*/

/*! \class Block
*
*/
class Block
{
 /*!
 * Pola klasy Block sa protected dlatego, zeby byly widoczne w klasach pochodnych.
 */
 protected:
 /*!
 * Wskaznik wspoldzielony na wektor 3D przechowujacy wymiary bryly.
 */
 std::shared_ptr<Vector3D> sizes_of_block;
 /*!
 * Wierzcholki bryly.
 */          
 std::vector<Vector3D> vertex;
 /*!
 * Zmienna okreslajaca srodek bryly.
 */     
 Vector3D center;
 /*!
 * Zmienna do zapamietywania nazwy pliku, do ktorego zostanie zapisana dana bryla.
 */          
 std::string name;
 public:

 Vector3D &operator[](int index);
 Vector3D operator[](int index) const;

 void set_center(Vector3D center);
 void set_name(std::string name);
 Vector3D get_center() const;
 std::string get_name() const;
 /*!
 * Metoda translacji bryly o wektor translacji.
 */ 
 void translate(Vector3D trans);
 /*!
 * Metoda obrotu bryly o macierz obrotu.
 */ 
 void rotation(Matrix3D rot);
 /*!
 * Metoda do zapisu danych bryly.
 */
 void write_to_file();
};