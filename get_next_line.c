#include "get_next_line.h"
#define LN '\n'

char	*get_line(int fd,char *line)
{
	int		i;
	int		j;
	char	*str_1;
	char	str_2[BUFFER_SIZE + 1];

	str_1 = (char *) malloc(sizeof(*line) * (i + 1));
	j = 1;
	while (j != 0)
	{
		j = read(fd, str_2, BUFFER_SIZE);
		str_2[BUFFER_SIZE] = '\0';
		i -= j;
		ft_strjoin(str_1, str_2);
	}
	return (str_1);
}

int	get_next_line(int fd, char **line)
{
	char	buf[BUFFER_SIZE];
	int		n;
	char	*str;

	
	free(str);
	return (0);
}

int main(void)
{
	char *buf;

	read(0, buf, 1);
	get_next_line(0, &buf);
}
