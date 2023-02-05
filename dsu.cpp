// Disjoint Set Union (DSU) : Union by Rank and Path Compression

#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int parent[100000];
int ran[100000];

void makeSet()
{
    for (int i = 1; i < 100000; i++)
    {
        parent[i] = i;
        ran[i] = 0;
    }
    return;
}

int findPar(int node)
{
    if (node == parent[node])
    {
        return node;
    }
    return parent[node] = findPar(parent[node]); // By this simple addition, we have done the path compression thing
    // It simply updates the parent of all, if traverses that path
    // return findPar(parent[node])
}

void unionSet(int x, int y)
{
    x = findPar(x);
    y = findPar(y);

    if (ran[x] < ran[y])
    {
        parent[x] = y;
    }
    else if (ran[x] > ran[y])
    {
        parent[y] = x;
    }
    else
    {
        parent[x] = y;
        ran[y]++;
    }
    return;
}

int main()
{
    makeSet();
    int m;
    cin >> m;
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        unionSet(u, v);
    }
    int a, b;
    cin >> a >> b;
    if (findPar(a) != findPar(b))
    {
        cout << "Different Components"
             << "\n";
    }
    else
    {
        cout << "Same Components"
             << "\n";
    }
    return 0;
}