#include <iostream>
#include <math.h>
#include "s21_matrix_oop.h"

S21Matrix::S21Matrix(): _rows(1), _cols(1) {
    create();
}

S21Matrix::S21Matrix(int rows, int cols) {
    if (rows <= 0 || cols <=0)
        throw std::out_of_range("Incorrect input, index is out of range");
    _rows = rows;
    _cols = cols;
    create();
}

S21Matrix::S21Matrix(const S21Matrix& other):
    _rows(other.getRows()), _cols(other.getColumns()) {
        create();
        for (int i = 0; i < _rows; i++)
            for (int j = 0; j < _cols; j++)
                _matrix[i][j] = other._matrix[i][j];
}

S21Matrix::S21Matrix(S21Matrix&& other):
    _rows(0), _cols(0), _matrix(nullptr) {
        std::swap(_rows, other._rows);
        std::swap(_cols, other._cols);
        std::swap(_matrix, other._matrix);
}

S21Matrix::~S21Matrix() {
    destroy();
}
void S21Matrix::destroy() {
    for (int i = 0; i <_rows; i++) {
        if (_matrix[i] != nullptr) delete [] _matrix[i];
    }
    if (_matrix != nullptr) delete[] _matrix;
}

void S21Matrix::create() {
    _matrix = new double*[_rows];
    for (int i = 0; i <_rows; i++)
        _matrix[i] = new double[_cols];
    for (int i = 0; i < _rows; i++)
        for (int j = 0; j < _cols; j++)
            _matrix[i][j] = 0;
}

int S21Matrix::getColumns() const {
    return _cols;
}

int S21Matrix::getRows() const {
    return _rows;
}

void S21Matrix::setColumns(int _cols) {
    if (_cols != this->_cols) {
        int _rows = this->_rows;
        destroy();
        this->_cols = _cols;
        this->_rows = _rows;
        create();
    }
}

void S21Matrix::setRows(int _rows) {
    if (_rows != this->_rows) {
        int _cols = this->_cols;
        destroy();
        this->_cols = _cols;
        this->_rows = _rows;
        create();
    }
}

bool S21Matrix::eq_matrix(const S21Matrix& other) {
    bool result = true;
    if (_rows != other._rows || _cols != other._cols) result = false;
    for (int i = 0; i < _rows && result; i++)
        for (int j = 0; j < _cols && result; j++)
            if (fabs(_matrix[i][j] - other._matrix[i][j]) > 1e-10) result = false;
    return result;
}

void S21Matrix::sum_matrix(const S21Matrix& other) {
    if (_rows != other._rows || _cols != other._cols) {
        throw std::out_of_range(
            "Incorrect input, different matrix dimensions");
    }
    for (auto i = 0; i < _rows; i++)
        for (auto j = 0; j < _cols; j++)
        _matrix[i][j] += other._matrix[i][j];
}

void S21Matrix::sub_matrix(const S21Matrix& other) {
    if (_rows != other._rows || _cols != other._cols) {
        throw std::out_of_range(
            "Incorrect input, different matrix dimensions");
    }
    for (auto i = 0; i < _rows; i++)
        for (auto j = 0; j < _cols; j++)
        _matrix[i][j] -= other._matrix[i][j];
}

void S21Matrix::mul_number(const double num) {
    for (auto i = 0; i < _rows; i++)
        for (auto j = 0; j < _cols; j++)
            _matrix[i][j] *= num;
}

void S21Matrix::mul_matrix(const S21Matrix& other) {
    if (_cols != other._rows) {
        throw std::out_of_range(
            "Incorrect input, the number of columns and rows are not equal");
    }
    S21Matrix temp(*this);
    destroy();
    _cols = other._cols;
    create();
    for (int i = 0; i < _rows; i++) {
        for (int j = 0; j < _cols; j++) {
            _matrix[i][j] = 0;
            for (int k = 0; k < temp._cols; k++) {
                _matrix[i][j] += (temp._matrix[i][k])*(other._matrix[k][j]);
            }
        }
    }
}

S21Matrix S21Matrix::transpose() const {
    S21Matrix result = S21Matrix(_cols, _rows);
    for (int i = 0; i < _rows; i++)
        for (int j = 0; j < _cols; j++)
            result._matrix[j][i] = _matrix[i][j];
    return result;
}

