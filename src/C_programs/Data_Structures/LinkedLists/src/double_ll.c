#include "ll_util.h"


dll_node_s *dll_root = NULL;

int main () {

    unsigned int middle_key=0;
    _insert_dll_node_last(&dll_root, 1, 0);
    _print_middle_node_key();
    _print_dll_top();

    _insert_dll_node_last(&dll_root, 2, 0);
    _print_middle_node_key();
    _print_dll_top();

    _insert_dll_node_last(&dll_root, 3, 0);
    _print_middle_node_key();
    _print_dll_top();
    
    _remove_dll_top(&dll_root);
    _print_middle_node_key();
    _print_dll_top();

    _insert_dll_node_last(&dll_root, 4, 0);
    _print_middle_node_key();
    _print_dll_top();

    _print_dll_nodes(&dll_root);

    _free_dll_nodes(&dll_root);
    _print_middle_node_key();
    _print_dll_top();


}
