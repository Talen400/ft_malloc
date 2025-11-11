#ifndef FT_MALLOC_H
# define FT_MALLOC_H

# include <assert.h>
# include <stdio.h>
# include <pthread.h>
# include <stdbool.h>

# define HEAP_CAPACITY 128000

# define SUCESS 0
# define FAIL 1

/*
 * To be thread-safe, is necessary a variable global mutex
 */

extern pthread_mutex_t	g_malloc_mutex;

#endif
