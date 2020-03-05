/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdeloise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 20:42:09 by kdeloise          #+#    #+#             */
/*   Updated: 2020/02/25 20:42:16 by kdeloise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"


int main(int argc, char **argv)
{
	char	*buff;


	buff = create_validation_buff();
	validation(buff);
	printf("%s", buff);
	return (0);
}