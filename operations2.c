/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dirony <dirony@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:57:53 by dirony            #+#    #+#             */
/*   Updated: 2022/01/10 21:30:50 by dirony           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_data *data)
{
	rotate(&data->a);
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_data *data)
{
	rotate(&data->b);
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_data *data)
{
	rotate(&data->a);
	rotate(&data->b);
	ft_putstr_fd("rr\n", 1);
}

void	rra(t_data *data)
{
	reverse_rotate(&data->a);
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_data *data)
{
	reverse_rotate(&data->b);
	ft_putstr_fd("rrb\n", 1);
}
