/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssar <ssar@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 10:07:17 by ssar              #+#    #+#             */
/*   Updated: 2021/08/23 11:56:49 by ssar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	place_of_unsort(t_pile *pile, int j)
{
	int	i;

	if (j == 1)
		launch_instruction(pile, "sa");
	else if (j == pile->size_tab - 1)
	{
		launch_instruction(pile, "rra");
		launch_instruction(pile, "rra");
		launch_instruction(pile, "sa");
		launch_instruction(pile, "ra");
		launch_instruction(pile, "ra");
	}
	else
		return (0);
	i = 0;
	while (++i < pile->size_tab)
	{
		if (pile->a[i] < pile->a[i - 1])
			return (place_of_unsort(pile, i));
	}
	return (1);
}

int	already_sort(t_pile *pile)
{
	int	i;

	i = 0;
	while (++i < pile->size_tab)
	{
		if (pile->a[i] < pile->a[i - 1] && pile->a[i] == pile->a[i - 1] - 1
			&& pile->size_tab > 3)
		{
			return (place_of_unsort(pile, i));
		}
		if (pile->a[i] < pile->a[i - 1])
			return (0);
	}
	return (1);
}

void	case_three(t_pile *pile)
{
	if (pile->a[0] < pile->a[1] && pile->a[1] > pile->a[2]
		&& pile->a[2] > pile->a[0])
	{
		launch_instruction(pile, "rra");
		launch_instruction(pile, "sa");
	}
	if (pile->a[0] > pile->a[1] && pile->a[1] < pile->a[2]
		&& pile->a[2] > pile->a[0])
		launch_instruction(pile, "sa");
	if (pile->a[0] < pile->a[1] && pile->a[1] > pile->a[2]
		&& pile->a[2] < pile->a[0])
		launch_instruction(pile, "rra");
	if (pile->a[0] > pile->a[1] && pile->a[1] > pile->a[2]
		&& pile->a[2] < pile->a[0])
	{
		launch_instruction(pile, "sa");
		launch_instruction(pile, "rra");
	}
	if (pile->a[0] > pile->a[1] && pile->a[1] < pile->a[2]
		&& pile->a[2] < pile->a[0])
		launch_instruction(pile, "ra");
}

void	push_min_max_b(t_pile *pile, int min_max)
{
	int	i;

	i = 0;
	while (pile->a[i] != min_max)
		i++;
	if (i > pile->pos_a / 2)
	{
		while (pile->a[0] != min_max)
			launch_instruction(pile, "rra");
	}
	else
	{
		while (pile->a[0] != min_max)
			launch_instruction(pile, "ra");
	}
	launch_instruction(pile, "pb");
}

void	short_sort(t_pile *pile, int nb)
{
	if (nb == 2)
		launch_instruction(pile, "sa");
	else if (nb == 3)
		case_three(pile);
	else if (nb == 4)
	{
		push_min_max_b(pile, 0);
		case_three(pile);
		launch_instruction(pile, "pa");
	}
	else if (nb == 5)
	{
		push_min_max_b(pile, 0);
		push_min_max_b(pile, 4);
		case_three(pile);
		launch_instruction(pile, "pa");
		launch_instruction(pile, "ra");
		launch_instruction(pile, "pa");
	}
}
