/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonadry <yonadry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 18:53:33 by yonadry           #+#    #+#             */
/*   Updated: 2023/02/07 20:07:22 by yonadry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar(char a)
{
	write(1, &a, 1);
}

void	ft_putnbr(int num)
{
	if (num > 9)
	{
		ft_putnbr(num / 10);
		ft_putnbr(num % 10);
	}
	else
		ft_putchar(num + 48);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i] != '\0')
	{
		ft_putchar(s[i]);
		i++;
	}
}

int	to_char(int *save)
{
	int	i;
	int	result;

	i = 0;
	result = 1;
	while (save[i] == 0)
		i++;
	i++;
	while (i < 8)
	{
		result = result * 2 + save[i];
		i++;
	}
	return (result);
}

int	ft_atoi(const char *str)
{
	int		i;
	size_t	res;

	res = 0;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res);
}
