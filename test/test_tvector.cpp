#include <gtest.h>
#include "utmatrix.h"

TEST(TVector, copied_vector_is_equal_to_source_one)
{
    ADD_FAILURE();
    TVector<int> v1(10, 5);
    v1[6] = 1;
    v1[7] = 2;
    TVector<int> v2(v1);
    EXPECT_EQ(v1, v2);
}

TEST(TVector, copied_vector_has_its_own_memory)
{
    ADD_FAILURE();
    TVector<int> v1(2);
    v1[0] = 1;
    v1[1] = 2;
    TVector<int> v2(1);
    v2[0] = 3;
    v2 = v1;
    EXPECT_EQ(v1, v2);
}

TEST(TVector, can_get_size){}

TEST(TVector, throws_when_set_element_with_negative_index)
{
    ADD_FAILURE();
    TVector<int> v(4);
    ASSERT_ANY_THROW(v[-1] = 1);
}

TEST(TVector, throws_when_set_element_with_too_large_index)
{
    ADD_FAILURE();
    TVector<int> v(4);
    ASSERT_ANY_THROW(v[5] = 1);
}

TEST(TVector, can_assign_vector_to_itself)
{
    ADD_FAILURE();
    TVector<int> v1(2);
    ASSERT_NO_THROW(v1 = v1);
}

TEST(TVector, can_assign_vectors_of_equal_size)
{
    ADD_FAILURE();
    const int size = 2;
    TVector<int> v1(size), v2(size);
    v1[0] = 1;
    v1[1] = 2;
    v2 = v1;
    EXPECT_EQ(v1[0], v2[0]);
    EXPECT_EQ(v1[1], v2[1]);
}

TEST(TVector, assign_operator_change_vector_size)
{
    ADD_FAILURE();
    const int size1 = 2, size2 = 1;
    TVector<int> v1(size1), v2(size2);
    v1[0] = 1;
    v1[1] = 2;
    v2[0] = 1;
    v1 = v2;
    EXPECT_EQ(size2, v1.getSize());
}

TEST(TVector, can_assign_vectors_of_different_size)
{
    ADD_FAILURE();
    const int size1 = 2, size2 = 1;
    TVector<int> v1(size1), v2(size2);
    v1[0] = 1;
    v1[1] = 2;
    v2 = v1;
    EXPECT_EQ(v1[0], v2[0]);
    EXPECT_EQ(v1[1], v2[1]);
}

TEST(TVector, compare_equal_vectors_return_true)
{
    ADD_FAILURE();
    const int size = 2;
    TVector<int> v1(size), v2(size);
    v1[0] = 1;
    v1[1] = 2;
    v2[0] = 1;
    v2[1] = 2;
    EXPECT_EQ(v1, v2);
}

TEST(TVector, compare_vector_with_itself_return_true)
{
    ADD_FAILURE();
    const int size = 2;
    TVector<int> v1(size);
    v1[0] = 1;
    v1[1] = 2;
    EXPECT_EQ(v1, v1);
}

TEST(TVector, vectors_with_different_size_are_not_equal)
{
    ADD_FAILURE();
    const int size1 = 2, size2 = 1;
    TVector<int> v1(size1), v2(size2);
    v1[0] = 1;
    v1[1] = 2;
    v2[0] = 1;
    EXPECT_NE(v1, v2);
}

TEST(TVector, can_add_scalar_to_vector)
{
    ADD_FAILURE();
    const int size = 2;
    TVector<int> v1(size), v2(size);
    v1[0] = 1;
    v1[1] = 2;
    v2[0] = 2;
    v2[1] = 3;
    v1 = v1 + 1;
    EXPECT_EQ(v1, v2);
}

TEST(TVector, can_subtract_scalar_from_vector)
{
    ADD_FAILURE();
    const int size = 2;
    TVector<int> v1(size), v2(size);
    v1[0] = 1;
    v1[1] = 2;
    v2[0] = 2;
    v2[1] = 3;
    v2 = v2 - 1;
    EXPECT_EQ(v1, v2);
}

TEST(TVector, can_multiply_scalar_by_vector)
{
    ADD_FAILURE();
    const int size = 2;
    TVector<int> v1(size), v2(size);
    v1[0] = 1;
    v1[1] = 2;
    v2[0] = 2;
    v2[1] = 4;
    v1 = v1 * 2;
    EXPECT_EQ(v1, v2);
}

TEST(TVector, can_add_vectors_with_equal_size)
{
    ADD_FAILURE();
    const int size = 2;
    TVector<int> v1(size), v2(size), v3(size);
    v1[0] = 1;
    v1[1] = 2;
    v2[0] = 2;
    v2[1] = 4;

    v3[0] = 3;
    v3[1] = 6;
    EXPECT_EQ(v3, v1 + v2);
}

TEST(TVector, cant_add_vectors_with_not_equal_size)
{
    ADD_FAILURE();
    const int size1 = 2, size2 = 1;
    TVector<int> v1(size1), v2(size2);
    v1[0] = 1;
    v1[1] = 2;
    v2[0] = 2;
    ASSERT_ANY_THROW(v1 + v2);
}

TEST(TVector, can_subtract_vectors_with_equal_size)
{
    ADD_FAILURE();
    const int size = 2;
    TVector<int> v1(size), v2(size), v3(size);
    v1[0] = 1;
    v1[1] = 2;
    v2[0] = 2;
    v2[1] = 4;

    v3[0] = 1;
    v3[1] = 2;
    EXPECT_EQ(v3, v2 - v1);
}

TEST(TVector, cant_subtract_vectors_with_not_equal_size)
{
    ADD_FAILURE();
    const int size1 = 2, size2 = 1;
    TVector<int> v1(size1), v2(size2);
    v1[0] = 1;
    v1[1] = 2;
    v2[0] = 2;
    ASSERT_ANY_THROW(v2 - v1);
}

TEST(TVector, can_multiply_vectors_with_equal_size)
{
    ADD_FAILURE();
    const int size = 2;
    TVector<int> v1(size), v2(size);
    int m = 10;
    v1[0] = 1;
    v1[1] = 2;
    v2[0] = 2;
    v2[1] = 4;
    EXPECT_EQ(m, v1 * v2);
}

TEST(TVector, cant_multiply_vectors_with_not_equal_size)
{
    ADD_FAILURE();
    const int size1 = 2, size2 = 1;
    TVector<int> v1(size1), v2(size2);
    v1[0] = 1;
    v1[1] = 2;
    v2[0] = 2;
    ASSERT_ANY_THROW(v1 * v2);
}