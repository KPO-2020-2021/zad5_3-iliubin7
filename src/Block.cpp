#include "../inc/Block.hpp"

Vector3D &Block::operator[](int index)
{
    return vertex[index];
}
Vector3D  Block::operator[](int index) const
{
    return vertex[index];
}

void Block::set_name(std::string name)
{
    this->name = name;
}

void Block::set_center(Vector3D center)
{
    this->center = center;
}

Vector3D Block::get_center() const
{
    return center;
}

std::string Block::get_name() const
{
    return name;
}

void Block::translate(Vector3D trans)
{
    for (int i = 0; i < (int)vertex.size(); i++)
    {
        vertex[i] = vertex[i] + trans;
    }
    center = center + trans;
}

void Block::rotation(Matrix3D rot)
{
    for (int i = 0; i < (int)vertex.size(); i++)
    {
        vertex[i] = (rot * vertex[i]);
    }
    center=rot*center;
}

void Block::write_to_file()
{
    std::fstream file;
    double tab[] = {0, 0, (*sizes_of_block)[2] / 2};
    Vector3D trans_cen(tab);

    file.open(name, std::ios::out);

    for (int i = 0; i < (int)vertex.size(); i += 2)
    {
        file << center + trans_cen << std::endl;
        for (int j = 0; j < 2; j++)
        {
            file << vertex[j + i] << std::endl;
        }
        file << center - trans_cen << std::endl<< std::endl;
    }

    file << center + trans_cen << std::endl;
    for (int j = 0; j < 2; j++)
    {
        file << vertex[j] << std::endl;
    }
    file << center - trans_cen << std::endl<< std::endl;
    file.close();
}

double Block::radius()
 {
     return sqrt(pow(center[0] - vertex[0][0], 2) + pow(center[1] - vertex[1][1], 2) + pow(center[2] - vertex[2][2], 2));
 }