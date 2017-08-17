#include <iostream>
#include <list>
#include <queue>

using namespace std;

class Grafo {
	int V; //Número de vértices
	list<int> *adj; //ponteiro para um array contendo as listas de adjacencias
public:
	Grafo(int V);//Construtor
	void addAresta(int v1, int v2); //Adiciona uma aresta no grafo
 	void bfs(int v);
};

Grafo::Grafo(int V) {
	this->V = V;
	adj = new list<int>[V];//Cria as listas
}

void Grafo::addAresta(int v1, int v2) {
	// Adiciona v2 à lista de adjacencia de v1
	adj[v1].push_back(v2);
}

void Grafo::bfs(int v) {
	
	queue<int> fila;
	bool visitados[V]; // Vetor de visitados

	for (int i = 0; i < V; i++)
	{
		visitados[i] = false;
	}

	cout << "Visitando vertice " << v << endl;
	visitados[v] = true;

	while(true){ 
		
		list<int>::iterator it;
		for (it = adj[v].begin();it != adj[v].end(); it++)
		{
			if (!visitados[*it])
			{
				cout << "Visitando vertice " << *it << endl;
				visitados[*it] = true; // visitado
				fila.push(*it);// vai pra fila
			}
		}

		if (!fila.empty())
		{
			v = fila.front();
			fila.pop();
		} else {
			break;
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

    graph.bfs(0);
    return 0;
}
