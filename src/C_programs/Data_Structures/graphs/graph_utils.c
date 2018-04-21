#include<stdio.h>
#include <stdlib.h>
#include "graph_utils.h"



/**@brief: Create graph structure and return the head pointer */

adl_graph_node* _create_graph(int max_ver) {

    adl_graph_node *ghead = (adl_graph_node *) malloc(sizeof(adl_graph_node) * max_ver);
    int i = 0;
    if (!ghead) {
        printf("\n create_graph: malloc failed !!");
        exit(-1);
    }

    /** Initialize vertex to -1 */
    for (i=0; i < max_ver; i++) {
        ghead[i].vertex = -1;
    }

    return ghead;
}


/** @brief: Create graph root to hold graph meta data 
 * and also creates a graph structure to hold graph nodes */

adl_graph_root* _create_graph_root(int max_ver, int graph_type) {

    adl_graph_root *groot = (adl_graph_root *) malloc(sizeof(adl_graph_root));
    if (groot) {
        groot->ghead = _create_graph(max_ver);
        groot->graph_type = graph_type;
        groot->max_ver = max_ver;
    } else {
        printf("\n create_graph_root failed");
        exit(-1);
    }

    return groot;
}


/**@brief: print contenets of graph  */

void _print_graph(adl_graph_root *groot, int vertices) {

    adl_graph_node *temp = NULL, *temp1 = NULL;
    int vertex = 0;
    if (!groot || !groot->ghead) {
        printf("\n graph is NULL ");
        return;
    }

    temp = groot->ghead;
    for (int i =0; i < groot->max_ver; i++) {

        /** loop through edges of each vertex */
        if (temp[i].vertex != -1) {

            printf("\n ######## Vertex: %d", temp[i].vertex);
            vertex = temp[i].vertex;
            temp1 = temp[i].edge;

            /** loop until all the edges from a vertex are done 
             * last node edge will have NULL */
            while (temp1) {

                printf("\n Edge from Vertex %d to %d", vertex, temp[i].vertex);
                temp1 = temp1[i].edge;
            }
        }
    }


}



/** @brief: insert a new edge into given graph 
 * edge_from: starting point of a edge 
 * edge_to: ending point of edge */

void _insert_graph_node(adl_graph_root *groot, int edge_from, int edge_to) {

    if (!groot || !groot->ghead) {
        printf("\n graph is NULL");
        return;
    }

    if (groot->graph_type == DIRECTED_GRAPH) {

        if(groot->ghead[edge_from].vertex == -1) {
            groot->ghead[edge_from].vertex = edge_from;
            groot->ghead[edge_from].edge = _create_graph(1);
            (groot->ghead[edge_from].edge)->vertex = edge_to;
            (groot->ghead[edge_from].edge)->edge = NULL;
            (groot->ghead[edge_from].edge)->weight = 0;
        } else {

            /** loop until last edge */
            adl_graph_node *temp = NULL;
            temp = groot->ghead[edge_from].edge;
            while(temp->edge) {
                temp = temp->edge;
            }

            temp->edge = _create_graph(1);
            temp->edge->vertex = edge_to;
            temp->edge->edge = NULL;
            temp->edge->weight = 0;

        }

    } else if (groot->graph_type == UNDIRECTED_GRAPH) {
        /** TODO */
    }



}


/**@brief: free memeory allocated to graph structure  */

void _free_graph(adl_graph_root *groot) {

    free(groot->ghead);
    free(groot);
}
