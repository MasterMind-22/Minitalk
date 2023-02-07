/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonadry <yonadry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 18:53:26 by yonadry           #+#    #+#             */
/*   Updated: 2023/02/07 19:57:47 by yonadry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include<signal.h>
# include<unistd.h>
# include<stdlib.h>

void	ft_putchar(char a);
void	ft_putnbr(int num);
void	ft_putstr(char *s);
int		to_char(int *save);
int		ft_atoi(const char *str);

#endif