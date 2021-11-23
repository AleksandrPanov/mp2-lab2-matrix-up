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
    TVector<int> a(3);
    a[2] = 10;
    TVector<int> b(a);
    EXPECT_EQ(a, b);
}

TEST(TVector, copied_vector_has_its_own_memory)
{
    TVector<int> a(3);
    a[2] = 10;
    TVector<int> b(a);
    b[2] = 55;
    EXPECT_NE(a, b);
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
    TVector<int> a(3);
    ASSERT_ANY_THROW(a.setElement(-1, 11));
}

TEST(TVector, throws_when_set_element_with_too_large_index)
{
    TVector<int> a(3);
    ASSERT_ANY_THROW(a.setElement(5, 5));
}

TEST(TVector, can_assign_vector_to_itself)
{
    TVector<int> a(3);
    ASSERT_NO_THROW(a = a);
}

TEST(TVector, can_assign_vectors_of_equal_size)
{
    TVector<int> a(5);
    TVector<int> b(5);
    a[3] = 5;
    b = a;
    EXPECT_EQ(a, b);
}

TEST(TVector, assign_operator_change_vector_size)
{
    TVector<int> a(5);
    TVector<int> b(3);
    b = a;
    EXPECT_EQ(5, b.getSize());
}

TEST(TVector, can_assign_vectors_of_different_size)
{
    TVector<int> a(10);
    TVector<int> b(12);
    b[3] = 5;
    ASSERT_NO_THROW(a = b);
}

TEST(TVector, compare_equal_vectors_return_true)
{
    TVector<int> a(10);
    for (int i = 0; i < 10; i++)
    {
        a[i] = 1;
    }
    TVector<int> b(a);
    EXPECT_EQ(a, b);
}

TEST(TVector, compare_vector_with_itself_return_true)
{
    TVector<int> a(5);

    for (int i = 0; i < 5; i++)
    {
        a[i] = 1;
    }

    EXPECT_EQ(a, a);
}

TEST(TVector, vectors_with_different_size_are_not_equal)
{
    TVector<int> a(5);
    TVector<int> b(3);
    EXPECT_NE(a, b);
}

TEST(TVector, can_add_scalar_to_vector)
{
    TVector<int> a(5);
    TVector<int> b(a);
    for (int i = 0; i < 5; i++)
    {
        a[i] = 10;
    }
    b = b + 10;
    EXPECT_EQ(a, b);
}

TEST(TVector, can_subtract_scalar_from_vector)
{
    TVector<int> a(5);
    TVector<int> b(5);
    for (int i = 0; i < 5; i++)
    {
        a[i] = 10;
    }
    b = a;
    b = b - 5;
    for (int i = 0; i < 5; i++)
    {
        a[i] = 5;
    }
    EXPECT_EQ(a, b);
}

TEST(TVector, can_multiply_scalar_by_vector)
{
    TVector<int> a(5);
    TVector<int> b(5);
    for (int i = 0; i < 5; i++)
    {
        a[i] = 5;
    }
    b = a * 5;
    for (int i = 0; i < 5; i++)
    {
        a[i] = 25;
    }
    EXPECT_EQ(b, a);
}

TEST(TVector, can_add_vectors_with_equal_size)
{
    TVector<int> a(5);
    TVector<int> b(5);
    TVector<int> c(5);
    for (int i = 0; i < 5; ++i)
    {
        a[i] = 1;
        b[i] = 1;
        c[i] = 2;
    }
    EXPECT_EQ(a + b, c);
}

TEST(TVector, cant_add_vectors_with_not_equal_size)
{
    TVector<int> a(5);
    TVector<int> b(2);
    ASSERT_ANY_THROW(a + b);
}

TEST(TVector, can_subtract_vectors_with_equal_size)
{
    TVector<int> a(5);
    TVector<int> b(5);
    TVector<int> c(5);
    for (int i = 0; i < 5; ++i)
    {
        a[i] = 2;
        b[i] = 1;
        c[i] = 1;
    }
    EXPECT_EQ(a - b, c);
}

TEST(TVector, cant_subtract_vectors_with_not_equal_size)
{
    TVector<int> a(5);
    TVector<int> b(4);
    ASSERT_ANY_THROW(a - b);
}

TEST(TVector, can_multiply_vectors_with_equal_size)
{
    TVector<int> a(5);
    TVector<int> b(5);
    for (int i = 0; i < 5; ++i)
    {
        a[i] = 1;
        b[i] = 1;
    }
    EXPECT_EQ(a * b, 5);
}

TEST(TVector, cant_multiply_vectors_with_not_equal_size)
{
    TVector<int> a(5);
    TVector<int> b(4);
    ASSERT_ANY_THROW(a * b);
}
