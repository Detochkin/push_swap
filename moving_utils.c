/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dirony <dirony@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 15:25:46 by dirony            #+#    #+#             */
/*   Updated: 2022/01/11 15:26:17 by dirony           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_optimal_from_b(t_data *data, t_stack *iter, int i)
{
	while (i < ft_abs(iter->b_score))
	{
		if (iter->b_score > 0)
		{	
			if (iter->a_score > 0)
			{
				rr(data);
				iter->a_score--;
			}
			else
				rb(data);
		}
		else
		{	
			if (iter->a_score < 0)
			{
				rrr(data);
				iter->a_score++;
			}
			else
				rrb(data);
		}
		i++;
	}
}

void	move_optimal_elem_to_a(t_data *data)
{
	t_stack	*iter;
	int		i;

	iter = get_optimal_elem(data);
	i = 0;
	move_optimal_from_b(data, iter, i);
	while (i < ft_abs(iter->a_score))
	{
		if (iter->a_score > 0)
			ra(data);
		else
			rra(data);
		i++;
	}
	pa(data);
}
