/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferenc <ferenc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 11:37:29 by ferenc            #+#    #+#             */
/*   Updated: 2025/03/20 20:01:12 by ferenc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
// # include <fcntl.h>
// # include <stdint.h>
// # include <sys/wait.h>

// typedef struct s_Node
// {
// 	int				x; // value
// 	int				index; // index of the value
// 	int				fee; // push_cost
// 	bool			above; // above median line
// 	bool			lowest; // cheapest cost
// 	struct s_Node	*target; // target node
// 	struct s_Node	*next;
// 	struct s_Node	*prev;
// }	t_Node;

// Handle errors
int		error_syntax(char *str);
int		duplicate_error(t_Node *root, int nbr);
void	free_errors(t_Node **root);

void	sort_three(t_Node **root);

void	sort_list(t_Node **a, t_Node **b);

void	prep_nodes_a(t_Node *a, t_Node *b);
void	prep_nodes_b(t_Node *a, t_Node *b);

t_Node	*get_lowest(t_Node *root);

void	rotate_both(t_Node **a, t_Node **b,	t_Node *lowest);
void	rev_rotate_both(t_Node **a, t_Node **b,	t_Node *lowest);
void	move_a_to_b(t_Node **a, t_Node **b);
void	move_b_to_a(t_Node **a, t_Node **b);

void	prep_for_push(t_Node **root, t_Node *top_node, char list_name);

void	index_and_median(t_Node *root);

void	target_for_a(t_Node *a, t_Node *b);
void	target_for_b(t_Node *a, t_Node *b);

void	check_fee(t_Node *a, t_Node *b);
void	set_lowest(t_Node *root);

void	min_on_top(t_Node **a);

// Commands
/*swap*/
void	sa(t_Node **a);
void	sb(t_Node **b);
void	ss(t_Node **a, t_Node **b);
/*push*/
void	pa(t_Node **a, t_Node **b);
void	pb(t_Node **b, t_Node **a);
/*rotate*/
void	ra(t_Node **a);
void	rb(t_Node **b);
void	rr(t_Node **a, t_Node **b);
/*reverse rotate*/
void	rra(t_Node **a);
void	rrb(t_Node **b);
void	rrr(t_Node **a, t_Node **b);

#endif