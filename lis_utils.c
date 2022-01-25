/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dirony <dirony@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 19:52:45 by dirony            #+#    #+#             */
/*   Updated: 2022/01/10 21:26:58 by dirony           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_lis_scores(t_data *data, int *lis)
{
	int		i;
	t_stack	*iter;

	i = 0;
	iter = data->a;
	while (iter)
	{
		iter->lis_score = lis[i];
		iter = iter->next;
		i++;
	}
}

void	get_lis_scores(int *array, t_data *data)
{
	int	*lis;
	int	i;
	int	j;

	lis = malloc(sizeof(int) * data->a_size);
	if (NULL == lis)
		exit(EXIT_FAILURE);
	i = data->a_size - 1;
	lis[i] = 1;
	while (i >= 0)
	{
		j = i;
		lis[i] = 1;
		while (j < data->a_size)
		{
			if (array[i] < array[j])
				lis[i] = ft_max(lis[i], lis[j] + 1);
			j++;
		}
		i--;
	}
	i++;
	put_lis_scores(data, lis);
	free(lis);
}

int	find_max_lis_score(t_stack *a)
{
	int	max;

	max = a->lis_score;
	while (a->next)
	{
		if (a->next->lis_score > max)
			max = a->next->lis_score;
		a = a->next;
	}
	return (max);
}

void	put_lis_tags(t_data *data)
{
	int		i;
	t_stack	*iter;

	iter = data->a;
	i = find_max_lis_score(data->a);
	while (iter)
	{
		if (iter->lis_score == i)
		{
			iter->is_in_lis = 1;
			i--;
		}
		iter = iter->next;
	}
}

int	is_only_lis_left(t_stack *a)
{
	int		flag;
	t_stack	*iter;

	flag = 1;
	iter = a;
	while (iter && flag)
	{
		if (iter->is_in_lis == 0)
			flag = 0;
		iter = iter->next;
	}
	return (flag);
}
