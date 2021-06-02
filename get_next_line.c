#include "get_next_line.h"
#include <stdio.h>
#define LN '\n'
#define BUFFER_SIZE 50
#include <fcntl.h>

void	*ft_realloc(void *arr, size_t size)
{
	void	*ptr;
	int		i;

	i = 0;
	ptr = malloc(size);
	while (((unsigned char *)arr)[i] != '\0')
	{
		((unsigned char *) ptr)[i] = ((unsigned char *) arr)[i];
		i++;
	}
	free(arr);
	return (ptr);
}

int		line_val(char *str, char **temp, size_t size)
{
	size_t i;

	i = 0;
	while (str[i] != '\n' || str[i] != EOF)
		if (!str[i++])
			return (0);
	temp[0] = ft_substr(str, 0, i);
	temp[1] = ft_substr(str, i + 1, size - i);
	temp[2] = (void *) 2;
	return (i);
}

char	*get_line(int fd)
{
	int		i;
	int		j;
	static char	str[BUFFER_SIZE + 1];
	static char	**temp;
	char	*final;

	final = (char *) malloc(sizeof(char) * BUFFER_SIZE);
	temp = (char **) malloc(sizeof(char *) * 3);
	if (temp[2] == (void *)2)
		ft_strjoin(final, temp[1]);
	i = read(fd, str, BUFFER_SIZE);
	if (i == BUFFER_SIZE)
	{
		str[BUFFER_SIZE] = '\0';
		j = line_val(str, temp, BUFFER_SIZE);
		if (!j)
		{
			ft_realloc(str, BUFFER_SIZE);
			ft_strjoin(final, str);
		}
		else
		{
			ft_realloc(final, j);
			ft_strjoin(final, temp[0]);
		}
		return (final);
	}
	j = line_val(str, temp, BUFFER_SIZE);
	ft_realloc(final, j);
	ft_strjoin(final, temp[0]);
	return (final);
}

int		get_next_line(int fd, char **line)
{

	*line = get_line(fd);
	return (1);
}
