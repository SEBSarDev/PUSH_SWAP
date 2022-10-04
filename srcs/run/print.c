/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssar <ssar@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 10:02:54 by ssar              #+#    #+#             */
/*   Updated: 2021/08/06 17:11:28 by ssar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	useless_swap_b(t_print *lst, char *first, char *sec, int *pc)
{
	int	deux;
	int	i;

	deux = 0;
	while (lst && ft_comp(lst->instruction, sec) == 1)
	{
		deux++;
		(pc[1])++;
		lst = lst->next;
	}
	i = -1;
	if (deux == pc[0])
		return (pc[1]);
	else if (deux < pc[0])
	{
		while (++i < pc[0] - deux)
			write(1, first, ft_len(first));
	}
	else
	{
		while (++i < deux - pc[0])
			write(1, sec, ft_len(sec));
	}
	return (pc[1]);
}

int	useless_swap(t_print *lst, char *first, char *sec)
{
	int	pc[2];
	int	i;

	pc[0] = 0;
	pc[1] = 0;
	while (lst && ft_comp(lst->instruction, first) == 1)
	{
		(pc[0])++;
		(pc[1])++;
		lst = lst->next;
	}
	if (!lst || ft_comp(lst->instruction, sec) == 0)
	{
		i = 0;
		while (i < pc[0])
		{
			write(1, first, ft_len(first));
			i++;
		}
		return (pc[1]);
	}
	return (useless_swap_b(lst, first, sec, pc));
}

int	print_or_not(t_pile *pile, t_print *lst)
{
	int	count;

	count = -1;
	if (ft_comp(lst->instruction, "pa\n") == 1)
		count = useless_swap(lst, "pa\n", "pb\n");
	else if (ft_comp(lst->instruction, "pb\n") == 1)
		count = useless_swap(lst, "pb\n", "pa\n");
	else
	{
		write(1, lst->instruction, ft_len(lst->instruction));
		return (1);
	}
	if (count != -1)
		return (count);
	else
		return (0);
}

void	print_instruction(t_pile *pile, t_print *lst)
{
	t_print	*stock;
	int		go_to;
	int		i;

	stock = lst;
	while (stock->next != NULL)
	{
		i = 0;
		go_to = print_or_not(pile, stock);
		while (stock->next != NULL && i < go_to)
		{
			if (!stock)
				break ;
			stock = stock->next;
			i++;
		}
	}
	if (stock)
	{
		write(1, stock->instruction, ft_len(stock->instruction));
	}
}
