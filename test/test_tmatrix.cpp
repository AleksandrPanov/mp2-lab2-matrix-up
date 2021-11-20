#include "utmatrix.h"

#include <gtest.h>

TEST(TMatrix, can_create_matrix_with_positive_length)
{
    ASSERT_NO_THROW(TMatrix<int> m(5));
}

TEST(TMatrix, cant_create_too_large_matrix)
{
    ASSERT_ANY_THROW(TMatrix<int>(static_cast<size_t>(std::sqrt(TVector<int>::max_size) + 1ull)));
}

//TEST(TMatrix, create_max_size_matrix)
//{
//    ASSERT_NO_THROW(TMatrix<int>(static_cast<size_t>(std::sqrt(TVector<int>::max_size))));
//}

TEST(TMatrix, throws_when_create_matrix_with_negative_length)
{
    ASSERT_ANY_THROW(TMatrix<int> m(-5));
}

TEST(TMatrix, can_create_copied_matrix)
{
    TMatrix<int> m(sizeof(int));

    ASSERT_NO_THROW(TMatrix<int> m1(m));
}

TEST(TMatrix, copied_matrix_is_equal_to_source_one)
{
    TMatrix<int> source(5);
    source[2][2] = 11;

    EXPECT_EQ(TMatrix<int>(source)[2][2], 11);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
    TMatrix<int> source(5);
    TMatrix<int> copy(source);

    source[2][2] = 100;

    EXPECT_NE(copy[2][2], source[2][2]);
}

TEST(TMatrix, can_get_size)
{
    TMatrix<int> matrix(10);

    EXPECT_EQ(matrix.getSize(), 10);
}

TEST(TMatrix, can_set_and_get_element)
{
    TMatrix<int> matrix(10);

    matrix[2][2] = 10;

    EXPECT_EQ(matrix[2][2], 10);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
    TMatrix<int> matrix(10);

    ASSERT_ANY_THROW(matrix[-10][-10]);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
    TMatrix<int> matrix(10);

    ASSERT_ANY_THROW(matrix[10][10]);
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
    TMatrix<int> matrix(10);

    ASSERT_NO_THROW(matrix = matrix);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
    TMatrix<int> matrix1(10);
    TMatrix<int> matrix2(10);

    matrix2[2][2] = 10;

    ASSERT_NO_THROW(matrix1 = matrix2);
    EXPECT_EQ(matrix1[2][2], matrix2[2][2]);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
    TMatrix<int> matrix1(100);
    TMatrix<int> matrix2(10);

    matrix1 = matrix2;

    EXPECT_EQ(matrix1.getSize(), 10);
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
    TMatrix<int> matrix1(100);
    TMatrix<int> matrix2(10);

    matrix2[2][2] = 10;

    ASSERT_NO_THROW(matrix1 = matrix2);
    EXPECT_EQ(matrix1[2][2], matrix2[2][2]);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
    TMatrix<int> matrix1(10);
    TMatrix<int> matrix2(matrix1);

    EXPECT_EQ(matrix1, matrix2);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
    TMatrix<int> matrix(10);

    EXPECT_EQ(matrix, matrix);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
    TMatrix<int> matrix1(100);
    TMatrix<int> matrix2(10);

    EXPECT_NE(matrix1, matrix2);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
    TMatrix<int> matrix1(10);
    TMatrix<int> matrix2(10);

    matrix1[2][2] = 10;
    matrix2[2][2] = 100;

    ASSERT_NO_THROW(matrix1 + matrix2);

    EXPECT_EQ((matrix1 + matrix2)[2][2], 110);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
    TMatrix<int> matrix1(100);
    TMatrix<int> matrix2(10);

    ASSERT_ANY_THROW(matrix1 + matrix2);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
    TMatrix<int> matrix1(10);
    TMatrix<int> matrix2(10);

    matrix1[2][2] = 10;
    matrix2[2][2] = 100;

    ASSERT_NO_THROW(matrix1 - matrix2);

    EXPECT_EQ((matrix1 - matrix2)[2][2], -90);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
    TMatrix<int> matrix1(100);
    TMatrix<int> matrix2(10);

    ASSERT_ANY_THROW(matrix1 - matrix2);
}
