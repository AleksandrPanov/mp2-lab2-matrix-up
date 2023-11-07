#include <gtest.h>
#include "utmatrix.h"
#include <iostream>
using namespace std;

TEST(TVector, can_create_vector_with_positive_length)
{
    ASSERT_NO_THROW(TVector<int> v(5));
}

TEST(TVector, cant_create_too_large_vector)
{
    // ������������ ���������� ������ ������� = TVector<int>::max_size
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
    TVector<int> v(10);
    for (int i = 0; i < 10; ++i)
    {
        v[i] = 5;
    }
    TVector<int> v1(v);

    EXPECT_EQ(v, v1);
}

TEST(TVector, copied_vector_has_its_own_memory)
{
    TVector<int> v(3);
    for (int i = 0; i < 3; i++) { v[i] = 1; }
    TVector<int> v1(v);
    
    v1[2] = 0;
    
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
    v.setElement(0, 4);

    EXPECT_EQ(4, v.getElement(0));
}

TEST(TVector, throws_when_set_element_with_negative_index)
{
    TVector<int>v(4, 2);
    int index = -1;
    int element = 1;

    ASSERT_ANY_THROW(v.setElement(index, element));
}

TEST(TVector, throws_when_set_element_with_too_large_index)
{
    TVector<int>v(4, 2);
    int index = 5;
    int element = 1;

    ASSERT_ANY_THROW(v.setElement(index, element));
}

TEST(TVector, can_assign_vector_to_itself)
{
    TVector<int>v(4);
    
    v = v;
    
    ASSERT_NO_THROW(v[2]);
}

TEST(TVector, can_assign_vectors_of_equal_size)
{
    TVector<int>v(4);
    for (int i = 0; i < 4; i++) { v[i] = 1; }
    TVector<int>v1(4);

    v1 = v;

    EXPECT_EQ(v, v1);
}

TEST(TVector, assign_operator_change_vector_size)
{
    TVector<int>v(4);
    TVector<int>v1(3);

    v1 = v;

    EXPECT_EQ(v.getSize(), v1.getSize());
}

TEST(TVector, can_assign_vectors_of_different_size)
{
    TVector<int>v(4);
    TVector<int>v1(3);
    //v1=v;

    ASSERT_NO_THROW(v1=v);
}

TEST(TVector, compare_equal_vectors_return_true)
{
    TVector<int> v(3); 
    v[0] = 0; v[1] = 0; v[2] = 0;
    TVector<int> vec(3);
    vec[0] = 0; vec[1] = 0; vec[2] = 0;

    EXPECT_EQ(true, v == vec);
}

TEST(TVector, compare_vector_with_itself_return_true)
{
    TVector<int> v(3);
    v[0] = 0; v[1] = 0; v[2] = 0;

    EXPECT_EQ(true, v == v);
}

TEST(TVector, vectors_with_different_size_are_not_equal)
{
    TVector<int> v(3);
    v[0] = 0; v[1] = 0; v[2] = 0;
    TVector<int> vec(4);
    vec[0] = 0; vec[1] = 0; vec[2] = 0; vec[3] = 0;

    EXPECT_NE(v, vec);
}

TEST(TVector, can_add_scalar_to_vector)
{
    int sc = 1;
    TVector<int>v(3);
    for (int i = 0; i < 3; i++)
    {
        v[i] = 0;
    }
    TVector<int>v1(3);
    for (int i = 0; i < 3; i++)
    {
        v1[i] = 1;
    }

    v=v + sc;

    EXPECT_EQ(v1, v);
}

TEST(TVector, can_subtract_scalar_from_vector)
{
    int sc = 1;
    TVector<int>v(3);
    for (int i = 0; i < 3; i++)
    {
        v[i] = 0;
    }
    TVector<int>v1(3);
    for (int i = 0; i < 3; i++)
    {
        v1[i] = 1;
    }

    v1 = v1 - sc;

    EXPECT_EQ(v, v1);
}

TEST(TVector, can_multiply_scalar_by_vector)
{
    int sc = 3;
    TVector<int>v1(3);
    for (int i = 0; i < 3; i++)
    {
        v1[i] = 1;
    }
    TVector<int>v(3);
    for (int i = 0; i < 3; i++)
    {
        v[i] = 3;
    }

    v1 = v1 * 3;

    EXPECT_EQ(v, v1);
}

TEST(TVector, can_add_vectors_with_equal_size)
{
    TVector<int> a(3, 0); TVector<int> b(3, 0); TVector<int> c(3, 0);
    for (int i = 0; i < 3; i++)
    {
        a[i] = 1; b[i] = 2; c[i] = 3;
    }
    TVector<int> res(3, 0);
    res = a + b;
    EXPECT_EQ(c, res);
}

TEST(TVector, cant_add_vectors_with_not_equal_size)
{
    TVector<int> a(3); 
    TVector<int> b(5);

    ASSERT_ANY_THROW(a + b);
}

TEST(TVector, can_subtract_vectors_with_equal_size)
{
    TVector<int> a(3); TVector<int> b(3); TVector<int> c(3);
    for (int i = 0; i < 3; i++)
    {
        a[i] = 1; b[i] = 2; c[i] = 3;
    }
    TVector<int>res(3);
    res = c - b;

    EXPECT_EQ(a, res);
}

TEST(TVector, cant_subtract_vectors_with_not_equal_size)
{
    TVector<int> a(3);
    TVector<int> b(5);

    ASSERT_ANY_THROW(a - b);
}

TEST(TVector, can_multiply_vectors_with_equal_size)
{
    TVector<int> a(3); TVector<int> b(3); 
    for (int i = 0; i < 3; i++)
    {
        a[i] = 2; b[i] = 3;
    }
    int res = 0;
    res = a * b;

    EXPECT_EQ(18, res);
}

TEST(TVector, cant_multiply_vectors_with_not_equal_size)
{
    TVector<int> a(3);
    TVector<int> b(5);

    ASSERT_ANY_THROW(a * b);
}
