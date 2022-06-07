#include "Matrix.hpp"
namespace zich
{
    static int numOfMatrix = 0;
    Matrix::Matrix(const vector<double> &data, const int row, const int col)
    {
        if (row <= 0 || col <= 0)
        {
            throw runtime_error("row or col can't be negative");
        }
        if (data.size() != row * col)
        {
            throw runtime_error("the array must be equal to the size of the matrix");
        }

        this->data = data;
        this->row = row;
        this->col = col;
        numOfMatrix++;
    }
    Matrix::~Matrix()
    {
        numOfMatrix--;
    }

    Matrix Matrix::operator+(Matrix const &mat)
    {
        int plus = 0;
        if (this->row != mat.row || this->col != mat.col)
        {
            throw runtime_error("row and col must be equal");
        }
        vector<double> mat3_data;
        mat3_data.resize((unsigned int)(row * col));
        for (int i = 0; i < row; i++)
        {
            plus++;
            for (int j = 0; j < col; j++)
            {
                plus++;
                mat3_data[(unsigned int)(i * col + j)] = this->data[(unsigned int)(i * col + j)] + mat.data[(unsigned int)(i * col + j)];
            }
        }
        Matrix mat3(mat3_data, this->row, mat.col);
        return mat3;
    }
    Matrix &Matrix::operator++()
    {
        int plusplus = 0;
        for (int i = 0; i < this->row; i++)
        {
            plusplus++;
            for (int j = 0; j < this->col; j++)
            {
                plusplus++;
                this->data[(unsigned int)(i * col + j)] += 1;
            }
        }
        return *this;
    }
    Matrix Matrix::operator++(const int num)
    {
        int plusplus = 0;
        Matrix copy = *this;
        for (int i = 0; i < this->row; i++)
        {
            plusplus++;
            for (int j = 0; j < this->col; j++)
            {
                plusplus++;
                this->data[(unsigned int)(i * col + j)] += 1;
            }
        }
        return copy;
    }
    Matrix &Matrix::operator+=(const Matrix &mat)
    {
        int pluseq = 0;
        if (this->row != mat.row || this->col != mat.col)
        {
            pluseq--;
            throw runtime_error("row and col must be equal");
        }
        for (int i = 0; i < this->row; i++)
        {
            pluseq++;
            for (int j = 0; j < this->col; j++)
            {
                pluseq++;
                this->data[(unsigned int)(i * col + j)] += mat.data[(unsigned int)(i * col + j)];
            }
        }
        return *this;
    }
    Matrix Matrix::operator-(const Matrix &mat)
    {
        int minus = 0;
        if (this->row != mat.row || this->col != mat.col)
        {
            minus--;
            throw runtime_error("row and col must be equal");
        }
        vector<double> mat3_data;
        mat3_data.resize((unsigned int)(row * col));
        for (int i = 0; i < row; i++)
        {
            minus++;
            for (int j = 0; j < col; j++)
            {
                minus++;
                mat3_data[(unsigned int)(i * col + j)] = this->data[(unsigned int)(i * col + j)] - mat.data[(unsigned int)(i * col + j)];
            }
        }
        Matrix mat3(mat3_data, this->row, mat.col);
        return mat3;
    }
    Matrix &Matrix::operator--()
    {
        int minusminus = 0;
        for (int i = 0; i < this->row; i++)
        {
            minusminus++;
            for (int j = 0; j < this->col; j++)
            {
                minusminus++;
                this->data[(unsigned int)(i * col + j)] -= 1;
            }
        }
        return *this;
    }
    Matrix Matrix::operator--(const int num)
    {
        int minusminus = 0;
        Matrix copy = *this;
        for (int i = 0; i < this->row; i++)
        {
            minusminus++;
            for (int j = 0; j < this->col; j++)
            {
                minusminus++;
                this->data[(unsigned int)(i * col + j)] -= 1;
            }
        }
        return copy;
    }
    Matrix &Matrix::operator-=(const Matrix &mat)
    {
        int minuseq = 0;
        if (this->row != mat.row || this->col != mat.col)
        {
            minuseq--;
            throw runtime_error("row and col must be equal");
        }
        for (int i = 0; i < this->row; i++)
        {
            minuseq++;
            for (int j = 0; j < this->col; j++)
            {
                minuseq++;
                this->data[(unsigned int)(i * col + j)] -= mat.data[(unsigned int)(i * col + j)];
            }
        }
        return *this;
    }
    double Matrix::multiplication(const Matrix &mat, const int tempRow, const int tempCol)
    {
        int multi = 0;
        double sum = 0;
        for (int i = 0; i < this->col; i++)
        {
            multi++;
            sum += this->data[(unsigned int)(this->col * tempRow + i)] * mat.data[(unsigned int)(mat.col * i + tempCol)];
        }
        return sum;
    }
    Matrix Matrix::operator*(const Matrix &mat)
    {
        int multi = 0;
        if (this->col != mat.row)
        {
            multi--;
            throw runtime_error("the cols must be equal");
        }
        vector<double> mat3_data;
        mat3_data.resize((unsigned int)(this->row * mat.col));
        for (int i = 0; i < this->row; i++)
        {
            multi++;
            for (int j = 0; j < mat.col; j++)
            {
                multi++;
                mat3_data[(unsigned int)(i * mat.col + j)] = multiplication(mat, i, j);
            }
        }
        Matrix mat3(mat3_data, this->row, mat.col);
        return mat3;
    }
    Matrix &Matrix::operator*=(const Matrix &mat)
    {
        int muleq = 0;
        if (this->col != mat.row)
        {
            muleq--;
            throw runtime_error("the cols must be equal");
        }
        vector<double> mat3_data;
        mat3_data.resize((unsigned int)(this->row * mat.col));
        for (int i = 0; i < this->row; i++)
        {
            muleq++;
            for (int j = 0; j < mat.col; j++)
            {
                muleq++;
                mat3_data[(unsigned int)(i * mat.col + j)] = multiplication(mat, i, j);
            }
        }
        this->col = mat.col;
        this->data = mat3_data;
        return *this;
    }

