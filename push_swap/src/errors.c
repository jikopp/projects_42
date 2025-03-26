/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferenc <ferenc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 12:47:10 by ferenc            #+#    #+#             */
/*   Updated: 2025/03/20 20:14:58 by ferenc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
Valid examples:
"123"
"-42"
"+987"
*/
int	error_syntax(char *str)
{
	if (!(*str == '+' || *str == '-' || (*str >= '0' && *str <= '9')))
		return (1);
	if ((*str == '+' || *str == '-') && !(str[1] >= '0' && str[1] <= '9'))
		return (1);
	while (*++str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (1);
	}
	return (0);
}

int	duplicate_error(t_Node *root, int nbr)
{
	if (root == NULL)
		return (0);
	while (root)
	{
		if (root->x == nbr)
			return (1);
		root = root->next;
	}
	return (0);
}

void	free_errors(t_Node **root)
{
	deallocate(root);
	ft_printf("Error\n");
	exit(1);
}
