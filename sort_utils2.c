/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dirony <dirony@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 20:01:48 by dirony            #+#    #+#             */
/*   Updated: 2022/01/10 21:34:00 by dirony           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *a)
{
	int		result;
	t_stack	*temp;

	result = 1;
	if (!a)
		return (1);
	while (a->next)
	{
		temp = a->next;
		if (a->value > temp->value)
			result = 0;
		a = a->next;
	}
	return (result);
}

int	find_current_max(t_data *data)
{
	int		temp;
	t_stack	*iter;

	iter = data->a;
	temp = iter->value;
	while (iter)
	{
		if (iter->value > temp)
			temp = iter->value;
		iter = iter->next;
	}
	return (temp);
}

int	find_current_min(t_data *data)
{
	int		temp;
	t_stack	*iter;

	iter = data->a;
	temp = iter->value;
	while (iter)
	{
		if (iter->value < temp)
			temp = iter->value;
		iter = iter->next;
	}
	return (temp);
}

int	find_next_max_position(t_data *data)
{
	int		i;
	int		temp;
	t_stack	*iter;

	i = 1;
	iter = data->a;
	temp = find_current_max(data);
	while (iter)
	{
		if (iter->value == temp)
			return (i);
		i++;
		iter = iter->next;
	}
	return (i - 1);
}

int	find_next_min_position(t_data *data)
{
	int		i;
	int		temp;
	t_stack	*iter;

	i = 0;
	iter = data->a;
	temp = find_current_min(data);
	while (iter)
	{
		if (iter->value == temp)
			return (i);
		i++;
		iter = iter->next;
	}
	return (i - 1);
}
