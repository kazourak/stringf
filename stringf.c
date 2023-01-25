/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stringf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nskiba <nskiba@student.42anougleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:15:14 by nskiba            #+#    #+#             */
/*   Updated: 2023/01/25 16:15:14 by nskiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stringf.h"

static int	add_pourcent(char **src, char *pourcent, int index)
{
	int		i;
	int		j;
	char	*tmp;

	tmp = *src;
	i = index;
	j = 0;
	while (pourcent[j] != '\0')
	{
		tmp[i] = pourcent[j];
		j++;
		i++;
	}
	return (j);
}

static char	*format(va_list args, const char *str, int len)
{
	char	*result;
	int		i;
	int		j;

	j = 0;
	i = 0;
	result = malloc(sizeof(char) * len + 1);
	if (!result)
		return (NULL);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			j += add_pourcent(&result, va_arg(args, char *), j);
			i++;
		}
		else
			j += add_char(&result, str[i], j);
		i++;
	}
	result[len] = '\0';
	return (result);
}

/*
NAME
       stringf - format and create string

SYNOPSIS
       stringf FORMAT [ARGUMENT]...

DESCRIPTION
       Create a string with ARGUMENT(s) according to FORMAT
*/
char	*stringf(const char *str, ...)
{
	va_list	args;
	va_list	args2;
	char	*result;
	int		i;
	int		len;

	i = 0;
	len = 0;
	if (!str)
		return (NULL);
	va_start(args, str);
	va_copy(args2, args);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			len += get_len_args(args, str[i + 1]);
			i++;
		}
		i++;
	}
	len += get_len(str);
	result = format(args2, str, len);
	return (result);
}
