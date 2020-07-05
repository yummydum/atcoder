#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define _GLIBCXX_DEBUG
#define rep(i, c) for (int i = 0; i < (int)c; i++)
#define debug(x) cout << #x << " = " << x << endl
#define print(x) cout << x << endl;
const ll MOD = 1000000007;

vector<ll> ans;

struct node
{
    ll id;
    ll cost;   // The cost to arrive at this node
    ll parent; // Not used for now
    node(ll _id, ll _cost)
    {
        id = _id;
        cost = _cost;
    }
};

bool operator<(const node &left, const node &right)
{
    return left.cost < right.cost;
}

bool operator>(const node &left, const node &right)
{
    return left.cost > right.cost;
}

struct edge
{
    ll to;
    ll cost;
    edge(ll _to, ll _cost)
    {
        to = _to;
        cost = _cost;
    }
};

struct Graph
{
    ll V;
    vector<vector<edge>> edges;

    // V is the number of vertices
    Graph(ll _V)
    {
        // init
        V = _V;
        rep(i, V)
        {
            edges.push_back({});
        }
    }

    void addEdge(ll u, ll v, ll w)
    {
        edges[u].push_back(edge(v, w));
    }

    // O((E+N)logN)
    vector<ll> dijkstra(ll s) // s: starting vertex
    {

        // init min distance vector
        // d[i] is the minimum distance from s to i
        vector<ll> d(V);
        rep(i, V)
        {
            d[i] = LLONG_MAX;
        }

        // the top element is the vertex with the smallest cost
        priority_queue<node, vector<node>, greater<node>> q;

        // init start vertex
        d[s] = 0;
        q.push(node(s, 0));

        // update
        while (!q.empty())
        {
            node n = q.top();
            q.pop();

            // cout << "Now at node " << n.id << endl;

            // Check all the node which connects with n
            for (edge e : edges[n.id])
            {
                // cout << "Searching edge from " << n.id << " to " << e.to << endl;
                ll cand = d[n.id] + e.cost; // Cost via n
                // cout << "Candidate cost to " << e.to << " is " << cand << endl;

                if (cand < d[e.to])
                {
                    // cout << "Update cost for " << e.to << " to " << cand << endl;
                    d[e.to] = cand;
                    // cout << "Mejirushi for " << e.to << "is" << n.id << endl;
                    ans[e.to] = n.id;
                    q.push(node(e.to, cand)); // If via n is better, this may improve the shortest cost so need check
                }
            }
        }

        return d;
    }
};

int main()
{
    ll N, M;
    cin >> N >> M;

    Graph graph(N);
    rep(i, M)
    {
        ll temp, temp2;
        cin >> temp >> temp2;
        temp--;
        temp2--;
        graph.addEdge(temp, temp2, 1);
        graph.addEdge(temp2, temp, 1);
        ans.push_back(-1);
    }

    graph.dijkstra(0);

    cout << "Yes" << endl;
    rep(i, N - 1)
    {
        cout << ans[i + 1] + 1 << endl;
    }
}
