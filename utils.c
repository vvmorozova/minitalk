/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eward <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 16:24:21 by eward             #+#    #+#             */
/*   Updated: 2022/03/22 16:24:23 by eward            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	my_error(void)
{
	ft_printf("Error\n");
	exit(0);
}

int	ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	else
		return (0);
}

int	ft_isdigit(int c)
{
	if ((c >= '0') && (c <= '9'))
		return (1);
	else
		return (0);
}

int	num_size(const char *str)
{
	int	i;
	int	size;

	size = 0;
	i = 0;
	while (ft_isspace(*(str + i)))
		i++;
	if (*(str + i) == '+' || *(str + i) == '-')
		i++;
	while (ft_isdigit(*(str + i)))
	{
		size++;
		i++;
	}
	return (size);
}

int	ft_atoi(const char *str)
{
	long	sign;
	int		rez;
	size_t	i;

	rez = 0;
	i = 0;
	sign = 1;
	while (ft_isspace(*(str + i)))
		i++;
	if (*(str + i) == '-' || *(str + i) == '+')
	{
		if (*(str + i) == '-')
			sign = -1;
		i++;
	}
	while (*(str + i) && ft_isdigit(*(str + i)))
	{
		rez = rez * 10 + str[i++] - '0';
		if (rez < 0)
			my_error();
	}
	if (*(str + i) && !ft_isdigit(*(str + i)) && (*(str + i) != '-'))
		my_error();
	return ((int)(rez * sign));
}
