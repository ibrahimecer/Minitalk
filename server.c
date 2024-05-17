/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iecer <iecer@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:13:54 by iecer             #+#    #+#             */
/*   Updated: 2024/05/08 12:38:47 by iecer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>

void	putnbr(int nbr)
{
	if (nbr > 9)
		putnbr(nbr / 10);
	write(1, &"0123456789"[nbr % 10], 1);
}

void	signal_converter(int signal)
{
	static char	bit;
	static int	i;

	if (signal == SIGUSR1)
		bit = bit | 1;
	i++;
	if (i == 8)
	{
		write(1, &bit, 1);
		i = 0;
		bit = 0;
	}
	bit = bit << 1;
}

int	main(void)
{
	write(1, "Server started and PID : ", 25);
	putnbr(getpid());
	write(1, "\n", 1);
	signal(SIGUSR1, signal_converter);
	signal(SIGUSR2, signal_converter);
	while (1)
		pause();
	return (0);
}
