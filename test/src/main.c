#include "unity.h"
#include <string.h>

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

int suite_array(void);
int suite_list(void);
int suite_stack(void);
int suite_queue(void);
int suite_max_pq(void);
int suite_min_pq(void);
int suite_bst(void);
int suite_rbt(void);
int suite_hashset(void);
int suite_hashmap(void);
int suite_union_find(void);
int suite_graph(void);

int main(void) {
	int res = (suite_array() ||
				suite_list() ||
				suite_stack() ||
				suite_queue() ||
				suite_max_pq() ||
				suite_min_pq() ||
				suite_bst() ||
				suite_rbt() ||
				suite_hashset() ||
				suite_hashmap() ||
				suite_union_find() ||
				suite_graph());
	puts(res ? "\n=> FAILED" : "\n=> ALL PASSED");
	return (res);
}
