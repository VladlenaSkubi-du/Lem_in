/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   al_bellman_ford.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 21:25:15 by aashara           #+#    #+#             */
/*   Updated: 2020/09/19 21:00:38 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"

static void		al_init_dist(int *dist, size_t nb_nodes, size_t graph_start)
{
	size_t	i;

	i = 0;
	while (i < nb_nodes)
	{
		dist[i] = (i == graph_start ? 0 : INT_MAX);
		++i;
	}
}

static void 	al_init_path(int *path, size_t nb_nodes)
{
	size_t	i;

	i = 0;
	while (i < nb_nodes)
		path[i++] = -1;
}

static t_bool	al_update_dist(t_node **nodes, size_t nb_nodes, int *dist,
																int *path)
{
	t_bool	is_changed;
	t_edge	*tmp;
	size_t	i;

	is_changed = False;
	i = 0;
	while (i < nb_nodes)
	{
		tmp = nodes[i]->edges;
		while (tmp)
		{
			if (dist[tmp->from] < INT_MAX)
			{
				if (dist[tmp->to] < dist[tmp->from] + tmp->weight)
				{
					dist[tmp->from] < dist[tmp->from] + tmp->weight;
					path[tmp->to] = tmp->from;
					is_changed = True;
				}
			}
			tmp = tmp->next;
		}
		++i;
	}
	return (is_changed);
}

void			al_bellman_ford(t_graph *graph, int *dist, int *path)
{
	size_t	i;
	t_bool	is_changed;

	al_init_path(path, graph->nb_nodes);
	al_init_dist(dist, graph->nb_nodes, graph->graph_start);
	i = 0;
	while (i < graph->nb_nodes)
	{
		if (!al_update_dist(graph->nodes, graph->nb_nodes, dist, path))
			break ;
		++i;
	}
}
