// Write a program accept a string from user and if in a string capital letter 
// replace from small letter and if in a string small letter replace from 
// capital letter
#include<stdio.h>

void strtoggleX(char *str)
{
    int Gap = 'a' - 'A';

    while(*str != '\0')
    {
        if((*str >= 'a') && (*str <= 'z'))
        {
            *str = *str - Gap;
        }
        else if((*str >= 'A') && (*str <= 'Z'))
        {
            *str = *str + Gap;
        }
        
        str++;
    }
}

int main()
{
    char Arr[20];

    printf("Enter string : \n");
    scanf("%[^'\n']s",Arr);

    strtoggleX(Arr);

    printf("String after editing is : %s\n",Arr);

    return 0;
}