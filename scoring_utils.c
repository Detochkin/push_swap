/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scoring_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dirony <dirony@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 20:18:12 by dirony            #+#    #+#             */
/*   Updated: 2022/01/11 15:30:21 by dirony           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_b_scores(t_data *data)
{
	t_stack	*iter;
	int		i;
	int		size;

	iter = data->b;
	size = ft_lstsize(data->b);
	i = 0;
	while (i < size)
	{
		if (i <= size / 2)
			iter->b_score = i;
		else
			iter->b_score = - (size - i);
		iter = iter->next;
		i++;
	}	
}

static int	get_a_score(t_data *data, int value)
{
	t_stack	*iter;
	int		i;
	int		size;
	int		flag;

	iter = data->a;
	flag = 0;
	size = ft_lstsize(data->a);
	i = 1;
	if (value < find_current_min(data))
		return (find_next_min_position(data));
	if (value > find_current_max(data))
		return (find_next_max_position(data));
	while (iter->next && !flag)
	{
		if (iter->value < value && iter->next->value > value)
			return (i);
		iter = iter->next;
		i++;
	}
	return (0);
}

void	put_a_scores(t_data *data)
{
	t_stack	*iter;
	int		a_score;
	int		size;

	iter = data->b;
	size = ft_lstsize(data->a);
	while (iter)
	{
		a_score = get_a_score(data, iter->value);
		if (a_score <= size / 2)
			iter->a_score = a_score;
		else
			iter->a_score = - (size - a_score);
		iter = iter->next;
	}	
}

t_stack	*get_optimal_elem(t_data *data)
{
	t_stack	*iter;
	t_stack	*result;
	int		min_score;
	int		temp;

	iter = data->b;
	result = iter;
	min_score = ft_abs(iter->b_score) + ft_abs(iter->a_score);
	temp = min_score;
	while (iter)
	{
		iter = iter->next;
		if (iter)
			temp = ft_abs(iter->b_score) + ft_abs(iter->a_score);
		if (temp < min_score)
		{
			min_score = temp;
			result = iter;
		}
	}
	return (result);
}
