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
    int si = 2;
    int sz = 5;
    TVector<int> v(sz,si);
    for (int i = 0; i < sz - si; i++) {
        v[i] = 10 - i;
    }
    TVector<int> v1(v);


    EXPECT_EQ(v1,v);
}

TEST(TVector, copied_vector_has_its_own_memory)
{
    TVector<int> v(10);
    TVector<int> v1(v);

    for (int i = 0; i < v.getSize(); i++) {
        v[i] = 3;
        v1[i] = 7;
        EXPECT_NE(v[i], v1[i]);
    }
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
    v.setElement(2, 5);
    EXPECT_EQ(5, v.getElement(2));
}

TEST(TVector, throws_when_set_element_with_negative_index)
{
    TVector<int> v(4);

    ASSERT_ANY_THROW(v.setElement(-3,5));
}

TEST(TVector, throws_when_set_element_with_too_large_index)
{
    TVector<int> v(4);

    ASSERT_ANY_THROW(v.setElement(5, 5));
}

TEST(TVector, can_assign_vector_to_itself)
{
    TVector<int> a(4);
    for (int i = 0; i < a.getSize(); i++) {
        a[i] = i;
    }
    TVector<int> b(a);
    a = b;
    EXPECT_EQ(a, b);
}

TEST(TVector, can_assign_vectors_of_equal_size)
{
    TVector<int> a(4);
    TVector<int> b(4);
    for (int i = 0; i < a.getSize(); i++) {
        a[i] = i;
    }
    a = b;
    EXPECT_EQ(a, b);
}

TEST(TVector, assign_operator_change_vector_size)
{
    TVector<int> a(4);
    TVector<int> b(7);
    for (int i = 0; i < a.getSize(); i++) {
        a[i] = i;
    }
    a = b;
    EXPECT_EQ(a.getSize(), b.getSize());
}

TEST(TVector, can_assign_vectors_of_different_size)
{
    TVector<int> a(4);
    TVector<int> b(7);
    for (int i = 0; i < a.getSize(); i++) {
        a[i] = i;
    }
    a = b;
    EXPECT_EQ(a, b);
}

TEST(TVector, compare_equal_vectors_return_true)
{
    TVector<int> a(4);
    TVector<int> b(7);
    for (int i = 0; i < a.getSize(); i++) {
        a[i] = i;
    }
    a = b;
    EXPECT_TRUE(a == b);
}

TEST(TVector, compare_vector_with_itself_return_true)
{
    ADD_FAILURE();
}

TEST(TVector, vectors_with_different_size_are_not_equal)
{
    TVector<int> a(4);
    TVector<int> b(4);
    for (int i = 0; i < a.getSize(); i++) {
        a[i] = 10;
        b[i] = -4;
    }
    EXPECT_NE(a, b);
}

TEST(TVector, can_add_scalar_to_vector)
{
    TVector<int> a(4);
    TVector<int> b(4);
    for (int i = 0; i < a.getSize(); i++) {
        a[i] = 10;
        b[i] = -4;
    }
    b = b + 14;
    EXPECT_EQ(a, b);
}

TEST(TVector, can_subtract_scalar_from_vector)
{
    TVector<int> a(4);
    TVector<int> b(4);
    for (int i = 0; i < a.getSize(); i++) {
        a[i] = 10;
        b[i] = -4;
    }
    a = a - 14;
    EXPECT_EQ(a, b);
}

TEST(TVector, can_multiply_scalar_by_vector)
{
    TVector<int> a(4);
    TVector<int> b(4);
    for (int i = 0; i < a.getSize(); i++) {
        a[i] = 10;
        b[i] = 2;
    }
    a = a * 5;
    EXPECT_EQ(a, b);
}

TEST(TVector, can_add_vectors_with_equal_size)
{
    /*TVector<int> a(4);
    TVector<int> b(4);
    TVector<int> c(4);
    for (int i = 0; i < a.getSize(); i++) {
        a[i] = 10;
        b[i] = 2;
        c[i] = 12;
    }
    a = a + b;
    EXPECT_EQ(a, c);*/
    ADD_FAILURE();
}

TEST(TVector, cant_add_vectors_with_not_equal_size)
{
    ADD_FAILURE();
}

TEST(TVector, can_subtract_vectors_with_equal_size)
{
    ADD_FAILURE();
}

TEST(TVector, cant_subtract_vectors_with_not_equal_size)
{
    ADD_FAILURE();
}

TEST(TVector, can_multiply_vectors_with_equal_size)
{
    ADD_FAILURE();
}

TEST(TVector, cant_multiply_vectors_with_not_equal_size)
{
    ADD_FAILURE();
}
