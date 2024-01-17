class card
{
private:
    int color;
    char types[13]={'2','3','4','5','6','7','8','9','0','J','Q','K','A'};
    char colors[4]={5,4,3,6};
    char clrclr[4]={0,12,12,0};
    int backgr=14;
    int forgr=0;
    std::string layout[3]
    {
        "TSB",
        "BCB",
        "BBR"
    };
public:
    int type;
    card(){type=color=1;}
    card(int t,int c)
    {
        type=t;
        color=c;
    }
    void draw(int x,int y,bool show)
    {
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<layout[i].length();j++)
            {
                if(!show)
                {
                    if(layout[i][j]=='C')draw_char('@',x+j,y+i,12,15);
                    else draw_char(177,x+j,y+i,12,15);
                }
                else if(layout[i][j]=='T')draw_char(types[type],x+j,y+i,forgr,backgr);
                else if(layout[i][j]=='C')draw_char(colors[color],x+j,y+i,clrclr[color],backgr);
                else if(layout[i][j]=='S' && type==8){draw_char('0',x+j,y+i,forgr,backgr);
                                                      draw_char('1',x+j-1,y+i,forgr,backgr);}
                else if(layout[i][j]=='R'){draw_char(types[type],x+j,y+i,forgr,backgr);
                                if(type==8)draw_char('1',x+j-1,y+i,forgr,backgr);}
                else draw_char(' ',x+j,y+i,0,backgr);
            }
        }
    }
};
