/**
	Problema: Uri 1123
	accepted - 15/09/2016. Time 0.012ms
	Solução: 
			Djkstra modificado. A idéia é usar djkstra normalmente, mas com a condição de que quando se esta visitando as cidades que pertencem a rota, não se deve sar, o que quer dizer que a atualização dos pesos dos adjacentes nesse caso so pode ser feita para v+1, em que v é a cidade atual e v+1 é a proxima cidade da rota. 
	Obs: devem ser considerados pedágios de custo 0.  
**/
#include <bits/stdc++.h>
#define maxn 255

using namespace std;

struct node {
	int vertice, peso;
	node(int a, int b) : vertice(a), peso(b) {}
	bool operator < (node p) const { return peso > p.peso; }
};

int grafo[maxn][maxn], distancia[maxn], n, m, c, k;

int djkstra(int origem) {
	for (int i = 0; i < n; i++) distancia[i] = INT_MAX;

	priority_queue< node > q;
	q.push(node(origem, 0));
	distancia[origem] = 0;

	while(!q.empty()) {
		node topo = q.top(); q.pop(); 
		int u = topo.vertice;
		if (u == c-1) return distancia[u];		
		for (int i = 0; i < n; i++) {
			if (grafo[u][i] != -1) {
				if (u < c) {
					if (i != u+1) continue;
					if(distancia[i] > distancia[u] + grafo[u][i]) {
						distancia[i] = distancia[u] + grafo[u][i];
						q.push(node(i, distancia[i]));
					}
 				}else {
					if (distancia[i] > distancia[u]+grafo[u][i]) {
						distancia[i] = distancia[u]+grafo[u][i];
						q.push(node(i, distancia[i]));
					}
				}
			}
		}
	}	
	
	return distancia[c-1];
}

int main () {
	while (scanf("%d %d %d %d", &n, &m, &c, &k) && n) {
		for (int i = 0; i < n; i++)
			for (int j = i; j < n; j++) {
				grafo[i][j] = -1;
				grafo[j][i] = -1;
			}
		for (int i = 0; i < m; i++) {
			int x, y, z;
			scanf("%d %d %d", &x, &y, &z);
			grafo[x][y] = z;
			grafo[y][x] = z;
		}
		
		printf("%d\n", djkstra(k));
	}

	return 0;
}
