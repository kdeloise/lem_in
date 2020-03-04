/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_rooms.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdeloise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 10:08:35 by kdeloise          #+#    #+#             */
/*   Updated: 2020/03/04 10:08:48 by kdeloise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	create_rooms(t_graph *graph, char *name_coor)
{
	char	**split_name_coor;
	t_llist	*add;
	t_room	*add_room;

	split_name_coor = ft_strsplit(name_coor, ' ');
	if (graph->rooms == NULL)
	{
		if (!(graph->rooms = (t_llist *)malloc(sizeof(t_llist))))
			ft_exit("Error <malloc>");
		if (!(add_room = (t_room *)malloc(sizeof(t_room))))
			ft_exit("Error <malloc>");
		add_room->name = split_name_coor[0];
		add_room->x = ft_atoi(split_name_coor[1]);
		add_room->y = ft_atoi(split_name_coor[2]);
		graph->rooms->data = add_room;
		graph->rooms->next = NULL;
	}
	else
	{
		if (!(add = (t_llist *)malloc(sizeof(t_llist))))
			ft_exit("Error <malloc>");
		if (!(add_room = (t_room *)malloc(sizeof(t_room))))
			ft_exit("Error <malloc>");
		add_room->name = split_name_coor[0];
		add_room->x = ft_atoi(split_name_coor[1]);
		add_room->y = ft_atoi(split_name_coor[2]);
		add->data = add_room;
		add->next = graph->rooms;
		graph->rooms = add;
	}
}

void	create_start_room(t_graph *graph, char *name_coor)
{
	char	**split_name_coor;

	split_name_coor = ft_strsplit(name_coor, ' ');
	if (!(graph->start = (t_room *)ft_memalloc(sizeof(t_room))))
		ft_exit("Error <malloc>");
	graph->start->name = split_name_coor[0];
	graph->start->x = ft_atoi(split_name_coor[1]);
	graph->start->y = ft_atoi(split_name_coor[2]);
}

void	create_end_room(t_graph *graph, char *name_coor)
{
	char	**split_name_coor;

	split_name_coor = ft_strsplit(name_coor, ' ');
	if (!(graph->end = (t_room *)ft_memalloc(sizeof(t_room))))
		ft_exit("Error <malloc>");
	graph->end->name = split_name_coor[0];
	graph->end->x = ft_atoi(split_name_coor[1]);
	graph->end->y = ft_atoi(split_name_coor[2]);
}