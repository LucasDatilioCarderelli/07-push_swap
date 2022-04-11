/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldatilio <ldatilio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 21:42:41 by ldatilio          #+#    #+#             */
/*   Updated: 2022/04/11 04:02:16 by ldatilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_node **dest, t_node **src)
{
	t_node	*tmp;

	if (*src == NULL)
		return ;
	insert_front(dest, (*src)->value, (*src)->index);
	tmp = *src;
	(*src) = (*src)->next;
	free(tmp);
}

void	rotate(t_node **head)
{
	t_node	*tmp;

	if (*head == NULL)
		return ;
	insert_back(head, (*head)->value, (*head)->index);
	tmp = *head;
	*head = (*head)->next;
	free(tmp);
}

void	rrotate(t_node **head)
{
	t_node	*temp;
	t_node	*last_node;

	if (*head == NULL)
		return ;
	temp = *head;
	while (temp->next->next != NULL)
		temp = temp->next;
	last_node = temp->next;
	temp->next = NULL;
	insert_front(head, last_node->value, last_node->index);
	free(last_node);
}

void	swap(t_node **head)
{
	int	tmp_value;
	int	tmp_index;

	if (*head == NULL)
		return ;
	if ((*head) && (*head)->next)
	{
		tmp_value = (*head)->value;
		tmp_index = (*head)->index;
		(*head)->value = (*head)->next->value;
		(*head)->index = (*head)->next->index;
		(*head)->next->value = tmp_value;
		(*head)->next->index = tmp_index;
	}
}
