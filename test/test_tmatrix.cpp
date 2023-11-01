#include "utmatrix.h"

#include <gtest.h>

TEST(TMatrix, can_create_matrix_with_positive_length)
{
    ASSERT_NO_THROW(TMatrix<int> m(5));
}

TEST(TMatrix, cant_create_too_large_matrix)
{
    ASSERT_ANY_THROW(TVector<int> gold(TVector<int>::max_size + static_cast<size_t>(1)));
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
    TMatrix<int> gold(10);
    for (int i = 0; i < 10; i++) {
        for (int j = i; j < 10; j++)
            gold[i][j] = 420;
    }
    TMatrix<int> silver(gold);
    EXPECT_EQ(silver, gold);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
    TMatrix<int> gold(3);
    for (int i = 0; i < 3; i++) {
        for (int j = i; j < 3; j++) {
            gold[i][j] = 69;
        }
    }
    TMatrix<int> silver = gold;
    silver[2][2] = 420;
    EXPECT_NE(gold, silver);
}

TEST(TMatrix, can_get_size)
{
    TMatrix<int> gold(6);
    EXPECT_EQ(gold.getSize(), 6);
}

TEST(TMatrix, can_set_and_get_element)
{
    TMatrix<int> gold(6);
    gold[3][3] = 420;
    EXPECT_EQ(gold[3][3], 420);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
    TMatrix<int> gold(10);
    ASSERT_ANY_THROW(gold[-1]);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
    TMatrix<int> gold(10);
    ASSERT_ANY_THROW(gold[11]);
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
    TMatrix<int> gold(10);
    ASSERT_NO_THROW(gold = gold);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
    TMatrix<int> gold(3), silver(3);
    for (int i = 0; i < 3; i++) {
        for (int j = i; j < 3; j++) {
            gold[i][j] = 69;
            silver[i][j] = 69;
        }
    }
    silver = gold;
    EXPECT_EQ(gold, silver);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
    TMatrix<int> gold(6), silver(9);
    for (int i = 0; i < 6; i++) {
        for (int j = i; j < 6; j++) {
            gold[i][j] = 69;
            silver[i][j] = 69;
        }
    }
    silver = gold;
    EXPECT_EQ(silver.getSize(), 6);
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
    TMatrix<int> gold(6), silver(9);
    for (int i = 0; i < 6; i++) {
        for (int j = i; j < 6; j++) {
            gold[i][j] = 69;
        }
    }
    silver = gold;
    EXPECT_EQ(gold, silver);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
    TMatrix<int> gold(6), silver(6);
    for (int i = 0; i < 6; i++) {
        for (int j = i; j < 6; j++) {
            gold[i][j] = 69;
            silver[i][j] = 69;
        }
    }
    EXPECT_EQ(gold, silver);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
    TMatrix<int> gold(6), silver(9);
    for (int i = 0; i < 6; i++) {
        for (int j = i; j < 6; j++) {
            gold[i][j] = 69;
        }
    }
    EXPECT_EQ(gold, gold);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
    TMatrix<int> gold(6), silver(9);
    for (int i = 0; i < 6; i++) {
        for (int j = i; j < 6; j++) {
            gold[i][j] = 69;
            silver[i][j] = 69;
        }
    }
    EXPECT_NE(gold, silver);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
    TMatrix<int> gold(6), silver(6), platinum(6);
    for (int i = 0; i < 6; i++) {
        for (int j = i; j < 6; j++) {
            gold[i][j] = 69;
            silver[i][j] = 351;
            platinum[i][j] = 420;
        }
    }
    EXPECT_EQ(gold + silver, platinum);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
    TMatrix<int> gold(6), silver(9);
    for (int i = 0; i < 6; i++) {
        for (int j = i; j < 6; j++) {
            gold[i][j] = 69;
            silver[i][j] = 351;
        }
    }
    ASSERT_ANY_THROW(gold + silver);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
    TMatrix<int> gold(6), silver(6), platinum(6);
    for (int i = 0; i < 6; i++) {
        for (int j = i; j < 6; j++) {
            gold[i][j] = 420;
            silver[i][j] = 351;
            platinum[i][j] = 69;
        }
    }
    EXPECT_EQ(gold - silver, platinum);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
    TMatrix<int> gold(6), silver(9);
    for (int i = 0; i < 6; i++) {
        for (int j = i; j < 6; j++) {
            gold[i][j] = 420;
            silver[i][j] = 351;
        }
    }
    ASSERT_ANY_THROW(gold - silver);
}
