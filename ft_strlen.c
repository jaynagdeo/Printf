/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnagdeo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 17:21:29 by jnagdeo           #+#    #+#             */
/*   Updated: 2018/10/04 17:21:39 by jnagdeo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t ft_strlen(const char *s)
{
  unsigned int count = 0;
  const char *ptr;

    ptr = s;
    while (*ptr != '\0'){
        count++;
        ptr++;
      }
    return (count);
}
