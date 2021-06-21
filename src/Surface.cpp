#include "../inc/Surface.hpp"

Surface::Surface(Vector3D sizes, int mesh_density, std::string name)
{
    this->name = name;
    double tab[3];
    straight_counter=0;
    for (int i = -sizes[0] / 2; i < sizes[0] / 2; i += mesh_density)
    {
        for (int j = -sizes[1] / 2; j < sizes[1] / 2; j += mesh_density)
        {
            tab[0] = i;
            tab[1] = j;

            vertex.push_back(tab);
        }
        straight_counter++;
    }
}
Vector3D &Surface::operator[](int index)
{
    return vertex[index];
}
Vector3D Surface::operator[](int index) const
{
    return vertex[index];
}

void Surface::set_name(std::string name)
{
    this->name = name;
}

std::string Surface::get_name() const
{
    return name;
}

void Surface::write_to_file()
{
      std::fstream file;

    file.open(name, std::ios::out);
 for (int i = 0; i < (int)vertex.size(); i ++)
 {
   if(i%straight_counter==0)
   file<<std::endl;
   file<<vertex[i]<<std::endl;
 }
   
    file.close();
}