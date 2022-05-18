/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eward <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 13:11:16 by eward             #+#    #+#             */
/*   Updated: 2022/03/22 13:11:18 by eward            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

unsigned long	ft_strlen(char *s);
void			my_error(void);
int				ft_atoi(const char *str);
int				ft_printf(const char *fmt, ...);
int				ft_strncmp(const char *s1, const char *s2, size_t n);

#endif