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
    TVector<int> v(10);
    for (int i = 0; i < 10; i++)
        v[i] = i;
    TVector <int> v1(v);
    EXPECT_EQ(v, v1);
}

TEST(TVector, copied_vector_has_its_own_memory)
{
    TVector<int> v(10);
    for (int i = 0; i < 10; i++)
        v[i] = i;
    TVector <int> v1(v);
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
    TVector <int> v(1);
    ASSERT_ANY_THROW(v.setElement(-100, 0));
}

TEST(TVector, throws_when_set_element_with_too_large_index)
{
    TVector <int> v(1);
    ASSERT_ANY_THROW(v.setElement(100, 0));
}

TEST(TVector, can_assign_vector_to_itself)
{
    TVector <int> v(5);
    for (int i = 0; i < 5; i++) v[i] = i;
    ASSERT_NO_THROW(v = v);
}

TEST(TVector, can_assign_vectors_of_equal_size)
{
    TVector <int> v(5),v1(5);
    for (int i = 0; i < 5; i++) v[i] = i;
    ASSERT_NO_THROW(v1 = v);
    EXPECT_EQ(v1, v);
    EXPECT_NE(&v1, &v);
}

TEST(TVector, assign_operator_change_vector_size)
{
    TVector <int> v(10,0), v1(10,5);
    for (int i = 0; i < 5; i++) {
        v[i] = i;
        v1[5 + i] = i;
    }
    v = v1;
    EXPECT_EQ(v, v1);
}

TEST(TVector, can_assign_vectors_of_different_size)
{
    TVector <int> v(5), v1(10),v2(3);
    for (int i = 0; i < 5; i++) v[i] = i;
    //для вектора побольше
    ASSERT_NO_THROW(v1 = v);
    EXPECT_EQ(v1, v);
    EXPECT_NE(&v1, &v);
    //для вектора поменьше
    ASSERT_NO_THROW(v2 = v);
    EXPECT_EQ(v2, v);
    EXPECT_NE(&v2, &v);
}

TEST(TVector, compare_equal_vectors_return_true)
{
    TVector <int> v(5), v1(5);
    for (int i = 0; i < 5; i++) {
        v[i] = i;
        v1[i] = i;
    }
    EXPECT_EQ(true, v1 == v);
}

TEST(TVector, compare_vector_with_itself_return_true)
{
    TVector <int> v(5);
    for (int i = 0; i < 5; i++) v[i] = i;
    EXPECT_EQ(true,v == v);
}

TEST(TVector, vectors_with_different_size_are_not_equal)
{
    TVector <int> v(5),v1(6);
    EXPECT_EQ(false, v == v1);
}

TEST(TVector, can_add_scalar_to_vector)
{
    TVector <int> v(5);
    for (int i = 0; i < 5; i++) v[i] = i;
    ASSERT_NO_THROW(v + 10);
    TVector <int> result = v + 10;
    EXPECT_EQ(result, v);
}

TEST(TVector, can_subtract_scalar_from_vector)
{
    TVector <int> v(5);
    for (int i = 0; i < 5; i++) v[i] = i;
    ASSERT_NO_THROW(v - 10);
    TVector <int> result = v - 10;
    EXPECT_EQ(result, v);
}

TEST(TVector, can_multiply_scalar_by_vector)
{
    TVector <int> v(5);
    for (int i = 0; i < 5; i++) v[i] = i;
    ASSERT_NO_THROW(v * 10);
    TVector <int> result = v * 10;
    EXPECT_EQ(result, v);
}

TEST(TVector, can_add_vectors_with_equal_size)
{
    TVector <int> v(5), v1(5),ans(5);
    for (int i = 0; i < 5; i++) {
        v[i] = i;
        v1[i] = 10 + i;
        ans[i] = 10 + 2*i;
    }
    ASSERT_NO_THROW(v1 + v);
    TVector <int> result = v1 + v;
    EXPECT_EQ(result, ans);
}

TEST(TVector, cant_add_vectors_with_not_equal_size)
{
    TVector <int> v(5), v1(6);
    ASSERT_ANY_THROW(v1 + v);
}

TEST(TVector, can_subtract_vectors_with_equal_size)
{
    TVector <int> v(5), v1(5), ans(5);
    for (int i = 0; i < 5; i++) {
        v[i] = i;
        v1[i] =i+10;
        ans[i] = 10;
    }
    ASSERT_NO_THROW(v1 - v);
    TVector <int> result = v1 - v;
    EXPECT_EQ(result, ans);
}

TEST(TVector, cant_subtract_vectors_with_not_equal_size)
{
    TVector <int> v(5), v1(6);
    ASSERT_ANY_THROW(v1 - v);
}

TEST(TVector, can_multiply_vectors_with_equal_size)
{
    TVector <int> v(5), v1(5);
    int result = 0;
    for (int i = 0; i < 5; i++) {
        v[i] = i;
        v1[i] = i;
        result += i * i;
    }
    ASSERT_NO_THROW(v1*v);
    int scalar = v1 * v;
    EXPECT_EQ(scalar, result);
}

TEST(TVector, cant_multiply_vectors_with_not_equal_size)
{
    TVector <int> v(5), v1(6);
    ASSERT_ANY_THROW(v1 * v);
}
TEST(Tvector, can_create_huge_vector)
{
    const size_t size = (size_t)200 * 100ull * 100ull * 100ull;
    const size_t startIndex = size - 10ull;
    TVector<double> v1(size, startIndex);
    ASSERT_NO_THROW(v1.setElement((size_t)(size - 1ull), 1.0));

    EXPECT_EQ(size, v1.getSize());
    EXPECT_EQ(1.0, v1.getElement((size_t)(size - 1ull)));
}
