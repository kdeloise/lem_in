/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suurbale.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 14:38:41 by mmarti            #+#    #+#             */
/*   Updated: 2020/03/07 14:38:43 by mmarti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		count_links(t_room *r)
{
	t_link_list	*tmp;
	int			ret;

	ret = 0;
	tmp = r->links;
	while (tmp)
	{
		tmp = tmp->next;
		ret++;
	}
	return (ret);
}

// t_set	*set_find(t_set *root, t_room *r)
// {
// 	t_set *ret;
// 	int comp;

// 	ret = root;
// 	while ((comp = ft_strcmp(ret->room->name, r->name)))
// 	{
// 		if (comp > 0)
// 			ret = ret->left;
// 		else
// 			ret = ret->right;
// 	}
// 	return (ret);
// }

// t_set	*set_add_find(t_set *root, t_room *r)
// {
// 	t_set	*ret;
// 	int		comp;

// 	ret = root;
// 	while ((comp = ft_strcmp(ret->room->name, r->name)))
// 	{
// 		if (comp > 0)
// 		{
// 			if (!ret->left)
// 				return (ret);
// 			ret = ret->left;
// 		}
// 		else
// 		{
// 			if (!ret->right)
// 				return (ret);
// 			ret = ret->right;
// 		}
// 	}
// 	return (ret);
// }

// t_set	*set_new_node(t_room *r)
// {
// 	t_set *new;

// 	if (!(new = ft_memalloc(sizeof(t_set))))
// 		exit (1);
// 	new->room = r;
// 	return (new);
// }

// void	insert_node(t_set *parent, t_set *ins, int comp)
// {
// 	if (comp > 0)
// 		parent->left = ins;
// 	else
// 		parent->right = ins;
// }

// t_set	*grandparent(t_set *node)
// {
// 	if (node->parent)
// 		return (node->parent->parent);
// 	return (NULL);
// }

// t_set	*uncle(t_set *node)
// {
// 	t_set *gp;

// 	if (!(gp = grandparent(node)))
// 		return (NULL);
// 	if (node->parent == gp->left)
// 		return (gp->right);
// 	else
// 		return (gp->left);
// }

// void	rotate_left(t_set *n)
// {
//     t_set *pivot = n->right;
	
//     pivot->parent = n->parent; /* при этом, возможно, pivot становится корнем дерева */
//     if (n->parent != NULL) 
// 	{
//         if (n->parent->left==n)
//             n->parent->left = pivot;
//         else
//             n->parent->right = pivot;
//     }		
//     n->right = pivot->left;
//     if (pivot->left != NULL)
//         pivot->left->parent = n;
//     n->parent = pivot;
//     pivot->left = n;
// }

// void	rotate_right(t_set *n)
// {
//     t_set *pivot = n->left;
	
// 	pivot->parent = n->parent; /* при этом, возможно, pivot становится корнем дерева */
// 	if (n->parent != NULL) 
// 	{
// 		if (n->parent->left==n)
// 			n->parent->left = pivot;
// 		else
// 			n->parent->right = pivot;
// 	}
// 	n->left = pivot->right;
// 	if (pivot->right != NULL)
// 		pivot->right->parent = n;
// 	n->parent = pivot;
// 	pivot->right = n;
// }

// void	case5(t_set *n)
// {
// 	t_set *g = grandparent(n);

// 	n->parent->color = BLACK;
// 	g->color = RED;
// 	if ((n == n->parent->left) && (n->parent == g->left))
// 		rotate_right(g);
// 	else
// 		rotate_left(g);
// }

// void	case4(t_set *n)
// {
// 	t_set *g = grandparent(n);

// 	if ((n == n->parent->right) && (n->parent == g->left))
// 		rotate_left(n->parent);
// 	else if ((n == n->parent->left) && (n->parent == g->right))
// 	{
// 		rotate_right(n->parent);
// 		n = n->right;
// 	}
// 	case5(n);
// }

// void	case3(t_set *n)
// {
// 	t_set *u;
// 	t_set *gp;

