
enum IDNumber {
    IDNUMBER_LEGAL = 0,
    IDNUMBER_ILLEGAL_LENGTH = 101,
    IDNUMBER_ILLEGAL_CHARACTER = 102,
    IDNUMBER_ILLEGAL_BIRTHDAY = 111,
};

#ifdef __cplusplus
    extern "C" {
#endif
        int isIDNumberLegal(char* idNumber); // return type refer to IDNumber
        int isIDNumber_Legal_Character(char* idNumber); //yes-1; no-0.
        int isIDNumber_Legal_Birthday(int year, int month, int day); //yes-1; no-0.
        int isLeapYear(int year); //yes-1; no-0.
        int getYear(char* idNumber);
        int getMonth(char* idNumber);
        int getDay(char* idNumber);
#ifdef __cplusplus
    }
#endif


/* shell cmd:
1.compile IDNumberUtil.c
 gcc IDNumberUtil.c -o IDNumberUtil

 
2.create so
 gcc -fPIC -c IDNumberUtil.c
 gcc -shared -o libIDNumberUtil.so IDNumberUtil.o

 or

 gcc IDNumberUtil.c -fPIC -shared -o libIDNumberUtil.so
*/
