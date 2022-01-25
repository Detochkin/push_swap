/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dirony <dirony@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 19:04:05 by dirony            #+#    #+#             */
/*   Updated: 2022/01/14 20:34:36 by dirony           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>

# define BUFFER_SIZE 100000

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

int			get_next_line(int fd, char **line);
size_t		ft_strlcpy(char *dest, const char *src, size_t size);
char		*ft_strdup(const char *str);
int			ft_strcmp(const char *s1, const char *s2);

t_stack		*ft_lstnew(char *str);
t_stack		*add_from_split_to_list(char *arg, t_stack **list);
void		ft_lstadd_back(t_stack **list, t_stack *new_elem);
int			ft_lstsize(t_stack *list);
int			check_value(char *str);
int			check_repetition(long long *array, int i);
int			check_arguments(int argc, char **argv, t_data *data);
void		print_stack_error(void);
int			ft_lstclear(t_stack **list);

char		**read_commands(void);
void		parse_and_exec_cmd(char *cmd, t_data *data);
int			check_cmd(char *cmd);
int			check_cmd_2(char *cmd);
int			is_sorted(t_stack *a);

void		swap(t_stack *a);
void		push(t_stack **a, t_stack **b);
void		rotate(t_stack **a);
void		reverse_rotate(t_stack **a);

void		sa(t_data *data);
void		sb(t_data *data);
void		ss(t_data *data);
void		pa(t_data *data);
void		pb(t_data *data);

void		ra(t_data *data);
void		rb(t_data *data);
void		rr(t_data *data);
void		rra(t_data *data);
void		rrb(t_data *data);
void		rrr(t_data *data);

#endif