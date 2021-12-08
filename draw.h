#include <windows.h>
void gotoxy(int x, int y) //指定位置
{
    // 更新光标位置
    COORD pos;
    HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(hOutput, pos);
    // 隐藏光标
    CONSOLE_CURSOR_INFO cursor;
    cursor.bVisible = FALSE;
    cursor.dwSize = sizeof(cursor);
    SetConsoleCursorInfo(hOutput, &cursor);
}
void gotoxyprint(int x, int y, char a) //指定打印位置
{
    gotoxy(x, y);
    printf("%c", a);
}
void drawgragh(int w, int h)
{
    for (int i = 0; i <= w; i += 2)
    {
        gotoxyprint(i, 0, '#');
        gotoxyprint(i, h, '#');
    }
    for (int i = 0; i <= h; i++)
    {
        gotoxyprint(0, i, '#');
        gotoxyprint(w, i, '#');
    }
}
void welcome()
{
    gotoxy(15 + 15, 10);
    printf("/**********************************************/");
    gotoxy(15 + 15, 20);
    printf("/**********************************************/");
    gotoxy(25 + 15, 13);
    printf("welcome to EatingSnake");
    gotoxy(25 + 15, 16);
    printf("press Enter to continue");
    while (getchar() != '\n'){}
    system("cls");
}
void final()
{
    gotoxy(15 + 15, 10);
    printf("/**********************************************/");
    gotoxy(15 + 15, 20);
    printf("/**********************************************/");
    gotoxy(25 + 15, 13);
    printf("You're dead. The game's over");
    gotoxy(25 + 15, 16);
    printf("press Enter to continue");
    while (getchar() != '\n'){}
    system("cls");
}
