#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define _GLIBCXX_DEBUG
#define rep(i, c) for (int i = 0; i < (int)c; i++)
#define debug(x) cout << #x << " = " << x << endl
#define print(x) cout << x << endl;
const ll MOD = 1000000007;

vector<vector<char>> maze;
vector<int> dx = {1, 0, -1, 0};
vector<int> dy = {0, 1, 0, -1};

struct node
{
    int x, y;
    node(int _x, int _y)
    {
        x = _x;
        y = _y;
    }
};

int H, W;

int bfs(queue<node> q, vector<vector<int>> shortest_move, int max_count)
{
    while (!q.empty())
    {
        node now = q.front();
        q.pop();

        // Update max count
        if (shortest_move[now.x][now.y] > max_count)
        {
            max_count = shortest_move[now.x][now.y];
        }

        // Next nodes
        for (int i : {0, 1, 2, 3})
        {
            int x = now.x + dx[i];
            int y = now.y + dy[i];

            bool cond1 = 0 <= x && x < H;
            bool cond2 = 0 <= y && y < W;

            if (cond1 && cond2 && maze[x][y] == '.' && shortest_move[x][y] == -1)
            {
                shortest_move[x][y] = shortest_move[now.x][now.y] + 1;
                q.push(node(x, y));
            }
        }
    }

    return max_count;
}

int main()
{
    cin >> H >> W;

    // init
    rep(i, H)
    {
        maze.push_back({});
        rep(j, W)
        {
            char temp;
            cin >> temp;
            maze[i].push_back(temp);
        }
    }

    int ans = -1;
    rep(i, H)
    {
        rep(j, W)
        {
            node start = node(i, j);
            if (maze[start.x][start.y] == '.')
            {

                // init maze
                queue<node> q;
                q.push(start);
                vector<vector<int>> shortest_move(H, vector<int>(W, -1));
                shortest_move[start.x][start.y] = 0;

                // get shortest move to all node
                int max_count = bfs(q, shortest_move, 0);

                // upate
                if (max_count > ans)
                {
                    ans = max_count;
                }
            }
        }
    }
    cout << ans << endl;
}
