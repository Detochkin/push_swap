/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dirony <dirony@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:57:53 by dirony            #+#    #+#             */
/*   Updated: 2022/01/12 19:43:11 by dirony           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ra(t_data *data)
{
	rotate(&data->a);
}

void	rb(t_data *data)
{
	rotate(&data->b);
}

void	rr(t_data *data)
{
	rotate(&data->a);
	rotate(&data->b);
}

void	rra(t_data *data)
{
	reverse_rotate(&data->a);
}

void	rrb(t_data *data)
{
	reverse_rotate(&data->b);
}
