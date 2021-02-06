/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_fc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drissi <drissi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 23:12:03 by kdrissi-          #+#    #+#             */
/*   Updated: 2021/02/06 21:35:20 by drissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"


t_list	*ft_lstlast(t_list *lst)
{
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*last;

	if (alst)
	{
		if (*alst)
		{
			last = ft_lstlast(*alst);
			last->next = new;
		}
		else
			*alst = new;
	}
}
void	ft_lstadd_front(t_list **alst, t_list *new)
{
	if (alst)
	{
		if (*alst)
			new->next = *alst;
		*alst = new;
	}
}

t_list	*ft_lstnew(void *content)
{
	t_list	*elt;

	if (!(elt = (t_list*)malloc(sizeof(*elt))))
		return (NULL);
	elt->content = content;
	
	elt->next = NULL;
	return (elt);
}


void	ft_lst_clear(t_list **lst)
{
	t_list *tmp;
	if(!lst || !*lst)
		return;

	while(lst && *lst)
	{
		tmp = (*lst)->next;
		free(((*lst)->content));
		free(*lst);
		*lst = tmp;
	}
}