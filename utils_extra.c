/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utlis_extra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaciri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 13:59:45 by anaciri           #+#    #+#             */
/*   Updated: 2022/03/28 16:14:45 by anaciri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

void	ft_putnbr(int nbr)
{
	long	nb;
	char	a;

	nb = nbr;
	if (nb < 0)
	{
		nb = -nb;
		write(1, "-", 1);
	}
	else if (nb < 10)
	{
		a = nb + 48;
		write(1, &a, 1);
	}
	else
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
}
