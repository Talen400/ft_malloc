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

t_block	**get_block_base(void)
{
	static t_block	*block = NULL;

	return (&block);
}
/*
t_block	*find_free_block(t_block **node, size_t size)
{
	return (NULL);
}
*/
void	*memory_ten(size_t size)
{
	t_block	*head;

	head = sbrk(sizeof(t_block) + size);
	if (head == (void *) -1)
		return (NULL);
	head->size = size;
	head->is_free = false;
	return (head + 1);
}

void	*memory_large(size_t size)
{
	void	*ptr;

	ptr = NULL;
	(void ) size;
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

	str = ft_malloc(10);
	debug_heap();
	ft_free(str);
	return (0);
}
