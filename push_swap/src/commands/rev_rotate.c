/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferenc <ferenc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:41:45 by ferenc            #+#    #+#             */
/*   Updated: 2025/02/25 16:31:45 by ferenc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	rev_rotate(t_Node **root)
{
	t_Node	*last;

	if (!*root || !(*root)->next)
		return ;
	last = find_last(*root);
	last->prev->next = NULL;
	last->next = *root;
	last->prev = NULL;
	*root = last;
	last->next->prev = last;
}

void	rra(t_Node **a)
{
	rev_rotate(a);
	ft_printf("rra\n");
}

void	rrb(t_Node **b)
{
	rev_rotate(b);
	ft_printf("rrb\n");
}

void	rrr(t_Node **a, t_Node **b)
{
	rev_rotate(a);
	rev_rotate(b);
	ft_printf("rrr\n");
}
