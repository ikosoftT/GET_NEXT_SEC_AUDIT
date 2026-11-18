/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoograme <yoograme@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 13:58:09 by yoograme          #+#    #+#             */
/*   Updated: 2026/11/18 16:52:36 by yoograme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static void	*ft_free_bonus(char *str, char *buffer)
{
	free(str);
	free(buffer);
	return (NULL);
}

char	*free_node(t_list **head, t_list *node)
{
	t_list	*trav;

	if (*head == node)
		*head = node->next;
	else
	{
		trav = *head;
		while (trav->next && trav->next != node)
			trav = trav->next;
		trav->next = node->next;
	}
	free(node->stash);
	free(node);
	return (NULL);
}

char	*ft_read_bonus(int fd, char *str)
{
	ssize_t		not;
	char		*buffer;
	char		*temp;

	not = 1;
	buffer = malloc((size_t)BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	buffer[0] = '\0';
	while (!ft_strchr_bonus(buffer, '\n') && not > 0)
	{
		not = read(fd, buffer, BUFFER_SIZE);
		if (not < 0)
			return (ft_free_bonus(str, buffer));
		if (not == 0)
			break ;
		buffer[not] = '\0';
		temp = ft_strjoin_bonus(str, buffer);
		if (!temp)
			return (ft_free_bonus(str, buffer));
		str = temp;
	}
	free(buffer);
	return (str);
}

t_list	*new_fd(t_list **head, int fd)
{
	t_list	*new;
	t_list	*trav;

	new = *head;
	while (new)
	{
		if (new->fd == fd)
			return (new);
		new = new->next;
	}
	trav = malloc(sizeof(t_list));
	if (!trav)
		return (NULL);
	trav->fd = fd;
	trav->stash = NULL;
	trav->next = *head;
	*head = trav;
	return (trav);
}

char	*get_next_line(int fd)
{
	t_list			*node;
	static t_list	*head;
	char			*result;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	node = new_fd(&head, fd);
	if (!node)
		return (NULL);
	node->stash = ft_read_bonus(fd, node->stash);
	if (!node->stash || !*node->stash)
		return (free_node(&head, node));
	result = buffer_new_line_bonus(node->stash);
	if (!result)
		return (free_node(&head, node));
	node->stash = after_new_line_bonus(node ->stash);
	return (result);
}
