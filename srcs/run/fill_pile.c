/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_pile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssar <ssar@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 18:26:30 by ssar              #+#    #+#             */
/*   Updated: 2021/08/06 10:59:18 by ssar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	replace_pos_val(t_pile *pile, t_list *pos)
{
	t_list	*stock;
	int		i;

	i = 0;
	stock = pos;
	while (pos->next != NULL)
	{
		pos->new_value = i + pile->add;
		i++;
		pos = pos->next;
	}
	pos->new_value = i + pile->add;
	pile->highter = pos->new_value;
	pos = stock;
}

int	replace_neg_val(t_pile *pile, t_list *neg)
{
	t_list	*stock;
	int		i;

	i = 0;
	stock = neg;
	while (neg->next != NULL)
	{
		neg->new_value = i;
		i++;
		neg = neg->next;
	}
	neg->new_value = i;
	pile->highter = neg->new_value;
	i++;
	neg = stock;
	return (i);
}

void	fill_without_neg(t_pile *pile, t_list *neg)
{
	int		i;
	t_list	*posi;

	i = 0;
	posi = transform_pos(pile, neg);
	pile->a = (unsigned int *)malloc(sizeof(unsigned int) * pile->size_tab);
	if (!pile->a)
		ft_error(pile, "Error malloc a\n");
	pile->alloue[0] = 1;
	pile->b = (unsigned int *)malloc(sizeof(unsigned int) * pile->size_tab);
	if (!pile->b)
		ft_error(pile, "Error malloc b\n");
	pile->alloue[1] = 1;
	while (i < pile->size_tab)
	{
		if (pile->stock_a[i] < 0)
			pile->a[i] = get_val_neg(pile, neg, i);
		else
			pile->a[i] = get_val_neg(pile, posi, i);
		i++;
	}
	if (neg != NULL)
		ft_free_lst(&neg);
	if (posi != NULL)
		ft_free_lst(&posi);
}

void	init_a_b(t_pile *pile, char **str, int i, int p)
{
	int		j;
	int		k;
	t_list	*neg;

	i = i - 1 + p;
	pile->stock_a = (int *)malloc(sizeof(int) * i);
	if (!pile->stock_a)
		ft_error(pile, "Error malloc b\n");
	pile->alloue[2] = 1;
	pile->size_tab = i;
	j = 0;
	k = 1 - p;
	while (k <= i - p)
	{
		pile->stock_a[j] = ft_atoi(str[k]);
		k++;
		j++;
	}
	neg = transform_neg(pile);
	fill_without_neg(pile, neg);
	pile->pos_a = i - 1;
	pile->pos_b = -1;
	pile->b_vide = 1;
	pile->a_vide = 0;
}
