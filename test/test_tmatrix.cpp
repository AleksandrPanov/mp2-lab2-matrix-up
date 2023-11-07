#include "utmatrix.h"

#include <gtest.h>

TEST(TMatrix, can_create_matrix_with_positive_length)
{
    ASSERT_NO_THROW(TMatrix<int> m(5));
}

TEST(TMatrix, cant_create_too_large_matrix)
{
    const int s = 65536;
    ASSERT_ANY_THROW(TMatrix<int>m(s));
}

TEST(TMatrix, throws_when_create_matrix_with_negative_length)
{
    ASSERT_ANY_THROW(TMatrix<int> m(-5));
}

TEST(TMatrix, can_create_copied_matrix)
{
    TMatrix<int> m(2);

    ASSERT_NO_THROW(TMatrix<int>m2(m));
}

TEST(TMatrix, copied_matrix_is_equal_to_source_one)
{
    TMatrix<int> m(3);
    m[0][0] = 1; m[0][1] = 1; m[0][2] = 1; m[1][1] = 1; m[1][2] = 1; m[2][2] = 1;

    TMatrix<int> mc(m);

    EXPECT_EQ(m, mc);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
    TMatrix<int> m(3);
    m[0][0] = 1; m[0][1] = 1; m[0][2] = 1; m[1][1] = 1; m[1][2] = 1; m[2][2] = 1;
    TMatrix<int> mc(m);

    mc[2][2] = 3;
    EXPECT_NE(m, mc);
}

TEST(TMatrix, can_get_size)
{
    TMatrix<int> m(2);
    m[0][0] = 1; m[0][1] = 1; m[1][1] = 1;

    EXPECT_EQ(2, m.getSize());
}

TEST(TMatrix, can_set_and_get_element)
{
    TMatrix<int> m(2);
    m[0][0] = 1; m[0][1] = 1; m[1][1] = 1;
    m[0].setElement(0, 1);

    EXPECT_EQ(1, m[0].getElement(0));

}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
    TMatrix<int> m(2);

    ASSERT_ANY_THROW(m[0].setElement(-1, 7));
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
    TMatrix<int> m(2);

    ASSERT_ANY_THROW(m[0].setElement(3, 7));
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
    TMatrix<int> m(2);
    
    ASSERT_NO_THROW(m = m);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
    TMatrix<int> m(2);
    m[0][0] = 0; m[0][1] = 2; m[1][1] = 3;
    TMatrix<int> mt(2);
    mt[0][0] = 1; mt[0][1] = 1; mt[1][1] = 1;

    ASSERT_NO_THROW(m = mt);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
    TMatrix<int> m(2);
    TMatrix<int> mt(3);

    m = mt;

    EXPECT_EQ(3, m.getSize());
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
    TMatrix<int> m(2);
    TMatrix<int> mt(3);

    ASSERT_NO_THROW(m = mt);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
    TMatrix<int> m(2);
    m[0][0] = 1; m[0][1] = 1; m[1][1] = 1;
    TMatrix<int> mt(2);
    mt[0][0] = 1; mt[0][1] = 1; mt[1][1] = 1;

    EXPECT_EQ(true, m == mt);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
    TMatrix<int> m(2);
    m[0][0] = 1; m[0][1] = 1; m[1][1] = 1;

    EXPECT_EQ(true, m == m);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
    TMatrix<int> m(2);
    m[0][0] = 1; m[0][1] = 1; m[1][1] = 1;
    TMatrix<int> mt(3);
    mt[0][0] = 1; mt[0][1] = 1; mt[1][1] = 1;

    EXPECT_EQ(true, m != mt);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
    TMatrix<int> m(2);
    m[0][0] = 1; m[0][1] = 1; m[1][1] = 1;
    TMatrix<int> mt(2);
    mt[0][0] = 1; mt[0][1] = 1; mt[1][1] = 1;
    
    m = m + mt;

    TMatrix<int> res(2);
    res[0][0] = 2; res[0][1] = 2; res[1][1] = 2;

    EXPECT_EQ(res, m);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
    TMatrix<int> m(2);
    m[0][0] = 1; m[0][1] = 1; m[1][1] = 1;
    TMatrix<int> mt(3);
    mt[0][0] = 1; mt[0][1] = 1; mt[1][1] = 1;

    ASSERT_ANY_THROW(m + mt);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
    TMatrix<int> m(2);
    m[0][0] = 2; m[0][1] = 2; m[1][1] = 2;
    TMatrix<int> mt(2);
    mt[0][0] = 1; mt[0][1] = 1; mt[1][1] = 1;

    TMatrix<int> res(2);
    m[0][0] = 1; m[0][1] = 1; m[1][1] = 1;

    EXPECT_EQ(res, m - mt);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
    TMatrix<int> m(2);
    m[0][0] = 2; m[0][1] = 2; m[1][1] = 2;
    TMatrix<int> mt(3);
    mt[0][0] = 1; mt[0][1] = 1; mt[1][1] = 1;

    ASSERT_ANY_THROW(m - mt);
}
