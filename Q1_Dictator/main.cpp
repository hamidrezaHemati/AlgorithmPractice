#include <iostream>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct Edge{
	int x, y, w;
};


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
