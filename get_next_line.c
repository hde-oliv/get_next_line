#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/select.h>

int	check_newline(char *slice)
{
	int		i;

	i = 0;
	while (slice[i] != '\n')
		if (slice[i++] == '\0')
			return (0);
	return (i);
}

void	ft_bzero(void *s, size_t n)
{
	while (n-- > 0)
		*(unsigned char *)s++ = '\0';
}

void excess_handler(char *slice, char **string, int index)
{
	char *temp_slice;
	char *temp_str;

	temp_slice = ft_substr(slice, 0, index);
	temp_str = *string;
	*string = ft_strjoin(*string, temp_slice);
	free(temp_slice);
	free(temp_str);
	ft_memmove(slice, &slice[index + 1], BUFFER_SIZE - index + 1);
}


int	get_line(int fd, char **string, char *slice)
{
	char	*temp;
	int		i;

	if (ft_strlen(slice))
	{
		i = check_newline(slice);
		if (!i)
		{
			excess_handler(slice, string, ft_strlen(slice));
			ft_bzero(slice, BUFFER_SIZE + 1);
			return(get_line(fd, string, slice));
		}
		excess_handler(slice, string, i);
		return (1);
	}
	if (read(fd, slice, BUFFER_SIZE) > 0)
	{
		i = check_newline(slice);
		if (!i)
		{
			temp = *string;
			*string = ft_strjoin(*string, slice);
			free(temp);
			return (get_line(fd, string, slice));
		}
		else
		{
			excess_handler(slice, string, i);
			return (1);
		}
	}
	return (0);
}


int	get_next_line(int fd, char **line)
{
	static char	slice[BUFFER_SIZE + 1];
	char		*string;

	//if (fd > FD_SETSIZE)
	string = (char *) malloc(sizeof(char) * BUFFER_SIZE + 1);
	ft_bzero(string, BUFFER_SIZE + 1);
	if (get_line(fd, &string, slice))
	{
		*line = string;
		return (1);
	}
	else
		return (0);
}
