HANDLE cnsl=GetStdHandle(STD_OUTPUT_HANDLE);
void cls(int clr)
{
    SetConsoleTextAttribute(cnsl,clr*16);
    SetConsoleCursorPosition(cnsl,{0,0});
    for(int i=0;i<30;i++)
    {
        for(int j=0;j<150;j++)
        {
            std::cout << ' ';
        }
        std::cout << '\n';
    }
}
void draw_char(char ch,int x,int y,int fr,int bk)
{
    SetConsoleCursorPosition(cnsl,{x,y});
    SetConsoleTextAttribute(cnsl,bk*16+fr);
    std::cout << ch;
}
