/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dirony <dirony@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 21:41:49 by dirony            #+#    #+#             */
/*   Updated: 2022/01/11 17:40:53 by dirony           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*put_stack_to_array(t_stack **a, t_data *data)
{
	int		*result;
	int		i;
	t_stack	*iter;

	result = malloc(sizeof(int) * data->argc);
	if (NULL == result)
		exit(EXIT_FAILURE);
	iter = *a;
	i = 0;
	while (iter)
	{
		result[i] = iter->value;
		iter = iter->next;
		i++;
	}
	get_lis_scores(result, data);
	return (result);
}

void	sort_array(int **array, t_data *data)
{
	int	*arr;
	int	i;
	int	j;
	int	temp;

	arr = *array;
	i = 0;
	while (i < data->a_size)
	{
		j = 0;
		while (j < i)
		{
			if (arr[j] > arr[i])
			{
				temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
			}
			j++;
		}
		i++;
	}
	data->mid = arr[data->a_size / 2];
	data->min = arr[0];
	data->max = arr[data->a_size - 1];
}
