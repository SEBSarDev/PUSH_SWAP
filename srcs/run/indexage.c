/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexage.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssar <ssar@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 10:57:50 by ssar              #+#    #+#             */
/*   Updated: 2021/08/06 10:59:51 by ssar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_neg(t_pile *pile, t_list *neg)
{
	t_list	*stock;
	t_list	*temp;
	int		val;
	int		rang;

	stock = neg;
	while (neg->next != NULL)
	{
		temp = neg->next;
		if (temp->value < neg->value)
		{
			val = neg->value;
			rang = neg->rank;
			neg->value = temp->value;
			neg->rank = temp->rank;
			temp->value = val;
			temp->rank = rang;
			neg = stock;
		}
		else
			neg = neg->next;
	}
	neg = stock;
	pile->add = replace_neg_val(pile, neg);
}

t_list	*transform_neg(t_pile *pile)
{
	int		i;
	t_list	*neg;
	t_list	*temp;

	i = 0;
	neg = NULL;
	pile->add = 0;
	while (i < pile->size_tab)
	{
		if (pile->stock_a[i] < 0)
		{
			temp = create_new_neg(pile, i, pile->stock_a[i], NULL);
			ft_lstadd_back(&neg, temp);
		}
		i++;
	}
	if (neg != NULL)
		sort_neg(pile, neg);
	return (neg);
}

void	sort_pos(t_pile *pile, t_list *pos)
{
	t_list	*stock;
	t_list	*temp;
	int		val;
	int		rang;

	stock = pos;
	while (pos->next != NULL)
	{
		temp = pos->next;
		if (temp->value < pos->value)
		{
			val = pos->value;
			rang = pos->rank;
			pos->value = temp->value;
			pos->rank = temp->rank;
			temp->value = val;
			temp->rank = rang;
			pos = stock;
		}
		else
			pos = pos->next;
	}
	pos = stock;
	replace_pos_val(pile, pos);
}

t_list	*transform_pos(t_pile *pile, t_list *neg)
{
	int		i;
	t_list	*pos;
	t_list	*temp;

	i = 0;
	pos = NULL;
	while (i < pile->size_tab)
	{
		if (pile->stock_a[i] >= 0)
		{
			temp = create_new_neg(pile, i, pile->stock_a[i], neg);
			ft_lstadd_back(&pos, temp);
		}
		i++;
	}
	if (pos != NULL)
		sort_pos(pile, pos);
	return (pos);
}
