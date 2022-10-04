/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssar <ssar@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 09:29:54 by ssar              #+#    #+#             */
/*   Updated: 2021/08/06 11:12:14 by ssar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_lstadd_back(t_list **alst, t_list *new_lst)
{
	t_list	*temp;

	if (!new_lst)
		return ;
	if (!*alst)
	{
		*alst = new_lst;
		return ;
	}
	temp = ft_lstlast(*alst);
	temp->next = new_lst;
}

void	ft_free_lst(t_list **lst)
{
	t_list	*temp_lst;

	if (!(*lst))
		return ;
	while (*lst)
	{
		temp_lst = (*lst)->next;
		free(*lst);
		*lst = temp_lst;
	}
	lst = 0;
}

t_list	*create_new_neg(t_pile *pile, int i, int val, t_list *del)
{
	t_list	*neg;

	neg = (t_list *)malloc(sizeof(t_list));
	if (!neg)
	{
		if (del != NULL)
			ft_free_lst(&del);
		ft_free_lst(&neg);
		ft_error(pile, "Error malloc lst\n");
	}
	neg->rank = i;
	neg->value = val;
	neg->next = NULL;
	return (neg);
}

unsigned int	get_val_neg(t_pile *pile, t_list *neg, int i)
{
	t_list			*stock;
	unsigned int	res;

	stock = neg;
	while (neg->rank != i)
	{
		if (neg->next == NULL)
			break ;
		else
			neg = neg->next;
	}
	if (neg->rank != i)
	{
		neg = stock;
		ft_free_lst(&neg);
		ft_error(pile, "convert unsigned int failed\n");
	}
	res = neg->new_value;
	neg = stock;
	return (res);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
