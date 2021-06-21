#include "../inc/Vector.hpp"

template <int Size>
Vector<Size>::Vector()
{
    for (int i = 0; i < Size; i++)
       cord[i] = 0;
    actual_objects++;
    all_objects++;
}

template <int Size>
Vector<Size>::Vector(double cord[Size])
{
    for (int i = 0; i < Size; i++)
        this->cord[i] = cord[i];
    actual_objects++;
    all_objects++;
}

template <int Size>
Vector<Size>::~Vector()
{
    actual_objects--;
}

template <int Size>
Vector<Size> Vector<Size>::operator+(Vector<Size> &arg)
{
    Vector<Size> Result;
    for (int i = 0; i < Size; i++)
    {
       Result[i] = cord[i] + arg[i];
    }
    return Result;
}

template <int Size>
Vector<Size> Vector<Size>::operator-(Vector<Size> &arg)
{
    Vector<Size> Result;
    for (int i = 0; i < Size; i++)
    {
        Result[i] = cord[i] - arg[i];
    }
    return Result;
}
template <int Size>
bool Vector<Size>::operator==(const Vector &v) const
{
    for (unsigned int i=0;i<Size;i++){
        if ((abs(cord[i] - v.cord[i]) <= 0.0001))
            return true;
    }
    return false;
}

template <int Size>
double Vector<Size>::operator[](int index) const
{
    if (index > Size || index < 0)
    {
        std::cerr << "Error: Wektor jest poza zasiegiem!" << std::endl;
        exit(1);
    }
    return cord[index];
}

template <int Size>
double &Vector<Size>::operator[](int index)
{
    if (index > Size || index < 0)
    {
        std::cerr << "Error: Wektor jest poza zasiegiem!" << std::endl;
        exit(1);
    }
    return cord[index];
}

template <int Size>
int Vector<Size>::all_objects = 0;

template <int Size>
int Vector<Size>::actual_objects = 0;

template <int Size>
void Vector<Size>::info()
{
    std::cout << "Akturalna ilosc obiektow Vector3D: " << actual_objects << endl;
    std::cout << "Laczna ilosc obiektow Vector3D: " << all_objects << endl;
}

template <int Size>
std::istream &operator >> (std::istream &Strm, Vector<Size> &Vec)
{
    for (int i = 0; i < Size; i++)
    {
        Strm >> Vec[i];
    }
    return Strm;
}

template <int Size>
inline std::ostream &operator << (std::ostream &Strm, const Vector<Size> &Vec)
{
    for (int i = 0; i < Size; i++)
    {
        Strm << Vec[i] << " ";
    }
    return Strm;
}