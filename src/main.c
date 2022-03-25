/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldatilio <ldatilio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:16:05 by ldatilio          #+#    #+#             */
/*   Updated: 2022/03/25 02:42:51 by ldatilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	operations(char *action, t_stack *stack)
{
	if (!ft_strncmp(action, "sa", 2))
		swap(&stack -> a);
	else if (!ft_strncmp(action, "sb", 2))
		swap(&stack -> b);
	else if (!ft_strncmp(action, "pa", 2))
		push(&stack -> a, &stack -> b);
	else if (!ft_strncmp(action, "pb", 2))
		push(&stack -> b, &stack -> a);
	else if (!ft_strncmp(action, "ra", 2))
		rotate(&stack -> a);
	else if (!ft_strncmp(action, "rb", 2))
		rotate(&stack -> b);
	else if (!ft_strncmp(action, "rra", 3))
		rrotate(&stack -> a);
	else if (!ft_strncmp(action, "rrb", 3))
		rrotate(&stack -> b);
	ft_printf("%s\n", action);
}

void	create_stack(int argc, char **argv)
{
	int		i;
	t_stack	stack;

	i = 1;
	stack.a = NULL;
	stack.b = NULL;
	while (i < argc)
	{
		insert_back(&stack.a, ft_atoi(argv[i]));
		i++;
	}
	operations("sa", &stack);
	operations("pb", &stack);
	operations("pb", &stack);
	operations("pb", &stack);
	operations("sa", &stack);
	operations("pa", &stack);
	operations("pa", &stack);
	operations("pa", &stack);
	free_node(stack.a);
	free_node(stack.b);
}

int	main(int argc, char **argv)
{	
	if (argc < 3)
		return (1);
	valid_args(argc, argv);
	create_stack(argc, argv);
	return (0);
}
