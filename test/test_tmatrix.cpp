#include "utmatrix.h"

#include <gtest.h>

TEST(TMatrix, can_create_matrix_with_positive_length)
{
    ASSERT_NO_THROW(TMatrix<int> m1(5));
    ASSERT_NO_THROW(TMatrix<size_t> m2(5));
}

TEST(TMatrix, cant_create_too_large_matrix)
{
    ASSERT_ANY_THROW(TMatrix<int> m(TVector<int>::max_size + 1ull));
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
    m[1][4] = 5;
    TMatrix<int> n(m);
    EXPECT_EQ(n, m);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
    TMatrix<int> m(5);
    TMatrix<int> n(m);
    m[1][4] = 5;
    EXPECT_NE(n, m);
}

TEST(TMatrix, can_get_size)
{
    TMatrix<int> m(5);
    EXPECT_EQ(m.getSize(), 5);
}

TEST(TMatrix, can_set_and_get_element)
{
    TMatrix<int> m(5);
    m.getElement(1).setElement(0, 20);
    EXPECT_EQ(m[1][1], 20);

    TVector<int> vec(5, 2);
    vec[2] = 30;
    m.setElement(2, vec);
    EXPECT_EQ(m[2][2], 30);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
    TMatrix<int> m(5);
    TVector<int> vec(5, 2);
    vec[2] = 30;
    ASSERT_ANY_THROW(m.setElement(-1, vec));
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
    TMatrix<int> m(5);
    TVector<int> vec(5, 2);
    vec[2] = 30;
    ASSERT_ANY_THROW(m.setElement(5, vec));
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
    TMatrix<int> m(5);
    ASSERT_NO_THROW(m = m);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
    TMatrix<int> m(5);
    TVector<int> vec1(5, 2);
    vec1[2] = 30;
    m.setElement(2, vec1);

    TMatrix<int> n(5);
    TVector<int> vec2(5, 3);
    vec2[3] = 40;
    n.setElement(3, vec2);

    ASSERT_NO_THROW(m = n);
    EXPECT_EQ(m[3][3], 40);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
    TMatrix<int> m(5);
    TMatrix<int> n(6);
    m = n;

    EXPECT_EQ(m.getSize(), n.getSize());
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
    TMatrix<int> m(5);
    TVector<int> vec1(5, 2);
    vec1[2] = 30;
    m.setElement(2, vec1);

    TMatrix<int> n(6);
    TVector<int> vec2(6, 3);
    vec2[3] = 40;
    n.setElement(3, vec2);
    m = n;

    EXPECT_EQ(m[3][3], 40);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
    TMatrix<int> m(5);
    TVector<int> vec1(5, 2);
    vec1[2] = 30;
    m.setElement(2, vec1);

    TMatrix<int> n(5);
    TVector<int> vec2(5, 2);
    vec2[2] = 30;
    n.setElement(2, vec2);
    
    EXPECT_EQ(m == n, true);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
    TMatrix<int> m(5);
    TVector<int> vec1(5, 2);
    vec1[2] = 30;
    m.setElement(2, vec1);
    EXPECT_EQ(m == m, true);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
    TMatrix<int> m(5);
    TMatrix<int> n(6);
    EXPECT_EQ(m != n, true);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
    TMatrix<int> m(5);
    TVector<int> vec1(5, 2);
    vec1[2] = 30;
    m.setElement(2, vec1);

    TMatrix<int> n(5);
    TVector<int> vec2(5, 2);
    vec2[2] = 40;
    n.setElement(2, vec2);

    
    ASSERT_NO_THROW(m + n);
    TMatrix<int> res = m + n;

    EXPECT_EQ(res[2][2], 70);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
    TMatrix<int> m(5);
    TMatrix<int> n(6);
    ASSERT_ANY_THROW(m + n);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
    TMatrix<int> m(5);
    TVector<int> vec1(5, 2);
    vec1[2] = 30;
    m.setElement(2, vec1);

    TMatrix<int> n(5);
    TVector<int> vec2(5, 2);
    vec2[2] = 40;
    n.setElement(2, vec2);


    ASSERT_NO_THROW(m - n);
    TMatrix<int> res = m - n;

    EXPECT_EQ(res[2][2], -10);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
    TMatrix<int> m(5);
    TMatrix<int> n(6);
    ASSERT_ANY_THROW(m - n);
}
