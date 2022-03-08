<h1> libft :books:</h1>

<figure>
	<img height="80" width="80" src="https://game.42sp.org.br/static/assets/achievements/libfte.png" alt="libft_img">
</figure>
	
<p>Primeiro projeto da fase 1 na 42. Esse é o projeto onde recriamos algumas funções de bibliotecas C bem conhecidas. Esse projeto se constitui de duas partes e a parte bônus. </p>

<blockquote>
<h4> Como navegar por esse repositório </h4>
<p>Na pasta <code><a href="https://github.com/lamorim42/libft/tree/master/src" target="_blank">src</a></code> estão os códigos fonte das minhas funções que estão na lib. Na pasta <code><a href="https://github.com/lamorim42/libft/tree/master/include" target="_blank">include</a></code> está o arquivo de header. Após o <code>make</code> os arquivos de objotas irão ficar nas pasta <code><a href="https://github.com/lamorim42/libft/tree/master/obj" target="_blank">obj</a></code>.</p>
</blockquote>
	
<div>
<b>Na parte 1 temos as funções:</b>

<pre>
<h3>---> Funções ctype.h</h3>
<p><a href="#isalpha">01- ft_isalpha </a></p>
<p><a href="#isdigit">02- ft_isdigit </a></p>
<p><a href="#isalnum">03- ft_isalnum </a></p>
<p><a href="#isascii">04- ft_isascii </a></p>
<p><a href="#isprint">05- ft_isprint </a></p>
<p><a href="#toupper">06- ft_toupper </a></p>
<p><a href="#tolower">07- ft_tolower </a></p></pre>

<pre>
<h3>---> Funções string.h</h3>
<p><a href="#strlen">09- ft_strlen </a></p>
<p><a href="#strlcpy">10- ft_strlcpy </a></p>
<p><a href="#strlcat">11- ft_strlcat </a></p>
<p><a href="#strchr">12- ft_strchr </a></p>
<p><a href="#strrchr">13- ft_strrchr </a></p>
<p><a href="#strncmp">14- ft_strncmp </a></p>
<p><a href="#strnstr">15- ft_strnstr </a></p>
<p><a href="#memset">16- ft_memset </a></p>
<p><a href="#memchr">17- ft_memchr </a></p>
<p><a href="#bzero">18- ft_bzero </a></p>
<p><a href="#memcpy">19- ft_memcpy </a></p>
<p><a href="#memmove">20- ft_memmove </a></p>
<p><a href="#memcmp">21- ft_memcmp </a></p></pre>

<h3>Funções stdlib.h</h3>
• ft_atoi
</div>

<div>
Na parte 2, temos:
• substr 
• strjoin 
• strtrim 
• split 
• itoa 
• strmapi 
• striteri 
• putchar_fd 
• putstr_fd 
• putendl_fd 
• putnbr_fd
</div>

<p>Meu projeto foi entregue sem a parte bônus, mas algumas funções já foram implementadas a minha biblioteca.</p>

<hr>

<h3 id="isalpha">ft_isalpha</h3>
<p>Verifica se o argumento passado é um caractere alfabético. Retorna 1 se não for alfabético ou 0 se for.</p>

```c
int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}
```

<h3 id="isdigit">ft_isdigit</h3>
<p>Verifica se o argumento passado é um caractere numérico. Retorna 1 se não for um número ou 0 se for.</p>

```c
int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
```

<h3 id="isalnum">ft_isalnum</h3>
<p>Verifica se o argumento passado é um caractere numérico ou alfabético. Retorna 1 se não for ou um 0 se for.</p>

```c
int	ft_isalnum(int c)
{
	if (((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) \
		|| (c >= '0' && c <= '9'))
		return (1);
	return (0);
}
```

<h3 id="isascii">ft_isascii</h3>
<p>Verifica se o argumento passado é um caractere da tabela ascii. Retorna 1 se não for ou um 0 se for.</p>

```c
int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
```

<h3 id="isprint">ft_isprint</h3>
<p>Verifica se o argumento passado é um caractere "printável". Retorna 1 se não for ou um 0 se for.</p>

```c
int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
```

<h3 id="toupper">ft_toupper</h3>
<p>Se o argumento passado é uma letra minúscula, a retorna maiúscula.</p>

```c
int	ft_toupper(int c)
{
	if (c > 64 && c < 91)
		c += 32;
	if (c > 96 && c < 123)
		c -= 32;
	return (c);
}
```

<h3 id="tolower">ft_tolower</h3>
<p>Se o argumento passado é uma letra maiúscula, a retorna minúscula.</p>

```c
int	ft_tolower(int c)
{
	if (c > 64 && c < 91)
		c += 32;
	return (c);
}
```

<h3 id="strlen">ft_strlen</h3>
<p>Retorna a quantidade de bytes em uma string.</p>

```c
size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}
```

<h3 id="strlcpy">ft_strlcpy</h3>
<p>Copia <code>(destsize - 1)</code> caracteres de <code>srt</code> para <code>dst</code>.</p>

```c
size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	src_size;
	size_t	dst_size;

	src_size = 0;
	dst_size = 0;
	while (src[src_size])
		src_size++;
	if (dstsize != 0)
	{
		while (dst_size < dstsize - 1 && src[dst_size] != '\0')
		{
			dst[dst_size] = src[dst_size];
			dst_size++;
		}
		dst[dst_size] = '\0';
	}
	return (src_size);
}
```

