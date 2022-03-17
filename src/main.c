/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldatilio <ldatilio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:16:05 by ldatilio          #+#    #+#             */
/*   Updated: 2022/03/17 00:50:28 by ldatilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_stack(int argc, char **argv)
{
	int		i;
	t_node	*steak_a;

	i = 1;
	steak_a = NULL;
	while (i < argc)
	{
		insert_back(&steak_a, ft_atoi(argv[i]));
		i++;
	}
	insert_front(&steak_a, 2);
	print_node(steak_a);
	print_node(steak_a);
	free_node(steak_a);
}

int	main(int argc, char **argv)
{
	if (argc < 3)
		return (1);
	valid_args(argc, argv);
	create_stack(argc, argv);
	return (0);
}
