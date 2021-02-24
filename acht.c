#include <stdio.h>
#include <ncurses.h>

struct telo
{
    int x;
    int y;
};

struct tank
{
    struct telo gusli[3][3];
    int gun;
    int dir;
};

void motion(struct tank* m2, int y, int x)
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            m2->gusli[i][j].y+=y;
            m2->gusli[i][j].x+=x;
        }
    }
}

void rotategusli(struct tank* m2, int dir)
{
    if(dir==0)
    {
        mvaddch(m2->gusli[0][1].y,m2->gusli[0][1].x,' ');
        mvaddch(m2->gusli[2][1].y,m2->gusli[2][1].x,' ');
        mvaddch(m2->gusli[1][0].y,m2->gusli[1][0].x,'*');
        mvaddch(m2->gusli[1][2].y,m2->gusli[1][2].x,'*');
        m2->dir=0;
    }
    else if(dir==1)
    {
        mvaddch(m2->gusli[0][1].y,m2->gusli[0][1].x,'*');
        mvaddch(m2->gusli[2][1].y,m2->gusli[2][1].x,'*');
        mvaddch(m2->gusli[1][0].y,m2->gusli[1][0].x,' ');
        mvaddch(m2->gusli[1][2].y,m2->gusli[1][2].x,' ');
        m2->dir=1;
    }
        mvaddch(m2->gusli[0][0].y,m2->gusli[0][0].x,'*');
        mvaddch(m2->gusli[0][2].y,m2->gusli[0][2].x,'*');
        mvaddch(m2->gusli[2][0].y,m2->gusli[2][0].x,'*');
        mvaddch(m2->gusli[2][2].y,m2->gusli[2][2].x,'*');
        mvaddch(m2->gusli[1][1].y,m2->gusli[1][1].x,'*');
}

void rotategun(struct tank* m2, int pos)
{
    if(pos==0)
    {
        mvaddch(m2->gusli[0][0].y,m2->gusli[0][0].x,'\\');
        m2->gun=0;
    }
    else if(pos==1)
    {
        mvaddch(m2->gusli[0][1].y,m2->gusli[0][1].x,'|');
        m2->gun=1;
    }
    else if(pos==2)
    {
        mvaddch(m2->gusli[0][2].y,m2->gusli[0][2].x,'/');
        m2->gun=2;
    }
    else if(pos==3)
    {
        mvaddch(m2->gusli[1][0].y,m2->gusli[1][0].x,'-');
        m2->gun=3;
    }
    else if(pos==4)
    {
        mvaddch(m2->gusli[1][2].y,m2->gusli[1][2].x,'-');
        m2->gun=4;
    }
    else if(pos==5)
    {
        mvaddch(m2->gusli[2][0].y,m2->gusli[2][0].x,'/');
        m2->gun=5;
    }
    else if(pos==6)
    {
        mvaddch(m2->gusli[2][1].y,m2->gusli[2][1].x,'|');
        m2->gun=6;
    }
    else if(pos==7)
    {
        mvaddch(m2->gusli[2][2].y,m2->gusli[2][2].x,'\\');
        m2->gun=7;
    }

}

void atank(struct tank* m2, int starty, int startx)
{
    m2->gusli[1][1].x = startx;
    m2->gusli[1][1].y = starty;
    m2->gusli[0][0].x = startx-1;
    m2->gusli[0][0].y = starty-1;
    m2->gusli[0][1].x = startx;
    m2->gusli[0][1].y = starty-1;
    m2->gusli[0][2].x = startx+1;
    m2->gusli[0][2].y = starty-1;
    m2->gusli[1][0].x = startx-1;
    m2->gusli[1][0].y = starty;
    m2->gusli[1][2].x = startx+1;
    m2->gusli[1][2].y = starty;
    m2->gusli[2][0].x = startx-1;
    m2->gusli[2][0].y = starty+1;
    m2->gusli[2][1].x = startx;
    m2->gusli[2][1].y = starty+1;
    m2->gusli[2][2].x = startx+1;
    m2->gusli[2][2].y = starty+1;
    rotategusli(m2,0);
    rotategun(m2,1);
}


void tankmoves(struct tank* m2, int ch)
{
    if(ch=='q')
    {
        m2->gun=0;
    }
    else if(ch=='w')
    {
        m2->gun=1;
    }
    else if(ch=='e')
    {
        m2->gun=2;
    }
    else if(ch=='a')
    {
        m2->gun=3;
    }
    else if(ch=='d')
    {
        m2->gun=4;
    }
    else if(ch=='z')
    {
        m2->gun=5;
    }
    else if(ch=='x')
    {
        m2->gun=6;
    }
    else if(ch=='c')
    {
        m2->gun=7;
    }
    else if(ch==KEY_UP)
    {
        if((m2->gusli[0][0].y-1)>=0)
        {
        motion(m2,-1,0);
        m2->dir=0;
        }
    }
    else if(ch==KEY_DOWN)
    {
        if((m2->gusli[2][0].y+1)<=(LINES-1))
        {
            motion(m2,1,0);
            m2->dir=0;
        }
        
    }
    else if(ch==KEY_LEFT)
    {
        if((m2->gusli[0][0].x-1)>=0)
        {
            motion(m2,0,-1);
            m2->dir=1;
        }
        
    }
    else if(ch==KEY_RIGHT)
    {
        if((m2->gusli[0][2].x+1)<=(COLS-1))
        {
            motion(m2,0,1);
            m2->dir=1;
        }
        
    }
    rotategusli(m2,m2->dir);
    rotategun(m2,m2->gun);

}


int main(int argc, char* argv[])
{
    int ch;
    struct tank m2;
    initscr();
    noecho();
    keypad(stdscr,true);
    atank(&m2, LINES/2, COLS/2);
    refresh();
    while((ch=getch())!=KEY_F(1))
    {
        clear();
        tankmoves(&m2,ch);
        refresh();
    }

    endwin();
    return 0;
}