/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dirony <dirony@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 22:20:55 by dirony            #+#    #+#             */
/*   Updated: 2022/01/14 20:28:36 by dirony           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

char	**read_commands(void)
{
	char	**result;
	int		i;
	int		rd;

	result = malloc(sizeof(char *) * BUFFER_SIZE);
	i = 0;
	rd = 1;
	while (rd)
	{
		result[i] = malloc(BUFFER_SIZE + 1);
		if (NULL == result)
			exit(EXIT_FAILURE);
		rd = get_next_line(0, &result[i]);
		i++;
	}
	return (result);
}

int	check_cmd_2(char *cmd)
{
	int	result;

	result = 0;
	if (ft_strcmp(cmd, "ra") == 0)
		result = 1;
	if (ft_strcmp(cmd, "rb") == 0)
		result = 1;
	if (ft_strcmp(cmd, "rr") == 0)
		result = 1;
	if (ft_strcmp(cmd, "rra") == 0)
		result = 1;
	if (ft_strcmp(cmd, "rrb") == 0)
		result = 1;
	if (ft_strcmp(cmd, "rrr") == 0)
		result = 1;
	return (result);
}

int	check_cmd(char *cmd)
{
	int	result;

	if (!cmd)
		return (0);
	result = 0;
	if (ft_strcmp(cmd, "sa") == 0)
		result = 1;
	if (ft_strcmp(cmd, "sb") == 0)
		result = 1;
	if (ft_strcmp(cmd, "ss") == 0)
		result = 1;
	if (ft_strcmp(cmd, "pa") == 0)
		result = 1;
	if (ft_strcmp(cmd, "pb") == 0)
		result = 1;
	if (check_cmd_2(cmd))
		result = 1;
	return (result);
}

void	parse_and_exec_cmd(char *cmd, t_data *data)
{
	if (ft_strcmp(cmd, "sa") == 0)
		sa(data);
	if (ft_strcmp(cmd, "sb") == 0)
		sb(data);
	if (ft_strcmp(cmd, "ss") == 0)
		ss(data);
	if (ft_strcmp(cmd, "pa") == 0)
		pa(data);
	if (ft_strcmp(cmd, "pb") == 0)
		pb(data);
	if (ft_strcmp(cmd, "ra") == 0)
		ra(data);
	if (ft_strcmp(cmd, "rb") == 0)
		rb(data);
	if (ft_strcmp(cmd, "rr") == 0)
		rr(data);
	if (ft_strcmp(cmd, "rra") == 0)
		rra(data);
	if (ft_strcmp(cmd, "rrb") == 0)
		rrb(data);
	if (ft_strcmp(cmd, "rrr") == 0)
		rrr(data);
}
