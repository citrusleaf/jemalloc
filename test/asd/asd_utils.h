#pragma once
#pragma GCC diagnostic ignored "-Wcomment"

#include <stddef.h>

#define	as_assert(e) do {							\
	if (!(e)) {							\
		malloc_printf(						\
		    "<jemalloc>: %s:%d: Failed assertion: \"%s\"\n",	\
		    __FILE__, __LINE__, #e);				\
		abort();						\
	}								\
} while (0)

// #define	not_reached() do {						\
// 	malloc_printf(							\
// 	    "<jemalloc>: %s:%d: Unreachable code reached\n",		\
// 	    __FILE__, __LINE__);					\
// 	abort();							\
// } while (0)

// #define	not_implemented() do {						\
// 	malloc_printf("<jemalloc>: %s:%d: Not implemented\n",		\
// 	    __FILE__, __LINE__);					\
// 	abort();							\
// } while (0)

// #define	assert_not_implemented(e) do {					\
// 	if (!(e))							\
// 		not_implemented();					\
// } while (0)
