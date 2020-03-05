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

void	check_double_room_coor(t_graph *graph, char *name_coor)
{
	char	**split_name_coor;
	t_llist *start;

	split_name_coor = ft_strsplit(name_coor, ' ');
	if (graph)
	{
		start = graph->rooms;
		while (graph->rooms)
		{
			if (!(ft_strcmp(graph->rooms->data->name, split_name_coor[0])))
				ft_exit("Error <duplicate name_room>");
			if (graph->rooms->data->x == ft_atoi(split_name_coor[1]) && graph->rooms->data->y == ft_atoi(split_name_coor[2]))
				ft_exit("Error <duplicate coordinate>");
			graph->rooms = graph->rooms->next;
		}
		graph->rooms = start;
	}
}

void	find_paste_link(t_llist *start, char *name_link, t_link *add_link)
{
	t_llist		*new_start;
	int			fl;

	fl = 0;
	new_start = start;
	while (start)
	{
		if (!(ft_strcmp(start->data->name, name_link)))
		{
			fl = 1;
			add_link->weight = 1;
			add_link->dst = start->data;
			start = new_start;
			break ;
		}
		start = start->next;
	}
	if (fl == 0)
		ft_exit("Error <Room does not exist>");
	start = new_start;
}

int		ft_not_link(t_link_list *link_rooms, char *name_room_for_link)
{
	t_link_list		*start;

	start = link_rooms;
	if (!link_rooms)
		return (1);
	while (link_rooms)
	{
		if (!(ft_strcmp(name_room_for_link, link_rooms->data->dst->name)))
			return (0);
		link_rooms = link_rooms->next;
	}
	link_rooms = start;
	return (1);
}

void	create_links(t_graph *graph, char *name_coor)
{
	char		**split_link;
	t_link_list	*add;
	t_link		*add_link;
	t_llist		*start;
	int			fl;

	fl = 0;
	start = graph->rooms;
	split_link = ft_strsplit(name_coor, '-');
	while (graph->rooms)
	{
		if (!(ft_strcmp(split_link[0], graph->rooms->data->name)))
		{
			fl = 1;
			if (ft_not_link(graph->rooms->data->links, split_link[1]))
			{
				if (!(add = (t_link_list *)malloc(sizeof(t_link_list))))
					ft_exit("Error <malloc>");
				if (!(add_link = (t_link *)malloc(sizeof(t_link))))
					ft_exit("Error <malloc>");
				find_paste_link(start, split_link[1], add_link);
				add->data = add_link;
				add->next = graph->rooms->data->links;
				graph->rooms->data->links = add;
			}
		}
		else if (!(ft_strcmp(split_link[1], graph->rooms->data->name)))
		{
			fl = 1;
			if (ft_not_link(graph->rooms->data->links, split_link[0]))
			{
				if (!(add = (t_link_list *)malloc(sizeof(t_link_list))))
					ft_exit("Error <malloc>");
				if (!(add_link = (t_link *)malloc(sizeof(t_link))))
					ft_exit("Error <malloc>");
				find_paste_link(start, split_link[0], add_link);
				add->data = add_link;
				add->next = graph->rooms->data->links;
				graph->rooms->data->links = add;
			}
		}
		graph->rooms = graph->rooms->next;
	}
	if (fl == 0)
		ft_exit("Error <Room does not exist>");
	graph->rooms = start;
}

void	create_rooms(t_graph *graph, char *name_coor)
{
	char	**split_name_coor;
	t_llist	*add;
	t_room	*add_room;

	split_name_coor = ft_strsplit(name_coor, ' ');
	if (graph->rooms == NULL)
	{
		if (!(graph->rooms = (t_llist *)ft_memalloc(sizeof(t_llist))))
			ft_exit("Error <malloc>");
		if (!(add_room = (t_room *)ft_memalloc(sizeof(t_room))))
			ft_exit("Error <malloc>");
		add_room->name = split_name_coor[0];
		add_room->x = ft_atoi(split_name_coor[1]);
		add_room->y = ft_atoi(split_name_coor[2]);
		graph->rooms->data = add_room;
		graph->rooms->next = NULL;
	}
	else
	{
		if (!(add = (t_llist *)ft_memalloc(sizeof(t_llist))))
			ft_exit("Error <malloc>");
		if (!(add_room = (t_room *)ft_memalloc(sizeof(t_room))))
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