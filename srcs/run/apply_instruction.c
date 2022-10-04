/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_instruction.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssar <ssar@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 14:47:59 by ssar              #+#    #+#             */
/*   Updated: 2021/08/23 12:01:09 by ssar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	is_it_swap(t_pile *pile, char *s)
{
	int	a;
	int	b;

	if (ft_comp(s, "sa") == 1)
	{
		a = apply_swap(pile, pile->a, pile->pos_a);
		if (a == 1)
			add_to_print(pile, "sa\n");
	}
	if (ft_comp(s, "sb") == 1)
	{
		b = apply_swap(pile, pile->b, pile->pos_b);
		if (b == 1)
			add_to_print(pile, "sb\n");
	}
	if (ft_comp(s, "ss") == 1)
	{
		a = apply_swap(pile, pile->a, pile->pos_a);
		b = apply_swap(pile, pile->b, pile->pos_b);
		if (a == 1 || b == 1)
			add_to_print(pile, "ss\n");
	}
	if (s[0] == 's')
		return (1);
	return (-1);
}

void	is_it_push(t_pile *pile, char *str, int *pos)
{
	if (ft_comp(str, "pa") == 1)
	{
		pos[0] = pile->pos_b;
		pos[1] = pile->pos_a;
		if (pile->pos_b > 0 || pile->b_vide == 0)
		{
			apply_push(pile, pile->b, pile->a, pos);
			pile->pos_b--;
			pile->pos_a++;
			add_to_print(pile, "pa\n");
		}
	}
	if (ft_comp(str, "pb") == 1)
	{
		pos[0] = pile->pos_a;
		pos[1] = pile->pos_b;
		if (pile->pos_a > 0 || pile->a_vide == 0)
		{
			apply_push(pile, pile->a, pile->b, pos);
			pile->pos_a--;
			pile->pos_b++;
			add_to_print(pile, "pb\n");
		}
	}
}

int	is_it_rotate(t_pile *pile, char *str)
{
	if (ft_comp(str, "ra") == 1)
	{
		apply_rotate(pile, pile->a, pile->pos_a);
		add_to_print(pile, "ra\n");
		return (1);
	}
	if (ft_comp(str, "rb") == 1)
	{
		apply_rotate(pile, pile->b, pile->pos_b);
		add_to_print(pile, "rb\n");
		return (1);
	}
	if (ft_comp(str, "rr") == 1)
	{
		apply_rotate(pile, pile->a, pile->pos_a);
		apply_rotate(pile, pile->b, pile->pos_b);
		add_to_print(pile, "rr\n");
		return (1);
	}
	return (-1);
}

int	is_it_reverse_rotate(t_pile *pile, char *str)
{
	if (ft_comp(str, "rra") == 1)
	{
		apply_reverse_rotate(pile, pile->a, pile->pos_a);
		add_to_print(pile, "rra\n");
		return (1);
	}
	if (ft_comp(str, "rrb") == 1)
	{
		apply_reverse_rotate(pile, pile->b, pile->pos_b);
		add_to_print(pile, "rrb\n");
		return (1);
	}
	if (ft_comp(str, "rrr") == 1)
	{
		apply_reverse_rotate(pile, pile->a, pile->pos_a);
		apply_reverse_rotate(pile, pile->b, pile->pos_b);
		add_to_print(pile, "rrr\n");
		return (1);
	}
	return (-1);
}

void	launch_instruction(t_pile *pile, char *str)
{
	int	pos[2];

	if (is_it_swap(pile, str) == 1)
		return ;
	else if (is_it_rotate(pile, str) == 1)
		return ;
	else if (is_it_reverse_rotate(pile, str) == 1)
		return ;
	else
		is_it_push(pile, str, pos);
	if (pile->pos_a < 0)
		pile->a_vide = 1;
	else
		pile->a_vide = 0;
	if (pile->pos_b < 0)
		pile->b_vide = 1;
	else
		pile->b_vide = 0;
	if (pile->pos_a >= pile->size_tab)
		pile->pos_a = pile->size_tab - 1;
	if (pile->pos_b >= pile->size_tab)
		pile->pos_b = pile->size_tab - 1;
}
