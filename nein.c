#include <stdio.h>
#include <ncurses.h>
int main(int argc, char* argv[])
{
    int ch, c=LINES/2,d=COLS/2, e, f;
    int musk[4][2];
    
    initscr();
    noecho();
    keypad(stdscr,true);
    mvaddstr(c,d,"ya dral tvoyu mat'");
    refresh();
    while((ch=getch())!='q')
    {
        switch(ch)
        {
            case KEY_UP:
                c--;
                if(c<0)
                    {
                        c=LINES-1;
                    }   
                break;
            case KEY_DOWN:
                c++;
                if(c>LINES-1)
                {  
                    c=0;
                }
                break;
            case KEY_LEFT:
                d--;
                if(d<0)
                {
                    d=COLS-1;
                }
                break;
            case KEY_RIGHT:
                d++;
                if(d>COLS-1)
                {
                    d=0;
                }
                break;
        }
        clear();
        musk[3][0]=musk[2][0];
        musk[3][1]=musk[2][1];
        musk[2][0]=musk[1][0];
        musk[2][1]=musk[1][1];
        musk[1][0]=musk[0][0];
        musk[1][1]=musk[0][1];
        musk[0][0]=c;
        musk[0][1]=d;

        if(ch==KEY_RIGHT || ch==KEY_DOWN)
        {
        mvaddch(musk[3][0],musk[3][1],'d');
        mvaddch(musk[2][0],musk[2][1],'i');
        mvaddch(musk[1][0],musk[1][1],'c');
        mvaddch(musk[0][0],musk[0][1],'k');
        }
        else if(ch==KEY_LEFT || ch==KEY_UP)
        {
        mvaddch(musk[3][0],musk[3][1],'k');
        mvaddch(musk[2][0],musk[2][1],'c');
        mvaddch(musk[1][0],musk[1][1],'i');
        mvaddch(musk[0][0],musk[0][1],'d');
        }
        
        
        
        move(0,0);
        refresh();
    }


    endwin();
    return 0;
}