/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssar <ssar@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 11:30:16 by ssar              #+#    #+#             */
/*   Updated: 2021/08/06 11:21:33 by ssar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_check_form_base(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		if ((str[i] > 8 && str[i] < 14)
			|| str[i] == 43 || str[i] == 45
			|| str[i] == 32)
			return (0);
		j = i + 1;
		while (str[j])
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		i++;
	}
	if (i <= 1)
		return (0);
	return (1);
}

void	ft_fill_tab(unsigned int n, char *bse_to, char *tab, int i)
{
	if (n == 0 && i == 1)
		i = i - 1;
	while (n >= (unsigned int)ft_len(bse_to))
	{
		ft_fill_tab(n / ft_len(bse_to), bse_to, tab, i - 1);
		n = n % ft_len(bse_to);
	}
	tab[i] = bse_to[n];
}

int	ft_size_of_conv(unsigned int n, char *base_to)
{
	int	u;

	u = 1;
	if (n >= (unsigned int)ft_len(base_to))
	{
		return (1 + ft_size_of_conv(n / ft_len(base_to), base_to));
	}
	return (u);
}

unsigned int	ft_get_nbr_dec(char *nbr, char *base_from)
{
	int				i;
	int				a;
	unsigned int	n;

	i = 0;
	a = 0;
	n = 0;
	while ((nbr[i] > 8 && nbr[i] < 14) || nbr[i] == 32)
		i++;
	while (nbr[i] == 45 || nbr[i] == 43)
		i++;
	a = ft_in(base_from, nbr[i]);
	while (a != -1)
	{
		n = n * ft_len(base_from) + a;
		i++;
		a = ft_in(base_from, nbr[i]);
	}
	return (n);
}

char	*conv_b(t_pile *pile, char *nbr, char *base_from, char *base_to)
{
	unsigned int	n;
	int				l;
	char			*tab;
	int				size_nb;
	int				i;

	if (!(ft_check_form_base(base_from)) || !(ft_check_form_base(base_to)))
		return (NULL);
	n = ft_get_nbr_dec(nbr, base_from);
	size_nb = ft_size_of_conv(n, base_to);
	if (pile->max_len != -1)
		l = pile->max_len;
	else
		l = ft_size_of_conv(n, base_to);
	tab = (char *)malloc(sizeof(char) * (l + 1));
	if (!tab)
		ft_error(pile, "error malloc \n");
	tab[l] = '\0';
	l = l - 1;
	ft_fill_tab(n, base_to, tab, l);
	free(nbr);
	i = l - size_nb + 1;
	while (pile->max_len != -1 && --i >= 0)
		tab[i] = '0';
	return (tab);
}
