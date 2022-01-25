/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dirony <dirony@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:31:44 by dirony            #+#    #+#             */
/*   Updated: 2022/01/12 18:35:28 by dirony           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	sa(t_data *data)
{
	swap(data->a);
}

void	sb(t_data *data)
{
	swap(data->b);
}

void	ss(t_data *data)
{
	sa(data);
	sb(data);
}

void	pa(t_data *data)
{
	push(&data->a, &data->b);
	data->a_size++;
	data->b_size--;
}

void	pb(t_data *data)
{
	push(&data->b, &data->a);
	data->b_size++;
	data->a_size--;
}
