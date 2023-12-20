#include <gtest.h>
#include "utmatrix.h"

TEST(TVector, can_create_vector_with_positive_length_int)
{
    const int size = 5;
    ASSERT_NO_THROW(TVector<int> v(size));
}

TEST(TVector, can_create_vector_with_positive_length_size_t)
{
    const size_t size = 5;
    ASSERT_NO_THROW(TVector<int> v(size));
}

TEST(Tvector, can_create_huge_vector)
{
    size_t size = 200ull * 100ull * 100ull * 100ull;
    size_t startIndex = size - 10ull;
    TVector<double> v1(size, startIndex);
    ASSERT_NO_THROW(v1.setElement(size - 1ull, 1.0));

    EXPECT_EQ(size, v1.getSize());
    EXPECT_EQ(1.0, v1.getElement(size - 1ull));

}

TEST(TVector, cant_create_too_large_vector_int)
{
    // максимальный допустимый размер вектора = TVector<int>::max_size
    ASSERT_ANY_THROW(TVector<int> v(TVector<int>::max_size + static_cast<size_t>(1)));
}

TEST(TVector, cant_create_too_large_vector_size_t)
{
    // максимальный допустимый размер вектора = TVector<int>::max_size
    ASSERT_ANY_THROW(TVector<size_t> v(TVector<size_t>::max_size + static_cast<size_t>(1)));
}

TEST(TVector, throws_when_create_vector_with_negative_length_int)
{
    const int size = -5;
    ASSERT_ANY_THROW(TVector<int> v(size));
}

TEST(TVector, throws_when_create_vector_with_negative_length_size_t)
{
    const size_t size = -5;
    ASSERT_ANY_THROW(TVector<int> v(size));
}

TEST(TVector, create_vector_with_startindex_int)
{
    const int size = 5;
    const int startIndex = 2;
    ASSERT_NO_THROW(TVector<int> v(size, startIndex));
}

TEST(TVector, create_vector_with_startindex_size_t)
{
    const size_t size = 5;
    const size_t startIndex = 2;
    ASSERT_NO_THROW(TVector<int> v(size, startIndex));
}


TEST(TVector, throws_when_create_vector_with_negative_startindex_int)
{
    const int size = 5;
    const int startIndex = -2;
    ASSERT_ANY_THROW(TVector<int> v(size, startIndex));
}

TEST(TVector, throws_when_create_vector_with_negative_startindex_size_t)
{
    const size_t size = 5;
    const size_t startIndex = -2;
    ASSERT_ANY_THROW(TVector<int> v(size, startIndex));
}

TEST(TVector, can_create_copied_vector)
{
    TVector<int> v(10);

    ASSERT_NO_THROW(TVector<int> v1(v));
}

TEST(TVector, copied_vector_is_equal_to_source_one)
{
    TVector<int> v1(2);
    v1[0] = 1;
    v1[1] = 2;
    TVector<int> v2 = v1;
    EXPECT_EQ(v1, v2);
}

