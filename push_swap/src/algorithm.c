/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnagy <fnagy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:30:15 by ferenc            #+#    #+#             */
/*   Updated: 2025/03/24 11:01:24 by fnagy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
push one node to b so we will have at least one node
push the rest of the nodes to b
- until only 3 remaining
- push while sorting
sort the remaining 3 nodes
push back to a
place the min to the first position
*/
void	sort_list(t_Node **a, t_Node **b)
{
	int	a_count;

	a_count = count_nodes(*a);
	if (a_count-- > 3 && !is_list_sorted(*a))
		pb(b, a);
	while (a_count-- > 3 && !is_list_sorted(*a))
	{
		prep_nodes_a(*a, *b);
		move_a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		prep_nodes_b(*a, *b);
		move_b_to_a(a, b);
	}
	min_on_top(a);
}

/*
set the index and median line for a and b
set targets for a
check fee using index and median
find the lowest fee and mark it True
*/
void	prep_nodes_a(t_Node *a, t_Node *b)
{
	index_and_median(a);
	index_and_median(b);
	target_for_a(a, b);
	check_fee(a, b);
	set_lowest(a);
}

void	prep_nodes_b(t_Node *a, t_Node *b)
{
	index_and_median(a);
	index_and_median(b);
	target_for_b(a, b);
}

/*------------------*/
/* 
search for the closest smallest value or if there is not
than get the largest value from b
*/
void	target_for_a(t_Node *a, t_Node *b)
{
	t_Node	*current_b;
	t_Node	*target;
	long	match;

	while (a)
	{
		match = LONG_MIN;
		current_b = b;
		while (current_b)
		{
			if (current_b->x < a->x && current_b->x > match)
			{
				match = current_b->x;
				target = current_b;
			}
			current_b = current_b->next;
		}
		if (match == LONG_MIN)
			a->target = find_max(b);
		else
			a->target = target;
		a = a->next;
	}
}

void	target_for_b(t_Node *a, t_Node *b)
{
	t_Node	*current_a;
	t_Node	*target;
	long	match;

	while (b)
	{
		match = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->x > b->x && current_a->x < match)
			{
				match = current_a->x;
				target = current_a;
			}
			current_a = current_a->next;
		}
		if (match == LONG_MAX)
			b->target = find_min(a);
		else
			b->target = target;
		b = b->next;
	}
}
