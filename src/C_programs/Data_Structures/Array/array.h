
#if !defined(ARRAY_DS)
#define ARRAY_DS

void _print_array(int *parr, int size);
int sanity_check_array(int *parr, int size);

/** Array data structures header file */


#define MIN(_a, _b) ((_a > _b) ? _b:_a)
#define MAX(_a, _b) ((_a > _b) ? _a:_b)

#endif /** ARRAY_DS */
