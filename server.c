/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eward <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 13:11:07 by eward             #+#    #+#             */
/*   Updated: 2022/03/22 13:11:09 by eward            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_handler(int signum, siginfo_t *siginfo, void *unused)
{
	static int	ascii = 0;
	static int	power = 0;

	(void)unused;
	if (signum == SIGUSR1)
		ascii += 1 << (7 - power);
	power++;
	if (power == 8)
	{
		ft_printf("%c", ascii);
		power = 0;
		ascii = 0;
		if (kill(siginfo->si_pid, SIGUSR2) == -1)
			my_error();
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	the_catch;

	(void)argc;
	(void)argv;
	ft_printf("my PID: %d", getpid());
	the_catch.sa_flags = SA_SIGINFO;
	the_catch.sa_sigaction = ft_handler;
	sigaction(SIGUSR1, &the_catch, 0);
	sigaction(SIGUSR2, &the_catch, 0);
	while (1)
		pause();
}
