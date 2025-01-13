#include "matrix.h"
#include "fraction.h"
using namespace std;


/* Contructor */
Matrix::Matrix()
{

}
Matrix::Matrix(int n, int m)
{
    rows = size_t(n);
    cols = size_t(m);
    M = std::vector<std::vector<Fraction>>(size_t(n), std::vector<Fraction> (size_t(m), 1));
}
Matrix::Matrix(std::vector<std::vector<Fraction>>& other) : rows(other.size()), cols(other[0].size()), M(other) {}

Matrix::~Matrix()
{
}


/* Matrix Operation functions */

Fraction Matrix::addition (size_t i1, size_t j1) {
    std::vector<std::vector<Fraction>> new_data;
    for (size_t i = 0; i != rows; i++) {
        if (i != i1) {
            std::vector<Fraction> temp;
            for (size_t j = 0; j != rows; ++j) {
                if (j != j1) {
                    temp.push_back(M[i][j]);
                }
            }
            new_data.push_back(temp);
        }
    }
    Matrix add(new_data);
    return add.getDeterminant() * Fraction((pow(-1,i1+j1)));
}


Matrix operator+(const Matrix &m1, const Matrix &m2)
{
    // Проверь одинаковая ли размерность матриц
    Matrix res = m1;
    for (int i = 0; i != m1.getRows(); i++)
    {
        for (int j = 0; j != m1.getCols(); j++)
        {
            res.M[i][j] += m2.M[i][j];
        }
    }
    return res;
}

Matrix operator-(const Matrix &f1, const Matrix &f2)
{
    // Проверь одинаковая ли размерность матриц
    Matrix res(f1);
    for (int i = 0; i != f1.getRows(); i++)
    {
        for (int j = 0; j != f1.getCols(); j++)
        {
            res.M[i][j] -= f2.M[i][j];
        }
    }
    return res;
}

/*float Matrix::dot(Matrix &B, int row, int col)  const*/
/* Computes the dot product of one row of a matrix with the column of another */
/*{
    float sum = 0;

    for(int i = 0; i < cols; i++)
    {
            sum = sum + getValue(row,i)*B.getValue(i, col);
    }

    return sum;
}
*/
Matrix pow (Matrix& matrix, unsigned int p) {
    Matrix m2 = matrix;
    for (int i = 1; i != p; ++i) {
        m2 = m2 * matrix;
    }
    return m2;
}
Matrix operator * (const Matrix& f1, const Matrix&& f2) {
    //if (f1.getCols() != f2.getRows()) {
        //Если число столбцов первой матрицы не равно числу строк во второй то умножать нельзя, обработай это как-то
    //}
    size_t n = f1.getRows(), m = f2.getCols(), COMMON = f1.getCols();
    Matrix res(n, m);
    for (size_t i = 0; i != n; ++i) {
        for (size_t j = 0; j != m; ++j) {
            Fraction temp = 0;
            for (size_t k = 0; k != COMMON; ++k) {
                temp += f1.M[i][k] * f2.M[k][j];
            }
            res.M[i][j] = temp;
        }
    }
    return res;

}
Matrix operator * (const Matrix& f1, const Matrix& f2) {
    //if (f1.getCols() != f2.getRows()) {
        //Если число столбцов первой матрицы не равно числу строк во второй то умножать нельзя, обработай это как-то
    //}
    int n = f1.getRows(), m = f2.getCols();
    Matrix res(n, m);
    for (size_t i = 0; i != n; ++i) {
        for (size_t j = 0; j != m; ++j) {
            Fraction temp = 0;
            for (size_t k = 0; k != f1.getCols(); ++k) {
                temp += f1.M[i][k] * f2.M[k][j];
            }
            res.M[i][j] = temp;
        }
    }
    return res;

}
Matrix Matrix::inverse() const {
    Fraction det = this->getDeterminant();
    Matrix tr_matrix = this->transpose();
    if (det == 0) {
        //Emilbek, я хз что нужно сделать, если определитель 0 (если что тогда обратную матрицу найти нельзя)
    }
    std::vector<std::vector<Fraction>> result {rows, std::vector<Fraction> (rows, 0)};
    for (size_t i = 0; i != rows; ++i) {
        for (size_t j = 0; j != rows; ++j) {
            result[i][j] = Fraction(tr_matrix.addition(i, j)/det);
        }
    }
    Matrix res = Matrix(result);
    return res;
}

