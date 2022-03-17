/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldatilio <ldatilio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 21:42:41 by ldatilio          #+#    #+#             */
/*   Updated: 2022/03/17 19:25:46 by ldatilio         ###   ########.fr       */
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

void rrotate(t_node **head)
{
	t_node *temp;
	t_node *last_node;

	temp = *head;
	while(temp->next->next != NULL)
		temp = temp->next;
	last_node = temp->next;
	temp->next = NULL;
	insert_front(head, last_node->value);
	free(last_node); 
}

void	swap(t_node **head)
{
	int	tmp;

	if ((*head) && (*head)->next)
	{
		tmp = (*head)->value;
		(*head)->value = (*head)->next -> value;
		(*head)->next -> value = tmp;
	}
}
