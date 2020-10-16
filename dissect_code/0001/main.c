#include <stdlib.h>
#include <stdio.h>
#include "kann.h"
#include "kautodiff.h"

// Traverse the computational graph
void traverse(kad_node_t* t) {
	kad_node_t *tmp = t;
	if (!tmp) return;
	if (tmp->node_flag == DENSE_W) {
		printf("I found dense_w, tmp->n_d: %d \n", tmp->n_d);
		if (tmp->n_d == 2) {
			for (int i=0; i<tmp->n_d; i++) {
				int d = tmp->d[i];
				for (int j=0; j<tmp->d[i]; j++) tmp->x[i*d+j] = 0.5;
			}
		} else if (tmp->n_d == 1) {
			for (int i=0; i<tmp->n_d; i++) tmp->x[i] = 0.5;
		}
		
	} else if (tmp->node_flag == DENSE_B) {
		printf("I found dense_B, tmp->n_d: %d \n", tmp->n_d);
		if (tmp->n_d == 2) {
			for (int i=0; i<tmp->n_d; i++) {
				int d = tmp->d[i];
				for (int j=0; j<tmp->d[i]; j++) tmp->x[i*d+j] = 0.5;
			}
		} else if (tmp->n_d == 1) {
			for (int i=0; i<tmp->n_d; i++) tmp->x[i] = 0.5;
		}

	}
	if (tmp->child) {
		traverse(tmp->child[0]);
		traverse(tmp->child[1]);
	}
}

