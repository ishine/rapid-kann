#include <stdlib.h>
#include <stdio.h>
#include "kann.h"
#include "kautodiff.h"

int main(int argc, char *argv[]) {

	kad_node_t *t;
	kann_t *nn;
	float input[5] = {0.1, 0.2, 0.3, 0.4, 0.5};

	printf("sizeof(kad_node_t): %d \n", sizeof(kad_node_t));
	t = kann_layer_input(5);
	printf("Show the dimension:");
	printf("Dimension: %d \n", t->n_d);
	
	printf("Size of dim 0 (t->d[0]): %d \n", t->d[0]);
	printf("Size of dim 1 (t->d[1]): %d \n", t->d[1]);
	printf("Size of dim 2 (t->d[2]): %d \n", t->d[2]);
	printf("Size of dim 3 (t->d[3]): %d \n", t->d[3]);
	printf("N children: %d \n", t->n_child);

	printf("t->x: %f \n", t->x);
	printf("Adding a dense layer:\n");

	t = kann_layer_dense(t, 10);
	printf("Dimension: %d \n", t->n_d);
	printf("N children: %d \n", t->n_child);
	printf("t->child[0]->x: %f \n", t->child[0]->x);
	printf("t->child[1]->x: %f \n", t->child[1]->x);
	printf("t->child[0]->child[0]->x: %f \n", t->child[0]->child[0]->x);

	printf("t->child[0]->child[1]->x[0]: %f \n", t->child[0]->child[1]->x[0]);
	printf("t->child[0]->child[1]->x[9]: %f \n", t->child[0]->child[1]->x[9]);
	printf("t->child[0]->child[1]->x[10]: %f \n", t->child[0]->child[1]->x[10]);
	printf("t->child[0]->child[1]->x[49]: %f \n", t->child[0]->child[1]->x[49]);
	printf("t->child[0]->child[1]->x[50]: %f \n", t->child[0]->child[1]->x[50]);

	// List bias 
	printf("t->child[1]->x: %f \n", t->child[1]->x[0]);
	printf("t->child[1]->x: %f \n", t->child[1]->x[1]);
	printf("t->child[1]->x: %f \n", t->child[1]->x[2]);
	printf("t->child[1]->x: %f \n", t->child[1]->x[3]);
	printf("t->child[1]->x: %f \n", t->child[1]->x[4]);
	printf("t->child[1]->x: %f \n", t->child[1]->x[5]);
	printf("t->child[1]->x: %f \n", t->child[1]->x[6]);
	printf("t->child[1]->x: %f \n", t->child[1]->x[7]);
	printf("t->child[1]->x: %f \n", t->child[1]->x[8]);
	printf("t->child[1]->x: %f \n", t->child[1]->x[9]);
	printf("t->child[1]->x: %f \n", t->child[1]->x[10]);

	
	// printf("t->child[1]->x[0]: %f \n", t->child[1]->x[0]);
	// printf("t->child[1]->x[9]: %f \n", t->child[1]->x[9]);
	// printf("t->child[2]->x: %f \n", t->child[2]->x);
	// printf("t->child[3]->x: %f \n", t->child[3]->x);
	// printf("t->child[1]->x[11]: %f \n", t->child[1]->x[11]);
	// if(t->child[1]->x[0]) {
	// 	printf("t->child[1]->x[11]: %f \n", t->child[1]->x[]);
	// }

	// printf("t->child[0]->n_child: %d \n", t->child[0]->n_child);
	// printf("t->child[0]->x: %f \n", t->child[0]->x);
	// printf("t->child[1]->x: %f \n", t->child[1]->x);
	// // printf("t->child[1]->x: %f \n", t->child[1]->x);
	// // printf("t->child[1].n_child: %d \n", t->child[1]->n_child);
	// printf("t->child[2].n_child: %d \n", t->child[2]->n_child);
	// printf("t->child[3].n_child: %d \n", t->child[3]->n_child);
	// printf("t->child[4].n_child: %d \n", t->child[4]->n_child);
	// printf("t->child[5].n_child: %d \n", t->child[5]->n_child);
	// if (!t->pre) {
	// 	printf("t has no pre!\n");
	// }
	// t = kann_layer_cost(t, 1, KANN_C_CEM);
	// printf("Initialize a neural net \n");
	// nn = kann_new(t, 0);
	// printf("Number of nodes in nn: %d \n", nn->n);
	// printf("nn->x[0]: %f \n", nn->x[0]);
	// printf("t->child[0]->x[0]: %f \n", t->child[0]->x[0]);
	// printf("nn->x[1000]: %f \n", nn->x[10]);



	// printf("nn->v[0]->x: %f\n", nn->v[0]->x);
	// printf("nn->x[1]: %f \n", nn->x[1]);
	// printf("nn->v[1]->x: %f\n", nn->v[1]->x);
	// // printf("nn->x[2]: %f \n", nn->x[2]);
	// printf("nn->v[1]->x[1]: %f \n", nn->v[1]->x[1]);
	// printf("nn->v[1]->x[9]: %f \n", nn->v[1]->x[9]);
	// printf("nn->v[1]->x[10]: %f \n", nn->v[1]->x[10]);
	// printf("nn->v[1]->x[12]: %f \n", nn->v[1]->x[12]);
	// // printf("nn->x[11]: %f \n", nn->x[11]);
	// // printf("nn->x[12]: %f \n", nn->x[12]);

	return 0;
}