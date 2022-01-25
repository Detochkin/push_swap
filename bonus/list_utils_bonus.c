/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dirony <dirony@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 19:45:15 by dirony            #+#    #+#             */
/*   Updated: 2022/01/11 20:32:17 by dirony           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_lstclear(t_stack **list)
{
	t_stack	*temp;
	t_stack	*iter;

	iter = *list;
	while (iter)
	{
		temp = iter->next;
		free(iter);
		iter = temp;
	}
	*list = NULL;
	return (0);
}

void	ft_lstadd_back(t_stack **list, t_stack *new_elem)
{
	t_stack	*iter;

	iter = *list;
	if (*list)
	{
		while (iter->next)
			iter = iter->next;
		iter->next = new_elem;
	}
	else
		*list = new_elem;
}

t_stack	*ft_lstnew(char *str)
{
	t_stack	*new_elem;

	if (!check_value(str))
		return (NULL);
	new_elem = malloc(sizeof(t_stack));
	if (NULL == new_elem)
		return (NULL);
	new_elem->next = NULL;
	new_elem->value = ft_atoi(str);
	new_elem->a_score = 0;
	new_elem->b_score = 0;
	new_elem->lis_score = 0;
	new_elem->is_in_lis = 0;
	return (new_elem);
}

t_stack	*add_from_split_to_list(char *arg, t_stack **list)
{
	int		i;
	t_stack	*new_elem;
	char	**argv;

	argv = ft_split(arg, ' ');
	i = 0;
	while (i < count_words(arg, ' '))
	{
		new_elem = ft_lstnew(argv[i]);
		if (new_elem)
			ft_lstadd_back(list, new_elem);
		else
		{
			ft_lstclear(list);
			return (NULL);
		}
		i++;
	}
	free_string(argv);
	return (*list);
}

int	ft_lstsize(t_stack *list)
{
	int	count;

	count = 0;
	while (list)
	{
		count++;
		list = list->next;
	}
	return (count);
}