TEST(TVector, copied_vector_has_its_own_memory)
{
    TVector<int> v1(2);
    v1[0] = 1;
    v1[1] = 2;
    TVector<int> v2(1);
    v2[0] = 3;
    v2 = v1;
    EXPECT_EQ(v1, v2);
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

TEST(TVector, can_set_and_get_element_with)
{
    TVector<int> v(4);
    v[0] = 4;

    EXPECT_EQ(4, v[0]);
}

TEST(TVector, can_set_and_get_element)
{
    TVector<int> v(4);
    v.getElement(0) = 4;

    EXPECT_EQ(4, v.getElement(0));
}

TEST(TVector, throws_when_set_element_with_negative_index)
{
    TVector<int> v(4);
    ASSERT_ANY_THROW(v[-1] = 1);
}

TEST(TVector, throws_when_set_element_with_too_large_index)
{
    TVector<int> v(4);
    ASSERT_ANY_THROW(v[5] = 1);
}

TEST(TVector, can_assign_vector_to_itself)
{
    TVector<int> v1(2);
    ASSERT_NO_THROW(v1 = v1);
}

TEST(TVector, can_assign_vectors_of_equal_size)
{
    const int size = 2;
    TVector<int> v1(size), v2(size);
    v1[0] = 1;
    v1[1] = 2;
    v2 = v1;
    EXPECT_EQ(v1[0], v2[0]);
    EXPECT_EQ(v1[1], v2[1]);
}

TEST(TVector, assign_operator_change_vector_size)
{
    const int size1 = 2, size2 = 1;
    TVector<int> v1(size1), v2(size2);
    v1[0] = 1;
    v1[1] = 2;
    v2[0] = 1;
    v1 = v2;
    EXPECT_EQ(size2, v1.getSize());
}

TEST(TVector, can_assign_vectors_of_different_size)
{
    const int size1 = 2, size2 = 1;
    TVector<int> v1(size1), v2(size2);
    v1[0] = 1;
    v1[1] = 2;
    v2 = v1;
    EXPECT_EQ(v1[0], v2[0]);
    EXPECT_EQ(v1[1], v2[1]);
}

TEST(TVector, compare_equal_vectors_return_true)
{
    const int size = 2;
    TVector<int> v1(size), v2(size);
    v1[0] = 1;
    v1[1] = 2;
    v2[0] = 1;
    v2[1] = 2;
    EXPECT_EQ(v1, v2);
}

TEST(TVector, compare_vector_with_itself_return_true)
{
    const int size = 2;
    TVector<int> v1(size);
    v1[0] = 1;
    v1[1] = 2;
    EXPECT_EQ(v1, v1);
}

TEST(TVector, vectors_with_different_size_are_not_equal)
{
    const int size1 = 2, size2 = 1;
    TVector<int> v1(size1), v2(size2);
    v1[0] = 1;
    v1[1] = 2;
    v2[0] = 1;
    EXPECT_NE(v1, v2);
}

TEST(TVector, can_add_scalar_to_vector)
{
    const int size = 2;
    TVector<int> v1(size),v2(size);
    v1[0] = 1;
    v1[1] = 2;
    v2[0] = 2;
    v2[1] = 3;
    v1 = v1 + 1;
    EXPECT_EQ(v1, v2);
}

TEST(TVector, can_subtract_scalar_from_vector)
{
    const int size = 2;
    TVector<int> v1(size), v2(size);
    v1[0] = 1;
    v1[1] = 2;
    v2[0] = 2;
    v2[1] = 3;
    v2 = v2 - 1;
    EXPECT_EQ(v1, v2);
}

TEST(TVector, can_multiply_scalar_by_vector)
{
    const int size = 2;
    TVector<int> v1(size), v2(size);
    v1[0] = 1;
    v1[1] = 2;
    v2[0] = 2;
    v2[1] = 4;
    v1 = v1 * 2;
    EXPECT_EQ(v1, v2);
}

TEST(TVector, can_add_vectors_with_equal_size)
{
    const int size = 2;
    TVector<int> v1(size), v2(size), v3(size);
    v1[0] = 1;
    v1[1] = 2;
    v2[0] = 2;
    v2[1] = 4;

    v3[0] = 3;
    v3[1] = 6;
    EXPECT_EQ(v3, v1 + v2);
}

TEST(TVector, cant_add_vectors_with_not_equal_size)
{
    const int size1 = 2, size2 =1;
    TVector<int> v1(size1), v2(size2);
    v1[0] = 1;
    v1[1] = 2;
    v2[0] = 2;
    ASSERT_ANY_THROW(v1 + v2);
}

TEST(TVector, can_subtract_vectors_with_equal_size)
{
    const int size = 2;
    TVector<int> v1(size), v2(size), v3(size);
    v1[0] = 1;
    v1[1] = 2;
    v2[0] = 2;
    v2[1] = 4;

    v3[0] = 1;
    v3[1] = 2;
    EXPECT_EQ(v3, v2 - v1);
}

TEST(TVector, cant_subtract_vectors_with_not_equal_size)
{
    const int size1 = 2, size2 = 1;
    TVector<int> v1(size1), v2(size2);
    v1[0] = 1;
    v1[1] = 2;
    v2[0] = 2;
    ASSERT_ANY_THROW(v2 - v1);
}

TEST(TVector, can_multiply_vectors_with_equal_size)
{
    const int size = 2;
    TVector<int> v1(size), v2(size);
    int m = 10;
    v1[0] = 1;
    v1[1] = 2;
    v2[0] = 2;
    v2[1] = 4;
    EXPECT_EQ(m, v1 * v2);
}

TEST(TVector, cant_multiply_vectors_with_not_equal_size)
{
    const int size1 = 2, size2 = 1;
    TVector<int> v1(size1), v2(size2);
    v1[0] = 1;
    v1[1] = 2;
    v2[0] = 2;
    ASSERT_ANY_THROW(v1 * v2);
}

TEST(TVector, can_1)
{
    const int size1 = 2, size2 = 0;
    TVector<int> v1(size1), v2;
    v1[0] = 1;
    v1[1] = 2;
    v2 = v1 + 1;
    v1 = v1 + 1;
    EXPECT_EQ(v1, v2);
}
