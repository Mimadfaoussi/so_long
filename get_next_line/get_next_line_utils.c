/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 09:42:39 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/03/02 17:15:09 by mfaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

void	append(t_list **head, char *buffer)
{
	t_list	*node;
	t_list	*index;

	if (!buffer)
		return ;
	node = malloc(sizeof(t_list));
	if (!node)
	{
		free(buffer);
		return ;
	}
	node->text = buffer;
	node->next = NULL;
	if (!*head)
		*head = node;
	else
	{
		index = *head;
		while (index->next)
			index = index->next;
		index->next = node;
	}
}

t_list	*find_last_node(t_list *head)
{
	t_list	*index;

	if (!head)
		return (NULL);
	index = head;
	while (index->next)
		index = index->next;
	return (index);
}

int	include_newline(t_list *head)
{
	t_list	*index;
	int		i;

	if (!head)
		return (0);
	index = head;
	while (index)
	{
		i = 0;
		while (index->text[i])
		{
			if (index->text[i] == '\n')
				return (1);
			i++;
		}
		index = index->next;
	}
	return (0);
}

void	copy_line(char *next_line, t_list *head)
{
	t_list	*index;
	int		i;
	int		j;

	if (!head)
		return ;
	j = 0;
	index = head;
	while (index)
	{
		i = 0;
		while (index->text[i])
		{
			next_line[j] = index->text[i];
			j++;
			if (index->text[i] == '\n')
			{
				next_line[j] = '\0';
				return ;
			}
			i++;
		}
		index = index->next;
	}
	next_line[j] = '\0';
}

void	free_all(t_list **head, char *buffer)
{
	t_list	*index;
	t_list	*node;

	index = *head;
	while (index)
	{
		*head = (*head)->next;
		free(index->text);
		free(index);
		index = *head;
	}
	if (buffer == NULL)
		return ;
	node = malloc(sizeof(t_list));
	if (!node)
		return ;
	node->text = buffer;
	node->next = NULL;
	if (buffer[0])
		*head = node;
	else
	{
		free(buffer);
		free(node);
	}
}
