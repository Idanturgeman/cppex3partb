#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
using namespace std;

namespace zich
{
    class Matrix
    {
    public:
        int getRow(){
            return this->row;
        }
        int getCol(){
            return this->col;
        }
        bool operator>(Matrix &mat);
        bool operator>=(Matrix &mat);
        ~Matrix();
        Matrix operator+(Matrix const &mat);
        Matrix& operator++();
        Matrix operator++(const int num);
        bool operator<(Matrix &mat);
        friend bool operator==(Matrix const &mat1,Matrix const &mat2);
        friend Matrix operator+(Matrix &mat);
        bool operator<=(Matrix &mat);
        bool operator!=(Matrix &mat);
        Matrix operator*(const double scalar);
        friend Matrix operator-(Matrix &mat);
        Matrix operator-(const Matrix &mat);
        Matrix operator*(const Matrix &mat);
        Matrix& operator*=(const Matrix &mat);
        friend Matrix operator*(const double scalar, Matrix &mat);
        Matrix& operator*=(const double scalar);
        double multiplication(const Matrix &mat, const int tempRow, const int tempCol);
        double sumMatrix();
        friend ostream & operator << (ostream &out, const Matrix &mat);
        Matrix& operator--();
        Matrix operator--(const int num);
        Matrix& operator-=(const Matrix &mat);
        Matrix();
        Matrix(const vector<double> &data, const int row, const int col);
        Matrix& operator+=(const Matrix &mat);
        friend istream& operator>> (istream &input , Matrix& mat);
    private:
        int row;
        int col;
        vector<double> data;    
    };
}