// 	if ((u = uncle(n)) && u->color == RED)
// 	{
// 		n->parent->color = BLACK;
// 		u->color = BLACK;
// 		gp = grandparent(n);
// 		gp->color = RED;
// 		return (case1(gp));
// 	}
// 	else
// 		return (case4(n));
// }

// void	case2(t_set *n)
// {
// 	if (n->parent->color == BLACK)
// 		return ;
// 	else
// 		return (case3(n));
// }

// void	case1(t_set *n)
// {
// 	if (!n->parent)
// 		n->color = BLACK;
// 	else
// 		return (case2(n));
// }

// void	set_insert(t_set *root, t_room *r)
// {
// 	t_set	*ins;
// 	t_set	*parent;
// 	int		comp;

// 	if (!(comp = ft_strcmp(r->name, parent = set_add_find(root, r))))
// 		return ;
// 	ins = set_new_node(r);
// 	ins->parent = parent;
// 	insert_node(parent, ins, comp);
// 	return (case1(r));
// }

// int		is_left(t_set *node)
// {
// 	if (!node->parent || node->parent->left != node)
// 		return (0);
// 	return (1);
// }

// void	del_in_parent(t_set *node)
// {
// 	if (is_left(node))
// 		node->parent->left = NULL;
// 	else
// 		node->parent->right = NULL;
// }

// void	replace_in_parent(t_set *node)
// {
// 	t_set *tmp;

// 	if (!(tmp = node->left))
// 		tmp = node->right;
// 	if (is_left(node))
// 		node->parent->left = tmp;
// 	else
// 		node->parent->right = tmp;
// }

// void	delete_node(t_set *node)
// {
// 	if (!node->right && !node->left)
// 		del_in_parent(node);
// 	else if ((node->right && !node->left) || (!node->right && node->left))
// 		replace_in_parent(node);
// 	else
			
// }

// void	set_delete(t_set *root, t_room *r)
// {
// 	t_set *node;

// 	if (!(node = set_find(root, r)))
// 		return ;
// 	delete_node(node);
// }

// t_set	*set_init(t_room *r)
// {
// 	t_set	*root;

// 	if (!(root = (t_set *)ft_memalloc(sizeof(t_set))))
// 		exit (1);
// 	root->room = r;
// 	root->color = BLACK;
// 	return (root);
// }

t_set	*set_find(t_set *s, t_room *r)
{
	while (s)
	{
		if (!ft_strcmp(s->r->name, r->name))
			return (s);
		s = s->next;
	}
	return (NULL);
}

void	set_add(t_set **s, t_room *r, int distance, t_room *p)
{
	t_set *new;
	t_set *tmp;
	
	if (!(tmp = set_find(*s, r)))
	{
		if (!(new = (t_set *)malloc(sizeof(t_set))))
			exit (1);
		r->distance = distance;
		r->parent = p;
		new->r = r;
		new->next = *s;
		*s = new;
	}
	else
	{
		if (tmp->r->distance > distance)
		{
			tmp->r->distance = distance;
			tmp->r->parent = p;
		}
	}
}

t_set	*set_init(t_room *r)
{
	t_set *f;

	if (!(f = (t_set *)malloc(sizeof(t_set))))
		exit (1);
	f->next = NULL;
	f->r = r;
	return (f);
}

t_set	*set_min(t_set *s)
{
	int		distance;
	t_set	*ret;

	ret = NULL;
	distance = INF;
	while (s)
	{
		if (s->r->distance < distance)
		{
			ret = s;
			distance = s->r->distance;
		}
		s = s->next;
	}
	return (ret);
}

t_set	*set_del(t_set *s, t_room *r)
{
	t_set *prev;
	t_set *first;

	prev = NULL;
	first = s;
	while (s)
	{
		if (s->r == r)
		{
			r->flag = 0;
			if (prev)
				prev->next = s->next;
			else
				first = first->next;
			free(s);
			break ;
		}
		prev = s;
		s = s->next;
	}
	return (first);
}

t_path	*p_find(t_path *p, t_room *r)
{
	while (p)
	{
		if (p->room == r)
			return (p);
		p = p->next;
	}
	return (NULL);
}

