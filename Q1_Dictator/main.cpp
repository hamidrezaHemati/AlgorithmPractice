#include <iostream>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n, m;
	cin >> n >> m;
	int nodes = n; int edges = m;
	int weight, x_node, y_node;
	for(int i=0; i<edges; i++){
		cin >> x_node >> y_node >> weight;
	}
	cout<<"checking"<<endl;
	cout<<"number of nodes: "<<nodes<<" number of edges: "<<edges<<endl;
	cout<<x_node<<weight;
	return 0;
}
