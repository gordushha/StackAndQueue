#include <../gtest/gtest.h>
#include <../stacklib/Queue.h>

TEST(queue, can_create_default_queue)
{
	ASSERT_NO_THROW(TQueue<int> A);
}

TEST(queue, can_not_create_queue_with_nagative_size)
{
	ASSERT_ANY_THROW(TQueue<int> A(-1));
}
TEST(queue, can_create_queue_with_positive_size)
{
	ASSERT_NO_THROW(TQueue<int> A(3));
}

TEST(queue, can_copy_queue)
{
	TQueue <int> B(3);
	ASSERT_NO_THROW(TQueue<int> A(B));
}

TEST(queue, can_push_and_pull)
{
	TQueue <int> A(1);
	int k = 1;
	A.push(k);

	EXPECT_EQ(1, A.pop());
}

TEST(queue, can_push_and_pull_size_3)
{
	TQueue<int> A(3);
	int x1 = 1, x2 = 2, x3 = 7;
	A.push(x1);
	A.push(x2);
	A.push(x3);

	EXPECT_EQ(1, A.pop());
	EXPECT_EQ(2, A.pop());
	EXPECT_EQ(7, A.pop());
}

TEST(queue, can_not_push_out_of_size)
{
	TQueue<int> A(3);
	int x1 = 1, x2 = 2, x3 = 7, x4 = -1;
	A.push(x1);
	A.push(x2);
	A.push(x3);

	ASSERT_ANY_THROW(A.push(x4));
}

TEST(queue, can_not_pull_out_of_size)
{
	TQueue<int> A(3);
	ASSERT_ANY_THROW(A.pop());
}

TEST(queue, can_copy_queue_with_any_elements)
{
	TQueue<int> A(3);
	int x1 = 1, x2 = 2, x3 = 7, x4 = 2;
	A.push(x1);
	A.push(x2);
	A.push(x3);

	TQueue<int> B(A);
	EXPECT_EQ(1, B.pop());
	EXPECT_EQ(2, B.pop());
	EXPECT_EQ(7, B.pop());
}