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
    TVector<int> gold(10);
    for (int i = 0; i < gold.getSize(); i++)
        gold[i] = 69;
    TVector<int> silver(gold);

    EXPECT_EQ(gold, silver);
}

TEST(TVector, copied_vector_has_its_own_memory)
{
    TVector<int> gold(10);
    for (int i = 0; i < gold.getSize(); i++)
        gold[i] = 69;
    TVector<int> silver(gold);
    silver[5] = 420;

    EXPECT_NE(gold, silver);
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
    TVector<int> gold(10);

    ASSERT_ANY_THROW(gold[-1]);
}

TEST(TVector, throws_when_set_element_with_too_large_index)
{
    TVector<int> gold(10);

    ASSERT_ANY_THROW(gold[69]);
}

TEST(TVector, can_assign_vector_to_itself)
{
    TVector<int> gold(10);
    for (int i = 0; i < gold.getSize(); i++)
        gold[i] = 69;
    TVector<int> silver(gold);
    gold = silver;

    EXPECT_EQ(gold, silver);
}

TEST(TVector, can_assign_vectors_of_equal_size)
{
    TVector<int> gold(10);
    for (int i = 0; i < gold.getSize(); i++)
        gold[i] = 69;
    TVector<int> silver(10);
    gold = silver;

    EXPECT_EQ(gold, silver);
}

TEST(TVector, assign_operator_change_vector_size)
{
    TVector<int> gold(10);
    for (int i = 0; i < gold.getSize(); i++)
        gold[i] = 69;
    TVector<int> silver(8);
    gold = silver;

    EXPECT_EQ(gold.getSize(), silver.getSize());
}

TEST(TVector, can_assign_vectors_of_different_size)
{
    TVector<int> gold(10);
    for (int i = 0; i < gold.getSize(); i++)
        gold[i] = 69;
    TVector<int> silver(8);
    gold = silver;

    EXPECT_EQ(gold, silver);
}

TEST(TVector, compare_equal_vectors_return_true)
{
    TVector<int> gold(10);
    for (int i = 0; i < gold.getSize(); i++)
        gold[i] = 69;
    TVector<int> silver(10);
    for (int i = 0; i < silver.getSize(); i++)
        silver[i] = 69;

    EXPECT_EQ(gold, silver);
}

TEST(TVector, compare_vector_with_itself_return_true)
{
    TVector<int> gold(10);
    for (int i = 0; i < gold.getSize(); i++)
        gold[i] = 69;

    EXPECT_EQ(gold, gold);
}

TEST(TVector, vectors_with_different_size_are_not_equal)
{
    TVector<int> gold(10);
    TVector<int> silver(8);

    EXPECT_NE(gold, silver);
}

TEST(TVector, can_add_scalar_to_vector)
{
    TVector<int> gold(10);
    for (int i = 0; i < gold.getSize(); i++)
        gold[i] = 69;
    gold = gold + 351;
    TVector<int> silver(10);
    for (int i = 0; i < silver.getSize(); i++)
        silver[i] = 420;

    EXPECT_EQ(gold, silver);
}

TEST(TVector, can_subtract_scalar_from_vector)
{
    TVector<int> gold(10);
    for (int i = 0; i < gold.getSize(); i++)
        gold[i] = 420;
    gold = gold - 351;
    TVector<int> silver(10);
    for (int i = 0; i < silver.getSize(); i++)
        silver[i] = 69;

    EXPECT_EQ(gold, silver);
}

TEST(TVector, can_multiply_scalar_by_vector)
{
    TVector<int> gold(10);
    for (int i = 0; i < gold.getSize(); i++)
        gold[i] = 1;
    gold = gold * 69;
    TVector<int> silver(10);
    for (int i = 0; i < silver.getSize(); i++)
        silver[i] = 69;

    EXPECT_EQ(gold, silver);
}

TEST(TVector, can_add_vectors_with_equal_size)
{
    TVector<int> gold(10);
    for (int i = 0; i < gold.getSize(); i++)
        gold[i] = 351;
    TVector<int> silver(10);
    for (int i = 0; i < silver.getSize(); i++)
        silver[i] = 69;
    TVector<int> platinum = gold + silver;
    EXPECT_EQ(gold + silver, platinum);
}

TEST(TVector, cant_add_vectors_with_not_equal_size)
{
    TVector<int> gold(10), silver(8);
    ASSERT_ANY_THROW(gold + silver);
}

TEST(TVector, can_subtract_vectors_with_equal_size)
{
    TVector<int> gold(10);
    for (int i = 0; i < gold.getSize(); i++)
        gold[i] = 420;
    TVector<int> silver(10);
    for (int i = 0; i < silver.getSize(); i++)
        silver[i] = 69;
    TVector<int> platinum = gold - silver;
    EXPECT_EQ(gold - silver, platinum);
}

TEST(TVector, cant_subtract_vectors_with_not_equal_size)
{
    TVector<int> gold(10), silver(8);
    ASSERT_ANY_THROW(gold - silver);
}

TEST(TVector, can_multiply_vectors_with_equal_size)
{
    TVector<int> gold(10);
    for (int i = 0; i < gold.getSize(); i++)
        gold[i] = 21;
    TVector<int> silver(10);
    for (int i = 0; i < silver.getSize(); i++)
        silver[i] = 2;
    EXPECT_EQ(gold * silver, 420);
}

TEST(TVector, cant_multiply_vectors_with_not_equal_size)
{
    TVector<int> gold(10), silver(8);
    ASSERT_ANY_THROW(gold * silver);
}
