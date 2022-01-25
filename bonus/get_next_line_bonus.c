/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dirony <dirony@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 11:39:30 by dirony            #+#    #+#             */
/*   Updated: 2022/01/14 20:26:11 by dirony           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	get_next_line(int fd, char **line)
{
	int		i;
	int		rd;
	char	ch;
	char	*result;

	result = *line;
	rd = read(fd, &ch, 1);
	i = 0;
	while (rd > 0 && ch != '\n')
	{
		result[i++] = ch;
		rd = read(fd, &ch, 1);
	}
	result[i] = '\0';
	*line = result;
	if (rd == 0 && *result == '\0')
	{
		free(result);
		*line = NULL;
	}
	if (rd && check_cmd(result))
		return (rd);
	else
		return (0);
}
