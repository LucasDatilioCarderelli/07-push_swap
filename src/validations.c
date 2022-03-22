/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldatilio <ldatilio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 00:15:34 by ldatilio          #+#    #+#             */
/*   Updated: 2022/03/22 01:27:36 by ldatilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief	In case of error, it must display "Error" followed by a ’\\n’ 
 * on the standard error. Print a message and exit with a failure.
 * 
 * @param	error_num	Exit with a integer code.
 */
void	exit_error(int error_num)
{
	write(2, "\033[0;31mError\033[0m\n", 18);
	exit(error_num);
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
	int	j;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		if (arg_is_alpha(argv[i]))
			exit_error(1);
		while (j < argc)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				exit_error(2);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_sorted(t_node *head, int argc)
{
	int	i;

	i = 1;
	while (head -> next != NULL)
	{
		if (head -> value > head -> next -> value)
			return (FALSE);
		head = head -> next;
		i++;
	}
	if (i < argc - 1)
		return (FALSE);
	return (TRUE);
}
