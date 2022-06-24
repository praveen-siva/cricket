#include "Score.h"
#include "WestIndies.h"

//#define BATTING(Wicket) strcat("BATSMAN",Wicket)

//char Team[]="WestIndies";
extern unsigned int TeamScore1;
extern char Team_1[12];
extern char Team_2[12];
int BATSMAN=1;
char BatsmanName[12][50]=WESTINDIESTOPLIST;
ScoreCard::ScoreCard(char Ings,char *TeamName)
{
    cout<<"****Start the Innings****"<<endl;
    CorrectBall=0;
    Innings=Ings;
    Ball=0;
    Run=0;
    Over=0;
    Score=0;
    Wicket=0;
    Batsman1_Ings={0};
    Batsman2_Ings={0};
    if(Ings == 1)
    {
       cout<<"TeamName:"<<TeamName<<endl;
       strcpy(Team1,TeamName);
       cout<<"Team1:"<<Team1<<endl;
    }
    if(Ings == 2)
       strcpy(Team2,TeamName);

    BatsMan_Init();
    OpeningBatsman();
   

#if 0
	cout<<"TeamName"<<Team1<<endl;
#endif
}
#if 0
int ScoreCard::_trial(char *details)
{
	if
}
#endif

int ScoreCard::PuttheOver()
{
    while(1)
    {
	printf("Ball is  the correct Ball:(y/n)");
	cin>>CorrectBall;

	printf("Its Any Wicket:(y/n)");
	cin>>ItsOut;
	if(ItsOut == 'Y' || ItsOut == 'y')
	{
	    Ball++;
	    Wicket++;
	    BatsmanCard();
	    BattingOrderChange();
	    if(BATSMAN == 2)
		    BATSMAN=1;
	    else
		    BATSMAN=2;

	    goto Overs_t;
	}

        printf("Run for the current %d.%d Over:",Over,Ball);
	cin>>Run;
	Score = Score + Run;   

            if(CorrectBall =='Y' || CorrectBall == 'y')
	    {	
	        Ball++;
	        if(Ball < 6)
	        {
                    BatsmanCard();
	            if((Run%2==0) && (BATSMAN ==1)) 
	                BATSMAN = 1;
	            else if((Run%2!=0) && (BATSMAN ==2)) 
	                BATSMAN = 1;
	            else
	                 BATSMAN = 2;
	        }
	    }
	    else
	    {
	        Score++;
	        BatsmanCard();
	        if((Run%2==0) && (BATSMAN ==1))
                   BATSMAN = 1;
                else if((Run%2!=0) && (BATSMAN ==2))
                    BATSMAN = 1;
                else
                    BATSMAN = 2;
	   }
Overs_t:
	   if(Ball ==6)
	   {
               Over++;
	       Ball=0;
	       BatsmanCard();
	       if(Run%2 ==0 && BATSMAN == 2)
	           BATSMAN =1;
	       else if(Run%2 !=0 && BATSMAN == 2)
	           BATSMAN =2;
	       else if(Run%2 ==0 && BATSMAN == 1)
	           BATSMAN =2;
	       else
	           BATSMAN =1;
	        break;
	   }
	   if((Innings == 2) && (Score > TeamScore1))
	   {
		cout<<TeamScore1<<endl;
		break;
	   }
	   if(BATSMAN == 1)
	       cout<<Batsman1_Ings.Batsman<<" is Batting "<<endl;
	   else
	       cout<<Batsman2_Ings.Batsman<<" is Batting "<<endl;
    }
}

