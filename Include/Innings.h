#ifndef INNINGS_H_
#define INNINGS_H_

#include "main.h"
class InninigsDetails
{
private:
    char TeamA[12];
    char TeamB[12];
    char Toss;
    char TossAsk;
    char TossWinner;
    char Winner;
    char IstInnings;

public:
    InninigsDetails(char* ATeam , char * BTeam);
    int DoingToss(void);
    char * DecissionByCaptain_Bat_or_Bowl();
    int Ist_Innings(char * Teamer);
};

#endif
