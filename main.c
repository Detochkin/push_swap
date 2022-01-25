/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dirony <dirony@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 19:03:35 by dirony            #+#    #+#             */
/*   Updated: 2022/01/15 13:17:50 by dirony           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*add_argv_to_list(char **argv)
{
	int		i;
	t_stack	*list;

	i = 0;
	list = NULL;
	while (argv[i])
	{
		add_from_split_to_list(argv[i], &list);
		i++;
	}
	return (list);
}

void	sort_mini_algo(t_data *data)
{
	while (data->a_size > 3 && !is_half_sorted(data->a))
		pb(data);
	if (data->a_size <= 3)
		sort_three_elements_a(data);
	sort_two_elements_b(data);
	while (data->b_size > 0)
	{
		put_b_scores(data);
		put_a_scores(data);
		move_optimal_elem_to_a(data);
	}
}

void	sort_common_algo(t_data *data)
{
	move_to_b(data);
	while (data->b_size > 0)
	{
		put_b_scores(data);
		put_a_scores(data);
		move_optimal_elem_to_a(data);
	}
}

int	main(int argc, char **argv)
{
	int		*array;
	t_data	data;

	if (!check_arguments(argc, argv, &data))
		return (ft_putstr_fd("Error\n", 2));
	data.a = add_argv_to_list(&argv[1]);
	data.a_size = ft_lstsize(data.a);
	if (data.argc < 2)
		return (ft_lstclear(&data.a));
	data.b = NULL;
	data.b_size = 0;
	array = put_stack_to_array(&data.a, &data);
	get_lis_scores(array, &data);
	put_lis_tags(&data);
	sort_array(&array, &data);
	if (data.a_size <= 5)
		sort_mini_algo(&data);
	else
		sort_common_algo(&data);
	if (!is_sorted(data.a))
		rotate_a_to_final(&data);
	free(array);
	return (ft_lstclear(&data.a));
}
