/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferenc <ferenc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:41:59 by ferenc            #+#    #+#             */
/*   Updated: 2025/02/25 16:32:39 by ferenc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	swap(t_Node **root)
{
	if (!*root || !(*root)->next)
		return ;
	*root = (*root)->next;
	(*root)->prev->prev = *root;
	(*root)->prev->next = (*root)->next;
	if ((*root)->next)
		(*root)->next->prev = (*root)->prev;
	(*root)->next = (*root)->prev;
	(*root)->prev = NULL;
}

void	sa(t_Node **a)
{
	swap(a);
	ft_printf("sa\n");
}

void	sb(t_Node **b)
{
	swap(b);
	ft_printf("sb\n");
}

void	ss(t_Node **a, t_Node **b)
{
	swap(a);
	swap(b);
	ft_printf("ss\n");
}
