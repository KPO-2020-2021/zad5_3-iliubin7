#include"../tests/doctest/doctest.h"
#include"../inc/Vector3D.hpp"

TEST_CASE("test Vector3D operator dodawania"){
double tab1[3] = {1,2,3};
Vector3D v1(tab1);
double tab2[3] = {3,4,5};
Vector3D v2(tab2);
double tab3[3] = {4,6,8};
Vector3D Res(tab3);
    CHECK(v1+v2 == Res);
}

TEST_CASE("test Vector3D operator odejmowania"){
double tab1[3] = {5,6,7};
Vector3D v1(tab1);
double tab2[3] = {3,2,1};
Vector3D v2(tab2);
double tab3[3] = {2,4,6};
Vector3D Res(tab3);
    CHECK(v1-v2 == Res);
}