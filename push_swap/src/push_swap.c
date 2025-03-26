/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferenc <ferenc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:16:47 by ferenc            #+#    #+#             */
/*   Updated: 2025/03/21 10:21:25 by ferenc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// static void	print_nodes(t_Node *root)
// {
// 	t_Node	*current;

// 	current = root;
// 	while (current != NULL)
// 	{
// 		printf("%d\n", current->x);
// 		current = current->next;
// 	}
// }
// print_nodes(a);

static void	free_split_result(char **array)
{
	size_t	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

static void	init_list_a(t_Node **a, char **av)
{
	long	nbr;
	int		i;

	i = 0;
	while (av[i])
	{
		if (error_syntax(av[i]))
			free_errors(a);
		nbr = ft_atol(av[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			free_errors(a);
		if (duplicate_error(*a, (int)nbr))
			free_errors(a);
		append_node(a, (int)nbr);
		i++;
	}
}

/*works only with 3 nodes*/
void	sort_three(t_Node **root)
{
	t_Node	*first;
	t_Node	*second;
	t_Node	*third;

	first = *root;
	second = first->next;
	third = second->next;
	if (first->x > second->x && first->x > third->x)
		ra(root);
	else if (second->x > first->x && second->x > third->x)
		rra(root);
	if ((*root)->x > (*root)->next->x)
		sa(root);
}

static void	choose_sort(t_Node **a, t_Node **b)
{
	int	a_count;

	if (!is_list_sorted(*a))
	{
		a_count = count_nodes(*a);
		if (a_count == 2)
			sa(a);
		else if (a_count == 3)
			sort_three(a);
		else
			sort_list(a, b);
	}
}

int	main(int ac, char **av)
{
	t_Node	*a;
	t_Node	*b;
	char	**split_av;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	else if (ac == 2)
	{
		split_av = ft_split(av[1], ' ');
		init_list_a(&a, split_av);
		free_split_result(split_av);
	}
	else
		init_list_a(&a, av + 1);
	choose_sort(&a, &b);
	deallocate(&a);
	return (0);
}
