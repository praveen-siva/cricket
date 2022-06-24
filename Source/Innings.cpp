#include "Innings.h"

extern unsigned int TeamScore1;
extern char Team_1[12];
extern char Team_2[12];

InninigsDetails::InninigsDetails(char* ATeam , char * BTeam)
{
    strcpy(TeamA,ATeam);
    strcpy(TeamB,BTeam);
}

int InninigsDetails::DoingToss(void)
{
    printf("==%s going to put the toss==\n", TeamA);
    printf("==And %s asking the Toss==\n", TeamB);
    cout<<"Please select the toss H or h for Head and T or t for tail"<<endl;
    cin>>TossAsk;
    sleep(0.33);
    Toss=rand()%2;
    if(TossAsk == 'H' || TossAsk == 'h')
    {
	if(Toss == 1)
	{
	    cout<<"Toss win By :";
	    cout<<TeamB<<" Team *****"<<endl;
	    TossWinner='B';		
	}
	else
	{
	    cout<<"Toss win By :";
	    cout<<TeamA<<" Team*****"<<endl;
	    TossWinner='A';		
	}
    }
    else if(TossAsk == 'T' || TossAsk == 't')
    {
        if(Toss == 1)
        {
            cout<<"Toss win By :";
	    cout<<TeamA<<" Team*****"<<endl;
	    TossWinner='A';		
        }
        else
        {
            cout<<"Toss win By :";
	    cout<<TeamB<<" Team*****"<<endl;
	    TossWinner='B';		
        }
    }
    else
	cout<<"Toss Failed" <<endl;	
    return 0;
}

char * InninigsDetails::DecissionByCaptain_Bat_or_Bowl()
{
    int Bat_or_Bowl= 2;
    cout<<"Congrats for Wining Toss Caps"<<endl;
    cout<<"Are you like to choose bat firt  or Bowl "<<endl;
    cout<<"1 for choosing Bat "<<endl;
    cout<<"2 for choosing Bowl "<<endl;
    cin>>Bat_or_Bowl;
    if(Bat_or_Bowl == 1)
    {
	if(TossWinner == 'A')
	{
	    printf(" %s choose to Bat First \n", TeamA);
	    return TeamA;
	}
	else
	{
	    printf(" %s choose to Bat First \n", TeamB);
	    return TeamB;
	}
    }
    
    if(Bat_or_Bowl == 2)
    {
	if(TossWinner == 'A')
	{
	    printf(" %s choose to Bowl First \n", TeamA);
	    return TeamB;
	}
   	else
	{
	    printf(" %s choose to Bowl First \n", TeamB);
	    return TeamA;
	}
    }
    return "NoTeam";
}

int InninigsDetails::Ist_Innings(char * Teamer)
{
    printf("Ist_Innings %s \n",Teamer);
    return 0;
}
