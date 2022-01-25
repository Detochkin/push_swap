/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dirony <dirony@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 13:41:37 by dirony            #+#    #+#             */
/*   Updated: 2022/01/11 22:05:39 by dirony           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *a)
{
	t_stack	*iter;
	int		temp;

	iter = a->next;
	if (iter)
	{
		temp = a->value;
		a->value = iter->value;
		iter->value = temp;
	}
}

void	rotate(t_stack **a)
{
	t_stack	*iter;
	t_stack	*temp;

	if (*a)
	{
		iter = (*a)->next;
		while (iter && iter->next)
			iter = iter->next;
		temp = (*a)->next;
		if (temp && iter)
		{
			iter->next = *a;
			(*a)->next = NULL;
			*a = temp;
		}
	}
}

void	reverse_rotate(t_stack **a)
{
	t_stack	*iter;
	t_stack	*temp;

	if (*a)
	{
		iter = *a;
		while (iter && iter->next)
		{
			temp = iter;
			iter = iter->next;
		}
		if (temp && iter)
		{
			iter->next = *a;
			temp->next = NULL;
			*a = iter;
		}
	}
}

void	push(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (*b)
	{
		temp = (*b)->next;
		(*b)->next = *a;
		*a = *b;
		*b = temp;
	}
}

void	rrr(t_data *data)
{
	reverse_rotate(&data->a);
	reverse_rotate(&data->b);
	ft_putstr_fd("rrr\n", 1);
}
