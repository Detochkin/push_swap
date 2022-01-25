/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dirony <dirony@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 19:04:05 by dirony            #+#    #+#             */
/*   Updated: 2022/01/15 13:19:54 by dirony           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_stack
{
	int				value;
	int				b_score;
	int				a_score;
	int				lis_score;
	int				is_in_lis;
	struct s_stack	*next;
}	t_stack;

typedef struct s_data
{
	int			argc;
	int			a_size;
	int			b_size;
	t_stack		*a;
	t_stack		*b;
	int			mid;
	int			min;
	int			max;
}	t_data;

int			ft_isdigit(char ch);
long long	ft_atoi(const char *str);
int			ft_abs(int n);
int			ft_max(int a, int b);
size_t		ft_strlen(const char *str);
char		*ft_strchr(char *str, char ch);
int			ft_putstr_fd(char *s, int fd);
char		**ft_split(char const *s, char ch);
int			count_words(char const *s, char ch);
void		free_string(char **argv);

t_stack		*ft_lstnew(char *str);
void		ft_lstadd_back(t_stack **list, t_stack *new_elem);
int			ft_lstsize(t_stack *list);
int			check_value(char *str);
int			check_repetition(long long *array, int i);
int			check_arguments(int argc, char **argv, t_data *data);
void		print_stack_error(void);
int			ft_lstclear(t_stack **list);

t_stack		*add_from_split_to_list(char *arg, t_stack **list);
t_stack		*add_argv_to_list(char **argv);
int			*put_stack_to_array(t_stack **a, t_data *data);
void		sort_array(int **array, t_data *data);
int			is_sorted(t_stack *a);
int			is_half_sorted(t_stack *a);
int			find_current_max(t_data *data);
int			find_current_min(t_data *data);

void		move_to_b(t_data *data);
void		sort_mini_algo(t_data *data);
void		sort_common_algo(t_data *data);

int			*shift_max_to_end(int *array, t_data *data);
void		get_lis_scores(int *array, t_data *data);
void		put_lis_scores(t_data *data, int *lis);
int			find_max_lis_score(t_stack *a);
void		put_lis_tags(t_data *data);
int			is_only_lis_left(t_stack *a);

void		put_b_scores(t_data *data);
void		put_a_scores(t_data *data);
t_stack		*get_optimal_elem(t_data *data);
void		move_optimal_elem_to_a(t_data *data);
void		rotate_a_to_final(t_data *data);

int			sort_three_elements_a(t_data *data);
int			sort_two_elements_b(t_data *data);
void		sort_less_than_six(t_data *data);

int			find_current_max(t_data *data);
int			find_current_min(t_data *data);
int			find_next_max_position(t_data *data);
int			find_next_min_position(t_data *data);

void		swap(t_stack *a);
void		push(t_stack **a, t_stack **b);
void		rotate(t_stack **a);
void		reverse_rotate(t_stack **a);

void		sa(t_data *data);
void		sb(t_data *data);
void		pa(t_data *data);
void		pb(t_data *data);

void		ra(t_data *data);
void		rb(t_data *data);
void		rr(t_data *data);
void		rra(t_data *data);
void		rrb(t_data *data);
void		rrr(t_data *data);

#endif