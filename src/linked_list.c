/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldatilio <ldatilio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 00:49:54 by ldatilio          #+#    #+#             */
/*   Updated: 2022/04/10 22:21:13 by ldatilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Insert a new_node at the end of the list.
 * 
 * @param head First pointer of the list.
 * @param value Int value of the node.
 */
void	insert_back(t_node **head, int value, int index)
{
	t_node	*new_node;
	t_node	*temp;

	new_node = (t_node *)malloc(sizeof(t_node));
	new_node -> value = value;
	new_node -> index = index;
	new_node -> next = NULL;
	if (*head == NULL)
	{
		new_node -> prev = NULL;
		*head = new_node;
		return ;
	}
	temp = *head;
	while (temp -> next != NULL)
		temp = temp -> next;
	temp -> next = new_node;
	new_node -> prev = temp;
}

/**
 * @brief Insert a new_node at the beginning of the list.
 * 
 * @param head First pointer of the list.
 * @param value Int value of the node.
 */
void	insert_front(t_node	**head, int value, int index)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	new_node -> value = value;
	new_node -> index = index;
	new_node -> next = *head;
	new_node -> prev = NULL;
	if (*head != NULL)
		(*head)->prev = new_node;
	*head = new_node;
}

/**
 * @brief Free the memory allocated for each node in the list.
 * 
 * @param head First pointer of the list.
 */
void	free_node(t_node *head)
{
	t_node	*tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head -> next;
		free(tmp);
	}
}

/**
 * @brief Print in the output each node from the list;
 * 
 * @param head First pointer of the list.
 */
void	print_node(t_node *head)
{
	if (head == NULL)
		printf("NULL\n");
	while (head != NULL)
	{
		ft_printf("%d \n", head -> index);
		head = head -> next;
	}
}
