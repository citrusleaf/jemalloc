//#define JEMALLOC_NO_RENAME
//#include "test/jemalloc_test.h"
#include "jemalloc/internal/jemalloc_internal.h"
#include "jemalloc/internal/jemalloc_internal_defs.h"
#include "jemalloc/internal/jemalloc_internal_decls.h"
#include "asd_utils.h"

/*
 * Test project "asd" using jemalloc with "je" prefix.
 * This demonstrates using jemalloc functions with explicit je_ prefix.
 */

void test_asd_basic_allocation(void)
{
	void *ptr;
	size_t size;
	size_t usable_size;

	/* Use je_malloc explicitly */
	size = 100;
	ptr = je_mallocx(size, 0);
	assert(ptr != NULL && "je_malloc should not return NULL");

	/* Use je_malloc_usable_size to check allocated size */
	usable_size = je_malloc_usable_size(ptr);
	assert(usable_size >= size && "Usable size should be at least requested size");

	/* Use je_free explicitly */
	je_free(ptr);
}

void test_asd_reallocation(void)
{
	void *ptr1, *ptr2;
	size_t size1 = 50;
	size_t size2 = 150;

	/* Allocate initial memory */
	ptr1 = je_malloc(size1);
	assert(ptr1 != NULL && "je_malloc should not return NULL");

	/* Reallocate to larger size */
	ptr2 = je_realloc(ptr1, size2);
	assert(ptr2 != NULL && "je_realloc should not return NULL");

	/* Free the reallocated memory */
	je_free(ptr2);
}

void test_asd_calloc(void)
{
	void *ptr;
	size_t num = 10;
	size_t size = sizeof(int);
	int *ints;
	size_t i;

	/* Use je_calloc explicitly */
	ptr = je_mallocx(num * size, 0);
	assert(ptr != NULL && "je_calloc should not return NULL");

	/* Verify memory is zero-initialized */
	ints = (int *)ptr;
	for (i = 0; i < num; i++) {
		assert(ints[i] == 0 && "calloc should zero-initialize memory");
	}

	je_free(ptr);
}

int
main(void)
{
	test_asd_basic_allocation();
	test_asd_reallocation();
	test_asd_calloc();
	return 0;
}
