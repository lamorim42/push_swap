/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 23:07:56 by lamorim           #+#    #+#             */
/*   Updated: 2021/09/30 18:37:13 by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define MAX_INT 2147483647
# define MIN_INT (-2147483648)

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef FD_MAX
#  define FD_MAX 256
# endif

# define N '\n'

/**
 * @brief Checks for an alphabetic character
 *
 * @param c Character to be checked
 *
 * @return int The values returned are 1 (true)
 * if c is alphabetic and 0 (false) if c is not alphabetic
 */
int		ft_isalpha(int c);

/**
 * @brief Checks for an digit (0 through 9) character
 *
 * @param c Character to be checked
 *
 * @return int The values returned are 1 (true)
 * if c is digit and 0 (false) if c is not digit
 */
int		ft_isdigit(int c);

/**
 * @brief Checks for an alphanumeric character
 *
 * @param c Character to be checked
 *
 * @return int The values returned are 1 (true)
 * if c is alphanumeric and 0 (false) if c is not alphanumeric
 */
int		ft_isalnum(int c);

/**
 * @brief Checks for a 7-bit US-ASCII character
 *
 * @param c Character to be checked
 *
 * @return int The values returned are 1 (true)
 * if c is 7-bit and 0 (false) if c is not 7-bit
 */
int		ft_isascii(int c);

/**
 * @brief Checks for printable character
 *
 * @param c Character to be checked
 *
 * @return int The values returned are 1 (true)
 * if c is printable and 0 (false) if c is not printable
 */
int		ft_isprint(int c);

/**
 * @brief If c is a lowercase letter, returns its uppercase,
 * if c is a uppercase letter, returns its lowercase
 *
 * @param c char to be converted
 *
 * @return int returns lowercase c or uppercase c
 */
int		ft_toupper(int c);

/**
 * @brief If c is a lowercase letter, returns its uppercase.
 *
 * @param c char to be converted
 *
 * @return int returns uppercase c
 */
int		ft_tolower(int c);

/**
 * @brief Calculates the length of the string pointed to by s,
 * excluding the terminating null byte ('\0').
 *
 * @param *s The string to be measured
 *
 * @return size_t returns the number of bytes in the string
 */
size_t	ft_strlen(const char *s);

/**
 * @brief copies up to dstsize - 1 characters from the string src to dst,
 * NUL-terminating the result if dstsize is not 0
 *
 * @param 
 * *dst string copy of *src
 * *src string font
 * dstsize size of dst
 *
 * @return size_t returns size of src
 */
size_t	ft_strlcpy(char *dst, char *src, size_t dstsize);

/**
 * @brief returns a pointer to the first occurrence of the
 * character c in the string s.
 *
 * @param 
 * s pointer to string
 * c letter to looking for
 *
 * @return char* returns the corresponding lower-case letter
 */
char	*ft_strchr(const char *s, int c);

/**
 * @brief returns a pointer to the last occurrence of the
 * character c in the string s.
 *
 * @param 
 * s pointer to string
 * c letter to looking for
 *
 * @return char* returns the corresponding lower-case letter
 */
char	*ft_strrchr(const char *s, int c);

/**
 * @brief compares the first n bytes of s1 and s2
 *
 * @param 
 * s1 pointer to string
 * s2 pointer to string
 * n number of characters to be compared
 *
 * @return size_t It returns an integer less than, equal to, or greater
 * than zero if s1 is found, respectively, to be less than, to  match,
 * or be greater than s2.
 */
int		ft_strncmp(const char *s1, const char *s2, size_t n);

/**
 * @brief concatenate src to dst string
 *
 * @param 
 * dst string destiny
 * src string source
 * size size of dst buff
 *
 * @return size_t return the total length of the string they tried to create
 *
 */
size_t	ft_strlcat(char *dst, const char *src, size_t size);

/**
 * @brief find the firts occurrence of little string in big string
 *
 * @param 
 * big string base
 * little string to be find
 * len limit of search
 *
 * @return char* return ponter to string
 *
 */
char	*ft_strnstr(const char *big, const char *little, size_t len);

/**
 * @brief fills the first n bytes of the memory area
 * pointed to by s with the constant byte c.
 *
 * @param 
 * s pointer to memory area
 * c constant byte 
 * n the amount of bytes
 *
 * @return void* returns point to s
 */
void	*ft_memset(void *s, int c, size_t n);

/**
 * @brief erases the data in the n bytes of the memory starting at
 * the location pointed to by s
 * 
 * @param 
 * s pointer to memory area
 * n the number of bytes to be 0
 *
 * @return void
 */
void	ft_bzero(void *s, size_t n);

/**
 * @brief cans the initial n bytes of the memory area pointed to by s
 * for the first instance of c
 * 
 * @param 
 * s pointer to memory area
 * c char to looking for
 * n the number of bytes to be scaned
 *
 * @return void* pointer to first instance of c or NULL
 */
void	*ft_memchr(const void *s, int c, size_t n);

/**
 * @brief copies n bytes from memory area src to memory area dest
 * 
 * 
 * @param 
 * dest memory area destination
 * src memory area source
 * n the number of bytes to be copy
 *
 * @return void* pointer to dest
 */
void	*ft_memcpy(void *dest, const void *src, size_t n);

