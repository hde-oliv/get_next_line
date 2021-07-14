#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

/**
 * get_next_line - Reads a line from a file descriptor
 *
 * @fd: File descriptor to read
 * @line: A pointer to a string to store the line
 *
 * Description: Reads an fd and returns a line from it.
 * If it's called in a loop, it'll print the entire file.
 *
 * Return: 1 on success, 0 on EOF, -1 on error.
 */
int		get_next_line(int fd, char **line);

/**
 * ft_strlcat - Concatenate two strings
 *
 * @dst: The buffer were the concatenation will occur.
 * @src: The string.
 * @dstsize: How many bytes the buffer has.
 *
 * Description: Concatenate a string to another buffer, this process is
 * only made on true C strings and it is a safer alternative
 * to strncat and strcat, because the result is always null
 * terminated as it transfers dstsize - 1 bytes.
 *
 * Return: The size of the string it tried to create.
 */
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);

/**
 * ft_strlen - Process the length of a string.
 *
 * @s: A string.
 *
 * Return: Its length.
 */
size_t	ft_strlen(const char *s);

/**
 * ft_strlcpy - Copies a string to a buffer
 *
 * @dst: The buffer to receive the string.
 * @src: The original string.
 * @dstsize: How many bytes the buffer has.
 *
 * Description: Copies a string to another buffer, the copy is
 * only made on true C strings and it is a safer alternative
 * to strncpy and strcpy, because the result is always null
 * terminated as it copies dstsize - 1 bytes.
 *
 * Return: The size of the string it tried to create.
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

/**
 * ft_strjoin - Allocates a new string that results from
 * the concatenation of two strings.
 *
 * @s1: The first string.
 * @s2: The second string.
 *
 * Return: The new string resulted of the concatenation of
 * the two previous strings.
 *
 * Example:
 *        ft_strjoin("Hello, ", "World!"); --> "Hello, World!"
 */
char	*ft_strjoin(char const *s1, char const *s2);

/**
 * ft_bzero - Fills the first n bytes of the
 * area pointed by s with zeroes.
 * 
 * @s: Pointer to the area.
 * @n: Number of bytes to fill.
 */
void	ft_bzero(void *s, size_t n);

/**
 * ft_strdup - Allocates a copy of a string.
 *
 * @s1: The string to copy.
 *
 * Return: The new string.
 */
char	*ft_strdup(const char *s1);

#endif
