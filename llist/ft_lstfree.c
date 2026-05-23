/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cascrizz <cascrizz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 16:17:19 by cascrizz          #+#    #+#             */
/*   Updated: 2026/02/27 16:17:19 by cascrizz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	ft_lstmin(t_list *lst)
{
	int	min;

	if (!lst)
		return (0);
	min = *(int *)lst->content;
	while (lst)
	{
		if (*(int *)lst->content < min)
			min = *(int *)lst->content;
		lst = lst->next;
	}
	return (min);
}
