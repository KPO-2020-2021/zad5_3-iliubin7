#include "../inc/Plateau.hpp"

Plateau::Plateau(Vector3D center, double x,double y, double z,std::string name)
{
    double tab[]={x,y,z};
    sizes_of_block=std::make_shared<Vector3D> (tab);
    this->name=name;
  this->center=center;
  Vector3D p;

  p[0]=center[0]-(x/2);
  p[1]=center[1]+(y/2);
  p[2]=center[2]+(z/2);
  vertex.push_back(p);

  p[0]=center[0]-(x/2);
  p[1]=center[1]+(y/2);
  p[2]=center[2]-(z/2);
  vertex.push_back(p);


  p[0]=center[0]+(x/2);
  p[1]=center[1]+(y/2);
  p[2]=center[2]+(z/2);
  vertex.push_back(p);

  p[0]=center[0]+(x/2);
  p[1]=center[1]+(y/2);
  p[2]=center[2]-(z/2);
  vertex.push_back(p);

  p[0]=center[0]+(x/2);
  p[1]=center[1]-(y/2);
  p[2]=center[2]+(z/2);
  vertex.push_back(p);

  p[0]=center[0]+(x/2);
  p[1]=center[1]-(y/2);
  p[2]=center[2]-(z/2);
  vertex.push_back(p);


  p[0]=center[0]-(x/2);
  p[1]=center[1]-(y/2);
  p[2]=center[2]+(z/2);
  vertex.push_back(p);

  p[0]=center[0]-(x/2);
  p[1]=center[1]-(y/2);
  p[2]=center[2]-(z/2);
  vertex.push_back(p);

}

Plateau::Plateau(Plateau& pr)
{
  sizes_of_block=pr.sizes_of_block;
  vertex=pr.vertex;
  center=pr.center;
  name=pr.name;
}