void	step(t_set **s, t_room *w, t_path *tmp)
{
	t_link_list *l;

	l = w->links;
	while (l)
	{
		if (l->data->weight < INF && !p_find(tmp, l->data->dst))
			set_add(s, l->data->dst, l->data->weight + w->distance, w);
		l = l->next;
	}
}

//void	split_vertex(t_room *r)
//{

//}

t_link	*find_link(t_link_list *l, t_room *r)
{
	while (l)
	{
		if (l->data->dst == r)
			return (l->data);
		l = l->next;
	}
	return (NULL);
}

t_link_list	*del_link(t_link_list *l, t_room *r)
{
	t_link_list *prev;
	t_link_list *first;

	prev = NULL;
	first = l;
	while (l)
	{
		if (l->data->dst == r)
		{
			l->data->weight = INF;
			break ;
		}
		prev = l;
		l = l->next;
	}
	return (first);
}

t_path	*p_push_begin(t_room *r, t_path *p)
{
	t_path *new;

	if (!(new = (t_path *)malloc(sizeof(t_path))))
		exit (1);
	new->room = r;
	new->next = p;
	return (new);
}

t_path	*assemble_path(t_room *e, t_graph *g)
{
	t_path	*p;

	p = NULL;
	while (e)
	{
		p = p_push_begin(e, p);
		if (e->parent)
		{
			find_link(e->links, e->parent)->weight = -1;
			e->parent->links = del_link(e->parent->links, e);
		}
		e = e->parent;
	}
	return (p);
}

t_path  *dejkstra(t_set **s, t_graph *g, int max_path)
{
	t_path	*p;
	t_room	*w;
	t_path *tmp = NULL;

	if (!*s)
		return (NULL);
	w = g->start;
	while (w && w != g->end)
	{
		step(s, w, tmp);
		tmp = p_push_begin(w, tmp);
		*s = set_del(*s, w);
		if (!*s)
			return (NULL);
		w = set_min(*s)->r;
	}
	*s = set_del(*s, g->end);
	return (assemble_path(w, g));
}

// void	print_links(t_room *r)
// {

// }

void	print_path(t_path *p)
{
	while (p)
	{
		printf("%s\n", p->room->name);
		p = p->next;
	}
	printf("\n");
}

t_paths_list *plist_push_back(t_paths_list *p_list, t_path *p)
{
	t_paths_list *first;
	t_paths_list *new;
	first = p_list;
	if (!(new = (t_paths_list *)ft_memalloc(sizeof(t_paths_list))))
		exit (1);
	new->p = p;
	if (!first)
		return (new);
	while (p_list->next)
		p_list = p_list->next;
	p_list->next = new;
	return (first);
}

void	restore(t_set *s, t_path *p)
{
	t_set *tmp;

	while (s)
	{
		tmp = s;
		s->r->parent = NULL;
		s->r->flag = 0;
		s->r->distance = INF;
		s = s->next;
		free(tmp);
	}
	while (p)
	{
		p->room->parent = NULL;
		p->room->flag = 0;
		p->room->distance = INF;
		p = p->next;
	}
}

#include <string.h>
t_room *find_by_name(t_llist *r, char *name)
{
	while (r)
	{
		if (!strcmp(r->data->name, name))
			return (r->data);
		r = r->next;
	}
	return (0);
}

void    suurbale(t_graph *graph)
{
	t_set *s;
	int max_path;
	t_path *p;
	t_paths_list *p_list;
	t_room *dbg;
	max_path = count_links(graph->end);
	p_list = NULL;
	dbg = find_by_name(graph->rooms, "A_i5");
	//p = dejkstra(&s, graph, max_path);
	while (max_path--)
	{
		s = set_init(graph->start);
	 	if (!(p = dejkstra(&s, graph, max_path)))
	 		break ;
		p_list = plist_push_back(p_list, p);
		restore(s, p);
		graph->start->distance = 0;
	}
	while (p_list)
	{
		print_path(p_list->p);
		p_list = p_list->next;
	}
}
