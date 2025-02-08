/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoub <ayoub@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 17:30:47 by ayaarab           #+#    #+#             */
/*   Updated: 2025/02/08 12:56:10 by ayoub            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// # include "ft_printf/ft_printf.h"
// # include "gnl/get_next_line.h"
// # include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

int	is_valid_int(char *str);
int	ft_isdigit(int c);
int	is_delimiter(char c);
int ft_atoi(const char *str);
void	ft_putnbr_fd(int n, int fd);

#endif