int ScoreCard::BatsmanCard()
{
    if(BATSMAN == 1)
    {
	if(ItsOut=='Y' || ItsOut == 'y')
	{
	    OutBatsmanDetails();
	    strcpy(Batsman1_Ings.Batsman,BatsmanName[Wicket-1]);
	}
	else
	{
	    strcpy(Batsman1_Ings.Batsman,BatsmanName[Wicket]);
            Batsman1_Ings.Run_Batsman=Batsman1_Ings.Run_Batsman+Run;
	}
	if(Run == 4)
    	    Batsman1_Ings.Batsman_4s=Batsman1_Ings.Batsman_4s+1;		
        if(Run == 6)
	    Batsman1_Ings.Batsman_6s=Batsman1_Ings.Batsman_6s+1;
        Batsman1_Ings.Ball_Batsman=Batsman1_Ings.Ball_Batsman+1;
    }
    if(BATSMAN == 2)
    {
	if(ItsOut=='Y' || ItsOut == 'y')
	{
	    OutBatsmanDetails();
	    strcpy(Batsman2_Ings.Batsman,BatsmanName[Wicket]);
	}
	else
	{
	    strcpy(Batsman2_Ings.Batsman,BatsmanName[Wicket+1]);
	    //strcpy(Batsman2_Ings.Batsman,BATTING(Wicket));
            Batsman2_Ings.Run_Batsman=Batsman2_Ings.Run_Batsman+Run;
	}
	if(Run == 4)
    	    Batsman2_Ings.Batsman_4s=Batsman2_Ings.Batsman_4s+1;		
        if(Run == 6)
	    Batsman2_Ings.Batsman_6s=Batsman2_Ings.Batsman_6s+1;
            Batsman2_Ings.Ball_Batsman=Batsman2_Ings.Ball_Batsman+1;
    }
    return 0;
}

int ScoreCard::OutBatsmanDetails()
{
    if(BATSMAN==1)
       printf("BATSMAN1 : %s  Score: %d Balls: %d 4`s: %d 6`s: %d  \n", Batsman1_Ings.Batsman,Batsman1_Ings.Run_Batsman,Batsman1_Ings.Ball_Batsman,Batsman1_Ings.Batsman_4s,Batsman1_Ings.Batsman_6s);
    else
       printf("BATSMAN2 : %s  Score: %d Balls: %d 4`s: %d 6`s: %d  \n", Batsman2_Ings.Batsman,Batsman2_Ings.Run_Batsman,Batsman2_Ings.Ball_Batsman,Batsman2_Ings.Batsman_4s,Batsman2_Ings.Batsman_6s);
    
    return 0;
}

int ScoreCard::OpeningBatsman()
{
    strcpy(Batsman1_Ings.Batsman,BatsmanName[0]);
    Batsman1_Ings.Run_Batsman=0;
    Batsman1_Ings.Batsman_4s=0;
    Batsman1_Ings.Batsman_6s=0;   
    Batsman1_Ings.Ball_Batsman=0;
    strcpy(Batsman2_Ings.Batsman,BatsmanName[1]);
    Batsman2_Ings.Run_Batsman=0;
    Batsman2_Ings.Batsman_4s=0;
    Batsman2_Ings.Batsman_6s=0;   
    Batsman2_Ings.Ball_Batsman=0;

    return 0;
}

int ScoreCard::WinningDeclaration()
{
    unsigned int RemainingBalls=0;
    unsigned int RemainingRuns=0;
    cout<<"TeamScore1 :"<<TeamScore1<<endl;
    if(Score >TeamScore1 )
    {
	RemainingBalls= (Over*6)+Ball;
	RemainingBalls= (TOTALOVER*6)-RemainingBalls;
	printf(" %s win by %d Ball\n",Team2,RemainingBalls);
    } 
    if(TOTALOVER == Over)
    {
	RemainingRuns= TeamScore1-Score ;
	cout<<"Team1: "<<Team1<<endl;
	printf(" %s win by %d run \n",Team1,RemainingRuns);
    } 
    return 0;
}


int ScoreCard::ScoreDetails()
{
    printf("==ScoreDetails==");
    printf("TotalScore: %d \n",Score);
    printf("Over: %d \n",Over);
    printf("Wicket: %d \n",Wicket);
    printf("BATSMAN1 : %s  Score: %d Balls: %d 4`s: %d 6`s: %d  \n", Batsman1_Ings.Batsman,Batsman1_Ings.Run_Batsman,Batsman1_Ings.Ball_Batsman,Batsman1_Ings.Batsman_4s,Batsman1_Ings.Batsman_6s);
    printf("BATSMAN2 : %s  Score: %d Balls: %d 4`s: %d 6`s: %d  \n", Batsman2_Ings.Batsman,Batsman2_Ings.Run_Batsman,Batsman2_Ings.Ball_Batsman,Batsman2_Ings.Batsman_4s,Batsman2_Ings.Batsman_6s);
   WicketChange();
   BattingDetails();
}

