#include "utmatrix.h"

#include <gtest.h>

TEST(TMatrix, can_create_matrix_with_positive_length)
{
    ASSERT_NO_THROW(TMatrix<int> m(5));
}

TEST(TMatrix, cant_create_too_large_matrix)
{
    ASSERT_ANY_THROW(TVector<int> mat(TVector<int>::max_size + static_cast<size_t>(1)));
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
    TMatrix<int> m(2);
    m[0][0]=1;
    m[0][1]=2;
    m[1][1]=3;
    TMatrix<int> mat(m);
    EXPECT_EQ(m,mat);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
    TMatrix<int> m(2);
    m[0][0]=1;
    m[0][1]=2;
    m[1][1]=3;
    TMatrix<int> mat(m);
    EXPECT_NE(&m,&mat);
}

TEST(TMatrix, can_get_size)
{
    TMatrix<int> mat(5);
    EXPECT_EQ(5,mat.getSize());
}

TEST(TMatrix, can_set_and_get_element)
{
    TMatrix<int> mat(5);
    mat[4][4]=5;
    EXPECT_EQ(5,mat[4][4]);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
    TMatrix<int> mat(5);
    ASSERT_ANY_THROW(mat[-4][4]=5);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
    TMatrix<int> mat(5);
    ASSERT_ANY_THROW(mat[5][4]=5);
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
    TMatrix<int> mat(5);
    ASSERT_NO_THROW(mat=mat);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
    int size=5;
    TMatrix<int> mat(size), mat1(size);
    mat[2][2]=1;
    mat[3][3]=2;
    mat1=mat;
    EXPECT_EQ(mat,mat1);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
    TMatrix<int> mat(5), mat1(2);
    mat[2][2]=1;
    mat[3][3]=2;
    mat1=mat;
    EXPECT_EQ(mat.getSize(),mat1.getSize());
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
    TMatrix<int> mat(5), mat1(2);
    mat[2][2]=1;
    mat[3][3]=2;
    mat1=mat;
    EXPECT_EQ(mat,mat1);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
    TMatrix<int> mat(5), mat1(5);
    mat[2][2]=1;
    mat[3][3]=2;
    mat1[2][2]=1;
    mat1[3][3]=2;
    EXPECT_EQ(mat,mat1);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
    TMatrix<int> mat(5);
    mat[2][2]=1;
    mat[3][3]=2;
    EXPECT_EQ(true,mat==mat);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
    TMatrix<int> mat(5), mat1(2);
    EXPECT_NE(mat,mat1);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
    TMatrix<int> mat(5), mat1(5), fin(5);
    mat[2][2]=1;
    mat[3][3]=2;
    mat1[2][2]=1;
    mat1[3][3]=2;
    fin[2][2]=mat[2][2]+mat1[2][2];
    fin[3][3]=mat[3][3]+mat1[3][3];
    EXPECT_EQ(fin,mat+mat1);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
    TMatrix<int> mat(2), mat1(5);
    ASSERT_ANY_THROW(mat+mat1);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
    TMatrix<int> mat(5), mat1(5), fin(5);
    mat[2][2]=2;
    mat[3][3]=3;
    mat1[2][2]=1;
    mat1[3][3]=2;
    fin[2][2]=mat[2][2]-mat1[2][2];
    fin[3][3]=mat[3][3]-mat1[3][3];
    EXPECT_EQ(fin,mat-mat1);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
    TMatrix<int> mat(2), mat1(5);
    ASSERT_ANY_THROW(mat-mat1);
}
