/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaouab <asaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 17:12:34 by asaouab           #+#    #+#             */
/*   Updated: 2023/08/12 02:35:29 by asaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*add_back(t_list *head, int nemb)
{
	t_list	*temp;
	t_list	*stock;

	temp = head;
	while (temp->next)
		temp = temp->next;
	stock = malloc(sizeof(t_list));
	stock->data = nemb;
	stock->next = NULL;
	temp->next = stock;
	return (head);
}

t_list	*linkedlist(t_list *newnode, int nemb)
{
	newnode = malloc(sizeof(t_list));
	if (newnode == NULL)
	{
		exit(1);
	}
	newnode->data = nemb; 
	newnode->next = NULL;
	return (newnode);
}

void	main_help2(int p, t_list **stacka, t_list **stackb, int *arr)
{
	if (p == 5)
		ft_sortfive(*stacka, *stackb);
	else
	{
		ft_full_numbers(arr, *stacka, p);
		arr = ft_sort_arr(arr, p);
		ft_add_indice(arr, *stacka, p);
		ft_sort_100(stacka, stackb);
		ft_repush_a(stacka, stackb);
	}
}

void	main_help(char **split, t_list **stacka, t_list **stackb, int argc)
{
	int		i;
	int		p;
	int		*arr;

	p = 0;
	i = 0;
	while (split[i++])
		p = i;
	if (p == 1 || argc == 1)
		return ;
	i = 1;
	while (split[i])
	{
		(*stacka) = add_back((*stacka), ft_atoi(split[i]));
		i++;
	}
	arr = malloc(ft_lstsize((*stacka)) * sizeof(int));
	if (p == 2)
		ft_sort_two(stacka);
	else if (p == 3)
		ft_sort_three(stacka);
	else if (p == 4)
		ft_sort_four(*stacka, *stackb);
	else
		main_help2(p, stacka, stackb, arr);
}
void adam (void)
{
	system("leaks push_swap");
}
int	main(int argc, char **argv)
{
	atexit(adam);
	char	*join;
	char	**split;
	int		p;
	t_list	*stacka;
	t_list	*stackb;

	stackb = NULL;
	stacka = NULL;
	join = NULL;
	join = ft_strjoin(argc - 1, argv + 1, " ");
	split = ft_split(join, ' ');
	free(join);
	p = 0;
	ft_check(split);
	more_check(split);
	check_dup_num(split);
	stacka = linkedlist(stacka, ft_atoi(split[0]));
	main_help(split, &stacka, &stackb, argc);
	return (0);
}
