#include <gtest/gtest.h>
#include <stdexcept>
#include "s21_matrix_oop.h"

TEST(constructors, Parametrized_constructor_true) {
    S21Matrix M1(2, 3);
    double arr1[] = {
        0, 0, 0,
        0, 0, 0
    };
    S21Matrix M1_res;
    M1_res.array_in_matrix(arr1, 2, 3);
    ASSERT_EQ(M1 == M1_res, 1);
}

TEST(constructors, Parametrized_constructor_false) {
    S21Matrix M2(2, 3);
    double arr2[] = {
        0, 0, 0.1,
        0, 0, 0
    };
    S21Matrix M2_res;
    M2_res.array_in_matrix(arr2, 2, 3);
    ASSERT_EQ(M2 == M2_res, 0);

    double arr3[] = {
        0, 0,
        0, 0
    };
    S21Matrix M3_res;
    M3_res.array_in_matrix(arr3, 2, 2);
    ASSERT_EQ(M2 == M3_res, 0);
}

TEST(constructors, copy_constructor_true) {
    double arr4[] = {
        134, 0, 0.1,
        0, 5.8, 0
    };
    S21Matrix M4;
    M4.array_in_matrix(arr4, 2, 3);
    S21Matrix M4_copy(M4);
    ASSERT_EQ(M4 == M4_copy, 1);

    double arr5[] = {
        0, 0,
        0, 0,
        5.9, 0,
    };
    S21Matrix M5;
    M5.array_in_matrix(arr5, 3, 2);
    S21Matrix M5_copy(M5);
    ASSERT_EQ(M5 == M5_copy, 1);
}

TEST(constructors, move_constructor_true) {
    double arr6[] = {
        134, 0, 0.1,
        0, 5.8, 0
    };
    S21Matrix M6;

    M6.array_in_matrix(arr6, 2, 3);
    S21Matrix M6_copy(M6);
    S21Matrix M6_move(std::move(M6));
    ASSERT_EQ(M6_copy == M6_move, 1);
}

TEST(overloads, sum) {
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
    ASSERT_EQ(M9 == M9_res, 1);

    M8 += M7;
    ASSERT_EQ(M9 == M8, 1);
}

TEST(overloads, sub) {
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
    ASSERT_EQ(M12 == M12_res, 1);

    M10 -= M11;
    ASSERT_EQ(M12 == M10, 1);
}

TEST(overloads, mul_matr) {
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
    ASSERT_EQ(M15 == M15_res, 1);

    M13 *= M14;
    ASSERT_EQ(M15.eq_matrix(M13), 1);
}

TEST(overloads, mul_num) {
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
    ASSERT_EQ(M17 == M17_res, 1);

    M16_1 *=2;
    ASSERT_EQ(M17 == M16_1, 1);

    double arr18[] = {
        -402, -0, -0.3,
        -0, -17.4, -0,
        2.1, 6, -0
    };
    S21Matrix M18;
    M18.array_in_matrix(arr18, 3, 3);
    S21Matrix M18_res = -3 * M16;
    ASSERT_EQ(M18 == M18_res, 1);
}

TEST(overloads, assignment) {
    double arr19[] = {
        134, 0, 0.1,
        0, 5.8, 0,
        -0.7, -2, 0
    };
    S21Matrix M19;
    M19.array_in_matrix(arr19, 3, 3);

    S21Matrix M20 = M19;
    ASSERT_EQ(M19 == M20, 1);
}

TEST(overloads, meanings) {
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
    ASSERT_EQ(res21, -2);
    ASSERT_EQ(res22, 100);
    ASSERT_EQ(res11, 5.8);
}

TEST(methods, inverse) {
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
    ASSERT_EQ(M23_res == M23, 1);

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
    ASSERT_EQ(M25_res == M25, 1);

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
    ASSERT_EQ(M27_res == M27, 1);
}


TEST(mutators, set) {
    double arr28[] = {
        0.5
    };
    S21Matrix M28;
    M28.array_in_matrix(arr28, 1, 1);
    M28.setColumns(5);
    M28.setRows(7);
    ASSERT_EQ(M28.getRows(), 7);
    ASSERT_EQ(M28.getColumns(), 5);
}

TEST(exeptions, constructor_breckets) {
    S21Matrix M28_1(1, 1);
    try {
        M28_1(-2, 6);
    } catch ( std::out_of_range &ex )  {
        ASSERT_EQ(1, 1);
    }

    S21Matrix M29(2, 6);
    try {
        double t = M29(-1, 2);
    } catch ( std::out_of_range &ex ) {
        ASSERT_EQ(1, 1);
    }
}


TEST(exeptions, sum_sub_mul) {
    S21Matrix M30(3, 6);
    S21Matrix M31(5, 6);
    try {
        M30.sum_matrix(M31);
    } catch ( std::out_of_range &ex )  {
        ASSERT_EQ(1, 1);
    }

    try {
        M30.sub_matrix(M31);
    } catch ( std::out_of_range &ex )  {
        ASSERT_EQ(1, 1);
    }

    try {
        M30.mul_matrix(M31);
    } catch ( std::out_of_range &ex )  {
        ASSERT_EQ(1, 1);
    }
}

TEST(exeptions, complements_det_inverse) {
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
    } catch ( std::out_of_range &ex )  {
        ASSERT_EQ(1, 1);
    }

    try {
        S21Matrix M34 = M32.inverse_matrix();
    } catch ( std::out_of_range &ex )  {
        ASSERT_EQ(1, 1);
    }

    double arr33[] = {
        1, 2,
        -1, -2
    };
    S21Matrix M33;
    M33.array_in_matrix(arr33, 2, 2);
    try {
        S21Matrix M34 = M33.inverse_matrix();
    } catch ( std::out_of_range &ex )  {
        ASSERT_EQ(1, 1);
    }
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
