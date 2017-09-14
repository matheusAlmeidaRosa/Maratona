#include <bits/stdc++.h>
#define maxn 49

using namespace std;

struct M {
	int m[maxn][maxn];
};

struct cmp {
	bool operator()(M a, M b) {
		for (int i = 0; i < maxn; i++) {
			for (int j = 0; j < maxn; j++) {
				if (a.m[i][j] != b.m[i][j]) {
					return false;
				}  
			}
		}
		return true;
	}
};

int visitado[maxn], n;
vector<int> g[maxn];
int dp[maxn][maxn];
set<M, cmp> S;

void dfs(int pai, int nivel, int indice) {
	visitado[pai] = 1;
	int cont = 0;
	for (int i = 0; i < g[pai].size(); i++) {
		if (!visitado[g[pai][i]]) {
			dfs(g[pai][i], nivel+1, cont++);
		}
	}
	
	dp[nivel][indice] = cont;
}

int main () {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int m; scanf("%d", &m);
		for (int i = 2; i <= m; i++) {
			int a; scanf("%d", &a);
			g[i].push_back(a);
			g[a].push_back(i);
		}

		memset(visitado, 0, sizeof visitado);
		memset(dp, 0, sizeof dp);
		dfs(1, 0, 0);

		M novo;
		for (int i = 0; i < maxn; i++) {
			for (int j = 0; j < maxn; j++) {
				novo.m[i][j] = dp[i][j];
				cout << novo.m[i][j] << ' ';
			}cout << endl;
		}cout << endl;

		S.insert(novo);

		for (int i = 0; i < maxn; i++) {
			g[i].clear();
		}
	}

	printf("%u\n", S.size());
} 