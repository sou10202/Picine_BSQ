/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyamaza <soyamaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:50:22 by soyamaza          #+#    #+#             */
/*   Updated: 2023/03/29 12:13:38 by soyamaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	check_charset(char str, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (str == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	count_words(char *str, char *charset)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (check_charset(str[i], charset))
		{
			i++;
			continue ;
		}
		count++;
		while (str[i] != '\0' && !check_charset(str[i], charset))
		{
			i++;
		}
	}
	return (count);
}

int	check_div_len(char *str, char *charset, int start)
{
	int	i;
	int	len;

	len = 0;
	i = start;
	while (check_charset(str[i], charset) && str[i] != '\0')
		i++;
	while (!check_charset(str[i], charset) && str[i] != '\0')
	{
		len++;
		i++;
	}
	return (len);
}

char	*cpy(char *dest, char *src, unsigned int n, int j)
{
	char	*p;

	p = dest;
	src += j;
	while (n > 0)
	{
		*dest = *src;
		dest++;
		src++;
		n--;
	}
	*dest = '\0';
	return (p);
}

char	**ft_split(char *str, char *charset)
{
	int		div;
	char	**sp;
	int		i;
	int		div_len;
	int		j;

	div = count_words(str, charset);
	sp = malloc(sizeof(char *) * (div + 1));
	if (sp == NULL)
		return (NULL);
	j = 0;
	i = 0;
	while (i < div)
	{
		div_len = check_div_len(str, charset, j);
		while (check_charset(str[j], charset))
			j++;
		sp[i] = cpy(malloc(sizeof(char) * (div_len + 1)), str, div_len, j);
		if (sp[i] == NULL)
			return (NULL);
		i++;
		j += div_len;
	}
	sp[i] = NULL;
	return (sp);
}
