#ifndef _MAIN_H_
#define _MAIN_H_


#include<iostream>
#include<unistd.h>
#include<string.h>

#define TOTALOVER	2

#define INDIA 		India		
#define AUSTRALIA	Australia	
#define	SRILANKA	Srilanka	
#define	PAKISTHAN	Pakisthan	
#define	SOUTHAFRICA	SouthAfrica 	
#define	ENGLAND		England		
#define	NEWZLAND	Newzland	
#define	WESTINDIES	WestEndies	

using namespace std;

typedef enum
{
    India=1,
    Australia=2,
    Srilanka=3,
    Pakisthan=4,
    SouthAfrica=5,
    England=6,
    Newzland=7,
    WestEndies=8
}Team;

#endif