int main(int argc, char *argv[]) {

	kad_node_t *t;
	kann_t *nn;
	float input[5] = {0.1, 0.2, 0.3, 0.4, 0.5};

	printf("sizeof(kad_node_t): %d \n", sizeof(kad_node_t));
	t = kann_layer_input(5);
	printf("The current graph: z = x; z is t; \n");
	printf("Show the dimension:");
	printf("Dimension: %d \n", t->n_d);
	
	printf("Size of dim 0 (t->d[0]): %d \n", t->d[0]);
	printf("Size of dim 1 (t->d[1]): %d \n", t->d[1]);
	printf("Size of dim 2 (t->d[2]): %d \n", t->d[2]);
	printf("Size of dim 3 (t->d[3]): %d \n", t->d[3]);
	printf("N children: %d \n", t->n_child);

	printf("t->x: %f \n", t->x);
	printf("Adding a dense layer:\n");

	// In dense layer, it add 2 nodes: weight (w) and (bias)
	// the weight and input are cmul together, the 
	t = kann_layer_dense(t, 10);
	printf("The current graph: z = w*x + b ; z:t, wx: t -> child[0], b:t->child[1]\n");
	printf("Dimension: %d \n", t->n_d);
	printf("N children: %d \n", t->n_child);
	printf("t->child[0]->x: %f \n", t->child[0]->x);
	printf("t->child[1]->x: %f \n", t->child[1]->x);

	// Input has no value
	printf("t->child[0]->child[0]->x: %f \n", t->child[0]->child[0]->x);

	// List weight value. There are 50 values.
	if (t->child[0]->child[1]->node_flag == DENSE_W) {
		printf("Since wx = t -> child[0], x: t->child[0]->child[0], w: t->child[0]->child[1] \n");
	}

	printf("t->child[0]->child[1]->x[0]: %f \n", t->child[0]->child[1]->x[0]);
	printf("t->child[0]->child[1]->x[9]: %f \n", t->child[0]->child[1]->x[9]);
	printf("t->child[0]->child[1]->x[10]: %f \n", t->child[0]->child[1]->x[10]);
	printf("t->child[0]->child[1]->x[49]: %f \n", t->child[0]->child[1]->x[49]);
	printf("t->child[0]->child[1]->x[50]: %f \n", t->child[0]->child[1]->x[50]);

	// List bias 
	printf("t->child[1]->x[0]: %f \n", t->child[1]->x[0]);
	printf("t->child[1]->x[1]: %f \n", t->child[1]->x[1]);
	printf("t->child[1]->x[2]: %f \n", t->child[1]->x[2]);
	printf("t->child[1]->x[3]: %f \n", t->child[1]->x[3]);
	printf("t->child[1]->x[4]: %f \n", t->child[1]->x[4]);
	printf("t->child[1]->x[5]: %f \n", t->child[1]->x[5]);
	printf("t->child[1]->x[6]: %f \n", t->child[1]->x[6]);
	printf("t->child[1]->x[7]: %f \n", t->child[1]->x[7]);
	printf("t->child[1]->x[8]: %f \n", t->child[1]->x[8]);
	printf("t->child[1]->x[9]: %f \n", t->child[1]->x[9]);
	printf("t->child[1]->x[10]: %f \n", t->child[1]->x[10]);

	// Add an output layer 
	printf("Add an output layer \n");
	t = kann_layer_dense(t, 1);
	printf("Now, the graph will become z' = w_1 * x_1 + b_1 where x_1 = wx+b \n");
	printf("t->child[1] is b_1, the value of bias is: \n");
	printf("t->child[1]->x[0]: %f \n", t->child[1]->x[0]);
	printf("t->child[0]->child[1] is the weight of w_1, its values are as follow: \n");
	printf("t->child[0]->child[1]->x[0]: %f \n", t->child[0]->child[1]->x[0]);
	printf("t->child[0]->child[1]->x[9]: %f \n", t->child[0]->child[1]->x[9]);
	printf("since w_1 only has 10 weights, x[10] will be 0 \n");
	printf("t->child[0]->child[1]->x[10]: %f \n", t->child[0]->child[1]->x[10]);

	printf("The bias b is t->child[0]->child[0]->child[1] now:  \n");
	printf("t->child[0]->child[0]->child[1]->x[0]: %f \n", t->child[0]->child[0]->child[1]->x[0]);
	printf("The weight w is t->child[0]->child[0]->child[0]->child[1] now \n");
	printf("t->child[0]->child[0]->child[0]->child[1]->x[0]: %f \n", t->child[0]->child[0]->child[0]->child[1]->x[0]);
	printf("t->child[0]->child[0]->child[0]->child[1]->x[49]: %f \n", t->child[0]->child[0]->child[0]->child[1]->x[49]);
	printf("t->child[0]->child[0]->child[0]->child[1]->x[50]: %f \n", t->child[0]->child[0]->child[0]->child[1]->x[50]);
	
	// Add sigmoid activation function
	printf("Add sigmoid activation function \n");
	t = kad_sigm(t);
	t->ext_flag = KANN_F_OUT;
	printf("Now, the t->child[0] is : z = sigm(w_1 * x_1 + b_1) \n");
	printf("The b_1 is : t->child[0]->child[1] \n");
	printf("The b_1 is : t->child[0]->child[1]->x[0] %f \n", t->child[0]->child[1]->x[0]);
	printf("The w_1 is : t->child[0]->child[0]->child[1] \n");
	printf("The w_1 is : t->child[0]->child[0]->child[1]->x[0] %f \n", t->child[0]->child[0]->child[1]->x[0]);
	printf("The w_1 is : t->child[0]->child[0]->child[1]->x[9] %f \n", t->child[0]->child[0]->child[1]->x[9]);
	printf("The w_1 is : t->child[0]->child[0]->child[1]->x[10] %f \n", t->child[0]->child[0]->child[1]->x[10]);
	// printf("t->child[0] is y and t->child[1] is z \n");
	// printf("t->child[1]->child[0]: sigmoid \n");
	// printf("t->child[1]->child[0]->child[0] is w*x \n");
	// printf("t->child[1]->child[0]->child[1] is b \n");
	// printf("t->child[1]->child[0]->child[0]->child[1] is w \n");
	// printf("t->child[1]->child[0]->child[0]->child[0] is x \n");
	// printf("Check the weight of w: \n");
	// printf("t->child[1]->child[0]->child[0]->child[1]->x[0]: %f \n", t->child[1]->child[0]->child[0]->child[1]->x[0]);
	// printf("t->child[1]->child[0]->child[0]->child[1]->x[49]: %f \n", t->child[1]->child[0]->child[0]->child[1]->x[49]);
	// t = kad_sigm(t);
	// t->ext_flag = KANN_F_OUT;
	
	

	// Cost function is not important in our case.
	// t = kann_layer_cost(t, 1, KANN_C_CEB);
	// printf("t->child[0]->child[0]->x: %f \n", t->child[0]->child[0]->x);
	// printf("============= \n");

	// Build the neural network
	// nn = kann_new(t, 0);
	// printf("nn->n: %d \n", nn->n);
	// 
	// float *y;
	// y = kann_apply1(nn, input);
	// printf("y: %f \n", *y);
	// printf("y: %f \n", y[0]);


	// Allocate weight
	// traverse(t);
	


	return 0;
}