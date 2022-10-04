/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssar <ssar@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 15:40:08 by ssar              #+#    #+#             */
/*   Updated: 2021/08/06 11:09:57 by ssar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_error(t_pile *pile, char *str)
{
	if (pile->alloue[0] == 1)
		free(pile->a);
	if (pile->alloue[1] == 1)
		free(pile->b);
	if (pile->alloue[2] == 1)
		free(pile->stock_a);
	if (pile->alloue[3] == 1)
		ft_free_tab(pile->a_char, pile->size_tab);
	if (pile->alloue[4] == 1)
		ft_free_tab(pile->b_char, pile->size_tab);
	if (pile->to_print != NULL)
		ft_free_lst_pr(&pile->to_print);
	write(2, str, ft_len(str));
	exit(EXIT_FAILURE);
}
