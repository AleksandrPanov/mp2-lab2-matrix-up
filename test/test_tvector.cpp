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
    TVector<int> v(3);
    v[0] = 1;
    v[1] = 2;
    v[2] = 3;

    TVector<int> v1(v);

    EXPECT_EQ(v, v1);
}

TEST(TVector, copied_vector_has_its_own_memory)
{
    TVector<int> v(3);
    v[0] = 1;
    v[1] = 2;
    v[2] = 3;

    TVector<int> v1(v);
    v[0] = 6;
    v[1] = 7;
    v[2] = 8;
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
    TVector<int> v(5);

    v.setElement(2, 4);

    EXPECT_EQ(4, v.getElement(2));
}

TEST(TVector, throws_when_set_element_with_negative_index)
{
    TVector<int> v(4);

    ASSERT_ANY_THROW(v.setElement(-5, 8));
}

TEST(TVector, throws_when_set_element_with_too_large_index)
{
    TVector<int> v(4);

    ASSERT_ANY_THROW(v.setElement(5, 8));
}

TEST(TVector, can_assign_vector_to_itself)
{
    TVector<int> v(4);

    ASSERT_NO_THROW(v = v);
}

TEST(TVector, can_assign_vectors_of_equal_size)
{
    TVector<int> v(3);
    v[0] = 1;
    v[1] = 2;
    v[2] = 3;

    TVector<int> v1(3);
    v1 = v;
    EXPECT_EQ(v, v1);
}

TEST(TVector, assign_operator_change_vector_size)
{
    int s1 = 3;
    int s2 = 4;

    TVector<int> v1(s1);

    TVector<int> v2(s2);

    v2 = v1;

    EXPECT_EQ(s1, v2.getSize());
}

TEST(TVector, can_assign_vectors_of_different_size)
{
    TVector<int> v(4);
    TVector<int> v1(7);

    v1 = v;

    EXPECT_EQ(v, v1);
}

TEST(TVector, compare_equal_vectors_return_true)
{
    TVector<int> v(3);
    v[0] = 1;
    v[1] = 2;
    v[2] = 3;

    TVector<int> v1(3);
    v1[0] = 1;
    v1[1] = 2;
    v1[2] = 3;

    EXPECT_EQ(v, v1);
}

TEST(TVector, compare_vector_with_itself_return_true)
{
    TVector<int> v(3);
    v[0] = 1;
    v[1] = 2;
    v[2] = 3;

    EXPECT_EQ(v, v);
}

TEST(TVector, vectors_with_different_size_are_not_equal)
{
    TVector<int> v(5);
    TVector<int> v1(6);

    EXPECT_NE(v, v1);
}

TEST(TVector, can_add_scalar_to_vector)
{
    int val = 5;
   
    TVector<int> v(3);
    v[0] = 1;
    v[1] = 2;
    v[2] = 3;

    TVector<int> res(3);
    res[0] = 6;
    res[1] = 7;
    res[2] = 8;

    EXPECT_EQ(v + val, res);
}

TEST(TVector, can_subtract_scalar_from_vector)
{
    int val = 1;

    TVector<int> v1(3);
    v1[0] = 1;
    v1[1] = 2;
    v1[2] = 3;

    TVector<int> res(3);
    res[0] = 0;
    res[1] = 1;
    res[2] = 2;

    EXPECT_EQ(v1 - val, res);
}

TEST(TVector, can_multiply_scalar_by_vector)
{
    int val = 2;

    TVector<int> v1(3);

    v1[0] = 1;
    v1[1] = 2;
    v1[2] = 3;

    TVector<int> res(3);
    res[0] = 2;
    res[1] = 4;
    res[2] = 6;

    EXPECT_EQ(v1 * val, res);
}

TEST(TVector, can_add_vectors_with_equal_size)
{
    TVector<int> v(3);
    v[0] = 6;
    v[1] = 7;
    v[2] = 8;

    TVector<int> v1(3);
    v1[0] = 6;
    v1[1] = 7;
    v1[2] = 8;

    TVector<int> res(3);
    res[0] = 12;
    res[1] = 14;
    res[2] = 16;

    EXPECT_EQ(v1 + v, res);
}

TEST(TVector, cant_add_vectors_with_not_equal_size)
{
    TVector<int> v(3);

    TVector<int> v1(4);

    ASSERT_ANY_THROW(v1 + v);
}

TEST(TVector, can_subtract_vectors_with_equal_size)
{
    TVector<int> v(3);
    v[0] = 1;
    v[1] = 2;
    v[2] = 3;

    TVector<int> v1(3);
    v1[0] = 2;
    v1[1] = 1;
    v1[2] = 8;

    TVector<int> res(3);
    res[0] = 1;
    res[1] = -1;
    res[2] = 5;

    EXPECT_EQ(v1 - v, res);
}

TEST(TVector, cant_subtract_vectors_with_not_equal_size)
{
    TVector<int> v(3);

    TVector<int> v1(4);

    ASSERT_ANY_THROW(v1 - v);
}

TEST(TVector, can_multiply_vectors_with_equal_size)
{
    int res = 19;
    TVector<int> v(3);
    v[0] = 1;
    v[1] = 2;
    v[2] = 6;

    TVector<int> v1(3);
    v1[0] = 1;
    v1[1] = 3;
    v1[2] = 2;

    EXPECT_EQ(v * v1, res);
}

TEST(TVector, cant_multiply_vectors_with_not_equal_size)
{
    TVector<int> v(3);

    TVector<int> v1(4);

    ASSERT_ANY_THROW(v * v1);
}
