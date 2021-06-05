#include "get_next_line.h"
#include <stdio.h>
#define BUFFER_SIZE 50

static int	slice_check(char *str, size_t size)
{
	size_t	i;

	i = 0;
	while (str[i] != '\n')
	{
		if (i == size)
			return (0);
		i++;
	}
	return (i);
}

static void	splited(char *str, char **line, size_t index, size_t size)
{
	char	*temp_str;
	char	*temp_slice;

	temp_str = *line;
	temp_slice = ft_substr(str, index, size);
	*line = ft_strjoin(temp_str, temp_slice);
	if (index != 0)
		str[index] = 32;
	free(temp_str);
	free(temp_slice);
}

static int	get_line(int fd, char **line, char *slice)
{
	char		*temp;
	size_t		i;

	i = slice_check(slice, BUFFER_SIZE);
	if (i)
		splited(slice, line, i, BUFFER_SIZE - i - slice_check(&slice[i + 1], BUFFER_SIZE - i));
	while (0 < read(fd, slice, BUFFER_SIZE))
	{
		i = slice_check(slice, BUFFER_SIZE);
		if (!i)
		{
			temp = *line;
			*line = ft_strjoin(*line, slice);
			free(temp);
		}
		else
		{
			splited(slice, line, 0, i);
			return (1);
		}
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	slice[BUFFER_SIZE + 1];
	char		*string;
	size_t		i;

	i = 0;
	slice[BUFFER_SIZE] = '\0';
	string = (char *) malloc(sizeof(char) * BUFFER_SIZE + 1);
	while (i <= BUFFER_SIZE)
		string[i++] = '\0';
	if (get_line(fd, &string, slice))
	{
		*line = string;
		return (1);
	}
	else
		return (0);
}
