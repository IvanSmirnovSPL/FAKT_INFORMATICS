#include <iostream>
using namespace std;
class Matrix3x3
{
private:
    double data[3][3];
public:
    Matrix3x3()
    {
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                data[i][j] = 0;
            }
        }
    }
    Matrix3x3(
         double a0b0
       , double a0b1
       , double a0b2
       , double a1b0
       , double a1b1
       , double a1b2
       , double a2b0
       , double a2b1
       , double a2b2
         )
         {
            data[0][0] = a0b0;
            data[0][1] = a0b1;
            data[0][2] = a0b2;
            data[1][0] = a1b0;
            data[1][1] = a1b1;
            data[1][2] = a1b2;
            data[2][0] = a2b0;
            data[2][1] = a2b1;
            data[2][2] = a2b2;
         }
    Matrix3x3(double arr[3][3])
    {
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                data[i][j] = arr[i][j];
            }
        }
    }
    double getValue(int i, int j) const
    {
        return data[i][j];
    }
    void setValue(int i, int j, double value)
    {
        data[i][j] = value;
    }
    friend ostream& operator<< (ostream& out, Matrix3x3 mAT)
    {
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                out<<mAT.data[i][j]<<", ";
            }
            out<< std::endl;
        }
        return out;
    }
        friend istream& operator>> (istream& in, Matrix3x3& mAT)
    {
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                in>>mAT.data[i][j];
            }
        }
        return in;
        
    }

    Matrix3x3 operator* (const Matrix3x3& Mat)
    {
        Matrix3x3 res;
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                double sth = 0;
                for (int z = 0; z < 3; ++z) 
                {
                    sth += data[i][z] *  Mat.getValue(z, j);
                }
                res.setValue(i, j, sth);
            }
        }
        return res;
    }

};
int main(int argc, char const *argv[])
{
    Matrix3x3 mat;
    cout<< mat<< endl;
    cin>> mat;
    cout<< mat<< endl;
    Matrix3x3 mat1;
    cin >> mat1;
    Matrix3x3 mat2;
    cin >> mat2;
    cout << mat1 * mat2;
    return 0;
}


