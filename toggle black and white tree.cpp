#include <bits/stdc++.h>
using namespace std;
#define FAST 	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll 		long long
#define vi 		vector<int>
#define INF 	0x3f3f3f3f
#define MN 		100010
#define pb 		push_back
#define rep(X,Y) 		for (int (X) = 0;(X) < (int)(Y);++(X))
int n, col[MN];
vi G[MN];
int Store[MN][2][2];

int calc(int u, int prv, int curCol, int change)
{
	int i, j, flg, mi = INF, val1, val2, color;
	int &rlt = Store[u][curCol][change];//no of operation required to get all the subtrees nodes black when current color is curcolor and change applied for it is change
	if (rlt != -1)
		return rlt;

	flg = (curCol + change) % 2;
	rlt = change;
	for (auto v : G[u])
	{
		if (v == prv) 
			continue;
		if (change)
			color = 1 - col[v];
		else
			color = col[v];
		val1 = calc(v, u, color, 0);
		val2 = calc(v, u, color, 1);
		if (min(val1, val2) > n)
		{
			rlt = INF;
			return rlt;
		}
		mi = min(mi, abs(val1 - val2));
		if (val1 > val2)
		{
			rlt += val2;
			flg = 1 - flg;
		}
		else
		{
			rlt += val1;
		}
	}
	if (flg)
	{
		rlt += mi;
	}
	return rlt;
}


void Solve()
{
	int i, j, u, v;
	
	cin >> n;
	rep (i, n)
	{
		G[i].clear();
		Store[i][0][0] = Store[i][0][1] = Store[i][1][0] = Store[i][1][1] = -1;
	}
	rep (i, n)
	{
		cin >> col[i];
	}
	rep (i, n - 1)
	{
		cin >> u >> v;
		u--; v--;
		G[u].pb(v);
		G[v].pb(u);
	}
	int ans = min(calc(0, -1, col[0], 0), calc(0, -1, col[0], 1));
	if (ans > n)
		ans = -1;
	cout << ans << endl;
}

int main()
{
	FAST
	
	int tc;
	cin >> tc;
	while (tc--)
	{
		Solve();
	}
	return 0;
}