/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaouab <asaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 17:29:48 by asaouab           #+#    #+#             */
/*   Updated: 2023/08/10 19:28:52 by asaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_four(t_list *stack, t_list *stackb)
{
	t_list	*temp;
	int		min;

	min = stack->data;
	temp = stack->next;
	while (temp)
	{
		if (min > temp->data)
		{
			min = temp->data;
		}
		temp = temp->next;
	}
	while (get_min(stack) != 0)
		ft_rra(&stack);
	ft_push_b(&stack, &stackb);
	ft_sort_three(&stack);
	ft_push_a(&stack, &stackb);
}

//  int ft_count(char **split)
//  {
// 	int i = 0;
// 	while(*split)
// 	{
// 		i++;
// 	}
// 	return(i); 
//  }
void	ft_sortfive(t_list *stack, t_list *stackb)
{
	t_list	*temp;
	int		small;

	small = stack->data;
	temp = stack->next;
	while (temp)
	{
		if (small > temp->data)
		{
			small = temp->data;
		}
		temp = temp->next;
	}
	while (get_min(stack) != 0)
		ft_rra(&stack);
	ft_push_b(&stack, &stackb);
	ft_sort_four(stack, stackb);
	ft_push_a(&stack, &stackb);
}

void	ft_full_numbers(int *arr, t_list *stacka, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		arr[i] = stacka->data;
		i++;
		stacka = stacka->next;
	}
}

int	*ft_sort_arr(int *arr, int len)
{
	int	temp;
	int	i;

	i = 0;
	while (i < len - 1)
	{
		if (arr[i] > arr[i + 1])
		{
			temp = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = temp;
			i = 0;
		}
		else
			i++;
	}
	return (arr);
}

void	ft_add_indice(int *arr, t_list *stacka, int len)
{
	t_list	*temp;
	int		j;

	j = 0;
	while (j < len)
	{
		temp = stacka;
		while (temp)
		{
			if (arr[j] == temp->data)
			{
				temp->indice = j;
				break ;
			}
			temp = temp->next;
		}
		j++;
	}
}