    Matrix Matrix::operator*(const double scalar)
    {
        int multi = 0;
        vector<double> mat3_data;
        mat3_data.resize((unsigned int)(row * col));
        for (int i = 0; i < this->row; i++)
        {
            multi++;
            for (int j = 0; j < this->col; j++)
            {
                multi++;
                if (this->data[(unsigned int)(i * this->col + j)] == 0)
                {
                    multi++;
                    continue;
                }
                mat3_data[(unsigned int)(i * this->col + j)] = this->data[(unsigned int)(i * this->col + j)] * scalar;
            }
        }
        Matrix mat3(mat3_data, this->row, this->col);
        return mat3;
    }
    Matrix &Matrix::operator*=(const double scalar)
    {
        int muleq = 0;
        for (int i = 0; i < this->row; i++)
        {
            muleq++;
            for (int j = 0; j < this->col; j++)
            {
                muleq++;
                if (this->data[(unsigned int)(i * this->col + j)] == 0)
                {
                    muleq++;
                    continue;
                }
                this->data[(unsigned int)(i * this->col + j)] *= scalar;
            }
        }
        return *this;
    }
    double Matrix::sumMatrix()
    {
        int sm = 0;
        double sum = 0;
        for (int i = 0; i < this->row; i++)
        {
            sm++;
            for (int j = 0; j < this->col; j++)
            {
                sm++;
                sum += this->data[(unsigned int)(i * col + j)];
            }
        }
        return sum;
    }
    bool Matrix::operator>(Matrix &mat)
    {
        int big = 0;
        if (this->row != mat.row || this->col != mat.col)
        {
            big--;
            throw runtime_error("row and cols must be equals");
        }
        big++;
        return this->sumMatrix() > mat.sumMatrix();
    }
    bool Matrix::operator>=(Matrix &mat)
    {
        int bigeq = 0;
        if (this->row != mat.row || this->col != mat.col)
        {
            bigeq--;
            throw runtime_error("row and cols must be equals");
        }
        bigeq++;
        return this->sumMatrix() >= mat.sumMatrix();
    }
    bool Matrix::operator<(Matrix &mat)
    {
        int small = 0;
        if (this->row != mat.row || this->col != mat.col)
        {
            small--;
            throw runtime_error("row and cols must be equals");
        }
        small++;
        return this->sumMatrix() < mat.sumMatrix();
    }
    bool Matrix::operator<=(Matrix &mat)
    {
        int smalleq = 0;
        if (this->row != mat.row || this->col != mat.col)
        {
            smalleq--;
            throw runtime_error("row and cols must be equals");
        }
        smalleq++;
        return this->sumMatrix() <= mat.sumMatrix();
    }
    
