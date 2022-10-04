/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssar <ssar@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 15:37:52 by ssar              #+#    #+#             */
/*   Updated: 2021/08/06 09:22:34 by ssar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	apply_swap(t_pile *pile, unsigned int *tab, int top)
{
	int	stock;

	if (top <= 0)
		return (-1);
	stock = tab[0];
	tab[0] = tab[1];
	tab[1] = stock;
	return (1);
}

void	apply_push(t_pile *pile, unsigned int *src, unsigned int *dest, int *w)
{
	int	stock_a;
	int	stock_b;
	int	i;
	int	temp;

	i = -1;
	stock_a = src[0];
	while (++i < w[0])
		src[i] = src[i + 1];
	src[w[0]] = '\0';
	i = 0;
	stock_b = dest[0];
	while (i <= w[1] && i < pile->size_tab)
	{
		temp = dest[i + 1];
		dest[i + 1] = stock_b;
		stock_b = temp;
		i++;
	}
	dest[0] = stock_a;
}

void	apply_reverse_rotate(t_pile *pile, unsigned int *tab, int top)
{
	int	stock;
	int	i;

	if (top < 0)
		return ;
	i = top - 1;
	stock = tab[top];
	while (i >= 0)
	{
		tab[top] = tab[i];
		i--;
		top--;
	}
	tab[0] = stock;
}

void	apply_rotate(t_pile *pile, unsigned int *tab, int top)
{
	int	stock;
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (top < 0)
		return ;
	stock = tab[0];
	while (i <= top)
	{
		tab[j] = tab[i];
		i++;
		j++;
	}
	tab[top] = stock;
}
