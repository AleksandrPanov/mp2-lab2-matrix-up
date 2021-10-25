#include "utmatrix.h"

#include <gtest.h>

TEST(TMatrix, can_create_matrix_with_positive_length)
{
    ASSERT_NO_THROW(TMatrix<int> m(5));
}

TEST(TMatrix, cant_create_too_large_matrix)
{
    size_t s = static_cast<unsigned long long>((TVector<int>::max_size) * TVector<int>::max_size) + 1;
    ASSERT_ANY_THROW(TMatrix<int> v(s));
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
    TMatrix<int> source(3);
    source[0][0] = 1;
    source[0][1] = 2;
    source[0][2] = 3;
    source[1][1] = 4;
    source[1][2] = 5;
    source[2][2] = 6;

    TMatrix<int> m(source);

    EXPECT_EQ(source, m);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
    TMatrix<int> m(3);
    m[0][0] = 1;
    m[0][1] = 2;
    m[0][2] = 3;
    m[1][1] = 4;
    m[1][2] = 5;
    m[2][2] = 6;

    bool flag = 0;
    if (sizeof(m)) flag = 1;
    EXPECT_EQ(1, flag);
}

TEST(TMatrix, can_get_size)
{
    TMatrix<int> m(3);

    EXPECT_EQ(3, m.getSize());
}

TEST(TMatrix, can_set_and_get_element)
{
    TMatrix<int> m(3);
    TVector<int> v(3);
    v[0] = 1;
    v[1] = 2;
    v[2] = 3;

    ASSERT_NO_THROW(m.setElement(0, v));
   
    EXPECT_EQ(v, m.getElement(0));
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
    TMatrix<int> m(3);
    TVector<int> v(3);
    v[0] = 1;
    v[1] = 2;
    v[2] = 3;

    ASSERT_ANY_THROW(m.setElement(-1, v));
    
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
    TMatrix<int> m(3);
    TVector<int> v(3);
    v[0] = 1;
    v[1] = 2;
    v[2] = 3;

    ASSERT_ANY_THROW(m.setElement(3, v));
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
    TMatrix<int> m(3);

    ASSERT_NO_THROW (m = m);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
    TMatrix<int> m1(3);
    TMatrix<int> m2(3);
    m1[0][0] = 1; 
    m1[0][1] = 2; 
    m1[0][2] = 3; 
    m1[1][1] = 4;
    m1[1][2] = 5; 
    m1[2][2] = 6;

    m2 = m1;

    EXPECT_EQ(m2, m1);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
    TMatrix<int> m1(3);
    TMatrix<int> m2(2);
    m1[0][0] = 1;
    m1[0][1] = 2;
    m1[0][2] = 3;
    m1[1][1] = 4;
    m1[1][2] = 5;
    m1[2][2] = 6;

    m2 = m1;

    EXPECT_EQ(3, m2.getSize());
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
    TMatrix<int> m1(3);
    TMatrix<int> m2(2);
    m1[0][0] = 1;
    m1[0][1] = 2;
    m1[0][2] = 3;
    m1[1][1] = 4;
    m1[1][2] = 5;
    m1[2][2] = 6;

    m2 = m1;

    EXPECT_EQ(m2, m1);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
    TMatrix<int> m1(3);
    TMatrix<int> m2(3);
    m1[0][0] = 1; m2[0][0] = 1;
    m1[0][1] = 2; m2[0][1] = 2;
    m1[0][2] = 3; m2[0][2] = 3;
    m1[1][1] = 4; m2[1][1] = 4;
    m1[1][2] = 5; m2[1][2] = 5; 
    m1[2][2] = 6; m2[2][2] = 6;

    EXPECT_EQ(true, m1 == m2);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
    TMatrix<int> m1(3);
    m1[0][0] = 1;
    m1[0][1] = 2;
    m1[0][2] = 3;
    m1[1][1] = 4;
    m1[1][2] = 5;
    m1[2][2] = 6;

    EXPECT_EQ(true, m1 == m1);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
    TMatrix<int> m1(3);
    TMatrix<int> m2(2);
    m1[0][0] = 1; m2[0][0] = 1;
    m1[0][1] = 2; m2[0][1] = 2;
    m1[0][2] = 3; m2[1][1] = 3;
    m1[1][1] = 4; 
    m1[1][2] = 5; 
    m1[2][2] = 6; 

    EXPECT_EQ(false, m1 == m2);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
    TMatrix<int> m1(3);
    TMatrix<int> m2(3);
    m1[0][0] = 1; m2[0][0] = 1;
    m1[0][1] = 2; m2[0][1] = 2;
    m1[0][2] = 3; m2[0][2] = 3;
    m1[1][1] = 4; m2[1][1] = 4;
    m1[1][2] = 5; m2[1][2] = 5;
    m1[2][2] = 6; m2[2][2] = 6;

    ASSERT_NO_THROW (m1 + m2);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
    TMatrix<int> m1(3);
    TMatrix<int> m2(2);
    m1[0][0] = 1; m2[0][0] = 1;
    m1[0][1] = 2; m2[0][1] = 2;
    m1[0][2] = 3; m2[1][1] = 3;
    m1[1][1] = 4; 
    m1[1][2] = 5;
    m1[2][2] = 6;

    ASSERT_ANY_THROW(m1 + m2);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
    TMatrix<int> m1(3);
    TMatrix<int> m2(3);
    m1[0][0] = 1; m2[0][0] = 1;
    m1[0][1] = 2; m2[0][1] = 2;
    m1[0][2] = 3; m2[0][2] = 3;
    m1[1][1] = 4; m2[1][1] = 4;
    m1[1][2] = 5; m2[1][2] = 5;
    m1[2][2] = 6; m2[2][2] = 6;

    ASSERT_NO_THROW(m1 - m2);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
    TMatrix<int> m1(3);
    TMatrix<int> m2(2);
    m1[0][0] = 1; m2[0][0] = 1;
    m1[0][1] = 2; m2[0][1] = 2;
    m1[0][2] = 3; m2[1][1] = 3;
    m1[1][1] = 4; 
    m1[1][2] = 5;
    m1[2][2] = 6;

    ASSERT_ANY_THROW(m1 - m2);
}
