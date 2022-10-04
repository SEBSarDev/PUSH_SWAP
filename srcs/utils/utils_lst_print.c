/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lst_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssar <ssar@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 18:42:36 by ssar              #+#    #+#             */
/*   Updated: 2021/08/23 10:30:00 by ssar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_lstadd_back_pr(t_print **alst, t_print *new_lst)
{
	t_print	*temp;

	if (!new_lst)
		return ;
	if (!*alst)
	{
		*alst = new_lst;
		return ;
	}
	temp = ft_lstlast_pr(*alst);
	temp->next = new_lst;
}

void	ft_free_lst_pr(t_print **lst)
{
	t_print	*temp_lst;

	if (!(*lst))
		return ;
	while (*lst)
	{
		temp_lst = (*lst)->next;
		free((*lst)->instruction);
		free(*lst);
		*lst = temp_lst;
	}
	lst = 0;
}

t_print	*create_new_pr(t_pile *pile, int i, char *inst)
{
	t_print	*print;
	int		j;

	j = -1;
	print = (t_print *)malloc(sizeof(t_print));
	if (!print)
		ft_error(pile, "Error malloc lst\n");
	print->place = i;
	print->instruction = (char *)malloc(sizeof(char) * (ft_len(inst) + 1));
	if (!print->instruction)
		ft_error(pile, "Error malloc\n");
	while (++j < ft_len(inst))
		print->instruction[j] = inst[j];
	print->instruction[j] = '\0';
	print->next = NULL;
	return (print);
}

t_print	*get_at_pos(t_pile *pile, t_print *lst, int i)
{
	if (!lst)
		return (0);
	while (lst->place != i && lst->next != NULL)
		lst = lst->next;
	if (lst->next == NULL && lst->place != i)
		ft_error(pile, "Place in print doesn't exist\n");
	return (lst);
}

t_print	*ft_lstlast_pr(t_print *lst)
{
	if (!lst)
		return (0);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
