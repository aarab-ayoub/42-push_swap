/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoub <ayoub@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 12:37:06 by ayoub             #+#    #+#             */
/*   Updated: 2025/02/08 12:56:43 by ayoub            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return 1;
	return 0;
}

int	is_valid_int(char *str)
{
	int  i = 0;
	if (str[i] == '-' ||  str[i] == '+')
		i++;
	if (str[i] == '\0')
		return 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return 0;
		i++;	
	}
	return 1;
}

void	ft_putnbr_fd(int n, int fd)
{
	char c;
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
	{
		c = n + '0';
		write(fd, &c, 1);
	}
}

int	is_delimiter(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return 1;
	return 0;
}

int	ft_atoi(const char *str)
{
	int i;
	int sign;
	int res;

	i = 0;
	sign = 1;
	res = 0;
	while (is_delimiter(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * sign);
}
