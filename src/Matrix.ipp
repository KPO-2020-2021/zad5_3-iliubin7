#include "../inc/Matrix.hpp"

template <int Size>
Matrix<Size>::Matrix()
{
  for(int i = 0; i < Size; ++i)
  {
    for(int j = 0; j < Size; ++j)
    {
      if(i==j)
      {
        Mat[i][j]=1;
      }
      else
      {
        Mat[i][j]=0;
      }
    }
  }
}

template <int Size>
Vector<Size> Matrix<Size>::operator * (Vector<Size> cor)
{
  Vector<Size> Result;

  for(int i = 0; i < Size; ++i)
  {
    for(int j = 0; j < Size; ++j)
    {
      Result[i] += Mat[i][j] * cor[j];
    }
  }
    return Result;
}

template <int Size>
Matrix<Size> Matrix<Size>::operator * (Matrix<Size> cor)
{
  Matrix<Size> Result;

  for(int i = 0; i < Size; ++i)
  {
    for(int j = 0; j < Size; ++j)
    {
      Result(i,j) = 0;
         for(int k = 0; k < Size; k++ ) 
         Result(i,j) += Mat [ i ][ k ] * cor(k,j) ;
    }
  }
    return Result;
}

template<int Size>
bool Matrix<Size>::operator == (Matrix const &tmp) const{
    for (unsigned int i=0;i<Size;++i){
        for (unsigned int j=0;j<Size;++j){
            if (abs(Mat[i][j]-tmp.Mat[i][j])<=0.000001)
                return true;
        }
    }
    return false;
}

template <int Size>
double Matrix<Size>::operator()(int row, int column) const
{
    if (row > Size|| row < 0 || column > Size || column < 0) 
    {
        std::cerr << "Error: Macierz jest poza zasiegiem" << std::endl;
        exit(1);
    }
    return Mat[row][column];
}

template <int Size>
double &Matrix<Size>::operator()(int row, int column)
{
    if (row > Size || row < 0 || column > Size || column < 0) 
    {
        std::cerr << "Error: Macierz jest poza zasiegiem" << std::endl;
        exit(1);
    }
    return Mat[row][column];
}




template <int Size>
inline std::ostream& operator << (std::ostream &Strm, const Matrix<Size> &cor)
{
   for(int i = 0; i < Size; ++i)
  {
    for(int j = 0; j < Size; ++j)
    {
     cout<<cor(i,j)<<" ";
    }
         cout<<endl;
  }
  return Strm;  
}