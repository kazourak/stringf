/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nskiba <nskiba@student.42anougleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:14:51 by nskiba            #+#    #+#             */
/*   Updated: 2023/01/25 16:14:53 by nskiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../stringf.h"

static int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (i);
	while (str[i] != '\0')
		i++;
	return (i);
}

int	add_char(char **src, char c, int index)
{
	int		i;
	char	*tmp;

	tmp = *src;
	i = index;
	tmp[i] = c;
	i++;
	return (1);
}

int	get_len_args(va_list args, char c)
{
	int	len;

	len = 0;
	if (c == 's')
		len += ft_strlen(va_arg(args, char *));
	return (len);
}

int	get_len(const char *str)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
			i += 1;
		else
			len++;
		i++;
	}
	return (len);
}
