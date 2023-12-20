#include <gtest.h>
#include "utmatrix.h"

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
    TVector<int> vec(2);
    vec[0]=1;
    vec[1]=2;
    TVector<int> vec1(vec);
    EXPECT_EQ(vec,vec1);
}

TEST(TVector, copied_vector_has_its_own_memory)
{
    TVector<int> vec(2);
    vec[0]=1;
    vec[1]=2;
    TVector<int> vec1(vec);
    EXPECT_NE(&vec,&vec1);
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
    TVector<int> vec(2);
    ASSERT_ANY_THROW(vec.setElement(-1,3));
}

TEST(TVector, throws_when_set_element_with_too_large_index)
{
    TVector<int> vec(2);
    ASSERT_ANY_THROW(vec.setElement(10,3));
}

TEST(TVector, can_assign_vector_to_itself)
{
    TVector<int> vec(2);
    ASSERT_NO_THROW(vec=vec);
}

TEST(TVector, can_assign_vectors_of_equal_size)
{
    int size=2;
    TVector<int> vec(size),vec1(size);
    vec[1]=1;
    vec1=vec;
    EXPECT_EQ(vec,vec1);
}

TEST(TVector, assign_operator_change_vector_size)
{
    TVector<int> vec(2),vec1(3);
    vec[1]=1;
    vec1=vec;
    EXPECT_EQ(vec.getSize(),vec1.getSize());
}

TEST(TVector, can_assign_vectors_of_different_size)
{
    TVector<int> vec(2),vec1(3);
    vec[1]=1;
    vec1=vec;
    EXPECT_EQ(vec,vec1);
}

TEST(TVector, compare_equal_vectors_return_true)
{
    TVector<int> vec(2),vec1(2);
    vec[1]=1;
    vec1[1]=1;
    EXPECT_EQ(vec,vec1);
}

TEST(TVector, compare_vector_with_itself_return_true)
{
    TVector<int> vec(2);
    vec[1]=1;
    EXPECT_EQ(vec,vec);
}

TEST(TVector, vectors_with_different_size_are_not_equal)
{
    TVector<int> vec(2),vec1(3);
    vec[0]=1;
    vec[1]=2;
    vec1[1]=1;
    EXPECT_NE(vec,vec1);
}

TEST(TVector, can_add_scalar_to_vector)
{
    TVector<int> vec(2),vec1(2);
    vec[0]=1;
    vec[1]=2;
    vec1[0]=2;
    vec1[1]=3;
    EXPECT_EQ(vec+1,vec1);
}

TEST(TVector, can_subtract_scalar_from_vector)
{
    TVector<int> vec(2),vec1(2);
    vec[0]=1;
    vec[1]=2;
    vec1[0]=0;
    vec1[1]=1;
    EXPECT_EQ((vec-1),vec1);
}

TEST(TVector, can_multiply_scalar_by_vector)
{
    TVector<int> vec(2),vec1(2);
    vec[0]=1;
    vec[1]=2;
    vec1[0]=2;
    vec1[1]=4;
    EXPECT_EQ((vec*2),vec1);
}

TEST(TVector, can_add_vectors_with_equal_size)
{
    TVector<int> vec(2),vec1(2),fin(2);
    vec[0]=1;
    vec[1]=2;
    vec1[0]=2;
    vec1[1]=4;
    fin[0]=vec[0]+vec1[0];
    fin[1]=vec[1]+vec1[1];
    EXPECT_EQ((vec+vec1),fin);
}

TEST(TVector, cant_add_vectors_with_not_equal_size)
{
    TVector<int> vec(1),vec1(2);
    vec[0]=1;
    vec1[0]=2;
    vec1[1]=4;
    ASSERT_ANY_THROW(vec+vec1);
}

TEST(TVector, can_subtract_vectors_with_equal_size)
{
    TVector<int> vec(2),vec1(2),fin(2);
    vec[0]=1;
    vec[1]=2;
    vec1[0]=2;
    vec1[1]=4;
    fin[0]=vec[0]-vec1[0];
    fin[1]=vec[1]-vec1[1];
    EXPECT_EQ((vec-vec1),fin);
}

TEST(TVector, cant_subtract_vectors_with_not_equal_size)
{
    TVector<int> vec(1),vec1(2);
    vec[0]=1;
    vec1[0]=2;
    vec1[1]=4;
    ASSERT_ANY_THROW(vec-vec1);
}

TEST(TVector, can_multiply_vectors_with_equal_size)
{
    TVector<int> vec(2),vec1(2);
    vec[0]=1;
    vec[1]=2;
    vec1[0]=2;
    vec1[1]=4;
    int fin=vec[0]*vec1[0]+vec[1]*vec1[1];
    EXPECT_EQ((vec*vec1),fin);
}

TEST(TVector, cant_multiply_vectors_with_not_equal_size)
{
    TVector<int> vec(1),vec1(2);
    vec[0]=1;
    vec1[0]=2;
    vec1[1]=4;
    ASSERT_ANY_THROW(vec*vec1);
}
