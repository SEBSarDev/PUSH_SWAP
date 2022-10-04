/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssar <ssar@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 13:58:36 by ssar              #+#    #+#             */
/*   Updated: 2021/08/06 11:09:21 by ssar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	ft_count_size_nbr(unsigned int n)
{
	unsigned int	nbr;

	nbr = n;
	if (nbr > 9)
		return (ft_count_size_nbr(nbr / 10) + 1);
	return (1);
}

static void	ft_fill(char *ptr, int size, unsigned int n)
{
	char			*dec;
	unsigned int	nbr;

	nbr = n;
	dec = "0123456789";
	while (nbr > 9)
	{
		ft_fill(ptr, size - 1, nbr / 10);
		nbr = nbr % 10;
	}
	ptr[size] = dec[nbr];
}

char	*ft_itoa(unsigned int n)
{
	int		size;
	char	*ptr;

	size = ft_count_size_nbr(n);
	ptr = (char *)malloc(sizeof(char) * (size + 1));
	if (!ptr)
		return (NULL);
	ft_fill(ptr, size - 1, n);
	ptr[size] = '\0';
	return (ptr);
}
