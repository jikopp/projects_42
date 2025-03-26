/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnagy <fnagy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 11:27:55 by ferenc            #+#    #+#             */
/*   Updated: 2025/03/24 11:50:55 by fnagy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rotate_both(t_Node **a, t_Node **b,	t_Node *lowest_fee)
{
	while (*b != lowest_fee->target && *a != lowest_fee)
		rr(a, b);
	index_and_median(*a);
	index_and_median(*b);
}

void	rev_rotate_both(t_Node **a, t_Node **b,	t_Node *lowest_fee)
{
	while (*b != lowest_fee->target && *a != lowest_fee)
		rrr(a, b);
	index_and_median(*a);
	index_and_median(*b);
}

/*
Optimizing simultaneous rotation:
- If both lowest_fee in Stack A and its target in Stack B
  are in the top half (above == true),
  we call rotate_both(a, b, lowest_fee), which executes rr(a, b).
- If both are in the bottom half (above == false),
  we call rev_rotate_both(a, b, lowest_fee), which executes rrr(a, b).
This step helps reduce the number of rotations needed overall!
Otherwise we call prep for push and rotate them invidually. 
Finally, when the required nodes on top we push.
*/
void	move_a_to_b(t_Node **a, t_Node **b)
{
	t_Node	*lowest_fee;

	lowest_fee = get_lowest(*a);
	if (lowest_fee->above && lowest_fee->target->above)
		rotate_both(a, b, lowest_fee);
	else if (!(lowest_fee->above) && !(lowest_fee->target->above))
		rev_rotate_both(a, b, lowest_fee);
	prep_for_push(a, lowest_fee, 'a');
	prep_for_push(b, lowest_fee->target, 'b');
	pb(b, a);
}

void	move_b_to_a(t_Node **a, t_Node **b)
{
	prep_for_push(a, (*b)->target, 'a');
	pa(a, b);
}

/*
it moves the node to the top of the list by rotating the list
we make sure the node we want to push is on the top
we tell the function which list we need to adjust bu the list_name
*/
void	prep_for_push(t_Node **root, t_Node *top_node, char list_name)
{
	while (*root != top_node)
	{
		if (list_name == 'a')
		{
			if (top_node->above)
				ra(root);
			else
				rra(root);
		}
		else if (list_name == 'b')
		{
			if (top_node->above)
				rb(root);
			else
				rrb(root);
		}
	}
}
