/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parcing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaouab <asaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 16:12:09 by asaouab           #+#    #+#             */
/*   Updated: 2023/08/10 16:18:25 by asaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check(char **argv)
{
	int	x;
	int	y;

	y = 0;
	while (argv[y])
	{
		if (argv[y][0] == '\0')
		{
			write(2, "empty string\n", 14);
			exit(1);
		}
		x = 0;
		if (argv[y][x] == '+' || argv[y][x] == '-')
			x++;
		while (argv[y][x])
		{
			if (argv[y][x] < '0' || argv[y][x] > '9')
			{
				write(2, "Error :Check args!\n", 20);
				exit(0);
			}
			x++;
		}
		y++;
	}
}

void	more_check(char **argv)
{
	int	y;
	int	x;

	y = 0;
	while (argv[y])
	{
		x = 0;
		while (argv[y][x])
		{
			if ((argv[y][x] == '-' || argv[y][x] == '+') &&
				(argv[y][x + 1] == ' ' || argv[y][x + 1] == '\t'))
			{
				write(2, "there is tab or space in the arg\n", 34);
				exit(0);
			}
			if ((argv[y][x] == '-' || argv[y][x] == '+') && 
				(argv[y][x + 1] == '+' || argv[y][x + 1] == '-'))
			{
				write(2, "there is - or + in the arg\n", 28);
				exit(0);
			}
			x++;
		}
		y++;
	}
}

void	check_dup_num(char	**argv)
{
	int	y;
	int	x;

	y = 0;
	while (argv[y]) 
	{
		x = y + 1; 
		while (argv[x]) 
		{
			if (atoi(argv[y]) == atoi(argv[x])) 
			{
				write(2, "Error: Duplicate numbers\n", 26);
				exit(1);
			}
			x++;
		}
		y++;
	}
}
