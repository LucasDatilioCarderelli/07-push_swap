/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldatilio <ldatilio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:16:05 by ldatilio          #+#    #+#             */
/*   Updated: 2022/03/19 00:22:53 by ldatilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_stack(int argc, char **argv)
{
	int		i;
	t_node	*stack_a;
	t_node	*stack_b;

	i = 1;
	stack_a = NULL;
	stack_b = NULL;
	while (i < argc)
	{
		insert_back(&stack_a, ft_atoi(argv[i]));
		i++;
	}
	ft_printf("\nstack_a:\n");
	print_node(stack_a);
	ft_printf("stack_b:\n");
	print_node(stack_b);
	swap(&stack_a);
	push(&stack_b, &stack_a);
	push(&stack_b, &stack_a);
	push(&stack_b, &stack_a);
	swap(&stack_a);
	push(&stack_a, &stack_b);
	push(&stack_a, &stack_b);
	push(&stack_a, &stack_b);
	ft_printf("\nstack_a:\n");
	print_node(stack_a);
	ft_printf("stack_b:\n");
	print_node(stack_b);
	free_node(stack_a);
	free_node(stack_b);
}

int	main(int argc, char **argv)
{	
	if (argc < 3)
		return (1);
	valid_args(argc, argv);
	create_stack(argc, argv);
	return (0);
}
