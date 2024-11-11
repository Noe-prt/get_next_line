/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npareti <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 02:38:00 by npareti           #+#    #+#             */
/*   Updated: 2024/11/11 21:47:29 by npareti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 5

#endif

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include "Libft/libft.h"

char	*get_next_line(int fd);
/* contain_line functioncheck if str contain a endline ('\n') 
 * and return 0 if str does'nt contain a endline
 * or the index of the endline if he found it */
int     contain_line(char *str);

#endif
