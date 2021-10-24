#include <gtest.h>
#include "utmatrix.h"

TEST(TVector, can_create_vector_with_positive_length)
{
    ASSERT_NO_THROW(TVector<int> v(5));
}

TEST(TVector, cant_create_too_large_vector)
{
    // ìàêñèìàëüíûé äîïóñòèìûé ðàçìåð âåêòîðà = TVector<int>::max_size
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
	TVector<int> a(10, 2);
	for (int i = 2; i < 10; ++i)
	{
		a[i] = 5;
	}
	TVector<int> b(a);
	EXPECT_EQ(a, b);
}

TEST(TVector, copied_vector_has_its_own_memory)
{
	TVector<int> a(10, 2);
	for (int i = 2; i < 10; ++i)
	{
		a[i] = 5;
	}
	TVector<int> b(a);
	b[3] = 8;
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
	v.setElement(0, 4);

    EXPECT_EQ(4, v.getElement(0));
}

TEST(TVector, throws_when_set_element_with_negative_index)
{
	TVector<int> v(4);
	ASSERT_ANY_THROW(v.setElement(-1, 4));
}

TEST(TVector, throws_when_set_element_with_too_large_index)
{
	TVector<int> v(4);
	ASSERT_ANY_THROW(v.setElement(4, 4));
}

TEST(TVector, can_assign_vector_to_itself)
{
	TVector<int> v(4);
	v = v;
	ASSERT_NO_THROW(v[1]);
}

TEST(TVector, can_assign_vectors_of_equal_size)
{
	TVector<int> a(5);
	TVector<int> b(5);
	for (int i = 2; i < 5; ++i)
	{
		a[i] = 5;
	}
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
	TVector<int> a(5);
	TVector<int> b(3);
	for (int i = 2; i < 5; ++i)
	{
		a[i] = 5;
	}
	b = a;
	EXPECT_EQ(a, b);
}

TEST(TVector, compare_equal_vectors_return_true)
{
	TVector<int> a(5,2);
	TVector<int> b(5,2);
	for (int i = 2; i < 5; ++i)
	{
		b[i] = a[i] = 3;
	}
	EXPECT_EQ(a==b,1);
}

TEST(TVector, compare_vector_with_itself_return_true)
{
	TVector<int> a(5, 2);
	for (int i = 2; i < 5; ++i)
	{
		a[i] = 3;
	}
	EXPECT_EQ(a == a, 1);
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
	TVector<int> b(5);
	for (int i = 0; i < 5; ++i)
	{
		a[i] = 3;
		b[i] = 9000;
	}
	a = a + 8997;
	EXPECT_EQ(a, b);
}

TEST(TVector, can_subtract_scalar_from_vector)
{
	TVector<int> a(5);
	TVector<int> b(5);
	for (int i = 0; i < 5; ++i)
	{
		a[i] = 3;
		b[i] = -2;
	}
	a = a - 5;
	EXPECT_EQ(a, b);
}

TEST(TVector, can_multiply_scalar_by_vector)
{
	TVector<int> a(5);
	TVector<int> b(5);
	for (int i = 0; i < 5; ++i)
	{
		a[i] = 3;
		b[i] = 9;
	}
	a = a * 3;
	EXPECT_EQ(a, b);
}

TEST(TVector, can_add_vectors_with_equal_size)
{
	TVector<int> a(5);
	TVector<int> b(5);
	TVector<int> c(5);
	for (int i = 0; i < 5; ++i)
	{
		a[i] = -3;
		b[i] = 9;
		c[i] = 6;
	}
	a = a + b;
	EXPECT_EQ(a, c);
}

TEST(TVector, cant_add_vectors_with_not_equal_size)
{
	TVector<int> a(5);
	TVector<int> b(4);
	ASSERT_ANY_THROW(a + b);
}

TEST(TVector, can_subtract_vectors_with_equal_size)
{
	TVector<int> a(5);
	TVector<int> b(5);
	TVector<int> c(5);
	for (int i = 0; i < 5; ++i)
	{
		a[i] = -3;
		b[i] = 9;
		c[i] = -12;
	}
	a = a - b;
	EXPECT_EQ(a, c);
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
	int expRes = -135;
	for (int i = 0; i < 5; ++i)
	{
		a[i] = -3;
		b[i] = 9;
	}
	int res = a * b;
	EXPECT_EQ(expRes, res);
}

TEST(TVector, cant_multiply_vectors_with_not_equal_size)
{
	TVector<int> a(5);
	TVector<int> b(4);
	ASSERT_ANY_THROW(a * b);
}
