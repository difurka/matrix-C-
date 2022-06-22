#include <stdexcept>
#include "s21_matrix_oop.h"

int main() {
    S21Matrix M1(2, 3);
    double arr1[] = {
        0, 0, 0,
        0, 0, 0
    };
    S21Matrix M1_res;
    M1_res.array_in_matrix(arr1, 2, 3);

    S21Matrix M2(2, 3);
    double arr2[] = {
        0, 0, 0.1,
        0, 0, 0
    };
    S21Matrix M2_res;
    M2_res.array_in_matrix(arr2, 2, 3);

    double arr3[] = {
        0, 0,
        0, 0
    };
    S21Matrix M3_res;
    M3_res.array_in_matrix(arr3, 2, 2);

    double arr4[] = {
        134, 0, 0.1,
        0, 5.8, 0
    };
    S21Matrix M4;
    M4.array_in_matrix(arr4, 2, 3);
    S21Matrix M4_copy(M4);

    double arr5[] = {
        0, 0,
        0, 0,
        5.9, 0,
    };
    S21Matrix M5;
    M5.array_in_matrix(arr5, 3, 2);
    S21Matrix M5_copy(M5);

    double arr6[] = {
        134, 0, 0.1,
        0, 5.8, 0
    };
    S21Matrix M6;

    M6.array_in_matrix(arr6, 2, 3);
    S21Matrix M6_copy(M6);
    S21Matrix M6_move(std::move(M6));

    double arr7[] = {
        134, 0, 0.1,
        0, 5.8, 0,
        -0.7, -2, 0
    };
    S21Matrix M7;
    M7.array_in_matrix(arr7, 3, 3);

    double arr8[] = {
        1.2, 3, 1,
        -2, -0.5, 0,
        0, 9, -3
    };
    S21Matrix M8;
    M8.array_in_matrix(arr8, 3, 3);

    double arr9[] = {
        135.2, 3, 1.1,
        -2, 5.3, 0,
        -0.7, 7, -3
    };
    S21Matrix M9;
    M9.array_in_matrix(arr9, 3, 3);

    S21Matrix M9_res = M8 + M7;

    M8 += M7;

    double arr10[] = {
        134, 0, 0.1,
        0, 5.8, 0,
        -0.7, -2, 0
    };
    S21Matrix M10;
    M10.array_in_matrix(arr10, 3, 3);

    double arr11[] = {
        1.2, 3, 1,
        -2, -0.5, 0,
        0, 9, -3
    };
    S21Matrix M11;
    M11.array_in_matrix(arr11, 3, 3);

    double arr12[] = {
        132.8, -3, -0.9,
        2, 6.3, 0,
        -0.7, -11, 3
    };
    S21Matrix M12;
    M12.array_in_matrix(arr12, 3, 3);

    S21Matrix M12_res = M10 - M11;

    M10 -= M11;

    double arr13[] = {
        134, 0, 0.1,
        0, 5.8, 0,
        -0.7, -2, 0
    };
    S21Matrix M13;
    M13.array_in_matrix(arr13, 3, 3);

    double arr14[] = {
        1.2, 3, 1,
        -2, -0.5, 0,
        0, 9, -3
    };
    S21Matrix M14;
    M14.array_in_matrix(arr14, 3, 3);

    double arr15[] = {
        160.8, 402.9, 133.7,
        -11.6, -2.9, -0,
        3.16, -1.1, -0.7
    };
    S21Matrix M15;
    M15.array_in_matrix(arr15, 3, 3);

    S21Matrix M15_res = M13 * M14;

    M13 *= M14;

    double arr16[] = {
        134, 0, 0.1,
        0, 5.8, 0,
        -0.7, -2, 0
    };
    S21Matrix M16;
    M16.array_in_matrix(arr16, 3, 3);
    S21Matrix M16_1(M16);

    double arr17[] = {
        268, 0, 0.2,
        0, 11.6, 0,
        -1.4, -4, 0
    };
    S21Matrix M17;
    M17.array_in_matrix(arr17, 3, 3);

    S21Matrix M17_res = M16_1 * 2;

    M16_1 *=2;

    double arr18[] = {
        -402, -0, -0.3,
        -0, -17.4, -0,
        2.1, 6, -0
    };
    S21Matrix M18;
    M18.array_in_matrix(arr18, 3, 3);
    S21Matrix M18_res = -3 * M16;

    double arr19[] = {
        134, 0, 0.1,
        0, 5.8, 0,
        -0.7, -2, 0
    };
    S21Matrix M19;
    M19.array_in_matrix(arr19, 3, 3);

    S21Matrix M20 = M19;

    double arr21[] = {
        134, -0.9, 0.1,
        0, 5.8, 0,
        -0.7, -2, 100
    };
    S21Matrix M21;
    M21.array_in_matrix(arr21, 3, 3);

    double res21 = M21(2, 1);
    double res22 = M21(2, 2);
    double res11 = M21(1, 1);

    double arr22[] = {
        0.5
    };
    S21Matrix M22;
    M22.array_in_matrix(arr22, 1, 1);

    double arr23[] = {
        2
    };
    S21Matrix M23;
    M23.array_in_matrix(arr23, 1, 1);
    S21Matrix M23_res = M22.inverse_matrix();

    double arr24[] = {
        0.5, 1,
        2.5, 0
    };
    S21Matrix M24;
    M24.array_in_matrix(arr24, 2, 2);

    double arr25[] = {
        0, 0.4,
        1, -0.2
    };
    S21Matrix M25;
    M25.array_in_matrix(arr25, 2, 2);
    S21Matrix M25_res = M24.inverse_matrix();

    double arr26[] = {
        1, 2, 4, -1, 0, -2,
        5, 0, 0, 0, 5, 0,
        0, 0, -8, 0, 1, 4,
        -1, 3, 0, 0, 0, 0,
        0, 0, 1, -3, 2, 0,
        1, 0, 4, 0, 1, -1
    };
    S21Matrix M26;
    M26.array_in_matrix(arr26, 6, 6);

    double arr27[] = {
        24/43.0,  -1/215.0, 13/43.0, -16/43.0, -8/43.0, 4/43.0,
        8/43.0, -1/645.0, 13/129.0, 9/43.0, -8/129.0, 4/129.0,
        3/43.0, -27/215.0, 7/43.0, -2/43.0, -1/43.0, 22/43.0,
        -15/43.0, 61/645.0, -19/129.0, 10/43.0, -28/129.0, 14/129.0,
        -24/43.0, 44/215.0, -13/43.0, 16/43.0, 8/43.0, -4/43.0,
        12/43.0, -13/43.0, 28/43.0, -8/43.0, -4/43.0, 45/43.0
    };
    S21Matrix M27;
    M27.array_in_matrix(arr27, 6, 6);
    S21Matrix M27_res = M26.inverse_matrix();


    double arr28[] = {
        0.5
    };
    S21Matrix M28;
    M28.array_in_matrix(arr28, 1, 1);
    M28.setColumns(5);
    M28.setRows(7);

    try {
        S21Matrix M28_1(-2, 6);
    } catch ( std::out_of_range &ex )  {    }

    S21Matrix M29(2, 6);
    try {
        double t = M29(-2, 6);
    } catch ( std::out_of_range &ex )  {    }

    S21Matrix M30(3, 6);
    S21Matrix M31(5, 6);
    try {
        M30.sum_matrix(M31);
    } catch ( std::out_of_range &ex )  {    }

    try {
        M30.sub_matrix(M31);
    } catch ( std::out_of_range &ex )  {    }

    try {
        M30.mul_matrix(M31);
    } catch ( std::out_of_range &ex )  {    }

    double arr32[] = {
        1, 2, 4, -1, 0, -2,
        5, 0, 0, 0, 5, 0,
        0, 0, -8, 0, 1, 4,
        -1, 3, 0, 0, 0, 0,
        0, 0, 1, -3, 2, 0
    };
    S21Matrix M32;
    M32.array_in_matrix(arr32, 5, 6);

    try {
        S21Matrix M33 = M32.calc_complements();
    } catch ( std::out_of_range &ex )  {    }

    try {
        S21Matrix M34 = M32.inverse_matrix();
    } catch ( std::out_of_range &ex )  {    }

    double arr33[] = {
        1, 2,
        -1, -2
    };
    S21Matrix M33;
    M33.array_in_matrix(arr33, 2, 2);
    try {
        S21Matrix M34 = M33.inverse_matrix();
    } catch ( std::out_of_range &ex )  {    }
}
