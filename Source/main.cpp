#include "Score.h"
#include "Innings.h"
#include "WestIndies.h"

unsigned int TeamScore1;
char Team_1[12];
char Team_2[12];
char TeamName[12];


char* Select_Team(Team TeamSelection)
{
    switch(TeamSelection)
    {
	case India:
	    printf("Achived**\n");
	    strcpy(TeamName,"INDIA");
	    break;
	case Australia:
	    strcpy(TeamName,"AUSTRALIA"); 
	    break;
	case Srilanka:
	    strcpy(TeamName,"SRILANKA"); 
	    break;
	case Pakisthan:
	    strcpy(TeamName,"PAKISTHAN"); 
	    break;
	case SouthAfrica:
	    strcpy(TeamName,"SOUTHAFRICA"); 
	    break;
	case England:
	    strcpy(TeamName,"ENGLAND"); 
	    break;
	case Newzland:
	    strcpy(TeamName,"NEWZLAND"); 
	    break;
	case WestEndies:
	    strcpy(TeamName,"WestIndies"); 
	    break;
    }
    return TeamName;
}

int main()
{
    char Teamer[12];
    strcpy(Team_1,"India");
    strcpy(Team_2,"WestIndies");
    InninigsDetails *FirstInningses =new InninigsDetails(Team_1,Team_2);	
    FirstInningses->DoingToss();
    
    strcpy(Teamer,FirstInningses->DecissionByCaptain_Bat_or_Bowl()); 
    FirstInningses->Ist_Innings(Teamer);
    cout<<"Teamer:"<<Teamer<<endl;
    ScoreCard *FirstInnings= new ScoreCard(1,Teamer);
    ScoreCard *SecondInnings;
#if 0
    char *sTeam= new char[12];
    sTeam= Select_Team(Team_1);

    //cin>>"STeam :";
    printf("STeam: %s",sTeam);
#endif
    while(1)
    {
	FirstInnings->PuttheOver();
	cout<<FirstInnings->Over<<endl;
	if(FirstInnings->Over == TOTALOVER)
	{
	    TeamScore1=FirstInnings->Score;
	    break;
	}
    FirstInnings->ScoreDetails();
    }
    FirstInnings->ScoreDetails();
    cout<<"*****Second Innings will start in another 10 seconds*****"<<endl;
    sleep(10);
    cout<<"Second Innings start"<<endl;
    if(strcmp(Teamer,Team_1)==0)
	SecondInnings=new ScoreCard(2,Team_2);
    else
	SecondInnings=new ScoreCard(2,Team_1);
    while(1)
    {
	SecondInnings->PuttheOver();
	cout<<SecondInnings->Over<<endl;
	if(SecondInnings->Over == TOTALOVER || SecondInnings->Score > TeamScore1)
	{
	    SecondInnings->WinningDeclaration();
	    break;
	}
    }

    delete FirstInnings;
    delete SecondInnings;
    return 0;
}