<h3 id="strlcat">ft_strlcat</h3>
<p>Concatena a string <code>str</code> na string <code>dst</code>.</p>

```c
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*dst_cpy;
	char	*src_cpy;
	size_t	src_len;
	size_t	dst_len;

	src_len = 0;
	dst_len = 0;
	while (src[src_len])
		src_len++;
	while (dst[dst_len])
		dst_len++;
	src_cpy = (char *) src;
	dst_cpy = dst;
	if (size <= dst_len)
		return (size + src_len);
	else
	{
		dst_cpy += dst_len;
		while (*src_cpy && --size > dst_len)
			*dst_cpy++ = *src_cpy++;
		*dst_cpy = '\0';
	}
	return (dst_len + src_len);
}
```

<h3 id="strchr">ft_strchr</h3>
<p>Retorna um ponteiro para primeira ocorrencia do caracter <code>c</code> na string <code>str</code>.</p>

```c
char	*ft_strchr(const char *s, int c)
{
	if (c == 0)
	{
		while (*s)
			s++;
		return ((char *)s);
	}
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return ((char *) '\0');
}
```

<h3 id="strrchr">ft_strrchr</h3>
<p>Retorna um ponteiro para última ocorrencia do caracter <code>c</code> na string <code>str</code>.</p>

```c
char	*ft_strrchr(const char *s, int c)
{
	size_t	len;
	char	*str;

	len = ft_strlen(s);
	str = (char *)s;
	if (c == 0)
		return (&str[len]);
	while (len)
	{
		if (str[len] == (char)c)
			return (&str[len]);
		len--;
	}
	if (str[len] == (char)c)
		return (&str[len]);
	return (0);
}
```

<h3 id="strncmp">ft_strncmp</h3>
<p>Compara os primeiros <code>n</code> bytes da string apontada por <code>s</code> com <code>c</code>.</p>

```c
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
```

<h3 id="strnstr">ft_strnstr</h3>
<p>Encontra a primeira ocorrencia da string <code>little</code> na string <code>big</code>.</p>

```c
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	big_i;
	size_t	lit_i;
	size_t	len_lit;
	char	*big_cpy;

	big_i = 0;
	lit_i = 0;
	len_lit = ft_strlen(little);
	big_cpy = (char *) big;
	if (len_lit == 0)
		return (big_cpy);
	while (big_cpy[big_i] != '\0' && len-- >= len_lit)
	{
		if (big_cpy[big_i] == little[lit_i]
			&& !ft_strncmp(big_cpy + big_i, little, len_lit))
			return (big_cpy + big_i);
		big_i++;
	}
	return (NULL);
}
```

<h3 id="memset">ft_memset</h3>
<p>Preenche os primeiros <code>n</code> bytes da memória apontada por <code>str</code> com o byte constante <code>c</code>.</p>

```c
void	*ft_memset(void *str, int c, size_t n)
{
	size_t	i;
	char	*s;

	s = (char *) str;
	i = 0;
	while (i < n)
	{
		s[i] = c;
		i++;
	}
	return (s);
}
```

<h3 id="memchr">ft_memchr</h3>
<p>Procura nos primeiros <code>n</code> bytes da memória apontada por <code>s</code> o caracter <code>c</code>.</p>

```c
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *) s;
	while (n--)
	{
		if (*str == (unsigned char)c)
			return ((void *)str);
		str++;
	}
	return (0);
}
```

<h3 id="bzero">ft_bzero</h3>
<p>Apaga o conteúdo dos primeiros <code>n</code> bytes da memória apontada por <code>s</code>.</p>

```c
void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (n--)
		((char *)s)[i++] = '\0';
}
```

<h3 id="memcpy">ft_memcpy</h3>
<p>Copia <code>n</code> bytes da memória apontada por <code>src</code> para <code>dest</code>.</p>

```c
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_cpy;
	unsigned char	*src_cpy;

	if ((!dest && !src) || !n)
		return (dest);
	dest_cpy = (unsigned char *)dest;
	src_cpy = (unsigned char *)src;
	while (n--)
		*dest_cpy++ = *src_cpy++;
	return (dest);
}
```

<h3 id="memmove">ft_memmove</h3>
<p>Copia <code>n</code> bytes da memória apontada por <code>src</code> para <code>src</code>.</p>

```c
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_cpy;
	unsigned char	*src_cpy;
	int				i;

	i = -1;
	dest_cpy = (unsigned char *)dest;
	src_cpy = (unsigned char *)src;
	if (dest > src)
	{
		while (n--)
			dest_cpy[n] = src_cpy[n];
		return (dest);
	}
	else
	{
		while (++i < (int)n)
			dest_cpy[i] = src_cpy[i];
	}
	return (dest);
}
```

<h3 id="memcmp">ft_memcmp</h3>
<p>Compara os <code>n</code> primeiros bytes da memória apontada por <code>s1</code> com a memória apontada por <code>s2</code>.</p>

```c
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_cpy;
	unsigned char	*s2_cpy;

	s1_cpy = (unsigned char *) s1;
	s2_cpy = (unsigned char *) s2;
	if (!s1 && !s2)
		return (0);
	while (n--)
	{
		if (*s1_cpy != *s2_cpy)
			return (*s1_cpy - *s2_cpy);
		s1_cpy++;
		s2_cpy++;
	}
	return (0);
}
```