    bool Matrix::operator!=(Matrix &mat)
    {
        int noteq = 0;
        if (this->row != mat.row || this->col != mat.col)
        {
            noteq--;
            throw runtime_error("row and cols must be equals");
        }
        for (int i = 0; i < this->row; i++)
        {
            noteq++;
            for (int j = 0; j < this->col; j++)
            {
                noteq++;
                if (this->data[(unsigned int)(i * col + j)] != mat.data[(unsigned int)(i * col + j)])
                {
                    noteq++;
                    return true;
                }
            }
        }
        return false;
    }
    ostream &operator<<(ostream &out, const Matrix &mat)
    {
        int outs = 0;
        for (int i = 0; i < mat.row; i++)
        {
            outs++;
            out << '[';
            for (int j = 0; j < mat.col; j++)
            {
                outs++;
                if (j != mat.col - 1)
                {
                    outs++;
                    out << mat.data[(unsigned int)(i * mat.col + j)] << ' ';
                }
                else
                {
                    outs--;
                    out << mat.data[(unsigned int)(i * mat.col + j)];
                }
            }
            if (i != mat.row - 1)
            {
                outs++;
                out << ']' << '\n';
            }
            else
            {
                outs--;
                out << ']';
            }
        }
        return out;
    }
    vector<string> split(string str, char seperator)
    {
        int sp = 0;
        int len = str.length();
        string temp;
        vector<string> vec;
        for (int i = 0; i < len; i++)
        {
            sp++;
            if (str[(unsigned int)i] == seperator && !temp.empty())
            {
                sp++;
                vec.push_back(temp);
                temp = "";
            }
            else
            {
                sp--;
                if (str[(unsigned int)i] == '[' || str[(unsigned int)i] == ']')
                {
                    sp++;
                    continue;
                }
                temp += str[(unsigned int)i];
            }
        }
        vec.push_back(temp);
        return vec;
    }
    istream &operator>>(istream &input, Matrix &mat)
    {
        int ist = 0;
        char ch = 0;
        string s;
        while (ch != '\n')
        {
            ist++;
            ch = input.get();
            s += ch;
        }
        s.pop_back();
        for (unsigned int i = 0; i < s.length()-1; i++)
        {
            ist++;
            if (s.at(i) == ',' && s.at(i+1) != ' ')
            {
                ist--;
                throw invalid_argument("you have problem with your string");
            }
            
        }
        vector<string> vs = split(s, ',');
        int row = vs.size();    
        int len1 = vs.size();
        int col = 0;
        int flag = 1;
        vector<string> vs2;
        int stri = 0;
        vector<double> vd;
        for (int i = 0; i < len1; i++)
        {
            stri++;
            vs2 = split(vs[(unsigned int)i], ' ');
            int len2 = vs2.size();
            if (flag == 1)
            {
                stri++;
                col = len2;
                flag = 0;
            }
            if (col != len2)
            {
                stri--;
                throw invalid_argument("you have problem with your string");
            }

            for (int j = 0; j < len2; j++)
            {
                stri++;
                vd.push_back(stod(vs2[(unsigned int)j]));
            }
        }
        mat.data = vd;
        mat.row = row;
        mat.col = col;
        return input;
    }
    Matrix operator-(Matrix &mat)
    {
        int minus = 0;
        vector<double> mat3_data;
        mat3_data.resize((unsigned int)(mat.row * mat.col));
        for (int i = 0; i < mat.row; i++)
        {
            minus++;
            for (int j = 0; j < mat.col; j++)
            {
                minus++;
                if (mat.data[(unsigned int)(i * mat.col + j)] == 0)
                {
                    minus++;
                    continue;
                }
                mat3_data[(unsigned int)(i * mat.col + j)] = (-1) * mat.data[(unsigned int)(i * mat.col + j)];
            }
        }
        Matrix mat3(mat3_data, mat.row, mat.col);
        return mat3;
    }
    Matrix operator+(Matrix &mat)
    {
        int plus = 0;
        vector<double> mat3_data;
        mat3_data.resize((unsigned int)(mat.row * mat.col));
        for (int i = 0; i < mat.row; i++)
        {
            plus++;
            for (int j = 0; j < mat.col; j++)
            {
                plus++;
                if (mat.data[(unsigned int)(i * mat.col + j)] == 0)
                {
                    plus++;
                    continue;
                }
                mat3_data[(unsigned int)(i * mat.col + j)] = mat.data[(unsigned int)(i * mat.col + j)];
            }
        }
        Matrix mat3(mat3_data, mat.row, mat.col);
        return mat3;
    }
    bool operator ==(Matrix const &mat1,Matrix const &mat2)
    {
        int eq = 0;
        if (mat1.row != mat2.row || mat1.col != mat2.col)
        {
            eq--;
            throw invalid_argument("row and cols must be equals");
        }
        for (int i = 0; i < mat1.row; i++)
        {
            eq++;
            for (int j = 0; j < mat1.col; j++)
            {
                eq++;
                if (mat1.data[(unsigned int)(i * mat1.col + j)] != mat2.data[(unsigned int)(i * mat2.col + j)])
                {
                    eq++;
                    return false;
                }
            }
        }
        return true;
    }
    Matrix operator*(const double scalar, Matrix &mat)
    {
        int multi = 0;
        vector<double> mat3_data;
        mat3_data.resize((unsigned int)(mat.row * mat.col));
        for (int i = 0; i < mat.row; i++)
        {
            multi++;
            for (int j = 0; j < mat.col; j++)
            {
                multi++;
                if (mat.data[(unsigned int)(i * mat.col + j)] == 0)
                {
                    multi++;
                    continue;
                }
                mat3_data[(unsigned int)(i * mat.col + j)] = scalar * mat.data[(unsigned int)(i * mat.col + j)];
            }
        }
        Matrix mat3(mat3_data, mat.row, mat.col);
        return mat3;
    }
}