/*Matrix Matrix::cofactor() const
{
    // only for square matrices
    Matrix A(rows, cols);
    for( int i = 0; i < A.rows; i++)
    {
        for(int j = 0; j < A.cols; j++)
        {
            Matrix B = minor(i,j);

            if(((i%2) == 0 && (j%2 ==0) )|| (i==j))
            { A.setValue(i,j, B.det()); }
            else
            { A.setValue(i,j, -(B.det()));}
        }
    }

    cout << A << endl;
    return A;
}*/
Matrix Matrix::transpose() const {
    std::vector<std::vector<Fraction>> new_data;
    for (size_t j = 0; j != rows; ++j) {
        std::vector<Fraction> temp;
        for (size_t i = 0; i != rows; ++i) {
            temp.push_back(M[i][j]);
        }
        new_data.push_back(temp);
    }
    Matrix tr_matrix(new_data);
    return tr_matrix;
}

Fraction Matrix::getDeterminant() const {
    if (rows == 1) {
        return M[0][0];
    } else if (rows == 2) {
        return M[0][0]*M[1][1] - M[0][1]*M[1][0];
    } else if (rows >= 3) {
        Fraction det = 0;
        for (size_t k = 0; k != rows; ++k) {
            std::vector<std::vector<Fraction>> sub_data;
            for (size_t i = 1; i != rows; ++i) {
                std::vector<Fraction> temp;
                for (size_t j = 0; j != rows; ++j) {
                    if (j != k) {
                        temp.push_back(M[i][j]);
                    }
                }
                sub_data.push_back(temp);
            }
            Matrix sub_matrix(sub_data);
            det += M[0][k] * sub_matrix.getDeterminant() * pow(-1, k);
        }
        return det;
    }
    return {0};
}
/*Matrix Matrix::minor(int i,int j) const
{
    Matrix min(rows-1,cols-1);

    for(int n = 0; n < min.getRows();n++)
    {
        for(int m = 0; m < min.getCols(); m++)
        {
            if(m >= j && n>=i)
                min.setValue(n,m, getValue(n+1,m+1));
            if (m >= j && n<i)
                    min.setValue(n,m, getValue(n, m+1));
            if(m < j && n>=i)
                min.setValue(n,m, getValue(n+1,m));
            if(n<i && m < j)
                min.setValue(n,m, getValue(n, m));
        }
    }
    return min;
}*/

std::istream& operator >> (std::istream& in, Matrix& matrix) {
    for (int i = 0; i != matrix.rows; ++i) {
        for (int j = 0; j != matrix.cols; ++j) {
            in >> matrix.M[i][j];
        }
    }
    return in;
}
std::ostream& operator << (std::ostream& out, Matrix& matrix) {
    for (int i = 0; i != matrix.rows; ++i) {
        for (int j = 0; j != matrix.cols; ++j) {
            out << matrix.M[i][j] << " ";
        }
        out << "\n";
    }
    return out;
}

std::ostream& operator << (std::ostream& out, Matrix&& matrix) {
    for (int i = 0; i != matrix.rows; ++i) {
        for (int j = 0; j != matrix.cols; ++j) {
            out << matrix.M[i][j] << " ";
        }
        out << "\n";
    }
    return out;
}

Matrix& Matrix::operator=(const Matrix& other) {
    rows = other.rows;
    cols = other.cols;
    M = other.M;
    return *this;
}


