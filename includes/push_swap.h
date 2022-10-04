/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssar <ssar@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 14:14:53 by ssar              #+#    #+#             */
/*   Updated: 2021/08/06 17:10:15 by ssar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int				rank;
	int				value;
	int				new_value;
	struct s_list	*next;
}				t_list;

typedef struct s_print
{
	int				place;
	char			*instruction;
	struct s_print	*next;
}				t_print;

typedef struct s_pile
{
	t_print			*to_print;
	int				*stock_a;
	int				j;
	unsigned int	*a;
	unsigned int	*b;
	char			**a_char;
	char			**b_char;
	int				alloue[6];
	int				a_vide;
	int				b_vide;
	int				pos_a;
	int				pos_b;
	int				size_tab;
	int				add;
	unsigned int	highter;
	int				max_len;
	int				pivot;
	unsigned int	min;
	unsigned int	max;
}				t_pile;

void			ft_error(t_pile *pile, char *str);
long long		ft_atoi(const char *str);
int				ft_len(char *str);
int				ft_in(char *str, char c);
int				ft_comp(char *s1, char *s2);
int				check_form(t_pile *pile, char **str, int i);
void			init_a_b(t_pile *pile, char **str, int i, int p);
void			launch_instruction(t_pile *pile, char *str);
int				apply_swap(t_pile *pile, unsigned int *tab, int top);
void			apply_push(t_pile *p, unsigned int *s, unsigned int *d, int *w);
void			apply_rotate(t_pile *pile, unsigned int *tab, int top);
void			apply_reverse_rotate(t_pile *pile, unsigned int *tab, int top);
char			**ft_free_tab(char **tab, int nb);
char			**ft_split(t_pile *pile, char const *s, char c);
void			ft_lstadd_back(t_list **alst, t_list *new_lst);
void			ft_free_lst(t_list **lst);
t_list			*ft_lstlast(t_list *lst);
unsigned int	get_val_neg(t_pile *pile, t_list *neg, int i);
t_list			*create_new_neg(t_pile *pile, int i, int val, t_list *del);
char			*ft_itoa(unsigned int n);
char			*conv_b(t_pile *pile, char *nbr, char *bf, char *bt);
void			ft_radix(t_pile *pile);
void			medium_sort(t_pile *pile);
t_print			*ft_lstlast_pr(t_print *lst);
t_print			*get_at_pos(t_pile *pile, t_print *lst, int i);
t_print			*create_new_pr(t_pile *pile, int i, char *inst);
void			ft_free_lst_pr(t_print **lst);
void			ft_lstadd_back_pr(t_print **alst, t_print *new_lst);
void			add_to_print(t_pile *pile, char *inst);
void			print_instruction(t_pile *pile, t_print *lst);
void			short_sort(t_pile *pile, int nb);
int				already_sort(t_pile *pile);
t_list			*transform_pos(t_pile *pile, t_list *neg);
t_list			*transform_neg(t_pile *pile);
int				replace_neg_val(t_pile *pile, t_list *neg);
void			replace_pos_val(t_pile *pile, t_list *pos);

#endif
