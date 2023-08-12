/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaouab <asaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 10:24:44 by asaouab           #+#    #+#             */
/*   Updated: 2023/08/12 02:33:26 by asaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

typedef struct s_list
{
	int				data;
	int				indice;
	struct s_list	*next;
}t_list;
int			ft_lstsize(t_list *stack);
char		**ft_split(char const *s, char c);
long		ft_atoi(const char *str);
void		ft_check(char **argv);
void		more_check(char **argv);
void		check_dup_num(char **argv);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(int size, char **strs, char *sep);
void		ft_swap(t_list *node1, int a);
void		ft_push_b(t_list **stacka, t_list **stackb);
void		ft_push_a(t_list **stacka, t_list **stackb);
void		ft_ra(t_list **stack);
void		ft_rb(t_list **stack);
void		ft_rra(t_list **stack);
void		ft_rrb(t_list **stack);
void		ft_sort_three(t_list **stack);
void		ft_sort_two(t_list **stack);
void		ft_sort_four(t_list *stack, t_list *stackb);
int			ft_check_sort(t_list *stack);
void		ft_sortfive(t_list *stack, t_list *stackb);
void		ft_sortfive(t_list *stack, t_list *stackb);
void		ft_full_numbers(int *arr, t_list *stacka, int len);
int			*ft_sort_arr(int *arr, int len);
void		ft_add_indice(int *arr, t_list *stacka, int len);
void		ft_sort_100(t_list **stacka, t_list **stackb);
int			get_max(t_list *stack);
void		ft_repush_a(t_list **stacka, t_list **stackb);
int			get_min(t_list *stack);
int			ft_lstsize(t_list *stack);

void		*my_malloc(size_t size);
void		my_free(void *ptr);
void		my_exit(int status);

# define MALLOC my_malloc
# define FREE my_free
# define EXIT my_exit
#endif