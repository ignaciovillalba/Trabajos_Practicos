#include "Validation.h"

int Validation_String(char string[])
{
    int i=0;
    int returnValue=1;
    while(string[i]!='\0')
    {
        if((string[i]!=' ') && (string[i]<'a' || string[i]>'z') && (string[i]<'A' || string[i]>'Z'))
        {
            returnValue=0;
        }
        i++;
    }
    return returnValue;
}

int Validation_Integer(char stringInteger[])
{
    int i=0;
    int returnValue=1;
    while(stringInteger[i]!='\0')
    {
        if((stringInteger[0]=='\n' || stringInteger[i]==' ') && (stringInteger[i]<'0' || stringInteger[i]>'9'))
        {
            returnValue=0;
        }
        i++;
    }
    return returnValue;
}

int Validation_IntID(char string[])
{
    int i=0;
    int returnValue=1;
    while(string[i]!='\0')
    {
        if((string[0]=='\n' || string[i]==' ') && (string[i]<'0' || string[i]>'9'))
        {
            returnValue=0;
        }
        i++;
    }
    return returnValue;
}
