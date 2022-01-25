/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dirony <dirony@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 19:03:35 by dirony            #+#    #+#             */
/*   Updated: 2022/01/14 20:28:08 by dirony           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

int	is_sorted(t_stack *a)
{
	int		result;
	t_stack	*temp;

	result = 1;
	if (!a)
		return (1);
	while (a->next)
	{
		temp = a->next;
		if (a->value > temp->value)
			result = 0;
		a = a->next;
	}
	return (result);
}

int	exec_commands(char **cmd, t_data *data)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		if (!check_cmd(cmd[i]))
			return (0);
		i++;
	}
	i = 0;
	while (cmd[i])
	{
		parse_and_exec_cmd(cmd[i], data);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	data;
	char	**cmd;

	if (argc < 2)
		return (0);
	if (!check_arguments(argc, argv, &data))
		return (ft_putstr_fd("Error\n", 2));
	data.a = add_argv_to_list(&argv[1]);
	data.a_size = ft_lstsize(data.a);
	if (data.argc < 2)
		return (ft_lstclear(&data.a));
	data.b = NULL;
	data.b_size = 0;
	cmd = read_commands();
	if (exec_commands(cmd, &data))
	{
		if (is_sorted(data.a) && data.b_size == 0)
			ft_putstr_fd("OK\n", 1);
		else
			ft_putstr_fd("KO\n", 1);
	}
	else
		ft_putstr_fd("Error\n", 2);
	free_string(cmd);
	return (ft_lstclear(&data.a));
}
