//chain reaction problem codejam 2022 qualification
//the first input is number of nodes
//next input are the value of nodes (all nodes index are from 1 to n), consider 0 index as the end node(let say NULL node)
//next inputs are node i pointing on what j node
//if the value Pointingto[i]=0 then it means it pointing the endpoint(you can say the NULL value)

#include<bits/stdc++.h>
using namespace std;
#define devesh_yadav92io ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define pb push_back
int main()
{
    devesh_yadav92io;
    ll fun[100], pointingto[100], temp1[100], child[100];
    vector<int> graph[100];
    queue<int> initiators;
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        
        cout << "Case #" << i << ": ";
        ll n, gg, zz, jj, yy = 0;
        cin >> n;
        for (int i = 0; i <= n; i++)
        {
            fun[i] = pointingto[i] = temp1[i] = child[i] = 0;
            graph[i].clear();
        }
        for (int i = 1; i <= n; i++) 
            cin >> fun[i];
        for (int i = 1; i <= n; i++)
        {
            cin >> gg;
            pointingto[i] = gg;
            graph[gg].pb(i);
            child[gg]++;
        }
        for (int i = 0; i <= n; i++) 
            if (child[i] == 0) 
                initiators.push(i);
        while (!initiators.empty())
        {
            gg = initiators.front();
            initiators.pop();
            zz = 1 << 30;
            for (int i = 0; i < graph[gg].size(); i++)//calculating the min value of the (max values of different branches)
            {
                if (temp1[graph[gg][i]] < zz)
                {
                    zz = temp1[graph[gg][i]];
                    jj = i;
                }
            }
            if(zz == 1 << 30) 
                zz = 0;
            for(int i = 0; i < graph[gg].size(); i++) //adding the values of branches
                if (i != jj) //which is not the minimum
                    yy += temp1[graph[gg][i]];//adding the max value
            temp1[gg] = max(fun[gg], zz);
            child[pointingto[gg]]--;
            if (child[pointingto[gg]] == 0) 
                initiators.push(pointingto[gg]);
        }
        cout << yy + temp1[0] << "\n";
    }

	return 0;
}