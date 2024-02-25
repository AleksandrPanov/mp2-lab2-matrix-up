#include "utmatrix.h"

#include <gtest.h>

TEST(TMatrix, can_create_matrix_with_positive_length)
{
    ASSERT_NO_THROW(TMatrix<int> m(5));
}

TEST(TMatrix, cant_create_too_large_matrix)
{
    ASSERT_ANY_THROW(TMatrix<int> m(999999999));
}

TEST(TMatrix, throws_when_create_matrix_with_negative_length)
{
    ASSERT_ANY_THROW(TMatrix<int> m(-5));
}

TEST(TMatrix, can_create_copied_matrix)
{
    TMatrix<int> m(5);

    ASSERT_NO_THROW(TMatrix<int> m1(m));
}

TEST(TMatrix, copied_matrix_is_equal_to_source_one)
{
    TMatrix<int> m(5);
    TMatrix<int> m1(m);
    m1 == m;
    ASSERT_EQ(m1, m);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
    TMatrix<int> m(5);
    TMatrix<int> m1(m);
    m[1][4] = 1000;
    ASSERT_NE(m1, m);

}

TEST(TMatrix, can_get_size)
{
    TMatrix<int> m(5);
    ASSERT_EQ(m.getSize(), 5);
}

TEST(TMatrix, can_set_and_get_element)
{
    TMatrix<int> m(5);
    int i = 0;
    int t = m[4][0];
    EXPECT_EQ(t, i);
    m[3][3] = 1000;
    EXPECT_EQ(1000, m[3][3]);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
    TMatrix<int> m(5);
    ASSERT_ANY_THROW(m[-1][-1]);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
    TMatrix<int> m(5);
    ASSERT_ANY_THROW(m[10][-1]);
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
    TMatrix<int> m(5);
    m = m;
    ASSERT_EQ(m, m);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
    TMatrix<int> m(5);
    TMatrix<int> m1(5);
    ASSERT_NO_THROW(m1 = m);

}

TEST(TMatrix, assign_operator_change_matrix_size)
{
    TMatrix<int> m(5);
    TMatrix<int> m1(10);
    m1 = m;
    ASSERT_EQ(m1.getSize(), m.getSize());
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
    TMatrix<int> m(5);
    TMatrix<int> m1(10);
    m1[4][6] = 31847;
    m= m1;
    ASSERT_EQ(m, m1);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
    TMatrix<int> m(5);
    TMatrix<int> m1(10);
    m1[4][6] = 31847;
    m = m1;
    ASSERT_EQ(m, m1);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
    TMatrix<int> m(5);
    ASSERT_TRUE(m == m);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
    TMatrix<int> m(5);
    TMatrix<int> m1(10);
    ASSERT_FALSE(m1 == m);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
    TMatrix<int> m(3);
    TMatrix<int> m1(3);
    m = m + m1;
    for (int i = 0; i < m.getSize(); i++)
        for (int j = i; j < m.getSize(); j++)
            EXPECT_EQ(2, m[i][j]);
    
    
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
    TMatrix<int> m(3);
    TMatrix<int> m1(4);
    ASSERT_ANY_THROW(m1 + m);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
    TMatrix<int> m(3);
    TMatrix<int> m1(3);
    m = m + m1;
    m = m - m1;
    for (int i = 0; i < m.getSize(); i++)
        for (int j = i; j < m.getSize(); j++)
            EXPECT_EQ(1, m[i][j]);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
    TMatrix<int> m(3);
    TMatrix<int> m1(67);
    ASSERT_ANY_THROW(m1 + m);
}
