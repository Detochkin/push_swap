/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dirony <dirony@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:16:40 by dirony            #+#    #+#             */
/*   Updated: 2022/01/10 21:34:52 by dirony           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_to_b(t_data *data)
{
	while (data->a_size > 3 && !is_only_lis_left(data->a))
	{
		if (data->a->is_in_lis == 0)
		{
			if (data->a->value < data->mid)
				pb(data);
			else
			{
				pb(data);
				rb(data);
			}
		}
		else
			ra(data);
	}
	if (data->a_size == 3)
		sort_three_elements_a(data);
}

static int	find_final_rotation(t_data *data)
{
	t_stack	*iter;
	int		i;
	int		min;
	int		size;
	int		flag;

	iter = data->a;
	i = 0;
	flag = 0;
	min = iter->value;
	size = ft_lstsize(data->a);
	while (iter && !flag)
	{
		if (iter->value < min)
		{
			min = iter->value;
			flag = 1;
		}
		iter = iter->next;
		i++;
	}
	if (--i <= size / 2)
		return (i);
	else
		return (-size + i);
}

void	rotate_a_to_final(t_data *data)
{
	int	i;

	i = find_final_rotation(data);
	if (i > 0)
	{
		while (i)
		{
			ra(data);
			i--;
		}
	}
	else
	{
		i = ft_abs(i);
		while (i)
		{
			rra(data);
			i--;
		}
	}
}