/**
 * @brief copies n bytes from memory area src to memory area dest
 * 
 * 
 * @param 
 * dest memory area destination
 * src memory area source
 * n the number of bytes to be copy
 *
 * @return void* pointer to dest
 */
void	*ft_memmove(void *dest, const void *src, size_t n);

/**
 * @brief compares the first n bytes (each interpreted as unsigned char)
 * of the memory areas s1 and s2.
 * 
 * 
 * @param
 * s1 memory area to be compare with
 * s2 memory area to be compare
 * n the number of bytes to be compare
 *
 * @return void function returns an integer less than, equal to, or greater
 * than zero if the first n bytes  of  s1 is found, respectively,
 * to be less than, to match, or be greater than the first n bytes of s2.
 */
int		ft_memcmp(const void *s1, const void *s2, size_t n);

/**
 * @brief converts the initial portion of the string pointed to by nptr to int.
 * 
 * @param
 * nptr initial string area
 *
 * @return int converted value
 */
int		ft_atoi(const char *nptr);

/**
 * @brief allocates memory for an array of nmemb elements of size bytes each
 * and returns a pointer to the allocated memory. The memory is set to zero.
 * If nmemb or size is 0, then calloc() returns either NULL
 * 
 * @param
 * nmemb number elements of the array
 * size size to be allocated
 *
 * @return void* pointer to the allocated memory
 */
void	*ft_calloc(size_t nmemb, size_t size);

/**
 * @brief Create a duplications of string s, the space of de duplicate of
 * s is allocate with malloc.
 * 
 * @param
 * s the string to be duplicated
 *
 * @return char* pointer to the duplicate string
 */
char	*ft_strdup(const char *s);

// Part 2

/**
 * @brief Allocates (with malloc(3)) and returns a substring 
 * from the string ’s’. The substring begins at index ’start’
 * and is of maximum size ’len’.
 * 
 * @param
 * s The string from which to create the substring.
 * start The start index of the substring in the string s
 * len The maximum length of the substring.
 *
 * @return char* returns a substring of s.
 */
char	*ft_substr(const char *s, unsigned int start, size_t len);

/**
 * @brief Allocates (with malloc(3)) and returns a new string,
 * which is the result of the concatenation of ’s1’ and ’s2’.
 * 
 * @param
 * s1 The prefix string.
 * s2 The suffix string.
 *
 * @return char* returns a new string,
 * which is the result of the concatenation of ’s1’ and ’s2’
 */
char	*ft_strjoin(const char *s1, const char *s2);

/**
 * @brief Allocates (with malloc(3)) and returns a copy of
 * ’s1’ with the characters specified in ’set’ removed
 * from the beginning and the end of the string.
 * 
 * @param
 * s1 The string to be trimmed
 * set The reference set of characters to trim
 *
 * @return char* returns a copy of
 * ’s1’ with the characters specified in ’set’ removed
 * from the beginning and the end of the string.
 */
char	*ft_strtrim(const char *s1, const char *set);

/**
 * @brief Allocates (with malloc(3)) and returns an array 
 * of strings obtained by splitting ’s’ using the
 * character ’c’ as a delimiter. The array must be
 * ended by a NULL pointer.
 * 
 * @param
 * s* The string to be split
 * c The delimiter character
 *
 * @return char* returns an array of strings obtained
 * by splitting ’s’ using the character ’c’ as a delimiter.
 */
char	**ft_split(const char *s, char c);

/**
 * @brief Allocates (with malloc(3)) and returns a string 
 * representing the integer received as an argument.
 * Negative numbers must be handled.
 * 
 * @param
 * n the integer to convert.
 *
 * @return char* returns a string representing the
 * integer received as an argument
 */
char	*ft_itoa(int n);

/**
 * @brief Applies the function ’f’ to each character of the
 * string ’s’ to create a new string (with malloc(3))
 * resulting from successive applications of ’f’.
 * 
 * @param
 * *s The string on which to iterate
 * *f The function to apply to each character
 *
 * @return char* return a pointer to the new string
 * resulting from successive applications of ’f’.
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/**
 * @brief Applies the function f to each character of the
 * string passed as argument, and passing its index
 * as first argument. Each character is passed by
 * address to f to be modified if necessary
 * 
 * @param
 * *s The string on which to iterate
 * *f The function to apply to each character
 *
 * @return none
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

/**
 * @brief Outputs the character ’c’ to the given file descriptor.
 * 
 * @param
 * c The character to output.
 * fd The file descriptor on which to write.
 *
 * @return none
 */
void	ft_putchar_fd(char c, int fd);

/**
 * @brief Outputs the string ’s’ to the given file descriptor.
 * 
 * @param
 * *s The string to output.
 * fd The file descriptor on which to write.
 *
 * @return none
 */
void	ft_putstr_fd(char *s, int fd);

/**
 * @brief Outputs the string ’s’ to the given file 
 * descriptor, followed by a newline.
 * 
 * @param
 * *s The string to output
 * fd The file descriptor on which to write.
 *
 * @return none
 */
void	ft_putendl_fd(char *s, int fd);

/**
 * @brief Outputs the integer ’n’ to the given file descriptor.
 * 
 * @param
 * n The integer to output.
 * fd The file descriptor on which to write.
 *
 * @return none
 */
void	ft_putnbr_fd(int n, int fd);

char	*ft_itoa_base(unsigned int n, int base);
// GNL
char	*get_next_line(int fd);

#endif
