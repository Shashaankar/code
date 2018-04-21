#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <error.h>
#include "graph_utils.h"




void main() {

    int max_ver = 10;
    adl_graph_root *groot = NULL;
    groot = _create_graph_root(max_ver, DIRECTED_GRAPH);


    /** Edges */
    _insert_graph_node(groot, 1, 2);
    _insert_graph_node(groot, 2, 7);
    _insert_graph_node(groot, 3, 6);
    _insert_graph_node(groot, 4, 3);
    _insert_graph_node(groot, 5, 2);
    _print_graph(groot, max_ver);

    _free_graph(groot);

} 
