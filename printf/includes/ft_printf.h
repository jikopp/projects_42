/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnagy <fnagy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:30:54 by fnagy             #+#    #+#             */
/*   Updated: 2024/10/10 11:46:39 by fnagy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>

int		ft_printf(const char *format, ...);

int		ft_print_chr(char c);
int		ft_print_str(char *s);
int		ft_print_nbr(int n);

int		ft_count_len(unsigned int element, int n);

int		ft_print_hex(unsigned long hex, unsigned int capital);
void	ft_hex(unsigned long hex, unsigned int capital);

int		ft_print_ptr(void *ptr);
int		ft_ptr_len(unsigned long nbr);

int		ft_print_dec(unsigned long dec);
void	ft_dec(unsigned long dec);

#endif
