#include "../inc/Prism.hpp"

Prism::Prism(Vector3D center, double z, double radius , std::string name)
{
    double tab[] = {0, 0, z};
    sizes_of_block =std::make_shared<Vector3D> (tab);
    this->name = name;
    this->center = center;
    Vector3D p;
    for (int i = 0; i < 360; i += 60)
    {
        p[0] = radius * cos(i * M_PI / 180);
        p[1] = radius * sin(i * M_PI / 180);
        p[2] = center[2] + (z / 2);
        vertex.push_back(p);
        p[0] = radius * cos(i * M_PI / 180);
        p[1] = radius * sin(i * M_PI / 180);
        p[2] = center[2] - (z / 2);
        vertex.push_back(p);
    }
}