/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 09:42:39 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/03/02 01:51:50 by mfaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

char	*get_line_text(t_list *head)
{
	int		size;
	char	*next_line;

	if (!head)
		return (NULL);
	size = get_line_size(head);
	next_line = malloc(size + 1);
	if (!next_line)
		return (NULL);
	copy_line(next_line, head);
	return (next_line);
}

void	create_list(t_list **head, int fd)
{
	char	*buffer;
	int		bytesize;

	while (!include_newline(*head))
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return ;
		bytesize = read(fd, buffer, BUFFER_SIZE);
		if (bytesize <= 0)
		{
			free(buffer);
			return ;
		}
		buffer[bytesize] = '\0';
		append(head, buffer);
	}
}

void	rearrange(t_list **head)
{
	t_list	*last;
	char	*buffer;
	int		i;
	int		j;

	if (!*head)
		return ;
	last = find_last_node(*head);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return ;
	j = 0;
	i = 0;
	while (last->text[i] && last->text[i] != '\n')
		i++;
	if (last->text[i] == '\n')
		i++;
	while (last->text[i])
	{
		buffer[j] = last->text[i];
		i++;
		j++;
	}
	buffer[j] = '\0';
	free_all(head, buffer);
}

int	get_line_size(t_list *head)
{
	t_list	*index;
	int		size;
	int		i;

	size = 0;
	if (!head)
		return (size);
	index = head;
	while (index)
	{
		i = 0;
		while (index->text[i])
		{
			size++;
			if (index->text[i] == '\n')
				return (size);
			i++;
		}
		index = index->next;
	}
	return (size);
}

char	*get_next_line(int fd)
{
	static t_list	*head;
	char			*next_line;

	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, &next_line, 0) < 0)
	{
		free_all(&head, NULL);
		return (NULL);
	}
	create_list(&head, fd);
	if (!head)
		return (NULL);
	next_line = get_line_text(head);
	rearrange(&head);
	return (next_line);
}

// int main()
// {
// 	char *line;
// 	int	fd;

// 	fd = open("./maps/map.bef",O_RDONLY);
// 	line = get_next_line(fd);
// 	printf("%s",line);
// 	//free(line);
// 	system("leaks exec");
// 	return (0);
// }
