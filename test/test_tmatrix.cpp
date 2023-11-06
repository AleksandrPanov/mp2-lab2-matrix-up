#include "utmatrix.h"

#include <gtest.h>

TEST(TMatrix, can_create_matrix_with_positive_length)
{
    ASSERT_NO_THROW(TMatrix<int> m(5));
}

TEST(TMatrix, cant_create_too_large_matrix)
{
    ASSERT_ANY_THROW(TVector<int> v(TVector<int>::max_size + static_cast<size_t>(1)));
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
    TMatrix<int> m(3);
    m[0][0] = 1;
    m[0][2] = 3;
    m[1][1] = 1;
    m[2][2] = 8;

    TMatrix<int> m1(m);
    
    EXPECT_EQ(m, m1);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
    TMatrix<int> m(3);

    m[0][0] = 1;
    m[0][2] = 3;
    m[1][1] = 1;
    m[2][2] = 8;

    TMatrix<int> m1(m);
    m[0][0] = 8;
    m[0][2] = 6;
    m[1][1] = 7;
    m[2][2] = 2;
    EXPECT_NE(m, m1);
}

TEST(TMatrix, can_get_size)
{
    TMatrix<int> m(3);

    EXPECT_EQ(3, m.getSize());
}

TEST(TMatrix, can_set_and_get_element)
{
    TMatrix<int> m(5);

    m[0][2] = 3;

    EXPECT_EQ(3, m[0].getElement(2));

    m[0].setElement(2, 4);

    EXPECT_EQ(4, m[0].getElement(2));
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
    TMatrix<int> m(3);

    ASSERT_ANY_THROW(m[2].setElement(-5, 2));
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
    TMatrix<int> m(3);

    ASSERT_ANY_THROW(m[2].setElement(8, 2));
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
    TMatrix<int> m(3);
  
    ASSERT_NO_THROW(m = m);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
    TMatrix<int> m(3);
    m[0][0] = 1;
    m[0][1] = 2;

    TMatrix<int> m1(3);
    m[0][0] = 2;
    m[0][1] = 1;

    ASSERT_NO_THROW(m1 = m);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
    int s = 3;
    TMatrix<int> m(s);
    m[0][0] = 1;
    m[0][1] = 2;

    int s1 = 4;
    TMatrix<int> m1(s1);
    m1[0][0] = 2;
    m1[0][1] = 1;

    m1 = m;
    ASSERT_NO_THROW(s1, m.getSize());
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
    int s = 3;
    TMatrix<int> m(s);
    m[0][0] = 8;
    m[0][1] = 34;

    int s1 = 4;
    TMatrix<int> m1(s1);
    m[0][0] = 6;
    m[0][1] = 1;

    ASSERT_NO_THROW(m1 = m);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
    TMatrix<int> m(3);
    m[0][0] = 6;
    m[0][1] = 1;

    TMatrix<int> m1(3);
    m1[0][0] = 6;
    m1[0][1] = 1;

    EXPECT_EQ(m, m1);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
    TMatrix<int> m(3);

    m[0][0] = 1;
    m[0][2] = 3;
    m[1][1] = 1;
    m[2][2] = 8;

    EXPECT_EQ(m, m);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
    TMatrix<int> m(3);

    TMatrix<int> m1(4);

    EXPECT_NE(m, m1);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
    TMatrix<int> m1(3);
    TMatrix<int> m2(3);
    TMatrix<int> res(3);

    for (int i = 0; i < 3; i++) {
        for (int j = i; j < 3; j++)
        {
            m1[i][j] = 1;
            m2[i][j] = 2;
            res[i][j] = 3;
        }
    }
    EXPECT_EQ(m2 + m1,res);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
    TMatrix<int> m1(3);

    TMatrix<int> m2(4);

    ASSERT_ANY_THROW(m2 + m1);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
    TMatrix<int> m1(3);
    TMatrix<int> m2(3);
    TMatrix<int> res(3);

    for (int i = 0; i < 3; i++) {
        for (int j = i; j < 3; j++)
        {
            m1[i][j] = 1;
            m2[i][j] = 2;
            res[i][j] = 1;
        }
    }
    EXPECT_EQ(m2 - m1, res);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
    TMatrix<int> m1(3);

    TMatrix<int> m2(4);

    ASSERT_ANY_THROW(m2 - m1);
}
