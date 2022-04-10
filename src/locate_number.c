/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   locate_number.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldatilio <ldatilio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 02:16:13 by ldatilio          #+#    #+#             */
/*   Updated: 2022/04/10 19:46:57 by ldatilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	locate_low_num_pos(t_node *head, int *low)
{
	int	low_pos;
	int	i;

	*low = head -> value;
	i = 0;
	while (head)
	{
		if (head -> value < *low)
		{
			*low = head -> value;
			low_pos = i;
		}
		head = head -> next;
		i++;
	}
	if (low_pos > i / 2)
		return (1);
	return (0);
}

int	locate_high_num_pos(t_node *head, int *high)
{
	int	high_pos;
	int	i;

	*high = head -> value;
	i = 0;
	while (head)
	{
		if (head -> value > *high)
		{
			*high = head -> value;
			high_pos = i;
		}
		head = head -> next;
		i++;
	}
	if (high_pos > i / 2)
		return (1);
	return (0);
}
