/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eward <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 13:11:01 by eward             #+#    #+#             */
/*   Updated: 2022/03/22 13:11:03 by eward            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned long	i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)(s1);
	str2 = (unsigned char *)(s2);
	i = 0;
	while (*(str1 + i) && *(str2 + i) && i < n)
	{
		if (*(str1 + i) != *(str2 + i))
			return (*((unsigned char *)(s1 + i)) -
					*((unsigned char *)(s2 + i)));
		i++;
	}
	if (i == n)
		return (0);
	return (*((unsigned char *)(s1 + i)) - *((unsigned char *)(s2 + i)));
}

void	ft_handler(int signum, siginfo_t *siginfo, void *unused)
{
	(void)signum;
	(void)siginfo;
	(void)unused;
}

void	send_message(char *pid, char *msg)
{
	int	i;
	int	j;

	j = 0;
	while ((msg[j]))
	{
		i = 128;
		while (i >= 1)
		{
			if (i & msg[j])
				kill(ft_atoi(pid), SIGUSR1);
			else
				kill(ft_atoi(pid), SIGUSR2);
			i /= 2;
			usleep(100);
		}
		j++;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	the_catch;

	if (argc != 3)
		my_error();
	(void)argv;
	the_catch.sa_flags = SA_SIGINFO;
	the_catch.sa_sigaction = ft_handler;
	sigaction(SIGUSR1, &the_catch, 0);
	sigaction(SIGUSR2, &the_catch, 0);
	send_message(argv[1], argv[2]);
}
