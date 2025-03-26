/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferenc <ferenc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:41:53 by ferenc            #+#    #+#             */
/*   Updated: 2025/02/25 16:32:08 by ferenc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	rotate(t_Node **root)
{
	t_Node	*last_node;

	if (!*root || !(*root)->next)
		return ;
	last_node = find_last(*root);
	last_node->next = *root;
	*root = (*root)->next;
	(*root)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

void	ra(t_Node **a)
{
	rotate(a);
	ft_printf("ra\n");
}

void	rb(t_Node **b)
{
	rotate(b);
	ft_printf("rb\n");
}

void	rr(t_Node **a, t_Node **b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}
