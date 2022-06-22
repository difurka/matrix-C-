#ifndef SRC_S21_MATRIX_OOP_H_
#define SRC_S21_MATRIX_OOP_H_

class S21Matrix {
    friend S21Matrix operator*(const double num, const S21Matrix& other);

 public:
    // constructors & destructor
    S21Matrix();
    S21Matrix(int rows, int cols);
    S21Matrix(const S21Matrix& other);
    S21Matrix(S21Matrix&& other);
    ~S21Matrix();

    // accessors and mutators
    void setRows(int);
    void setColumns(int);
    int getRows() const;
    int getColumns() const;

    // public methods
    bool eq_matrix(const S21Matrix& other);
    void sum_matrix(const S21Matrix& other);
    void sub_matrix(const S21Matrix& other);
    void mul_number(const double num);
    void mul_matrix(const S21Matrix& other);
    S21Matrix transpose() const;
    S21Matrix calc_complements() const;
    double determinant() const;
    S21Matrix inverse_matrix() const;

    // operators overloads
    S21Matrix operator+(const S21Matrix& other);
    S21Matrix operator-(const S21Matrix& other);
    S21Matrix operator*(const S21Matrix& other);
    S21Matrix operator*(const double num);
    bool operator==(const S21Matrix& other);
    S21Matrix& operator=(const S21Matrix& other);
    S21Matrix& operator+=(const S21Matrix& other);
    S21Matrix& operator-=(const S21Matrix& other);
    S21Matrix& operator*=(const double num);
    S21Matrix& operator*=(const S21Matrix& other);
    double& operator()(int row, int col) const;

    void print();
    void array_in_matrix(const double *arr, int n, int m);

 private:
    int _rows, _cols;
    double **_matrix;

    void create();
    void destroy();
    S21Matrix minor(int n, int m) const;
};

#endif  // SRC_S21_MATRIX_OOP_H_
