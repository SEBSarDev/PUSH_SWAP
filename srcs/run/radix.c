/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssar <ssar@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 09:31:42 by ssar              #+#    #+#             */
/*   Updated: 2021/08/06 09:43:54 by ssar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	binaire_b(t_pile *pile, int j)
{
	int	i;

	i = -1;
	while (++j <= pile->pos_a)
		pile->a_char[j] = conv_b(pile, ft_itoa(pile->a[j]), "0123456789", "01");
	j--;
	while (++j < pile->size_tab)
	{
		pile->a_char[j] = (char *)malloc(sizeof(char) * 1);
		if (!pile->a_char[j])
			ft_error(pile, "error malloc\n");
		pile->a_char[j][0] = '\0';
	}
	pile->a_char[pile->size_tab] = 0;
	while (++i <= pile->pos_b)
		pile->b_char[i] = conv_b(pile, ft_itoa(pile->b[i]), "0123456789", "01");
	i--;
	while (++i < pile->size_tab)
	{
		pile->b_char[i] = (char *)malloc(sizeof(char) * 1);
		if (!pile->b_char[i])
			ft_error(pile, "error malloc\n");
		pile->b_char[i][0] = '\0';
	}
	pile->b_char[pile->size_tab] = 0;
}

void	pass_binaire(t_pile *pile)
{
	int		i;
	char	*max;

	pile->max_len = -1;
	max = conv_b(pile, ft_itoa(pile->highter), "0123456789", "01");
	pile->max_len = ft_len(max);
	free(max);
	i = -1;
	if (pile->alloue[3] == 1)
		ft_free_tab(pile->a_char, pile->size_tab);
	pile->alloue[3] = 0;
	if (pile->alloue[4] == 1)
		ft_free_tab(pile->b_char, pile->size_tab);
	pile->alloue[4] = 0;
	pile->a_char = (char **)malloc(sizeof(char *) * (pile->size_tab + 1));
	if (!pile->a_char)
		ft_error(pile, "error malloc\n");
	pile->alloue[3] = 1;
	pile->b_char = (char **)malloc(sizeof(char *) * (pile->size_tab + 1));
	if (!pile->b_char)
		ft_error(pile, "error malloc\n");
	pile->alloue[4] = 1;
	binaire_b(pile, i);
}

int	how_many(t_pile *pile, int j)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i <= pile->pos_a)
	{
		if (pile->a_char[i][j] == '0')
			count++;
		i++;
	}
	return (count);
}

int	get_lenght_max(t_pile *pile)
{	
	pass_binaire(pile);
	return (pile->max_len);
}

void	ft_radix(t_pile *pile)
{
	int	i;
	int	j;
	int	unit;

	j = get_lenght_max(pile);
	while (--j >= 0)
	{
		i = -1;
		unit = how_many(pile, j);
		while (++i < pile->size_tab)
		{
			if (pile->a_char[0][j] == '0')
				launch_instruction(pile, "pb");
			else
				launch_instruction(pile, "ra");
			pass_binaire(pile);
			if (pile->pos_b >= unit)
				break ;
		}
		while (pile->pos_b > -1)
		{
			launch_instruction(pile, "pa");
			pass_binaire(pile);
		}
	}
}
