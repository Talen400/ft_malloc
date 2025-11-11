#include "../includes/ft_malloc.h"

void	*malloc(size_t size)
{
	void	*ptr;

	if (!size)
		return (NULL);
	pthread_mutex_lock(&g_malloc_mutex);

	pthread_mutex_lock(&g_malloc_mutex);
}
