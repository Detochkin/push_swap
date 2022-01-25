/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dirony <dirony@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 20:16:18 by dirony            #+#    #+#             */
/*   Updated: 2022/01/10 21:32:44 by dirony           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_rest_of_stack(t_stack *a, t_stack *iter, int min)
{
	int		flag;
	t_stack	*temp;

	flag = 1;
	while (iter->next && flag)
	{
		temp = iter->next;
		if (iter->value > temp->value)
			flag = 0;
		iter = iter->next;
	}
	if (flag == 0 || min > a->value || a->value < iter->value)
		return (0);
	iter = a;
	while (iter->next && flag)
	{
		temp = iter->next;
		if (iter->value > temp->value)
			flag = 0;
		iter = iter->next;
	}
	if (iter->value == min)
		return (1);
	else
		return (0);
}

int	is_half_sorted(t_stack *a)
{
	int		flag;
	int		min;
	int		rotations;
	t_stack	*temp;
	t_stack	*iter;

	flag = 1;
	iter = a;
	rotations = 0;
	if (!iter)
		return (1);
	min = a->value;
	while (iter->next && flag)
	{
		temp = iter->next;
		if (iter->value > temp->value)
			flag = 0;
		iter = iter->next;
		rotations++;
		min = temp->value;
	}
	if (flag)
		return (1);
	return (check_rest_of_stack(a, iter, min));
}

void	find_min_max_mid(t_stack *a, t_data *data)
{
	t_stack	*iter;

	iter = a;
	data->min = a->value;
	while (iter)
	{
		if (data->min > iter->value)
			data->min = iter->value;
		iter = iter->next;
	}
	iter = a;
	data->max = a->value;
	while (iter)
	{
		if (data->max < iter->value)
			data->max = iter->value;
		iter = iter->next;
	}
	iter = a;
	while (iter)
	{
		if (data->min < iter->value && data->max > iter->value)
			data->mid = iter->value;
		iter = iter->next;
	}	
}

int	sort_three_elements_a(t_data *data)
{
	if (data->a_size == 2)
	{
		if (data->a->value > data->a->next->value)
			sa(data);
		return (0);
	}
	find_min_max_mid(data->a, data);
	if (data->a->value == data->max)
		ra(data);
	if (data->a->value == data->mid)
	{
		if (data->a->next->value == data->max)
			rra(data);
		else
			sa(data);
		return (0);
	}
	if (data->a->next->value == data->max)
	{
		rra(data);
		sa(data);
	}
	return (0);
}

int	sort_two_elements_b(t_data *data)
{
	if (data->b_size == 1)
		return (0);
	if (data->b_size == 2)
	{
		if (data->b->value > data->b->next->value)
			sb(data);
		return (0);
	}
	return (0);
}
