/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dirony <dirony@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:31:44 by dirony            #+#    #+#             */
/*   Updated: 2022/01/11 21:27:02 by dirony           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_data *data)
{
	swap(data->a);
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_data *data)
{
	swap(data->b);
	ft_putstr_fd("sb\n", 1);
}

void	pa(t_data *data)
{
	push(&(data->a), &(data->b));
	data->a_size++;
	data->b_size--;
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_data *data)
{
	push(&(data->b), &(data->a));
	data->b_size++;
	data->a_size--;
	ft_putstr_fd("pb\n", 1);
}
