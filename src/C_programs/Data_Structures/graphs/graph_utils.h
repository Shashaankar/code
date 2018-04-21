
#if !defined(GRAPH_UTILS)
#define GRAPH_UTILS



#define DIRECTED_GRAPH 0
#define UNDIRECTED_GRAPH 1

/** Single node of a graph 
 * adl - Adjacency list representation */
typedef struct adl_graph_node {
    int vertex;
    int weight;
    /** Each edge points to another node */
    struct adl_graph_node  *edge;
}adl_graph_node;

typedef struct adl_graph_root {
    /** 0 - directed graph 
     *  1 - undirected graph */
    int graph_type;
    int max_ver;
    struct adl_graph_node  *ghead;
}adl_graph_root;


/** create a node for a vertex to hold */
void _adl_create_node();

/** Insert edge in one of the vertices */
void _adl_insert_edge(adl_graph_root *groot, int edge_from, int edge_to);


/** creates a graph with supplied number of vertices */
adl_graph_node* _create_graph(int max_ver);

/** Create graph root */
adl_graph_root* _create_graph_root(int max_ver, int graph_type);

/** print graph contents */
void _print_graph(adl_graph_root *groot, int vertices);


/** free memory allocated to adl graph */
void _free_graph(adl_graph_root *groot);

/** Insert an edge into graph */
void _insert_graph_node(adl_graph_root *groot, int edge_from, int edge_to);


#endif


