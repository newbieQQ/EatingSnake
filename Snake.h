#include <stdio.h>
#include <conio.h>
#include <time.h>
#include "draw.h"

#define up 'w'
#define do 's'
#define ri 'd'
#define lf 'a'

struct Node
{
    int x;
    int y;
    int dir = 2; //默认右 0为下 1为上 2为右 3为左
};

struct Snake
{
    int head = 50000;
    int end = 50000;
    int length;
    int direction[4][2] = {{0, 1}, {0, -1}, {2, 0}, {-2, 0}}; //下上右左
    bool foodlive = 0;
    Node node[100000], food;

    void init()
    {
        head = end =50000;
        node[head].x = 58;
        node[head].y = 15;
        node[head].dir = 2;
        end += 2;
        for (int i = head + 1; i <= end; i++)
        {
            node[i].x = node[i - 1].x - 2;
            node[i].y = node[i - 1].y;
        }
    }

    void printfSnake()
    {
        for (int i = head; i <= end; i++)
            gotoxyprint(node[i].x, node[i].y, '@');
    }

    void CreatFood()
    {
        srand(time(0));
        food.x = (rand() % (115 / 2) + 1) * 2;
        food.y = rand() % 28 + 1;
        gotoxyprint(food.x, food.y, '*');
        foodlive = 1;
    }

    void move()
    {
        if (kbhit())
        {
            switch (_getch())
            {
            case up:
                if(node[head].dir != 0)node[head].dir = 1;
                break;
            case do:
                if(node[head].dir != 1)node[head].dir = 0;
                break;
            case lf:
                if(node[head].dir != 2)node[head].dir = 3;
                break;
            case ri:
                if(node[head].dir != 3)node[head].dir = 2;
                break;
            }
        }
        int xx = node[head].x + direction[node[head].dir][0];
        int yy = node[head].y + direction[node[head].dir][1];
        if (xx == food.x && yy == food.y)
        {
            foodlive = 0;
            food.dir = node[head].dir;
            node[--head] = food;
        }
        else
        {
            for (int i = head; i <= end; i++)
                gotoxyprint(node[i].x, node[i].y, ' ');
            for (int i = end; i > head; i--)
            {
                node[i].dir = node[i - 1].dir;
                node[i].x = node[i - 1].x;
                node[i].y = node[i - 1].y;
            }
            node[head].x = xx;
            node[head].y = yy;
        }
    }

    bool Snakelive()
    {
        int xx = node[head].x;
        int yy = node[head].y;
        for (int i = head + 1; i <= end; i++)
        {
            if (xx == node[i].x && yy == node[i].y)
                return 0;
        }
        if (xx <= 0 || xx >= 117 || yy <= 0 || yy >= 29)
            return 0;
        return 1;
    }

} snake;
