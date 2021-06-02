#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>

# define LB \n

int		get_next_line(int fd, char **line);
void	ft_putstr_fd(int fd, char *c);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
void	ft_putstr_fd(int fd, char *c);



#endif
