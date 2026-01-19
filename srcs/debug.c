#include "../includes/ft_malloc.h"

void	debug_heap()
{
	t_block	**base_ptr;
	t_block	*current;

	base_ptr = get_block_base();
	current = *base_ptr;
	ft_printf("--- HEAP ---\n");
	if (!current)
	{
		ft_printf("HEAP void\n");
		return ;
	}
	while (current)
	{
		ft_printf("[Block @ %p]\n", (void *) current);
		if (current->is_free)
			ft_printf("	|--> Status: FREE\n");
		else
			ft_printf("	|--> Status: ALLOC\n");
		ft_printf("	|--> Size: %zu bytes\n", current->size);
		ft_printf("	|--> Data: %p\n", (void *) (current + 1));
		ft_printf("	|--> Next: %p\n", (void *) current->next);
		ft_printf("---------------------------------\n");
		current = current->next;
	}
	ft_printf("End of heap (sbrk(0)): %p\n\n", sbrk(0));
}
