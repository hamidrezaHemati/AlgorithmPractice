#include <iostream>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct Edge{
	int x, y, w;
};

// searchs between available edges to find the one with minimum weight
int find_min_weight(struct Edge *edges, int *selected){
	return -1;	
} 

//checks if the graphs is Acycle or contains a cycle. return True of Acycle.
bool isAcycle(int *selected){
	return false;
}

// performs the kruskal algorithm on the input and returns the weight. if the output is -1 it means the input is not suitable 
//for creating a MST. 
int kruskal(int number_of_nodes, int number_of_edges, struct Edge *edges){
	int selected[number_of_nodes-1]; //	selected edges. To coprise a MST and avoid creating a cycle there will be number_of_nodes-1 edges in the graph.
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
	cout<<"checking"<<endl;
	cout<<"number of nodes: "<<number_of_nodes<<" number of edges: "<<number_of_edges<<endl;
	cout<<"number of edges based on sizof: "<<sizeof(edges)/sizeof(struct Edge)<<endl;
	for(int i=0; i<number_of_edges; i++){
		cout<<edges[i].x << edges[i].y << edges[i].w;
	}
	return 0;
}
