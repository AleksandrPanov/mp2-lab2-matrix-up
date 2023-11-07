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
    TVector<int> v0(30);
    for (size_t i = 0; i < 30; i++)
    {
        v0[i] = i;
    }
    TVector<int> v1(v0);
    EXPECT_EQ(v0, v1);
}

TEST(TVector, copied_vector_has_its_own_memory)
{
    TVector<int> v0(30);
    for (size_t i = 0; i < 30; i++)
    {
        v0[i] = i;
    }
    TVector<int> v1(v0);
    EXPECT_EQ(1, &v0 != &v1);
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
    TVector<int> v(5);
    ASSERT_ANY_THROW(v[-5]);
}

TEST(TVector, throws_when_set_element_with_too_large_index)
{
    TVector<int> v(5);
    ASSERT_ANY_THROW(v[5]);
}

TEST(TVector, can_assign_vector_to_itself)
{
    TVector<int> v(5);
    ASSERT_NO_THROW(v = v);
}

TEST(TVector, can_assign_vectors_of_equal_size)
{
    TVector<int> v0(5), v1(5);
    ASSERT_NO_THROW(v0 = v1);
}

TEST(TVector, assign_operator_change_vector_size)
{
    TVector<int> v0(5), v1(1);
    v1 = v0;
    EXPECT_EQ(v1.getSize(), 5);
}

TEST(TVector, can_assign_vectors_of_different_size)
{
    TVector<int> v0(5), v1(4);
    ASSERT_NO_THROW(v0 = v1);
}

TEST(TVector, compare_equal_vectors_return_true)
{
    TVector<int> v0(10), v1(10);
    for (size_t i = 0; i < 10; i++)
    {
        v0[i] = i;
        v1[i] = i;
    }
    EXPECT_EQ(v0, v1);
}

TEST(TVector, compare_vector_with_itself_return_true)
{
    TVector<int> v0(10);
    EXPECT_EQ(1, v0 == v0);
}

TEST(TVector, vectors_with_different_size_are_not_equal)
{
    TVector<int> v0(10), v1(11);
    for (size_t i = 0; i < 10; i++)
    {
        v0[i] = i;
    }
    for (size_t i = 0; i < 11; i++)
    {
        v1[i] = i;
    }
    EXPECT_EQ(1, v0 != v1);
}

TEST(TVector, can_add_scalar_to_vector)
{
    TVector<int> v0(2);
    v0[0] = 1;
    v0[1] = 2;
    v0 = v0 + 5;
    EXPECT_EQ(13, v0[0]+v0[1]);
}

TEST(TVector, can_subtract_scalar_from_vector)
{
    TVector<int> v0(2);
    v0[0] = 1;
    v0[1] = 2;
    v0 = v0 - 5;
    EXPECT_EQ(-7, v0[0] + v0[1]);
}

TEST(TVector, can_multiply_scalar_by_vector)
{
    TVector<int> v0(2);
    v0[0] = 1;
    v0[1] = 2;
    v0 = v0 * 5;
    EXPECT_EQ(15, v0[0] + v0[1]);
}

TEST(TVector, can_add_vectors_with_equal_size)
{
    TVector<int> v0(4), v1(4);
    ASSERT_NO_THROW(v0 = v0 + v1);
}

TEST(TVector, cant_add_vectors_with_not_equal_size)
{
    TVector<int> v0(5), v1(4);
    ASSERT_ANY_THROW(v0 = v0 + v1);
}

TEST(TVector, can_subtract_vectors_with_equal_size)
{
    TVector<int> v0(4), v1(4);
    ASSERT_NO_THROW(v0 = v0 - v1);
}

TEST(TVector, cant_subtract_vectors_with_not_equal_size)
{
    TVector<int> v0(5), v1(4);
    ASSERT_ANY_THROW(v0 = v0 - v1);
}

TEST(TVector, can_multiply_vectors_with_equal_size)
{
    TVector<int> v0(2);
    v0[0] = 4;
    v0[1] = 3;
    TVector<int> v1 = v0;
    EXPECT_EQ(25, v0 * v1);
    ASSERT_NO_THROW(v0 * v1);
}

TEST(TVector, cant_multiply_vectors_with_not_equal_size)
{
    TVector<int> v0(2);
    TVector<int> v1(3);
    ASSERT_ANY_THROW(v0 * v1);
}
