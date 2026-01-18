#include "../includes/ft_malloc.h"
# define SMALL 10
# define MID   100
# define BIG   1000

/*
 * Malloc usa duas chamadas de syscall do linux para
 * alocamento de memória:
 * 
 * brk(), sbrk(), mmap()
 *
 * Para entender o malloc, precisamos entender
 * o que são processos, em especifico linux
 *
 * Processos tem quatro componentes:
 * 	 - text (o código)
 *   - stack
 *   -
 */

pthread_mutex_t	g_malloc_mutex;

typedef struct	s_block
{
	size_t			size; // Tamanho do bloco
	bool			is_free; // Se o bloco está livre ou não
	struct s_block	*next;
	void			*s_break; // endereço do bloco
}	t_block;

t_block	**get_block_base(void)
{
	static t_block	*block;

	block = NULL;
	return (&block);
}

t_block	*find_free_block(t_block **node, size_t size)
{
	t_block	*pointer;

	pointer = *node;
	while (node)
	{
		if (pointer->is_free == 1)
			return (pointer);
		pointer =:
	}
	return (pointer);
}

void	*memory_ten(size_t size)
{
	void	*ptr;
	t_block	**base;
	t_block	*node;
	
	base = get_block_base();
	if (*base)
	{
		node = find_free_block(base, size);
		if (node)
			node = 
	}
	else
	{
		*base->s_break = sbrk(size);
	}
	/*
	ptr = sbrk(size);
	if (ptr == (void *) -1)
		return (NULL);
	*/
	
	return (ptr);
}

void	*memory_large(size_t size)
{
	void	*ptr;

	ptr = NULL;
	return (ptr);
}

void	*ft_malloc(size_t size)
{
	void	*ptr;

	if (!size)
		return (NULL);
	// protection to multithread context
	pthread_mutex_lock(&g_malloc_mutex);
	ptr = NULL;
	if (size <= SMALL)
		ptr = memory_ten(size);
	else if (size <= MID)
		ptr = memory_large(size);
	pthread_mutex_unlock(&g_malloc_mutex);
	return (ptr);
}

void	ft_free(void *ptr)
{
	pthread_mutex_lock(&g_malloc_mutex);
	(void ) ptr;
	pthread_mutex_unlock(&g_malloc_mutex);
}

int	main(void)
{
	void	*str;
	void	*s_break;

	s_break = sbrk(0);
	str = ft_malloc(10);
	ft_printf("initial break: %p \n", s_break);
	ft_printf(" pointer of memory: 	%p \n", str);
	ft_printf(" break actually: %p \n", sbrk(0));
	ft_free(str);
	return (0);
}