S21Matrix S21Matrix::calc_complements() const {
    if (_cols != _rows || _cols <= 1)
        throw std::out_of_range("Incorrect input, the matrix is not square");
    S21Matrix result = S21Matrix(_rows, _cols);
    for (int i = 0; i < _rows; i++) {
        for (int j = 0; j < _cols; j++) {
            S21Matrix  minor = this->minor(i, j);
            int koef = ((i + j) % 2 == 0) ? 1 : -1;
                result._matrix[i][j] = koef*minor.determinant();
        }
    }
    return result;
}

double S21Matrix::determinant() const {
    if (_cols != _rows)
        throw std::out_of_range("Incorrect input, the matrix is not square");
    double result = 0.0;
    if (_rows == 1) {
            result = _matrix[0][0];
    } else if (_rows == 2) {
            result = _matrix[0][0]*_matrix[1][1] - _matrix[1][0]*_matrix[0][1];
    } else {
        int koef = 1;
        for (int m = 0; m < _cols; m++) {
            S21Matrix minor = this->minor(0, m);
            result += koef*minor.determinant()*_matrix[0][m];
            koef *= -1;
        }
    }
    return result;
}

S21Matrix S21Matrix::inverse_matrix() const {
    double det = determinant();
    if (fabs(det)< 1e-7)
        throw std::out_of_range("Incorrect input, matrix determinant is 0");
    S21Matrix result(*this);
    if (_rows == 1) {
        result.mul_number(1.0 / (det*det));
    } else {
        S21Matrix matrix_of_minors = result.calc_complements();
        S21Matrix result_temp = matrix_of_minors.transpose();
        result_temp.mul_number(1 / det);
        result = result_temp;
    }
    return result;
}

S21Matrix S21Matrix::operator+(const S21Matrix& other) {
    S21Matrix result(*this);
    result.sum_matrix(other);
    return result;
}

S21Matrix S21Matrix::operator-(const S21Matrix& other) {
    S21Matrix result(*this);
    result.sub_matrix(other);
    return result;
}

S21Matrix S21Matrix::operator*(const S21Matrix& other) {
    S21Matrix result(*this);
    result.mul_matrix(other);
    return result;
}

S21Matrix S21Matrix::operator*(const double num) {
    S21Matrix result(*this);
    result.mul_number(num);
    return result;
}

S21Matrix operator*(const double num, const S21Matrix& other) {
    S21Matrix result(other);
    result.mul_number(num);
    return result;
}

bool S21Matrix::operator==(const S21Matrix& other) {
    return eq_matrix(other);
}

S21Matrix& S21Matrix::operator=(const S21Matrix& other) {
    if (&other != this) {
        destroy();
        _cols = other._cols;
        _rows = other._rows;
        create();
        for (int i = 0; i < _rows; i++)
            for (int j = 0; j < _cols; j++)
                _matrix[i][j] = other._matrix[i][j];
    }
    return *this;
}

S21Matrix& S21Matrix::operator+=(const S21Matrix& other) {
    sum_matrix(other);
    return *this;
}

S21Matrix& S21Matrix::operator-=(const S21Matrix& other) {
    sub_matrix(other);
    return *this;
}

S21Matrix& S21Matrix::operator*=(const double num) {
    mul_number(num);
    return *this;
}

S21Matrix& S21Matrix::operator*=(const S21Matrix& other) {
    mul_matrix(other);
    return *this;
}

double& S21Matrix::operator()(int row, int col) const {
    if (row > _rows || row < 0 || col < 0 || col > _cols)
        throw std::out_of_range("Incorrect input, index is out of range");
    return _matrix[row][col];
}

S21Matrix S21Matrix::minor(int n, int m) const {
    S21Matrix result(_rows - 1, _cols - 1);
    int p = 0, q = 0;
    for (int i = 0; i < _rows; i++) {
        for (int j = 0; j < _cols; j++) {
            if (i != n && j != m) {
                result._matrix[p][q] = _matrix[i][j];
                q++;
            }
        }
        if (i != n) p++;
        q = 0;
    }
    return result;
}

void S21Matrix::array_in_matrix(const double *arr, int n, int m) {
    if (_rows != n || _cols != m) {
        destroy();
        _rows = n;
        _cols = m;
        create();
    }
    int k = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            _matrix[i][j] = arr[k++];
}

void S21Matrix::print() {
    std::cout << "Rows: " << getRows();
    std::cout << "\nColumns: " << getColumns() << "\n";
    for (int i = 0; i < getRows(); i++) {
        for (int j = 0; j < getColumns(); j++)
            std::cout << _matrix[i][j] << " ";
        std::cout << "\n";
    }
    std::cout << std::endl;
}
