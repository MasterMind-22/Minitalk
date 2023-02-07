/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonadry <yonadry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:13:22 by yonadry           #+#    #+#             */
/*   Updated: 2023/02/07 20:02:06 by yonadry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

static void	sig_handler(int signum, siginfo_t *info, void *ptr)
{
	static int		save[8];
	static int		i;
	static pid_t	prev_pid;
	int				charac;

	(void) ptr;
	if (prev_pid != info->si_pid)
	{
		i = 0;
		prev_pid = info->si_pid;
	}
	if (signum == SIGUSR1)
		save[i++] = 1;
	else if (signum == SIGUSR2)
		save[i++] = 0;
	if (i == 8)
	{
		charac = to_char(save);
		if (charac == 125)
			kill(info->si_pid, SIGUSR2);
		else
			write(1, &charac, 1);
		i = 0;
	}
}

int	main(void)
{
	struct sigaction	act;

	sigemptyset(&act.sa_mask);
	act.sa_sigaction = sig_handler;
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &act, 0);
	sigaction(SIGUSR2, &act, 0);
	ft_putstr("The PID is: ");
	ft_putnbr(getpid());
	ft_putchar('\n');
	while (1)
		pause();
}
