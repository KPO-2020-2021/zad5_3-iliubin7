#include"../tests/doctest/doctest.h"
#include"../inc/Matrix3D.hpp"
#include"../inc/Vector3D.hpp"

TEST_CASE("test konstruktor bezparametryczny")
{
   Matrix3D a;
   Matrix3D b;
   for(int i = 0; i < 3; ++i)
  {
    for(int j = 0; j < 3; ++j)
    {
      if(i==j)
      {
        b(i,j)=1;
      }
      else
      {
        b(i,j)=0;
      }
    }
  }
   CHECK(a == b);
}

TEST_CASE("test operator mnozenia macierzy razy wektor")
{
   Matrix3D a;
   a(0,0)=2;
   a(0,1)=3;
   a(0,2)=4;
   a(1,0)=5;
   a(1,1)=6;
   a(1,2)=7;
   a(2,0)=8;
   a(2,1)=9;
   a(2,2)=1;
   double tab1[3] = {1,2,3};
   double tab2[3] = {20, 38, 29};
   Vector3D v(tab1);
   Vector3D Res(tab2);
   CHECK(a*v == Res);
}

