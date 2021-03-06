/*
 ================================
| uri 1205 - accept              |  
| theme: caminho minimo          |
| complexity: O(ElogV)           |
| time: 0.244s                   |	
 ================================
*/

#include <bits/stdc++.h>
#define maxn 1009
#define inf 0x3f3f3f3f

using namespace std;

struct no {
	int v, qtd;
	no() {}
	no(int v, int qtd) : v(v), qtd(qtd) {}
	bool operator < (const no &outro) const {
		return qtd > outro.qtd;
	}
};

vector<int> g[maxn];
int atiradores[maxn];

int dijkstra(int s, int t) {
	int qtd[maxn]; memset(qtd, inf, sizeof qtd);
	priority_queue<no> pq;
	pq.push(no(s, atiradores[s]));
	qtd[s] = atiradores[s];

	while (!pq.empty()) {
		no tmp = pq.top(); pq.pop();
		int u = tmp.v;
		if (u == t) return qtd[u];
		for (int i = 0; i < g[u].size(); i++) {
			int v = g[u][i];
			if (qtd[v] > qtd[u] + atiradores[v]) {
				qtd[v] = qtd[u] + atiradores[v];
				pq.push(no(v, qtd[v]));
			}
		}
	}

	return inf;
}

int main () {
	int n, m, k;
	long double p;


	while (scanf("%d %d %d %Lf", &n, &m, &k, &p) != EOF) {
		for (int i = 0; i < m; i++) {
			int a, b; scanf("%d %d", &a, &b);
			g[a].push_back(b);
			g[b].push_back(a);	
		}

		int a; scanf("%d", &a);

		for (int i = 0; i < a; i++) {
			int pos; scanf("%d", &pos);
			atiradores[pos]++;
		}

		int s, t; scanf("%d %d", &s, &t);

		int ans = dijkstra(s, t);
		if (ans > k) {
			printf("0.000\n");
		} else {
			printf("%.3Lf\n", pow(p, ans));
		}

		for (int i = 0; i <= n; i++) {
			g[i].clear();	
			atiradores[i] = 0;
		}
	}

	return 0;
}
