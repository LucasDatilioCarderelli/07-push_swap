/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldatilio <ldatilio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:16:05 by ldatilio          #+#    #+#             */
/*   Updated: 2022/03/12 22:32:24 by ldatilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief	In case of error, it must display "Error" followed by a ’\\n’
 * 			on the standard error. Print a message and exit with a failure.
 * 
 * @param	error_msg	char string message.
 */
void	print_error(char *error_msg)
{
	write(2, "\033[0;31mError:\033[0m\n", 19);
	ft_putstr_fd(error_msg, 2);
	write(2, "\n", 2);
	exit(EXIT_FAILURE);
}

/**
 * @brief	not duplicate, only number.
 */
int	valid_args(int argc, char **argv)
{
	int	i;
	int j;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			printf("i: %d, j: %d\n", ft_atoi(argv[i]), ft_atoi(argv[j]));
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				print_error("Found Duplicate");
			j++;
		}
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc < 3)
		return (1);
	valid_args(argc, argv);
	return (0);
}
