#ifndef TESTING_UNIT_TEST_H
#define TESTING_UNIT_TEST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define UNIT_CHECK(cond) if(!(cond)) { \
	fprintf(stderr, "FAILED: condition:%s, line%u, file:%s\n", #cond, __LINE__, __FILE__); \
	exit(3) ; \
}


int thaistr_unit_test_eq(void* obj1, void* obj2, size_t size);


#endif // TESTING_UNIT_TEST_H
