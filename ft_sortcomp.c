/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sortcomp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaouab <asaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 16:20:54 by asaouab           #+#    #+#             */
/*   Updated: 2023/08/10 19:29:31 by asaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_sort(t_list *stack)
{
	t_list	*temp;

	temp = stack;
	if (temp->next == NULL)
		return (1);
	while (temp->next)
	{
		if (temp->data > temp->next->data)
			return (0);
		temp = temp->next;
	}
	return (1);
}

void	ft_sort_two(t_list **stack)
{
	int	temp;

	temp = (*stack)->data;
	if ((((*stack)->next->data) < (*stack)->data))
	{
		ft_swap(*stack, 1);
	}
}

void	ft_sort_three(t_list **stack)
{
	if ((*stack)->data > (*stack)->next->data
		&& (*stack)->data < (*stack)->next->next->data)
		ft_swap((*stack), 1);
	else if ((*stack)->data > (*stack)->next->data
		&& (*stack)->next->data > (*stack)->next->next->data)
	{
		ft_swap((*stack), 1);
		ft_rra(stack);
	}
	else if ((*stack)->data > (*stack)->next->data
		&& (*stack)->next->data < (*stack)->next->next->data)
		ft_ra(stack);
	else if ((*stack)->data < (*stack)->next->data
		&& (*stack)->data < (*stack)->next->next->data
		&& (*stack)->next->next->data < (*stack)->next->data)
	{
		ft_swap((*stack), 1);
		ft_ra(stack);
	}
	else if ((*stack)->data < (*stack)->next->data
		&& (*stack)->data > (*stack)->next->next->data)
		ft_rra(stack);
}

int	get_min(t_list *stack)
{
	int	max;
	int	indice;
	int	j;

	max = 0;
	indice = 0;
	j = 0;
	if (!stack)
		return (0);
	max = stack->data;
	while (stack)
	{
		if (max > stack->data)
		{
			max = stack->data;
			indice = j; 
		}
		stack = stack->next;
		j++;
	}
	return (indice);
}
