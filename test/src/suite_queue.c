#include "unity.h"
#include "queue.h"

void test_queue_new(void) {
	t_queue *queue = queue_new(g_type_float);
	TEST_ASSERT(queue_size(queue) == 0);
	queue_delete(queue);
}

void test_queue_enqueue_dequeue_peek(void) {
	t_queue *queue = queue_new(g_type_int);
	queue_enqueue(queue, int2ptr(1));
	TEST_ASSERT(queue_size(queue) == 1);
	queue_enqueue(queue, int2ptr(-9827));
	TEST_ASSERT(queue_size(queue) == 2);
	queue_enqueue(queue, int2ptr(127127));
	TEST_ASSERT(queue_size(queue) == 3);
	TEST_ASSERT_EQUAL_FLOAT(1, ptr2int(queue_peek(queue)));
	TEST_ASSERT_EQUAL_FLOAT(1, ptr2int(queue_dequeue(queue)));
	TEST_ASSERT_EQUAL_FLOAT(-9827, ptr2int(queue_peek(queue)));
	TEST_ASSERT_EQUAL_FLOAT(-9827, ptr2int(queue_dequeue(queue)));
	TEST_ASSERT_EQUAL_FLOAT(127127, ptr2int(queue_dequeue(queue)));
	queue_delete(queue);
}

void test_queue_copy(void) {
	t_queue *queue = queue_new(g_type_float);
	queue_enqueue(queue, int2ptr(1));
	queue_enqueue(queue, int2ptr(-9827));
	queue_enqueue(queue, int2ptr(127127));
	t_queue *copy = queue_copy(queue);
	TEST_ASSERT_EQUAL_FLOAT(1, ptr2int(queue_peek(copy)));
	TEST_ASSERT_EQUAL_FLOAT(1, ptr2int(queue_dequeue(copy)));
	TEST_ASSERT_EQUAL_FLOAT(-9827, ptr2int(queue_peek(copy)));
	TEST_ASSERT_EQUAL_FLOAT(-9827, ptr2int(queue_dequeue(copy)));
	TEST_ASSERT_EQUAL_FLOAT(127127, ptr2int(queue_dequeue(copy)));
	TEST_ASSERT_EQUAL_FLOAT(1, ptr2int(queue_peek(queue)));
	TEST_ASSERT_EQUAL_FLOAT(1, ptr2int(queue_dequeue(queue)));
	TEST_ASSERT_EQUAL_FLOAT(-9827, ptr2int(queue_peek(queue)));
	TEST_ASSERT_EQUAL_FLOAT(-9827, ptr2int(queue_dequeue(queue)));
	TEST_ASSERT_EQUAL_FLOAT(127127, ptr2int(queue_dequeue(queue)));
	queue_delete(queue);
	queue_delete(copy);
}

int suite_queue(void) {
 	UNITY_BEGIN();
    RUN_TEST(test_queue_new);
    RUN_TEST(test_queue_enqueue_dequeue_peek);
    RUN_TEST(test_queue_copy);
    return UNITY_END();
}
