/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldatilio <ldatilio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:16:05 by ldatilio          #+#    #+#             */
/*   Updated: 2022/03/12 01:18:38 by ldatilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../libs/libft/libft.h"

/**
 * @brief not duplicate, only number.
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
			printf("i: %d, j: %d\n; %d", ft_atoi(argv[i]), ft_atoi(argv[j]));
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				exit(2);
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
