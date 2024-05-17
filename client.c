/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iecer <iecer@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:14:00 by iecer             #+#    #+#             */
/*   Updated: 2024/05/08 12:39:36 by iecer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		++i;
	}
}

int	converter_int(char *str)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (str[i])
	{
		res = (res * 10) + (str[i] - '0');
		++i;
	}
	return (res);
}

void	send_message(char chr, int pid)
{
	int	i;
	int	error;

	i = 0;
	error = 0;
	while (i < 8)
	{
		if (chr << i & 128)
			error = kill(pid, SIGUSR1);
		else
			error = kill(pid, SIGUSR2);
		++i;
		usleep(150);
	}
	if (error == -1)
	{
		ft_putstr("Wrong PID input !!");
		exit(1);
	}
}

int	main(int arc, char **arg)
{
	int	pid;
	int	i;

	i = 0;
	if (arc == 3)
	{
		pid = converter_int(arg[1]);
		while (arg[2][i])
		{
			send_message(arg[2][i], pid);
			++i;
		}
	}
	else
	{
		ft_putstr("Incorrect format !!");
		exit(1);
	}
}
