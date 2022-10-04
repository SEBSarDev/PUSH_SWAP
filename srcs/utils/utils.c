/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssar <ssar@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 15:42:53 by ssar              #+#    #+#             */
/*   Updated: 2021/08/06 10:48:06 by ssar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_in(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_comp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s2[i] && s1[i])
	{
		if (s2[i] != s1[i])
			return (0);
		i++;
	}
	if (s2[i])
		return (0);
	if (s1[i])
		return (0);
	return (1);
}

char	**ft_free_tab(char **tab, int size)
{
	int	i;

	i = 0;
	if (size == -2)
	{
		while (tab[i])
		{
			free(tab[i]);
			i++;
		}
	}
	else
	{
		while (i < size)
		{
			free(tab[i]);
			i++;
		}
	}
	free(tab);
	return (NULL);
}

void	add_to_print(t_pile *pile, char *inst)
{
	t_print	*temp;

	pile->j++;
	temp = create_new_pr(pile, pile->j, inst);
	ft_lstadd_back_pr(&pile->to_print, temp);
}
