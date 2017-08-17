#include <iostream>
#include <list>
#include <queue>
#include <stack>

using namespace std;


class Grafo
{
	int V; 
	list<int> *adj; 

public:
	Grafo(int V);
	void addAresta(int x, int y);
	void dfs(int x);
};

Grafo::Grafo(int V) {
	this->V = V;
	adj = new list<int>[V];
}

void Grafo::addAresta(int x, int y) {
	adj[x].push_back(y);
}

void Grafo::dfs(int r) {
	stack<int> pilha;
	bool visitados[V];

	for (int i = 0; i < V; ++i)
		visitados[i] = false;

	while(true) {
		if (!visitados[r])
		{
			std::cout << "Visitando Vértice " << r << std::endl;
			visitados[r] = true; // mArca como visitado
			pilha.push(r);
		}
		bool encontrou = false;
		list<int>::iterator it;

		//busca de vizinho não visitado
		for (it = adj[r].begin(); it != adj[r].end(); it++)
		{
			if (!visitados[*it])
			{
				encontrou = true;
				break;
			}
		}
		if (encontrou == true)
		{
			r = *it;
		} else {
			//ou todos os vizinhos estão vizitados ou não tem vizinhos
			pilha.pop();
			if (pilha.empty())
			{
				break; //pilha vazia
			}
			r = pilha.top();
		}
	}
}

int main(int argc, char const *argv[])
{
	Grafo graph(4);

	graph.addAresta(0,1);
    graph.addAresta(0,3);
    graph.addAresta(1,2);
    graph.addAresta(3,1);
    graph.addAresta(3,2);

    graph.dfs(0); 
	return 0;
}
