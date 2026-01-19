#ifndef FT_MALLOC_H
# define FT_MALLOC_H

# include <assert.h>
# include <stdio.h>
# include <pthread.h>
# include <stdbool.h>
# include <sys/resource.h>
# include <unistd.h>
# include <stdint.h>
# include "../libft/libft.h"
# define HEAP_CAPACITY 128000

# define SUCESS 0
# define FAIL 1

/*
 * To be thread-safe, is necessary a variable global mutex
 */

typedef struct	s_block
{
	size_t			size; // Tamanho do bloco
	bool			is_free; // Se o bloco está livre ou não
	struct s_block	*next;
	void			*s_break; // endereço do bloco
}	t_block;

t_block	**get_block_base(void);
void	*ft_malloc(size_t size);
void	debug_heap();

extern pthread_mutex_t	g_malloc_mutex;

#endif
