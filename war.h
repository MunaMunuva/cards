using namespace std;

class war
{
public:
    int p1;
    int p2;
    vector<card> Cards;
    vector<card> hCards;
    vector<card> pcCards;
    vector<card> reward;
    int cardNums=13;

    war(){}
    void init()
    {
        if(DEV)cardNums=5 ;
        for(int i=0;i<cardNums;i++)
        {
            for(int j=0;j<4;j++)
            {
                Cards.push_back(card(i,j));
            }
        }
        random_shuffle(Cards.begin(),Cards.end());
        for(int i=0;i<cardNums*2;i++)
        {
            hCards.push_back(Cards[i]);
        }
        for(int i=cardNums*2;i<cardNums*4;i++)
        {
            pcCards.push_back(Cards[i]);
        }
    }
    void drawDecks()
    {
        system("color 20");
        int pos;
        bool show=0;
        if(DEV){pos=4;show=1;}
        else pos=0;
        for(int i=pcCards.size()-1;i>0;i--)
        {
            pcCards[i].draw(i*pos+15,5,show);
        }
        for(int i=hCards.size()-1;i>0;i--)
        {
            hCards[i].draw(i*pos+15,25,show);
        }
        SetConsoleCursorPosition(cnsl,{3,6});
        SetConsoleTextAttribute(cnsl,32);
        cout << "OPPONENT:";
        SetConsoleCursorPosition(cnsl,{5,26});
        SetConsoleTextAttribute(cnsl,32);
        cout << "YOU:\n\n\n";
        pcCards[0].draw(50,13,1);
        hCards[0].draw(50,18,1);
    }
    void isend()
    {
        if(pcCards.size()==0)while(1)cout << "WIN ";
        if(hCards.size()==0)while(1)cout << "LOSE ";
    }
    int warPlay(int pos)
    {
        int br=3;
        int ret;
        if(pcCards[2].type>hCards[2].type)ret=1;
        else if(pcCards[2].type<hCards[2].type)ret=2;
        else ret=0;
        while(br>0)
        {
            reward.push_back(hCards[br-1]);
            reward.push_back(pcCards[br-1]);
            pcCards[br-1].draw(br*4+pos,13,1);
            hCards[br-1].draw(br*4+pos,18,1);
            pcCards.erase(pcCards.begin()+br-1);
            hCards.erase(hCards.begin()+br-1);
            isend();
            br--;
        }
        return ret;
    }
    void game()
    {
        while(1)
        {
            if(GetAsyncKeyState(VK_SPACE))
            {
                cls(2);
                drawDecks();
                if(pcCards[0].type>hCards[0].type)
                {
                    pcCards.push_back(hCards[0]);
                    pcCards.push_back(pcCards[0]);
                    hCards.erase(hCards.begin());
                    pcCards.erase(pcCards.begin());
                    isend();
                }
                else if(pcCards[0].type<hCards[0].type)
                {
                    hCards.push_back(pcCards[0]);
                    hCards.push_back(hCards[0]);
                    pcCards.erase(pcCards.begin());
                    hCards.erase(hCards.begin());
                    isend();
                }
                else
                {
                    reward.push_back(pcCards[0]);
                    reward.push_back(hCards[0]);
                    pcCards.erase(pcCards.begin());
                    hCards.erase(hCards.begin());
                    isend();
                    int i=0;
                    int w;
                    while(w=warPlay(i*13+50)==0)i++;
                    if(w==1)
                    {
                        while(reward.size()>0)
                        {
                            pcCards.push_back(reward[0]);
                            reward.erase(reward.begin());
                        }
                    }
                    else
                    {
                        while(reward.size()>0)
                        {
                            hCards.push_back(reward[0]);
                            reward.erase(reward.begin());
                        }
                    }
                }
            }
        }
    }
};
