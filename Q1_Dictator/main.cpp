#include <iostream>
#include <limits.h>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct Edge{
	int x, y, w;
};

/* 
this function sorts the edges based on their w(weights).
output: An array with the index of edges from min to max
exaple: if the edges are stored as below:
1 2 96
1 3 9
2 3 79
the output of this function is like this: [1,2,0] 
*/
int* sort_edges_based_on_weights(int size, struct Edge *edges){
	int weights[size];
	int sorted_indexes[size];
	for(int i=0; i<size; i++){
		weights[i] = edges[i].w;
		sorted_indexes[i] = -100;
	}
	
	int min_weight = INT_MAX;
	int min_index = -1;
	for(int i=0; i<size; i++){
		min_weight = INT_MAX;
		min_index = -1;
		for(int j=0; j<size; j++){
			bool IsFound = false;
			for (int k=0; k<size; k++) {
		        if (sorted_indexes[k] == j) {
		            IsFound = true; // Set the flag to indicate that the value is found
		            break;     // No need to continue searching, exit the loop
		        }
		    }
			if(!IsFound && (weights[j] < min_weight)){
				min_weight = weights[j];
				min_index = j;
			}
		sorted_indexes[i] = min_index;
		}	
	}
	
	for(int i=0; i<size; i++){
		cout<<sorted_indexes[i]<<" ";
	}
	cout<<endl;
	
	return sorted_indexes;
}

//checks if the graphs is Acycle or contains a cycle. return True of Acycle.
bool isAcycle(int *selected){
	return false;
}

// Finds the next minimum edge in the MST
int find_next_edge(int number_of_nodes, int number_of_edges, struct Edge *edges, int *selected){
	cout<<*sort_edges_based_on_weights(number_of_edges, edges);
//	int* sorted_indexes = sort_edges_based_on_weights(number_of_edges, edges);
//	for(int i=0; i<number_of_edges; i++){
//		cout<<sorted_indexes[i]<<" ";
//	}
}


// performs the kruskal algorithm on the input and returns the weight. if the output is -1 it means the input is not suitable 
//for creating a MST. 
int kruskal(int number_of_nodes, int number_of_edges, int z, struct Edge *edges){
	int selected[number_of_nodes-1]; //	selected edges. To coprise a MST and avoid creating a cycle there will be number_of_nodes-1 edges in the graph.
	for(int i=0; i<number_of_nodes-1; i++) selected[i]=-1;
	selected[0] = z;
	find_next_edge(number_of_nodes, number_of_edges, edges, selected);
	
	
//	for(int i=0; i<number_of_edges; i++){
//		cout<<edges[i].x <<" "<< edges[i].y <<" "<< edges[i].w<<endl;
//	}
	return -1;
}


int main(int argc, char** argv) {
	int n, m;
	cin >> n >> m;
	int number_of_nodes = n; int number_of_edges = m;
	struct Edge edges[number_of_edges];
	for(int i=0; i<number_of_edges; i++){
		cin >> edges[i].x >> edges[i].y >> edges[i].w;
	}
	int z;
	cin>>z;

	kruskal(number_of_nodes, number_of_edges, z, edges);
	return 0;
}