int ScoreCard::BatsMan_Init()
{
	for(int i=0;i<=10;i++)
	{
    strcpy(Batsman1_Ings.Batsman,BatsmanName[i]);
    Batsman1_Ings.Run_Batsman=0;
    Batsman1_Ings.Batsman_4s=0;
    Batsman1_Ings.Batsman_6s=0;
    Batsman1_Ings.Ball_Batsman=0;
    BatsmanStatus.insert(std::pair<int,Batsman_t>(i,Batsman1_Ings));
	}
   BattingDetails();
    
    return 0;
}

int ScoreCard::BattingOrderChange()
{
    if(BATSMAN == 1)
    {
	std::map<int,Batsman_t>::iterator it = BatsmanStatus.find(Wicket-1);
	if(it != BatsmanStatus.end())
	    it->second=Batsman1_Ings;

        Batsman1_Ings=Batsman2_Ings;
	strcpy(Batsman1_Ings.Batsman,Batsman2_Ings.Batsman);
	strcpy(Batsman2_Ings.Batsman,BatsmanName[Wicket+1]);
        Batsman2_Ings.Run_Batsman=0;
        Batsman2_Ings.Batsman_4s=0;
        Batsman2_Ings.Batsman_6s=0;
        Batsman2_Ings.Ball_Batsman=0;
	WicketChange();
        BattingDetails();
    }
    if(BATSMAN == 2)
    {
	std::map<int,Batsman_t>::iterator it = BatsmanStatus.find(Wicket);
	if(it != BatsmanStatus.end())
	    it->second=Batsman2_Ings;
	strcpy(Batsman2_Ings.Batsman,BatsmanName[Wicket+1]);
        Batsman2_Ings.Run_Batsman=0;
        Batsman2_Ings.Batsman_4s=0;
        Batsman2_Ings.Batsman_6s=0;
        Batsman2_Ings.Ball_Batsman=0;
	WicketChange();
        BattingDetails();
    }
    return 0;
}
int ScoreCard::WicketChange()
{
       std::map<int,Batsman_t>::iterator it = BatsmanStatus.find(Wicket);
	if(it != BatsmanStatus.end())
	    it->second=Batsman1_Ings;
       std::map<int,Batsman_t>::iterator its = BatsmanStatus.find(Wicket+1);
	if(its != BatsmanStatus.end())
	    its->second=Batsman2_Ings;
#if 0
    if(BATSMAN==2)
    {
       std::map<int,Batsman_t>::iterator it = BatsmanStatus.find(Wicket+1);
	if(it != BatsmanStatus.end())
	    it->second=Batsman1_Ings;
       std::map<int,Batsman_t>::iterator its = BatsmanStatus.find(Wicket+2);
	if(its != BatsmanStatus.end())
	    its->second=Batsman2_Ings;
    }
#endif
    return 0;
}

int ScoreCard::BattingDetails()
{
       std::map<int,Batsman_t>::iterator it;
    cout<<"Batting Dettails"<<'\n';
    printf("BATSMAN1 \t\t\tScore \tBalls \t4`s \t6`s \t  \n");
    for(it=BatsmanStatus.begin(); it!=BatsmanStatus.end(); ++it)
    {
         cout<<it->second.Batsman<<"\t\t\t"<<it->second.Run_Batsman <<"\t"<< it->second.Ball_Batsman <<"\t" << it->second.Batsman_4s <<"\t"<< it->second.Batsman_6s <<'\n';
    }

    return 0;
}
#if 0
	ballmap.insert ( std::pair<t_Ball,t_Run>(Ball,Run));
	overmap.insert (Ball,std::pair<t_Ball,t_Run>(Ball,Run));
#endif
