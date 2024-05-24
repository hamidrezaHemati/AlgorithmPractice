#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct Edge{
	int x, y, w;
};

/* 
Finds the next minimum edge in the MST using sorted_indexes and edge weight values.
*/
int find_next_edge(int number_of_nodes, int number_of_edges, struct Edge *edges, int *selected, int *sorted_indexes){
	int MST_size = number_of_nodes - 1; 
	for(int i=0; i<number_of_edges; i++){
		bool wasSelected = false;
		for(int j=0; j<MST_size; j++){
			if(selected[j] == sorted_indexes[i]){
				wasSelected = true;
				break;
			}
		}
		if(wasSelected){
			continue;
		}
		else{
			return sorted_indexes[i];
		}
	}
}

int find(int *parents, int v) {
    if (parents[v] == -1) {
        return v;
    }
    // Path compression step: set the parent of v to the root
    parents[v] = find(parents, parents[v]);
    return parents[v];
}




// Checks if adding an edge creates a cycle
bool isAcycle(int *selected, int candidate, struct Edge *edges, int number_of_nodes, int number_of_edges, int *parents, int *ranks) {
	cout<<"parents"<<endl;
	for(int i=0; i<number_of_nodes; i++){
		cout<<parents[i]<<" ";
	}
	cout<<"ranks"<<endl;
	for(int i=0; i<number_of_nodes; i++){
		cout<<ranks[i]<<" ";
	}
	cout<<"in is asycle"<<endl;
	int s = edges[candidate].x-1;
	int d = edges[candidate].y-1;
	int wt = edges[candidate].w;
	cout<<"candidate: "<<candidate<<" s: "<<s<<" d: "<<d<<" w: "<<wt;
	int s_parent = find(parents, s);
	int d_parent = find(parents, d);
	cout<<s<<" "<<d<<" "<<wt<<endl;
	cout<<"parent of x: "<<s_parent<<" parent of y: "<<d_parent<<endl;
	
	if (s_parent == d_parent){
		return false;
	}
	//RANK
	if(ranks[s] > ranks[d])	//s has higher rank
		parents[d] = s;
	else if(ranks[s] < ranks[d])	//d has higher rank
		parents[s] = d;
	else
	{
		//Both have same rank and so anyone can be made as parent
		parents[d] = s;
		ranks[s] +=1;		//Increase rank of parent
	}
	return true;
	
}

 
/* 
Performs the kruskal algorithm on the input and returns the weight. if the output is -1 it means the input is not suitable 
for creating a MST.
First this function sorts the edges based on their w(weights).
output: An array with the index of edges from min to max
exaple: if the edges are stored as below:
1 2 96
1 3 9
2 3 79
the output of this function is like this: [1,2,0] 
*/
int kruskal(int number_of_nodes, int number_of_edges, int z, struct Edge *edges){
	int MST_size = number_of_nodes-1;
	int selected[MST_size]; //	selected edges. To coprise a MST and avoid creating a cycle there will be number_of_nodes-1 edges in the graph.
	for(int i=0; i<MST_size; i++) selected[i]=-1;
	selected[0] = z-1;
	
	////////////////////////////////////////////// Sorting
	int size = number_of_edges;
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
	////////////////////////////////////// Selecting edges
	cout<<"selected edges before: ";
	for(int i=0; i<number_of_nodes-1; i++){
		cout<<selected[i]<<" ";
	}
	cout<<endl;
	cout<<"sorted indexes: ";
	for(int i=0; i<number_of_edges; i++){
		cout<<sorted_indexes[i]<<" ";
	}
	cout<<endl;
	
	int parents[number_of_nodes];
    int ranks[number_of_nodes];
    for(int i=0; i<number_of_nodes; i++){
    	parents[i] = -1;
    	ranks[i] = 0;
	}
	int s = edges[selected[0]].x-1;
	int d = edges[selected[0]].y-1;
	parents[d] = s;
	ranks[s] += 1;
	
	for(int i=0; i<MST_size; i++){
		int candidate = find_next_edge(number_of_nodes, number_of_edges, edges, selected, sorted_indexes);
		cout<<"candidate: "<<candidate<<endl;
		if(isAcycle(selected, candidate, edges, number_of_nodes, number_of_edges, parents, ranks)){
			for(int j=0; j<MST_size; j++){
				if(selected[j] == -1){
					selected[j] = candidate;
				}
			}
		}	
	}
	
	cout<<"selected edges: "<<endl;
	for(int i=0; i<number_of_nodes-1; i++){
		cout<<selected[i]<<" ";
	}
	
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
