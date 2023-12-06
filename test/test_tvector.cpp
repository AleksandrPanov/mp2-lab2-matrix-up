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
    int size = 10;
    int startindex = 5;
    TVector<int> ex(size,startindex);
    for (int i = startindex; i < size; i++)
        ex[i] = i;
    TVector<int> test(ex);
    EXPECT_EQ(ex, test);
}

TEST(TVector, copied_vector_has_its_own_memory)
{
    int size = 10;
    int startindex = 5;
    TVector<int> ex(size, startindex);
    auto test = ex;
    
    for (int i = startindex; i < size; i++)
    {
        ex[i] = 2;
        test[i] = -2;
        
    }
    for (int i = startindex; i < size; i++)
        EXPECT_NE(ex[i], test[i]);
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
    int size = 111;
    int startindex = 5;
    TVector<int> ex(size, startindex);
    ASSERT_ANY_THROW(ex[-2]);
}

TEST(TVector, throws_when_set_element_with_too_large_index)
{
    int size = 111;
    int startindex = 5;
    
    TVector<int> ex(size, startindex);

    ASSERT_ANY_THROW(ex[size + 1]);
}

TEST(TVector, can_assign_vector_to_itself)
{
    size_t size = 100;
    size_t startIndex = 43;
    TVector<size_t> ex(size, startIndex);
    auto temp = &ex;
    ex = ex;
    ASSERT_EQ(temp, &ex);
}

TEST(TVector, can_assign_vectors_of_equal_size)
{
    size_t size = 100;
    size_t startIndex = 43;
    TVector<size_t> ex(size, startIndex);
    TVector<size_t> test(size, startIndex-6);
    ex[65] = 123123123;
    test = ex;
    ASSERT_EQ(test, ex);
}

TEST(TVector, assign_operator_change_vector_size)
{
    size_t size = 100;
    size_t startIndex = 43;
    TVector<size_t> ex(size, startIndex);
    size = 2;
    startIndex = 1;
    TVector<size_t> test(size, startIndex);
    ex = test;
    ASSERT_EQ(ex.getSize(),test.getSize());
}

TEST(TVector, can_assign_vectors_of_different_size)
{
    size_t size = 100;
    size_t startIndex = 43;
    TVector<size_t> ex(size, startIndex);
    size = 2;
    startIndex = 1;
    TVector<size_t> test(size, startIndex);
    test[1] = 3798234;
    ex = test;
    ASSERT_EQ(test, ex);
}

TEST(TVector, compare_equal_vectors_return_true)
{
    size_t size = 100;
    size_t startIndex = 43;
    TVector<size_t> ex(size, startIndex);
    ex[99] = 100;
    auto test = ex;
    ASSERT_TRUE(ex == test);
}

TEST(TVector, compare_vector_with_itself_return_true)
{
    size_t size = 100;
    size_t startIndex = 43;
    TVector<size_t> ex(size, startIndex);
    ASSERT_TRUE(ex == ex);
}

TEST(TVector, vectors_with_different_size_are_not_equal)
{
    size_t size = 100;
    size_t startIndex = 43;
    TVector<size_t> ex(size, startIndex);
    size = 99;
    TVector<size_t> test(size, startIndex);
    EXPECT_NE(test, ex);
}

TEST(TVector, can_add_scalar_to_vector)
{
    int size = 100;
    int startIndex = 43;
    TVector<int> ex(size);
    TVector<int> test(size);
    ex = ex + 100;
    test = test + 100;
    
    
    ASSERT_EQ(test, ex);
}

TEST(TVector, can_subtract_scalar_from_vector)
{
    int size = 100;
    int startIndex = 43;
    TVector<int> ex(size);
    TVector<int> test(size);
    ex = ex + 100;
    test = test + 100;
    ASSERT_EQ(test, ex);
}

TEST(TVector, can_multiply_scalar_by_vector)
{
    int size = 100;
    int startIndex = 10;
    TVector<int> ex(size,startIndex);
    TVector<int> test(size,startIndex);
    test[10] = 1;
    test = test * 6;
    ex[10] = 6;
    ASSERT_EQ(test[99], 6);
}

TEST(TVector, can_add_vectors_with_equal_size)
{
    int size = 100;
    int startIndex = 1;
    TVector<int> test1(size, startIndex);
    TVector<int> test2(size, startIndex);
    TVector<int> test3(size, startIndex);
    TVector<int> ex(size, startIndex);

    test1[1] = 138910;
    test2[1] = 123123;
    ex[1] = 138910 + 123123;
    test3 = test1 + test2;
    
    ASSERT_NO_THROW(test1 + test2);
}

TEST(TVector, cant_add_vectors_with_not_equal_size)
{
    TVector<int> test1(101935, 1);
    TVector<int> test2(235123, 1);
    test1[1] = 23;
    test2[1] = 23;
    ASSERT_ANY_THROW(test1 + test2);

}

TEST(TVector, can_subtract_vectors_with_equal_size)
{
    TVector<int> test1(3, 1);
    TVector<int> test2(3, 1);
    TVector<int> ex(3,1);
    test1[1] = 23;
    test2[1] = 24;
    ex[1] = -1;
    ex[2] = 0;
    auto test3 = test1 - test2;
    
    
    ASSERT_EQ(ex, test3);
}

TEST(TVector, cant_subtract_vectors_with_not_equal_size)
{
    TVector<int> test1(101935, 1);
    TVector<int> test2(235123, 1);
    test1[1] = 23;
    test2[1] = 23;
    ASSERT_ANY_THROW(test1 - test2);
}

TEST(TVector, can_multiply_vectors_with_equal_size)
{
    TVector <int> test1(4);
    TVector <int> test2(4);
    test1[0] = 1;
    test1[1] = 1;
    test1[2] = 1;
    test1[3] = 1;
    test2[0] = 1;
    test2[1] = 1;
    test2[2] = 1;
    test2[3] = 1;
    int ex = 2;

    ASSERT_EQ(ex, test1 * test2);
}

TEST(TVector, cant_multiply_vectors_with_not_equal_size)
{
    TVector <int> test1(6);
    TVector <int> test2(4);
    ASSERT_ANY_THROW(test1 * test2);
}
