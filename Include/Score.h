#ifndef _SCORE_H_
#define _SCORE_H_

#include <map>
#include "main.h"

typedef unsigned char t_Ball;
typedef unsigned short t_Run;
typedef unsigned int t_Over;

typedef struct Batsman{
    char Batsman[50];
    unsigned int Run_Batsman;
    unsigned int Batsman_4s;
    unsigned int Batsman_6s;
    unsigned int Ball_Batsman;

}Batsman_t;

class ScoreCard
{
private:
    char CorrectBall;
    char Innings;
    char ItsOut;
    char Wicket;
    char Team1[12];
    char Team2[12];
    unsigned char Ball;
    unsigned short Run;
    unsigned int Batsman1Score;
    unsigned int Batsman2Score;
    std::map<t_Ball,t_Run> ballmap;
    std::map<int,Batsman_t>BatsmanStatus;
    std::map<int,Batsman_t>::iterator it;
    std::map<t_Ball,std::map<t_Ball,t_Run>> overmap;
    //std::map<t_Ball,t_Run>::iterator it;
    std::map<t_Ball,std::map<t_Ball,t_Run>>::iterator ptr;
    Batsman_t Batsman1_Ings;
    Batsman_t Batsman2_Ings;
	
public:
    unsigned int Over;
    unsigned int Score;

public:
    ScoreCard(char Ings,char *TeamName);
    int PuttheOver();
    int WinningDeclaration();
    int ScoreDetails();
    int BatsmanCard();
    int BattingOrderChange();
    int BattingDetails();
    int BatsMan_Init();
    int WicketChange();
    int OutBatsmanDetails();
    int OpeningBatsman();
};

#endif
