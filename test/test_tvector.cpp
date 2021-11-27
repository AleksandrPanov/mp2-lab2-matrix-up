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
    TVector<int> f(10);
    f.setElement(6, 23);
    TVector<int> l(f);

    EXPECT_EQ(l[6], f[6]);
}

TEST(TVector, copied_vector_has_its_own_memory)
{
    TVector<int> f(13);
    TVector<int> l(f);
    f.setElement(3, 23);

    EXPECT_NE(f[3], l[3]);
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
    ASSERT_ANY_THROW(v.setElement(-1, 23));
}

TEST(TVector, throws_when_set_element_with_too_large_index)
{
    TVector<int> v(4);
    ASSERT_ANY_THROW(v.setElement(32, 23));
}

TEST(TVector, can_assign_vector_to_itself)
{
    TVector<int> v(4);
    ASSERT_NO_THROW(v = v);
}

TEST(TVector, can_assign_vectors_of_equal_size)
{
    TVector<int> v(4), m(4);
    m.setElement(1, 23);
    ASSERT_NO_THROW(v = m);
    EXPECT_EQ(v[1], m[1]);
}

TEST(TVector, assign_operator_change_vector_size)
{
    TVector<int> v(4), m(10);
    v = m;
    EXPECT_EQ(v.getSize(), 10);
}

TEST(TVector, can_assign_vectors_of_different_size)
{
    TVector<int> v(4), m(10);
    m.setElement(8, 23);
    ASSERT_NO_THROW(v = m);
    EXPECT_EQ(v[8], m[8]);
}

TEST(TVector, compare_equal_vectors_return_true)
{
    TVector<int> v(15);
    v[10] = 5;
    TVector<int> m = v;
    EXPECT_EQ(v == m, true);
}

TEST(TVector, compare_vector_with_itself_return_true)
{
    TVector<int> v(15);
    v[10] = 5;
    EXPECT_EQ(v == v, true);
}

TEST(TVector, vectors_with_different_size_are_not_equal)
{
    TVector<int> v(15), m(20);
    EXPECT_EQ(v == m, false);
}

TEST(TVector, can_add_scalar_to_vector)
{
    TVector<int> v(4), m(4);
    for (size_t i = 0; i < 4; i++) {
        v[i] = 5;
        m[i] = 0;
    }
    ASSERT_NO_THROW(m + 5);
    m = m + 5;
    EXPECT_EQ(v, m);
}

TEST(TVector, can_subtract_scalar_from_vector)
{
    TVector<int> v(4), m(4);
    for (size_t i = 0; i < 4; i++) {
        v[i] = -5;
        m[i] = 0;
    }
    ASSERT_NO_THROW(m - 5);
    m = m - 5;
    EXPECT_EQ(v == m, true);
}

TEST(TVector, can_multiply_scalar_by_vector)
{
    TVector<int> v(4), m(4);
    for (size_t i = 0; i < 4; i++) {
        v[i] = 5;
        m[i] = 1;
    }
    ASSERT_NO_THROW(m * 5);
    m = m * 5;
    EXPECT_EQ(v == m, true);
}

TEST(TVector, can_add_vectors_with_equal_size)
{
    TVector<int> v(4), m(4);
    TVector<int> res(4);
    for (size_t i = 0; i < 4; i++) {
        v[i] = 2;
        m[i] = 4;
        res[i] = 6;
    }
    v[3] = 10;
    m[3] = 21;
    res[3] = 31;
    EXPECT_EQ(res, v + m);
}

TEST(TVector, cant_add_vectors_with_not_equal_size)
{
    TVector<int> v(4), m(6);
    ASSERT_ANY_THROW(v + m);
}

TEST(TVector, can_subtract_vectors_with_equal_size)
{
    TVector<int> v(4), m(4);
    TVector<int> res(4);
    for (size_t i = 0; i < 4; i++) {
        v[i] = 2;
        m[i] = 4;
        res[i] = -2;
    }
    v[3] = 10;
    m[3] = 21;
    res[3] = -11;
    EXPECT_EQ(res, v - m);
}

TEST(TVector, cant_subtract_vectors_with_not_equal_size)
{
    TVector<int> v(4), m(6);
    ASSERT_ANY_THROW(v - m);
}

TEST(TVector, can_multiply_vectors_with_equal_size)
{
    TVector<int> v(5), m(5);
    int res;
    for (size_t i = 0; i < 5; i++) {
        v[i] = 1;
        m[i] = 1;
    }
    v[3] = 7;
    m[3] = 3;
    res = 25;
    EXPECT_EQ(res, v * m);
}

TEST(TVector, cant_multiply_vectors_with_not_equal_size)
{
    TVector<int> v(4), m(6);
    ASSERT_ANY_THROW(v * m);
}
