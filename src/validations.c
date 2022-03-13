/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldatilio <ldatilio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 00:15:34 by ldatilio          #+#    #+#             */
/*   Updated: 2022/03/14 00:19:22 by ldatilio         ###   ########.fr       */
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
 * @brief iterate an argument and verify if there's a aplha.
 * 
 * @param argv argument to be validated.
 * @return int TRUE (1), if a char is aplha.
 */
int	arg_is_alpha(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (ft_isalpha(argv[i++]))
			return (TRUE);
	}
	return (FALSE);
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
		if (arg_is_alpha(argv[i]))
			print_error("arguments aren't integers");
		while (j < argc)
		{
			printf("i: %d, j: %d\n", ft_atoi(argv[i]), ft_atoi(argv[j]));
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				print_error("there are duplicates");
			j++;
		}
		i++;
	}
	return (0);
}