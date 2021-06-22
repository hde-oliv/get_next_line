#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

/**
 * @brief Reads an fd and returns a line from it.
 * If it's called in a loop, it'll print the entire file.
 * 
 * Must have an BUFFER_SIZE macro defined.
 *
 * @param fd The file descriptor to read.
 * @param line A pointer to a string to write the
 * allocated line.
 *
 * @return 1 (Success) | 0 (EOF) | -1 (Error)
 */
int		get_next_line(int fd, char **line);

/**
 * @brief Concatenate a string to another buffer, this process is
 * only made on true C strings and it is a safer alternative
 * to strncat and strcat, because the result is always null
 * terminated as it transfers dstsize - 1 bytes.
 *
 * @param dst The buffer were the concatenation will occur.
 * @param src The a string.
 * @param dstsize How many bytes the buffer has.
 *
 * @return The size of the string that it tried to create.
 */
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);

/**
 * @brief Process the length of a string.
 *
 * @param s A string.
 *
 * @return Its length.
 */
size_t	ft_strlen(const char *s);

/**
 * @brief Copies a string to another buffer, the copy is
 * only made on true C strings and it is a safer alternative
 * to strncpy and strcpy, because the result is always null
 * terminated as it copies dstsize - 1 bytes.
 *
 * @param dst The buffer that receives the string.
 * @param src The original string.
 * @param dstsize How many bytes the buffer has.
 *
 * @return The size of the string that it tried to create.
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

/**
 * @brief Allocates a new string that results
 * from the concatenation of two strings.
 *
 * @param s1 The first string.
 * @param s2 The second string.
 *
 * @return The new string resulted of the concatenation of
 * the two previous strings.
 */
char	*ft_strjoin(char const *s1, char const *s2);

/**
 * @brief Fills the first n bytes of the
 * area pointed by s with zeroes.
 * 
 * @param s Pointer to the area.
 * @param n Number of bytes to fill.
 *
 * @return Nothing.
 */
void	ft_bzero(void *s, size_t n);

/**
 * @brief Allocates a copy of a
 * string.
 *
 * @param s1 The string to copy.
 *
 * @return The new string.
 */
char	*ft_strdup(const char *s1);

#endif
