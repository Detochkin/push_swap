/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils2_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dirony <dirony@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 21:11:08 by dirony            #+#    #+#             */
/*   Updated: 2022/01/12 21:51:48 by dirony           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	check_first_arg(char *arg)
{
	char		**argv;
	int			i;
	long long	*array;
	int			result;

	result = 1;
	argv = ft_split(arg, ' ');
	array = malloc(sizeof(long long) * count_words(arg, ' '));
	if (NULL == array)
		exit(EXIT_FAILURE);
	i = -1;
	while (++i < count_words(arg, ' '))
	{
		if (check_value(argv[i]))
			array[i] = ft_atoi(argv[i]);
		else
			result = 0;
		if (array[i] < INT_MIN || array[i] > INT_MAX)
			result = 0;
		if (check_repetition(array, i) == 0)
			result = 0;
	}
	free(array);
	free_string(argv);
	return (result);
}

int	add_args_to_array(char *arg, long long *array, int k)
{
	char	**argv;
	int		i;

	argv = ft_split(arg, ' ');
	i = 0;
	while (argv[i])
	{
		array[k + i] = ft_atoi(argv[i]);
		i++;
	}
	free_string(argv);
	return (i);
}

static int	check_every_word(t_data *data, char **argv, int i, long long *array)
{
	int			result;
	int			temp;
	int			k;

	k = 0;
	result = 1;
	while (k < data->argc && result)
	{
		temp = k;
		k += add_args_to_array(argv[i], array, k);
		while (temp < k)
		{
			if (array[temp] < INT_MIN || array[temp] > INT_MAX)
				result = 0;
			if (check_repetition(array, temp) == 0)
				result = 0;
			temp++;
		}
		i++;
	}
	free(array);
	return (result);
}

int	check_arguments(int argc, char **argv, t_data *data)
{
	int			result;
	int			i;
	long long	*array;

	result = 1;
	i = 1;
	data->argc = 0;
	while (i < argc)
	{
		data->argc += count_words(argv[i], ' ');
		if (check_first_arg(argv[i]) == 0 || *argv[i] == '\0')
			return (0);
		i++;
	}
	array = malloc(sizeof(long long) * data->argc);
	if (NULL == array)
		exit(EXIT_FAILURE);
	return (check_every_word(data, argv, 1, array));
}
