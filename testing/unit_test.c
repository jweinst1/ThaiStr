#include "unit_test.h"

int thaistr_unit_test_eq(void* obj1, void* obj2, size_t size)
{
	size_t i;
	const unsigned char* read1 = obj1;
	const unsigned char* read2 = obj2;
	for(i = 0; i< size; i++) {
		if(read1[i] != read2[i]) {
			fprintf(stderr, "Eq FAILED: Differs at index: %lu, ", i);
			fprintf(stderr, "object 1 has the byte '%u', while object 2 has '%u'\n", read1[i], read2[i]);
			return 0;
		}
	}
	return 1;
}
