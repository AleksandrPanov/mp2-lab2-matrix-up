#include <gtest.h>
#include "utmatrix.h"

TEST(TVector, can_create_vector_with_positive_length)
{
    ASSERT_NO_THROW(TVector<int> v(5));
}

TEST(TVector, cant_create_too_large_vector)
{
    ASSERT_ANY_THROW(TVector<int> v(TVector<int>::max_size + 1ull));
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

    ASSERT_NO_THROW(TVector<int>(v));
}

TEST(TVector, copied_vector_is_equal_to_source_one)
{
    TVector<int> source(10);

    source.setElement(3, 100);

    EXPECT_EQ(source[3], TVector<int>(source)[3]);
}

TEST(TVector, copied_vector_has_its_own_memory)
{
    TVector<int> source(10);
    TVector<int> vector(source);

    source.setElement(5, 55);

    EXPECT_NE(source.getElement(5), vector.getElement(5));
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
    TVector<int> vector(10);

    ASSERT_ANY_THROW(vector.setElement(-10, 100));
}

TEST(TVector, throws_when_set_element_with_too_large_index)
{
    TVector<int> vector(10);

    ASSERT_ANY_THROW(vector.setElement(10, 100));
}

TEST(TVector, can_assign_vector_to_itself)
{
    TVector<int> vector(10);

    ASSERT_NO_THROW(vector = vector);
}

TEST(TVector, can_assign_vectors_of_equal_size)
{
    TVector<int> vector1(10);
    TVector<int> vector2(10);

    vector1[2] = 1000;

    ASSERT_NO_THROW(vector1 = vector2);

    EXPECT_EQ(vector1[2], vector2[2]);
}

TEST(TVector, assign_operator_change_vector_size)
{
    TVector<int> vector1(100);
    TVector<int> vector2(10);

    vector2 = vector1;

    EXPECT_NE(vector2.getSize(), 10);
}

TEST(TVector, can_assign_vectors_of_different_size)
{
    TVector<int> vector1(100);
    TVector<int> vector2(10);

    ASSERT_NO_THROW(vector2 = vector1);
}

TEST(TVector, compare_equal_vectors_return_true)
{
    TVector<int> vector1(100);
    TVector<int> vector2(vector1);

    EXPECT_EQ(vector1, vector2);
}

TEST(TVector, compare_vector_with_itself_return_true)
{
    TVector<int> vector(100);

    EXPECT_EQ(vector, vector);
}

TEST(TVector, vectors_with_different_size_are_not_equal)
{
    TVector<int> vector1(100);
    TVector<int> vector2(10);

    EXPECT_NE(vector1, vector2);
}

TEST(TVector, can_add_scalar_to_vector)
{
    TVector<int> vector(100);

    ASSERT_NO_THROW(vector + 10);

    EXPECT_EQ((vector + 10)[10], 10);
}

TEST(TVector, can_subtract_scalar_from_vector)
{
    TVector<int> vector(100);

    ASSERT_NO_THROW(vector - 10);

    EXPECT_EQ((vector - 10)[10], -10);
}

TEST(TVector, can_multiply_scalar_by_vector)
{
    TVector<int> vector(100);

    ASSERT_NO_THROW(vector * 10);
}

TEST(TVector, can_add_vectors_with_equal_size)
{
    TVector<int> vector1(10);
    TVector<int> vector2(10);

    vector1[4] = 10;
    vector2[4] = 100;

    ASSERT_NO_THROW(vector1 + vector2);

    EXPECT_EQ((vector1 + vector2)[4], 110);
}

TEST(TVector, cant_add_vectors_with_not_equal_size)
{
    TVector<int> vector1(100);
    TVector<int> vector2(10);

    ASSERT_ANY_THROW(vector1 + vector2);
}

TEST(TVector, can_subtract_vectors_with_equal_size)
{
    TVector<int> vector1(10);
    TVector<int> vector2(10);

    vector1[4] = 10;
    vector2[4] = 100;

    ASSERT_NO_THROW(vector1 - vector2);

    EXPECT_EQ((vector1 - vector2)[4], -90);
}

TEST(TVector, cant_subtract_vectors_with_not_equal_size)
{
    TVector<int> vector1(100);
    TVector<int> vector2(10);

    ASSERT_ANY_THROW(vector1 - vector2);
}

TEST(TVector, can_multiply_vectors_with_equal_size)
{
    TVector<int> vector1(10);
    TVector<int> vector2(10);

    vector1[4] = 10;
    vector2[4] = 100;
    
    ASSERT_NO_THROW(vector1 * vector2);

    EXPECT_EQ((vector1 * vector2), 1000);
}

TEST(TVector, cant_multiply_vectors_with_not_equal_size)
{
    TVector<int> vector1(100);
    TVector<int> vector2(10);

    ASSERT_ANY_THROW(vector1 * vector2);
}
