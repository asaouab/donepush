/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swapcomp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaouab <asaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 16:14:46 by asaouab           #+#    #+#             */
/*   Updated: 2023/08/10 20:33:33 by asaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_list *node1, int a)
{
	int	temp;

	temp = node1->data;
	node1->data = node1->next->data;
	node1->next->data = temp;
	if (a == 1)
		write(1, "sa\n", 3);
	if (a == 2)
		write(1, "sb\n", 3);
}

void	ft_push_b(t_list **stacka, t_list **stackb)
{
	t_list	*temp;

	if (*stacka == NULL)
		return ;
	temp = *stacka;
	(*stacka) = (*stacka)->next;
	temp->next = (*stackb);
	(*stackb) = temp;
	write(1, "pb\n", 3);
}

void	ft_push_a(t_list **stacka, t_list **stackb)
{
	t_list	*temp;

	if (*stackb == NULL)
		return ;
	temp = *stackb;
	(*stackb) = (*stackb)->next;
	temp->next = (*stacka);
	(*stacka) = temp;
	write(1, "pa\n", 3);
}

void	ft_ra(t_list **stack)
{
	t_list	*temp;

	if (*stack == NULL)
		return ;
	if ((*stack)->next == NULL)
		return ;
	temp = *stack;
	while (temp)
	{
		if (temp->next == NULL)
			break ;
		temp = temp->next;
	}
	temp->next = *stack;
	temp = *stack;
	(*stack) = (*stack)->next;
	temp->next = NULL;
	write(1, "ra\n", 3);
}
