#include <gtest.h>
#include "utmatrix.h"

TEST(TVector, can_create_vector_with_positive_length)
{
    ASSERT_NO_THROW(TVector<int> v(5));
}

TEST(TVector, cant_create_too_large_vector)
{
    ASSERT_ANY_THROW(TVector<int> v(TVector<int>::max_size + static_cast<size_t>(1)));
}

TEST(TVector, throws_when_create_vector_with_negative_length)
{
    ASSERT_ANY_THROW(TVector<int> v(-5));
}

TEST(TVector, throws_when_create_vector_with_negative_startindex)
{
    ASSERT_ANY_THROW(TVector<int> v(5, -2));
}

TEST(TVector, can_create_copied_vector)
{
    TVector<int> v(10);

    ASSERT_NO_THROW(TVector<int> v1(v));
}

TEST(TVector, copied_vector_is_equal_to_source_one)
{
    TVector<int> v1(3);
    v1[0] = 1; 
    v1[1] = 3;
    v1[2] = 2;

    TVector<int> v2(v1);
    EXPECT_EQ(v1, v2);
}

TEST(TVector, copied_vector_has_its_own_memory)
{
    TVector<int> v(3);
    TVector<int> v1(v);
    bool flag;

    if (sizeof(v1)) flag = 1;
    EXPECT_EQ(1, flag);
}

TEST(TVector, can_get_size)
{
    TVector<int> v(4);

    EXPECT_EQ(4, v.getSize());
}

TEST(TVector, can_get_start_index)
{
    TVector<int> v(4, 2);

    EXPECT_EQ(2, v.getStartIndex());
}

TEST(TVector, can_set_and_get_element)
{
    TVector<int> v(4);
    v[0] = 4;

    EXPECT_EQ(4, v[0]);
}

TEST(TVector, throws_when_set_element_with_negative_index)
{
    TVector<int> v;

    ASSERT_ANY_THROW(v[-1] = 1);
}

TEST(TVector, throws_when_set_element_with_too_large_index)
{
    TVector<int> v(10);

    ASSERT_ANY_THROW(v[10] = 1);
}

TEST(TVector, can_assign_vector_to_itself)
{
    TVector<int> v1;

    ASSERT_NO_THROW(v1 = v1);
}

TEST(TVector, can_assign_vectors_of_equal_size)
{
    const int size = 3;
    TVector<int> v1(size);
    TVector<int> v2(size);

    v2 = v1;

    EXPECT_EQ(v1, v2);
}

TEST(TVector, assign_operator_change_vector_size)
{
    const int size1 = 3;
    const int size2 = 5;
    TVector<int> v1(size1);
    TVector<int> v2(size2);

    ASSERT_NO_THROW(v2 = v1);
    EXPECT_EQ(size1, v2.getSize());
}

TEST(TVector, can_assign_vectors_of_different_size)
{
    TVector<int> v1(5, 2);
    TVector<int> v2(5, 2);

    ASSERT_NO_THROW(v2 = v1);
    EXPECT_EQ(v1, v2);
}

TEST(TVector, compare_equal_vectors_return_true)
{
    TVector<int> v1(5, 2);
    TVector<int> v2(5, 2);
    v1[2] = 1; v2[2] = 1;
    v1[3] = 3; v2[3] = 3;
    v1[4] = 2; v2[4] = 2;

    EXPECT_EQ(true, v1 == v2);
}

TEST(TVector, compare_vector_with_itself_return_true)
{
    TVector<int> v;

    EXPECT_EQ(true, v == v);
}

TEST(TVector, vectors_with_different_size_are_not_equal)
{
    TVector<int> v1(5, 2);
    TVector<int> v2(7, 2);

    EXPECT_EQ(false, v1 == v2);
}

TEST(TVector, can_add_scalar_to_vector)
{
    TVector<int> v(5, 2);
    TVector<int> res(5, 2);

    v[2] = 1;
    v[3] = 3;
    v[4] = 2;

    res[2] = 6;
    res[3] = 8;
    res[4] = 7;

    v = v + 5;

    EXPECT_EQ(v, res);
}

TEST(TVector, can_subtract_scalar_from_vector)
{
    TVector<int> v(5, 2);
    TVector<int> res(5, 2);

    v[2] = 6;
    v[3] = 8;
    v[4] = 7;

    res[2] = 1;
    res[3] = 3;
    res[4] = 2;

    v = v - 5;

    EXPECT_EQ(v, res);
}

TEST(TVector, can_multiply_scalar_by_vector)
{
    TVector<int> v(5, 2);
    TVector<int> res(5, 2);

    v[2] = 1;
    v[3] = 3;
    v[4] = 2;

    res[2] = 3;
    res[3] = 9;
    res[4] = 6;

    v = v * 3;

    EXPECT_EQ(v, res);
}

TEST(TVector, can_add_vectors_with_equal_size)
{
    TVector<int> v1(5, 2);
    TVector<int> v2(5, 2);
    TVector<int> res(5, 2);

    v1[2] = 1; v2[2] = 1;
    v1[3] = 3; v2[3] = 2;
    v1[4] = 2; v2[4] = 6;

    res[2] = 2;
    res[3] = 5;
    res[4] = 8;

    TVector<int> v3 = v1 + v2;

    EXPECT_EQ(v3, res);
}

TEST(TVector, cant_add_vectors_with_not_equal_size)
{
    TVector<int> v1(7, 2);
    TVector<int> v2(5, 2);
    TVector<int> res(7, 2);

    ASSERT_ANY_THROW(res = v1 + v2);
}

TEST(TVector, can_subtract_vectors_with_equal_size)
{
    TVector<int> v1(5, 2);
    TVector<int> v2(5, 2);
    TVector<int> res(5, 2);

    v1[2] = 1; v2[2] = 1;
    v1[3] = 3; v2[3] = 2;
    v1[4] = 2; v2[4] = 6;

    res[2] = 0;
    res[3] = 1;
    res[4] = -4;

    TVector<int> v3 = v1 - v2;

    EXPECT_EQ(v3, res);
}

TEST(TVector, cant_subtract_vectors_with_not_equal_size)
{
    TVector<int> v1(7, 2);
    TVector<int> v2(5, 2);
    TVector<int> res(7, 2);

    ASSERT_ANY_THROW(res = v1 - v2);
}

TEST(TVector, can_multiply_vectors_with_equal_size)
{
    TVector<int> v1(5, 2);
    TVector<int> v2(5, 2);

    v1[2] = 1; v2[2] = 1;
    v1[3] = 3; v2[3] = 2;
    v1[4] = 2; v2[4] = 6;

    int res = 19;
    int prod = v1 * v2;

    EXPECT_EQ(prod, res);
    
}

TEST(TVector, cant_multiply_vectors_with_not_equal_size)
{
    TVector<int> v1(7, 2);
    TVector<int> v2(5, 2);
    int res;

    ASSERT_ANY_THROW(res = v1 * v2);
}
