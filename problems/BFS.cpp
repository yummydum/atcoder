#include <bits/stdc++.h>
#define rep(i, c) for (int i = 0; i < (int)c; i++)
#define _GLIBCXX_DEBUG
using namespace std;

vector<int> dx = {1, 0, -1, 0};
vector<int> dy = {0, 1, 0, -1};
pair<int, int> start;
pair<int, int> goal;
vector<vector<char>> maze;
vector<vector<int>> shortest_move;
queue<pair<int, int>> q;

int bfs()
{

    // update
    pair<int, int> now = q.front();
    q.pop();

    // end condition
    if (now == goal)
    {
        return shortest_move[now.first - 1][now.second - 1];
    }

    // recursion
    rep(i, 4)
    {
        int x = now.first + dx[i];
        int y = now.second + dy[i];
        if (maze[x - 1][y - 1] == '.' && shortest_move[x - 1][y - 1] == -1)
        {
            q.push(make_pair(x, y));
            shortest_move[x - 1][y - 1] = shortest_move[now.first - 1][now.second - 1] + 1;
        }
    }
    bfs();
}

int main()
{
    // read input
    int R, C;
    cin >> R >> C;

    int temp, temp2;
    cin >> temp >> temp2;
    start = make_pair(temp, temp2);

    int temp3, temp4;
    cin >> temp3 >> temp4;
    goal = make_pair(temp3, temp4);

    rep(i, R)
    {
        maze.push_back({});
        shortest_move.push_back({});
        rep(j, C)
        {
            char temp;
            cin >> temp;
            maze[i].push_back(temp);
            shortest_move[i].push_back(-1);
        }
    }

    // init
    q.push(start);
    shortest_move[start.first - 1][start.second - 1] = 0;

    // ans
    cout << bfs() << endl;
}