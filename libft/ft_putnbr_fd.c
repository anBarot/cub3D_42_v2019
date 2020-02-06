/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 18:01:48 by abarot            #+#    #+#             */
/*   Updated: 2019/10/14 11:45:53 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_display(long int i, int fd)
{
	int tmp;

	if ((i / 10) > 0)
		ft_display((i / 10), fd);
	tmp = (i % 10) + 48;
	ft_putchar_fd(tmp, fd);
}

void		ft_putnbr_fd(int n, int fd)
{
	long int		i;

	i = n;
	if (n == 0)
	{
		ft_putchar_fd('0', fd);
		return ;
	}
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		i = -n;
	}
	ft_display(i, fd);
}
