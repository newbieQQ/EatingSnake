#include <stdio.h>
#include "Snake.h"

int main()
{
    welcome();
    snake.init();
    while (1)
    {
        drawgragh(117, 29);
        snake.printfSnake();
        if(!snake.foodlive)snake.CreatFood();
        gotoxyprint(snake.food.x,snake.food.y,'*');
        Sleep(1);
        snake.move();
        if(!snake.Snakelive())
        {
            final();
            system("cls");
            snake.init();
        }
    }
    return 0;
}
