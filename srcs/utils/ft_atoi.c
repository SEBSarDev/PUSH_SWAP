/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssar <ssar@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 16:51:26 by ssar              #+#    #+#             */
/*   Updated: 2021/08/06 10:47:41 by ssar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	ft_inbase(const char c)
{
	int		i;
	char	*base;

	base = "0123456789";
	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

static int	ft_space(const char *str)
{
	int	i;

	i = 0;
	while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
		i++;
	return (i);
}

int	is_neg(const char *str, int *i)
{
	int	neg;

	neg = 1;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			neg = -1;
		(*i)++;
	}
	return (neg);
}

long long	ft_atoi(const char *str)
{
	int					i;
	int					neg;
	int					a;
	long long			n;
	unsigned long long	nbr;

	i = ft_space(str);
	nbr = 0;
	neg = is_neg (str, &i);
	a = ft_inbase(str[i]);
	while (a != -1)
	{
		nbr = nbr * 10 + a;
		i++;
		a = ft_inbase(str[i]);
	}
	if (neg < 0)
		return (n = nbr * neg);
	else
		return (nbr);
}
