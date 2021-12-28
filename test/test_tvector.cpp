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
    TVector <int> v(5);
    for (int i = 0; i < 5; i++)
        v[i] = i;
    TVector<int> v1(v);
    for (int i = 0; i < 5; i++)
        EXPECT_EQ(v[i], v1[i]);
}

TEST(TVector, copied_vector_has_its_own_memory)
{
    TVector <int> v(5);
    for (int i = 0; i < 5; i++)
        v[i] = i;
    TVector<int> v1(v);
    EXPECT_NE(&v, &v1);
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
    ASSERT_ANY_THROW(v[-1]);
}

TEST(TVector, throws_when_set_element_with_too_large_index)
{
    TVector<int> v(5);
    ASSERT_ANY_THROW(v[5]);
}

TEST(TVector, can_assign_vector_to_itself)
{
    TVector<int> v(5);
    for (int i = 0; i < 5; i++)
        v[i] = i;
    ASSERT_NO_THROW(v = v);
}

TEST(TVector, can_assign_vectors_of_equal_size)
{
    TVector<int> v(5), v1(5);
    for (int i = 0; i < 5; i++)
        v[i] = i;
    ASSERT_NO_THROW(v1 = v);
    for (int i = 0; i < 5; i++)
        EXPECT_EQ(v[i], v1[i]);
}

TEST(TVector, assign_operator_change_vector_size)
{
    TMatrix<int> v(5), v1(2);
    v1 = v;
    EXPECT_EQ(v.getSize(), v1.getSize());
    EXPECT_EQ(5, v1.getSize());
}

TEST(TVector, can_assign_vectors_of_different_size)
{
    TVector<int> v(5), v1(3);
    for (int i = 0; i < 5; i++)
        v[i] = i;
    ASSERT_NO_THROW(v1 = v);
    for (int i = 0; i < 5; i++)
        EXPECT_EQ(v[i], v1[i]);
}

TEST(TVector, compare_equal_vectors_return_true)
{
    TVector <int> v(5), v1(5);
    for (int i = 0; i < 5; i++)
    {
        v[i] = i;
        v1[i] = i;
    }
    EXPECT_EQ(v, v1);
}

TEST(TVector, compare_vector_with_itself_return_true)
{
    TVector <int> v(5);
    for (int i = 0; i < 5; i++)
        v[i] = i;
    EXPECT_EQ(v, v);
}

TEST(TVector, vectors_with_different_size_are_not_equal)
{
    TVector <int> v(5), v1(7);
    EXPECT_EQ(true, v == v1);
}

TEST(TVector, can_add_scalar_to_vector)
{
    TVector <int> v(5);
    for (int i = 0; i < 5; i++)
        v[i] = i;
    ASSERT_NO_THROW(v + 5);
    TVector<int>res = v + 5;
    for (int i = 0; i < 5; i++)
        EXPECT_EQ(res[i], i + 5);
}

TEST(TVector, can_subtract_scalar_from_vector)
{
    TVector <int> v(5);
    for (int i = 0; i < 5; i++)
        v[i] = i;
    ASSERT_NO_THROW(v - 5);
    TVector<int>res = v - 5;
    for (int i = 0; i < 5; i++)
        EXPECT_EQ(res[i], i - 5);
}

TEST(TVector, can_multiply_scalar_by_vector)
{
    TVector <int> v(5);
    for (int i = 0; i < 5; i++)
        v[i] = i;
    ASSERT_NO_THROW(v * 5);
    TVector<int>res = v * 5;
    for (int i = 0; i < 5; i++)
        EXPECT_EQ(res[i], i * 5);
}

TEST(TVector, can_add_vectors_with_equal_size)
{
    TVector <int> v(5), v1(5);
    for (int i = 0; i < 5; i++)
    {
        v[i] = 2 * i;
        v1[i] = -i;
    }
    ASSERT_NO_THROW(v + v1);
    TVector<int>res = v + v1;
    for (int i = 0; i < 5; i++)
        EXPECT_EQ(res[i], i);
}

TEST(TVector, cant_add_vectors_with_not_equal_size)
{
    TVector <int> v(5), v1(7);
    ASSERT_ANY_THROW(v + v1);
}

TEST(TVector, can_subtract_vectors_with_equal_size)
{
    TVector <int> v(5), v1(5);
    for (int i = 0; i < 5; i++)
    {
        v[i] = -i;
        v1[i] = -2 * i;
    }
    ASSERT_NO_THROW(v - v1);
    TVector<int>res = v - v1;
    for (int i = 0; i < 5; i++)
        EXPECT_EQ(res[i], i);
}

TEST(TVector, cant_subtract_vectors_with_not_equal_size)
{
    TVector <int> v(5), v1(7);
    ASSERT_ANY_THROW(v - v1);
}

TEST(TVector, can_multiply_vectors_with_equal_size)
{
    TVector <int> v(5), v1(5);
    for (int i = 0; i < 5; i++)
    {
        v[i] = i;
        v1[i] = 2;
    }
    ASSERT_NO_THROW(v * v1);
    int res = v * v1;
    EXPECT_EQ(20, res);
}

TEST(TVector, cant_multiply_vectors_with_not_equal_size)
{
    TVector <int> v(5), v1(7);
    ASSERT_ANY_THROW(v * v1);
}
