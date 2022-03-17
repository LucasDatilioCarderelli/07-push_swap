/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldatilio <ldatilio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 21:42:41 by ldatilio          #+#    #+#             */
/*   Updated: 2022/03/17 14:43:54 by ldatilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_node **dest, t_node **src)
{
	t_node	*tmp;

	insert_front(dest, (*src)->value);
	tmp = *src;
	(*src) = (*src)->next;
	free(tmp);
}

void	rotate(t_node **head)
{
	t_node	*tmp;

	insert_back(head, (*head)->value);
	tmp = *head;
	*head = (*head)->next;
	free(tmp);
}
