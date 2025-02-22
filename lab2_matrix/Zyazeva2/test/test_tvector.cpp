#include "tmatrix.h"

#include <gtest.h>

TEST(TDynamicVector, can_create_vector_with_positive_length)
{
	ASSERT_NO_THROW(TDynamicVector<int> v(5));
}

TEST(TDynamicVector, cant_create_too_large_vector)
{
	ASSERT_ANY_THROW(TDynamicVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TDynamicVector, throws_when_create_vector_with_negative_length)
{
	ASSERT_ANY_THROW(TDynamicVector<int> v(-5));
}

TEST(TDynamicVector, can_create_copied_vector)
{
	TDynamicVector<int> v(10);

	ASSERT_NO_THROW(TDynamicVector<int> v1(v));
}

TEST(TDynamicVector, copied_vector_is_equal_to_source_one)
{
	TDynamicVector<int> v1(5);
	for (size_t i = 0; i < 5; ++i) {
		v1[i] = i;
	}

	TDynamicVector<int> v2(v1);

	for (size_t i = 0; i < 5; ++i) {
		EXPECT_EQ(v1[i], v2[i]);
	}
}

TEST(TDynamicVector, copied_vector_has_its_own_memory)
{
	TDynamicVector<int> v2(5);
	for (size_t i = 0; i < 5; ++i) {
		v2[i] = i;
	}
	TDynamicVector<int> v1(v2);
	v2[0] = 10;
	EXPECT_NE(v2[0], v1[0]);
}

TEST(TDynamicVector, can_get_size)
{
	TDynamicVector<int> v(4);

	EXPECT_EQ(4, v.size());
}

TEST(TDynamicVector, can_set_and_get_element)
{
	TDynamicVector<int> v(4);
	v[0] = 4;

	EXPECT_EQ(4, v[0]);
}

TEST(TDynamicVector, throws_when_set_element_with_negative_index)
{
	TDynamicVector<int> v(4);
	ASSERT_ANY_THROW(v.at(-1) = 4;);
}

TEST(TDynamicVector, throws_when_set_element_with_too_large_index)
{
	TDynamicVector<int> v(4);
	ASSERT_ANY_THROW(v.at(6) = 4;);
}

TEST(TDynamicVector, can_assign_vector_to_itself)
{
	const int size = 2;
	TDynamicVector<int> v1(size), v2(size);
	for (int i = 0; i < size; i++) {
		v2[i] = 1;
	}
	v2 = v2;
	EXPECT_NE(0, v2[0]);
	EXPECT_NE(0, v2[1]);
}

TEST(TDynamicVector, can_assign_vectors_of_equal_size)
{
	const int size = 2;
	TDynamicVector<int> v1(size), v2(size);
	for (int i = 0; i < size; i++) {
		v1[i] = 1;
	}
	v2 = v1;
	EXPECT_EQ(1, v2[0]);
	EXPECT_EQ(1, v2[1]);
}

TEST(TDynamicVector, assign_operator_change_vector_size)
{
	TDynamicVector<int> v1(2);
	TDynamicVector<int> v2(3);
	v1[0] = 1;
	v1[1] = 2;
	v2 = v1;
	EXPECT_EQ(2, v2.size());
}

TEST(TDynamicVector, can_assign_vectors_of_different_size)
{
	const int size = 2;
	TDynamicVector<int> v1(size), v2(3);
	for (int i = 0; i < size; i++) {
		v1[i] = 1;
	}
	v2 = v1;
	EXPECT_EQ(1, v2[0]);
	EXPECT_EQ(1, v2[1]);
}

TEST(TDynamicVector, compare_equal_vectors_return_true)
{
	TDynamicVector<int> v(4);
	v[2] = 3;
	TDynamicVector<int> c = v;

	EXPECT_EQ(c, v);
}

TEST(TDynamicVector, compare_vector_with_itself_return_true)
{
	TDynamicVector<int> v(4);
	/*v[2] = 3;
	TDynamicVector<int> c = v;*/

	EXPECT_EQ(v, v);
}

TEST(TDynamicVector, vectors_with_different_size_are_not_equal)
{
	TDynamicVector<int> v1(4), v2(7);
	/*v[2] = 3;
	TDynamicVector<int> c = v;*/

	EXPECT_NE(v1, v2);
}


TEST(TDynamicVector, can_add_scalar_to_vector)
{
	TDynamicVector<int> v(2);
	v[0] += 2;
	v[1] += 3;
	EXPECT_EQ(2, v[0]);
	EXPECT_EQ(3, v[1]);
}

TEST(TDynamicVector, can_subtract_scalar_from_vector)
{
	TDynamicVector<int> v(2);
	v[0] -= 2;
	v[1] -= 3;
	EXPECT_EQ(-2, v[0]);
	EXPECT_EQ(-3, v[1]);
}

TEST(TDynamicVector, can_multiply_scalar_by_vector)
{
	TDynamicVector<int> v(2);
	v[0] = 1;
	v[1] = 1;
	v = v * 7;
	EXPECT_EQ(7, v[0]);
	EXPECT_EQ(7, v[1]);
}

TEST(TDynamicVector, can_add_vectors_with_equal_size)
{
	TDynamicVector<int> v1(2), v2(2), res(2);
	v1[0] = 1;
	v1[1] = 2;
	v2[0] = 1;
	v2[1] = 2;
	res = v1 + v2;
	EXPECT_EQ(2, res[0]);
	EXPECT_EQ(4, res[1]);
}

TEST(TDynamicVector, cant_add_vectors_with_not_equal_size)
{
	TDynamicVector<int> v1(4), v2(7), res(7);
	v1[1] = 9;
	ASSERT_ANY_THROW(res = v1 + v2);
}

TEST(TDynamicVector, can_subtract_vectors_with_equal_size)
{
	TDynamicVector<int> v1(2), v2(2), res(2);
	v1[0] = 1;
	v1[1] = 2;
	v2[0] = 2;
	v2[1] = 3;
	res = v1 - v2;
	EXPECT_EQ(-1, res[0]);
	EXPECT_EQ(-1, res[1]);
}

TEST(TDynamicVector, cant_subtract_vectors_with_not_equal_size)
{
	TDynamicVector<int> v1(4), v2(7), res(7);
	v1[1] = 9;
	ASSERT_ANY_THROW(res = v1 - v2);
}

TEST(TDynamicVector, can_multiply_vectors_with_equal_size)
{
	TDynamicVector<int> v1(2), v2(2);
	int res;
	v1[0] = 1;
	v1[1] = 2;
	v2[0] = 1;
	v2[1] = 2;
	res = v1 * v2;
	EXPECT_EQ(5, res);
}

TEST(TDynamicVector, cant_multiply_vectors_with_not_equal_size)
{
	TDynamicVector<int> v1(4), v2(7), res(7);
	v1[1] = 9;
	ASSERT_ANY_THROW(res = v1 * v2);
}

