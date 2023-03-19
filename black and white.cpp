#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define vll vector<ll>
ll INF = 1e18;
const int N = 3e5 + 11, mod = 1e9 + 7;

ll min(ll a, ll b) { return ((a > b) ? b : a); }

int a[N], b[N];
long long black[N], white[N], none[N];
//white means the number of operation required to make subtree every node acc to req array b after making it complete white
//black means the number of operation required to make subtree every node acc to req array b after making it complete black
//none means the number of operation required to make subtree every node acc to req array b after making it no change

vll v[N];
void dfs(int u, int p)
{
    if (b[u])// agar node black hai to 
        white[u]++; //white se black karna hai to one operation to chahiye for that node
        //because pura tree white ho chuka hai
        //ab black agar banana hai vo particular node to 1 operation add karna padega
    else
        black[u]++;
    for (auto x : v[u])
    {
        if (x == p)
            continue;
        dfs(x, u);
        //here in below line 1 is added in white and black because
        //ab hum yaha pe vo operation add kar rahe hai jab hum us child node vale tree ko purra black ya pura white kar denge, isliye vo ek operation add kar rahe hai
        none[u] += min(min(none[x], 1 + white[x]), 1 + black[x]);


        //agar b[u] =1 hai to 1 opearation hum sabse upar add kar chuke hai in 21 line
        //matlab tree white hone par white hone par agar us node ko black karna hai to ek operation lagana padega 
        //usse pura subtree black ho jayega
        if (b[u])
        {
            black[u] += black[x];
            //ab agar sare nodes bhi black ho gaye to sab nodes ko  black se required color par jana hai to sabke black nodes add karenge


            white[u] += black[x];// white tree hone par humne upar ek opearation add kiya hua hai jisse tree vapas black ho jayega kyunki 
            //u node ko black  karne ke liye uski zarrorat hai jo hum add kar chuke hai
            //to ab fir vahi upar vala case, sab black nodes se require vale par zana hai to add the blacks
        }
        if (!b[u])
        {
            white[u] += white[x];
            black[u] += white[x];
        }
    }
    if (a[u] != b[u])
        none[u] = 1e9;
    return;
}
void sol(void)
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i], v[i].clear(), black[i] = white[i] = none[i] = 0;
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    for (int i = 1; i <= n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
    }
    dfs(1, -1);
    cout << min(min(1 + black[1], none[1]), 1 + white[1]) << '\n';
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int test = 1;
    cin >> test;
    while (test--)
        sol();
}