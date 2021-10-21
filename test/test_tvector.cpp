#include <gtest.h>
#include "utmatrix.h"

TEST(TVector, can_create_vector_with_positive_length)
{
    ASSERT_NO_THROW(TVector<int> v(5));
}

TEST(TVector, cant_create_too_large_vector)
{
    // максимальный допустимый размер вектора = TVector<int>::max_size
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
    TVector<int> v(10, 0);
    v.setElement(0, 1);
    v.setElement(1, 2);
    TVector<int> v1(v);
    EXPECT_EQ(v, v1);
}

TEST(TVector, copied_vector_has_its_own_memory)
{
    TVector<int> v(10);
    v.setElement(0, 1);
    v.setElement(1, 2);
    TVector<int> v1(v);
    v.setElement(5, 5);
    EXPECT_NE(v, v1);
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
    TVector<int> v(4);
    ASSERT_ANY_THROW(v.setElement(-5, 1));
}

TEST(TVector, throws_when_set_element_with_too_large_index)
{
    TVector<int> v(4);
    ASSERT_ANY_THROW(v.setElement(100, 100));
}

TEST(TVector, can_assign_vector_to_itself)
{
    TVector<int> v(4);
    ASSERT_NO_THROW(v = v);
}

TEST(TVector, can_assign_vectors_of_equal_size)
{
    TVector<int> v(4);
    TVector<int> v1(4);
    for (int i = 0; i < 4; i++)
    {
        v[i] = 1;
        v1[i] = 2;
    }
    v = v1;
    EXPECT_EQ(v, v1);
}

TEST(TVector, assign_operator_change_vector_size)
{
    TVector<int> v(1);
    TVector<int> v1(10);
    v = v1;
    EXPECT_EQ(10, v.getSize());
}

TEST(TVector, can_assign_vectors_of_different_size)
{
    TVector<int> v(1);
    v.setElement(0, 1);
    TVector<int> v1(10);
    for (int i = 0; i < 10; i++)
    {
        v1[i] = i;
    }
    v = v1;
    EXPECT_EQ(v, v1);
}

TEST(TVector, compare_equal_vectors_return_true)
{
    TVector<int> v(4);
    TVector<int> v1(4);
    for (int i = 0; i < 4; i++)
    {
        v[i] = i;
        v1[i] = i;
    }
    EXPECT_EQ(true, v == v1);
}

TEST(TVector, compare_vector_with_itself_return_true)
{
    TVector<int> v(4);
    EXPECT_EQ(true, v == v);
}

TEST(TVector, vectors_with_different_size_are_not_equal)
{
    TVector<int> v(4);
    TVector<int> v1(5);
    EXPECT_EQ(false, v == v1);
}

TEST(TVector, can_add_scalar_to_vector)
{
    TVector<int> v(4);
    TVector<int> v1(4);
    for (int i = 0; i < 4; i++)
    {
        v[i] = 1;
        v1[i] = 2;
    }
    v = v + 1;
    EXPECT_EQ(v, v1);
}

TEST(TVector, can_subtract_scalar_from_vector)
{
    TVector<int> v(4);
    TVector<int> v1(4);
    for (int i = 0; i < 4; i++)
    {
        v[i] = 2;
        v1[i] = 1;
    }
    v = v - 1;
    EXPECT_EQ(v, v1);
}

TEST(TVector, can_multiply_scalar_by_vector)
{
    TVector<int> v(4);
    TVector<int> v1(4);
    for (int i = 0; i < 4; i++)
    {
        v[i] = 1;
        v1[i] = 8;
    }
    v = v * 8;
    EXPECT_EQ(v, v1);
}

TEST(TVector, can_add_vectors_with_equal_size)
{
    TVector<int> result(4);
    TVector<int> v(4);
    TVector<int> v1(4);
    TVector<int> v2(4);
    for (int i = 0; i < 4; i++)
    {
        v[i] = 1;
        v1[i] = 2;
        v2[i] = 3;
    }
    result = v + v1;
    EXPECT_EQ(result, v2);
}

TEST(TVector, cant_add_vectors_with_not_equal_size)
{
    TVector<int> v(1);
    TVector<int> v1(10);
    ASSERT_ANY_THROW(v + v1);
}

TEST(TVector, can_subtract_vectors_with_equal_size)
{
    TVector<int> result(4);
    TVector<int> v(4);
    TVector<int> v1(4);
    TVector<int> v2(4);
    for (int i = 0; i < 4; i++)
    {
        v[i] = 5;
        v1[i] = 2;
        v2[i] = 3;
    }
    result = v - v1;
    EXPECT_EQ(result, v2);
}

TEST(TVector, cant_subtract_vectors_with_not_equal_size)
{
    TVector<int> v(10);
    TVector<int> v1(1);
    ASSERT_ANY_THROW(v - v1);
}

TEST(TVector, can_multiply_vectors_with_equal_size)
{
    int result = 6;
    TVector<int> v(4);
    TVector<int> v1(4);
    for (int i = 0; i < 4; i++)
    {
        v[i] = i;
        v1[i] = 1;
    }
    EXPECT_EQ(result, v * v1);
}

TEST(TVector, cant_multiply_vectors_with_not_equal_size)
{
    TVector<int> v(1);
    TVector<int> v1(10);
    ASSERT_ANY_THROW(v * v1);
}
