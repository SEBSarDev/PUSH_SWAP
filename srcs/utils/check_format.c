/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssar <ssar@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 18:09:51 by ssar              #+#    #+#             */
/*   Updated: 2021/08/06 14:23:24 by ssar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	check_is_nbr(char *str)
{
	int	i;

	if (str[0] == '-' && !str[1])
		return (-1);
	if (ft_in("-0123456789", str[0]) == -1)
		return (-1);
	i = 0;
	while (str[++i])
	{
		if (ft_in("0123456789", str[i]) == -1)
			return (-1);
	}
	return (1);
}

int	check_doublon(char **str, int i)
{
	int	j;
	int	k;

	j = 0;
	while (++j < i)
	{
		if (ft_atoi(str[j]) == ft_atoi(str[i]))
			return (-1);
	}
	return (1);
}

int	check_form(t_pile *pile, char **str, int i)
{
	if (check_is_nbr(str[i]) == -1)
	{
		if (pile->alloue[5] == 1)
			ft_free_tab(str, -2);
		ft_error(pile, "Error\n");
	}
	if (ft_atoi(str[i]) > 2147483647 || ft_atoi(str[i]) < -2147483648)
	{
		if (pile->alloue[5] == 1)
			ft_free_tab(str, -2);
		ft_error(pile, "Error\n");
	}
	if (check_doublon(str, i) == -1)
	{	
		if (pile->alloue[5] == 1)
			ft_free_tab(str, -2);
		ft_error(pile, "Error\n");
	}
	return (1);
}
