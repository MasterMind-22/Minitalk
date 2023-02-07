/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonadry <yonadry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:13:09 by yonadry           #+#    #+#             */
/*   Updated: 2023/02/07 20:01:03 by yonadry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

static void	confirm_receipt(int signal)
{
	if (signal == SIGUSR2)
		ft_putstr("Message is delivered Successfully");
}

static void	send_bits(int pid, char byte)
{
	int	i;
	int	b;

	i = 0;
	b = (int)byte;
	while (i < 8)
	{
		if ((128 >> i) & b)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i++;
		usleep(500);
	}
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	pid = atoi(av[1]);
	i = 0;
	signal(SIGUSR2, confirm_receipt);
	if (ac == 3)
	{
		while (av[2][i])
		{
			send_bits(pid, av[2][i]);
			i++;
		}
		send_bits(pid, 125);
	}
	else
	{
		ft_putstr("Invalid Arguments!!\nCorrect Format: \"");
		ft_putstr(av[0]);
		ft_putstr(" SERVER_PID MESSAGE_TO_SEND\"");
	}
}
