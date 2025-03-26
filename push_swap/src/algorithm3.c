/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnagy <fnagy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 11:25:49 by ferenc            #+#    #+#             */
/*   Updated: 2025/03/24 11:55:36 by fnagy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
set position for each nodes as index
and marked if it is above or under the median line
*/
void	index_and_median(t_Node *root)
{
	int	i;
	int	median;

	i = 0;
	if (!root)
		return ;
	median = count_nodes(root) / 2;
	while (root)
	{
		root->index = i;
		if (i <= median)
			root->above = true;
		else
			root->above = false;
		root = root->next;
		++i;
	}
}

/*
check fee for each nodes
how many operations takes to bring a
and a->target node on top
checks the number of rotations (ra/rb or rra/rrb) needed
by their position
*/
void	check_fee(t_Node *a, t_Node *b)
{
	int	a_count;
	int	b_count;

	a_count = count_nodes(a);
	b_count = count_nodes(b);
	while (a)
	{
		a->fee = a->index;
		if (!(a->above))
			a->fee = a_count - a->index;
		if (a->target->above)
			a->fee += a->target->index;
		else
			a->fee += b_count - a->target->index;
		a = a->next;
	}
}

/*
after all nodes got the fee calculated, 
set the node with lowest fee to True
*/
void	set_lowest(t_Node *root)
{
	long	min_cost;
	t_Node	*lowest_fee;

	if (!root)
		return ;
	min_cost = LONG_MAX;
	while (root)
	{
		if (root->fee < min_cost)
		{
			min_cost = root->fee;
			lowest_fee = root;
		}
		root = root->next;
	}
	lowest_fee->lowest = true;
}

/*
search the list to find the FIRST node marked True as lowest
*/
t_Node	*get_lowest(t_Node *root)
{
	if (!root)
		return (NULL);
	while (root)
	{
		if (root->lowest)
			return (root);
		root = root->next;
	}
	return (NULL);
}

/*
check the lowest node and place it on top by
rotating the list until it is on the first position
*/
void	min_on_top(t_Node **a)
{
	t_Node	*min_node;

	index_and_median(*a);
	min_node = find_min(*a);
	while ((*a)->x != min_node->x)
	{
		if (min_node->above)
			ra(a);
		else
			rra(a);
		min_node = find_min(*a);
	}
}
