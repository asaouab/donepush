/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garp_coll.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaouab <asaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 01:41:30 by asaouab           #+#    #+#             */
/*   Updated: 2023/08/12 01:56:12 by asaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void	my_exit(int status);

typedef struct s_gc	t_gc;

struct s_gc
{
	void	*ptr;
	int		isfreed;
	t_gc	*next;
};

t_gc	*get_gc(void)
{
	static t_gc	gc;

	return (&gc);
}

void	*my_malloc(size_t size)
{
	void	*ptr;
	t_gc	*gc;

	gc = get_gc();
	while (gc->next)
		gc = gc->next;
	gc->next = malloc(sizeof(t_gc));
	if (!gc->next)
	{
		write(2, "malloc error!\n", 14);
		my_exit(1);
	}
	ptr = malloc(size);
	if (!ptr)
	{
		write(2, "malloc error!\n", 14);
		my_exit(1);
	}
	gc->next->ptr = ptr;
	gc->next->isfreed = 0;
	gc->next->next = NULL;
	return (ptr);
}

void	my_free(void *ptr)
{
	t_gc	*gc;

	if (!ptr)
		return ;
	gc = get_gc()->next;
	while (gc)
	{
		if ((gc->ptr == ptr) && (gc->isfreed == 0))
		{
			gc->isfreed = 1;
			free(ptr);
			return ;
		}
		gc = gc->next;
	}
	free (ptr);
}

void	my_exit(int status)
{
	t_gc	*gc;
	t_gc	*prev;

	gc = get_gc()->next;
	while (gc)
	{
		if (gc->isfreed == 0)
		{
			gc->isfreed = 1;
			free (gc->ptr);
		}
		prev = gc;
		gc = gc->next;
		free (prev);
	}
	exit (status);
}
