/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dirony <dirony@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 16:05:23 by dirony            #+#    #+#             */
/*   Updated: 2022/01/15 13:14:16 by dirony           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_putstr_fd(char *s, int fd)
{
	if (s)
		write(fd, s, ft_strlen(s));
	return (0);
}

int	check_value(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	if (!ft_isdigit(str[i]))
		return (0);
	while (ft_isdigit(str[i]))
		i++;
	if (str[i] == ' ' || str[i] == '\0')
		return (1);
	else
		return (0);
}

int	check_repetition(long long *array, int i)
{
	int	j;
	int	result;

	result = 1;
	j = 0;
	while (j < i)
	{
		if (array[j] == array[i])
			result = 0;
		j++;
	}
	return (result);
}

void	free_string(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}
