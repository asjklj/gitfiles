#include "linkStack.h"
#include <iostream>
using namespace std;
struct point
{
    int x;
    int y;
    point(int m = 0, int n = 0)
    {
        x = m;
        y = n;
    }
    /* data */
};
int maze[12][12] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0},
    {0, 0, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0},
    {0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0},
    {0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0},
    {0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 0},
    {0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0},
    {0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0},
    {0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
};

int main()
{int i = 1, j = 1;
    linkStack<point> *m = new linkStack<point>();
    while (i != 11 || j != 11)
    {
        maze[i][j] = 0;
        if (maze[i + 1][j] == 1)
        {
            point *x = new point(i, j);
            m->push(*x);
            i++;
        }
        else if (maze[i - 1][j] == 1)
        {
            point *x = new point(i, j);
            m->push(*x);
            i--;
        }
        else if (maze[i][j + 1] == 1)
        {
            point *x = new point(i, j);
            m->push(*x);
            j++;
        }
        else if (maze[i][j - 1] == 1)
        {
            point *x = new point(i, j);
            m->push(*x);
            j--;
        }
        else
        {
            while ((!m->isEmpty()) && (maze[i + 1][j] == 0) && (maze[i - 1][j] == 0) && (maze[i][j + 1] == 0) && (maze[i][j - 1] == 0))
            {
                i = m->top().x;
                j = m->top().y;
                m->pop();
            }
        }
    }
    point *road = new point[100];
    int foot = 0;
    while (!m->isEmpty())
    {
        road[foot] = m->pop();
        ++foot;
    }
    cout << "one possible path:" << endl;
    for (int i = foot-1; i > 0; i--)
    {
        cout << road[i].x << "," << road[i].y << endl;
    }
    system("pause");
}