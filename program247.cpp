#include<iostream>
using namespace std;

typedef unsigned int UINT;

UINT ToggleBit(UINT iNo)
{
    UINT iMask = 0X000000120;
    UINT iResult = 0;

    iResult = iNo ^ iMask;

    return iResult;
}

int main()
{
    UINT iValue = 0;
    UINT ivalue = 0;
    UINT ivalue2 = 0;
    
    UINT iRet = 0;

    cout<<"Enter number : "<<"\n";
    cin>>iValue;

    iRet = ToggleBit(iValue);
    cout<<"Result is : "<<iRet<<"\n";

    return 0;
}

/*

    iPos = 7

    iNo        0   0   1   1   0   1   0   0 
               0   1   0   0   0   0   0   0        ^
-----------------------------------------------------
               0   0   1   1   0   1   0   0
*/


