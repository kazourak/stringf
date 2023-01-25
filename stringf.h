/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stringf.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nskiba <nskiba@student.42anougleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:14:56 by nskiba            #+#    #+#             */
/*   Updated: 2023/01/25 16:14:57 by nskiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRINGF_H
#define STRINGF_H

# include <assert.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>

char	*stringf(const char *str, ...);
int		add_char(char **src, char c, int index);
int		get_len_args(va_list args, char c);
int		get_len(const char *str);


#endif
