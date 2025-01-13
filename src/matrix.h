#ifndef MATRIX_H
#define MATRIX_H
#include "fraction.h"
#define MAXROWS 100
#define MAXCOLS 100

using namespace std;
class Matrix
{
public:
    Matrix();
    Matrix(int n, int m);
    Matrix(std::vector<std::vector<Fraction>>& other);
    ~Matrix();



    /* Accessor functions */
    inline void setSize(int n, int m)
    {
        rows = size_t(n);
        cols = size_t(m);
        M.resize(n);
        for (int i = 0; i < M.size(); i++) {
            M[i].resize(m);
        }
    }
    inline int getRows() const
    {
        return rows;
    }
    inline int getCols() const
    {
        return cols;
    }
    inline Fraction getValue(int n, int m) const
    {
        return M[n][m];
    }
    inline void setValue(int n, int m, Fraction x)
    {
        M[n][m] = x;
    }
    inline void clear(){
        M.clear();
    }
    Fraction getDeterminant() const;
    Matrix transpose() const;
    Fraction addition (size_t i1, size_t j1);
    Matrix inverse() const;
    /* Matrix Operation functions */
    friend std::istream& operator >> (std::istream& in, Matrix& m);
    friend std::ostream& operator << (std::ostream& out, Matrix& m);
    friend std::ostream& operator << (std::ostream& out, Matrix&& m);
    friend Matrix operator * (const Matrix& f1, const Matrix& f2);
    friend Matrix operator * (const Matrix& f1, const Matrix&& f2);
    Matrix& operator=(const Matrix& other);
    friend Matrix operator+(const Matrix &m1, const Matrix &m2);
    friend Matrix operator-(const Matrix &f1, const Matrix &f2);

private:
    size_t rows= 1;
    size_t cols= 1;
    std::vector<std::vector<Fraction>> M {rows, std::vector<Fraction> (cols, 1)};
};

#endif // MATRIX_H
