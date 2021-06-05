#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#define LN '\n'
#define BUFFER_SIZE 50

int	slice_val(char *str, size_t size)
{
	size_t	i;

	i = 0;
	while (i != size)
	{
		if (str[i] == '\n')
			return (i);
		else if (str[i] == EOF)
			return (i);
		i++;
	}
	return (0);
}

int	get_line(int fd, char **line)
{
	static char	slice[BUFFER_SIZE];
	char		*temp;
	size_t		i;
	size_t		j;

	i = slice_val(slice, BUFFER_SIZE);
	if (i)
	{
		temp = ft_substr(slice, i, BUFFER_SIZE - i + 1);
		*line = ft_strjoin(*line, temp);
	}
	while (0 != read(fd, slice, BUFFER_SIZE))
	{
		i = slice_val(slice, BUFFER_SIZE);
		if (!i)
		{
			temp = ft_substr(slice, 0, BUFFER_SIZE);
			*line = ft_strjoin(*line, temp);
		}
		else
		{
			temp = ft_substr(slice, 0, i);
			*line = ft_strjoin(*line, temp);
			return (1);
		}
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char		*string;

	string = calloc(1, BUFFER_SIZE);
	if (get_line(fd, &string))
	{
		*line = string;
		return (1);
	}
	else
		return (0);
}
