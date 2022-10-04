/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssar <ssar@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 14:14:13 by ssar              #+#    #+#             */
/*   Updated: 2021/08/23 11:56:51 by ssar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_free(t_pile *pile)
{
	if (pile->alloue[0] == 1)
		free(pile->a);
	pile->alloue[0] = 0;
	if (pile->alloue[1] == 1)
		free(pile->b);
	pile->alloue[1] = 0;
	if (pile->alloue[2] == 1)
		free(pile->stock_a);
	pile->alloue[2] = 0;
	if (pile->alloue[3] == 1)
		ft_free_tab(pile->a_char, pile->size_tab);
	pile->alloue[3] = 0;
	if (pile->alloue[4] == 1)
		ft_free_tab(pile->b_char, pile->size_tab);
	pile->alloue[4] = 0;
	if (pile->to_print != NULL)
		ft_free_lst_pr(&pile->to_print);
}

void	init_pile_char(t_pile *pile)
{
	int	i;

	i = -1;
	pile->a_char = (char **)malloc(sizeof(char *) * (pile->size_tab + 1));
	if (!pile->a_char)
		ft_error(pile, "Error malloc\n");
	while (++i <= pile->size_tab)
		pile->a_char[i] = 0;
	pile->alloue[3] = 1;
	pile->b_char = (char **)malloc(sizeof(char *) * (pile->size_tab + 1));
	if (!pile->b_char)
		ft_error(pile, "Error malloc\n");
	i = -1;
	while (++i <= pile->size_tab)
		pile->b_char[i] = 0;
	pile->alloue[4] = 1;
}

void	initialize_pile(t_pile *pile, int j, int argc, char **argv)
{
	int		i;
	char	**spl;

	pile->j = 0;
	pile->to_print = NULL;
	while (++j < 6)
		pile->alloue[j] = 0;
	if (argc == 1)
		exit(EXIT_SUCCESS);
	i = 0;
	if (argc == 2)
	{
		spl = ft_split(pile, argv[1], ' ');
		i = -1;
		while (spl[++i])
			check_form(pile, spl, i);
		init_a_b(pile, spl, i, 1);
		ft_free_tab(spl, -2);
	}
	else
	{
		while (argv[++i])
			check_form(pile, argv, i);
		init_a_b(pile, argv, i, 0);
	}
}

int	main(int argc, char **argv)
{
	t_pile	pile;
	int		j;

	j = -1;
	initialize_pile(&pile, j, argc, argv);
	if (already_sort(&pile) == 1)
	{
		if (pile.to_print != NULL)
			print_instruction(&pile, pile.to_print);
		ft_free(&pile);
		exit(EXIT_SUCCESS);
	}
	if (pile.size_tab < 6)
		short_sort(&pile, pile.size_tab);
	else
		ft_radix(&pile);
	if (pile.to_print != NULL)
		print_instruction(&pile, pile.to_print);
	ft_free(&pile);
	exit(EXIT_SUCCESS);
}
