#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "IDNumberUtil.h"

int isIDNumberLegal(char* idNumber) {
    if (strlen(idNumber) != 18) {
        return IDNUMBER_ILLEGAL_LENGTH;
    } else if(!isIDNumber_Legal_Character(idNumber)) {
        return IDNUMBER_ILLEGAL_CHARACTER;
    } else {
        int year, month, day;
        year = getYear(idNumber);
        month = getMonth(idNumber);
        day = getDay(idNumber);
        if (!isIDNumber_Legal_Birthday(year, month, day)) {
            return IDNUMBER_ILLEGAL_BIRTHDAY;
        }
    }
    return IDNUMBER_LEGAL;
}

int isIDNumber_Legal_Character(char* idNumber) {
    //check idNumber 1 to 17
    int i;
    for(i=0; i<17; i++) {
        if( (idNumber[i]<'0' && idNumber[i]>'9') ) {
            return 0;
        }
    }
    //check idNumber 18
    char ch = idNumber[17];
    if( (ch!='x') && (ch<'0' || ch>'9') ) {
        return 0;
    }
    return 1;
}

int isIDNumber_Legal_Birthday(int year, int month, int day) {
    int leap;
    leap = isLeapYear(year);
    if( (year<1900 || year>2100) || (month<1 || month>12) )
        return 0;
    switch(month) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12: {
            if(day<1 || day>31)
                return 0;
            break;
        }
        case 4:
        case 6:
        case 9:
        case 11: {
            if(day<1 || day>30)
                return 0;
            break;
        }
        case 2: {
            if(leap) {
                if(day<1 || day>29)
                    return 0;
            } else {
                if(day<1 || day>28)
                    return 0;
            }
            break;
        }
    }
    return 1;
}


//yes-1; no-0.
int isLeapYear(int year) {
    if ( ((year%4==0) && (year%400!=0)) || (year%400==0) ) {
        return 1;
    }
    return 0;
}

int getYear(char* idNumber) {
    int year=0;
    year = (idNumber[6]-'0') * 1000 + (idNumber[7]-'0') * 100 + (idNumber[8]-'0') * 10 + (idNumber[9]-'0');
    return year;
}

int getMonth(char* idNumber) {
    int month=0;
    month = (idNumber[10]-'0') * 10 + (idNumber[11]-'0');
    return month;
}

int getDay(char* idNumber) {
    int day=0;
    day = (idNumber[12]-'0') * 10 + (idNumber[13]-'0');
    return day;
}

/************************* test cases ************************
int main()
{
    const int ARR_LEN = 4;
    char idNumber[ARR_LEN][100] = {"511002111222", "511002abc123456789", "51100219880808123a", "511002198808081234"};
    int i;
    for(i=0; i<ARR_LEN; i++)
    {
        printf("idNumber = %s,  LEGAL = ", idNumber[i]);

        switch (isIDNumberLegal(idNumber[i])) {
            case IDNUMBER_LEGAL:                printf("IDNUMBER_LEGAL");               break;
            case IDNUMBER_ILLEGAL_LENGTH:       printf("IDNUMBER_ILLEGAL_LENGTH");      break;
            case IDNUMBER_ILLEGAL_CHARACTER:    printf("IDNUMBER_ILLEGAL_CHARACTER");   break;
            case IDNUMBER_ILLEGAL_BIRTHDAY:     printf("IDNUMBER_ILLEGAL_BIRTHDAY");    break;
            default:    break;
        }
        printf("\n");
    }
    return 0;
}
*/

