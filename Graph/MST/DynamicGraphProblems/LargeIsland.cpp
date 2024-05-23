#include <bits/stdc++.h>
using namespace std;
class Solution
{
    class Disjoint_Set
    {

    public:
        vector<int> size, parent;
        Disjoint_Set(int n)
        {
            size.resize(n + 1, 1);
            parent.resize(n + 1);
            for (int i = 0; i <= n; i++)
            {
                parent[i] = i;
            }
        }
        int findUparent(int node)
        {
            if (node == parent[node])
                return node;
            return parent[node] = findUparent(parent[node]);
        }
        void UnionbySize(int u, int v)
        {
            int ulp_u = findUparent(u);
            int ulp_v = findUparent(v);
            if (ulp_u == ulp_v)
                return;
            if (size[ulp_u] < size[ulp_v])
            {
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            }
            else
            {
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }
        }
    };

public:
    int largestIsland(vector<vector<int>> &grid)
    {
        int rowno = grid.size();
        int colno = grid[0].size();

        Disjoint_Set ds(rowno * colno);
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        for (int row = 0; row < rowno; row++)
        {
            for (int col = 0; col < colno; col++)
            {
                if (grid[row][col] == 0)
                    continue;
                for (int i = 0; i < 4; i++)
                {
                    int nrow = row + dr[i];
                    int ncol = col + dc[i];
                    if (nrow >= 0 && ncol >= 0 && nrow < rowno && ncol < colno && grid[nrow][ncol] == 1)
                    {
                        int u = row * colno + col;
                        int v = nrow * colno + ncol;
                        ds.UnionbySize(u, v);
                    }
                }
            }
        }

        int cnt = 0;

        for (int row = 0; row < rowno; row++)
        {
            for (int col = 0; col < colno; col++)
            {
                if (grid[row][col] == 1)
                    continue;
                set<int> comp;
                for (int i = 0; i < 4; i++)
                {
                    int nrow = row + dr[i];
                    int ncol = col + dc[i];
                    if (nrow >= 0 && ncol >= 0 && nrow < rowno && ncol < colno && grid[nrow][ncol] == 1)
                    {
                        //  int u = row*colno + col;
                        int v = nrow * colno + ncol;
                        comp.insert(ds.findUparent(v));
                    }
                }
                int temp = 0;
                for (auto it : comp)
                {
                    temp += ds.size[it];
                }
                cnt = max(temp + 1, cnt);
            }
        }
        for (int cellNo = 0; cellNo < rowno * colno; cellNo++)
        {
            cout << ds.size[ds.findUparent(cellNo)] << " ";
            cnt = max(cnt, ds.size[ds.findUparent(cellNo)]);
        }
        return cnt;
    }
};