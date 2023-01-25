#include <stdio.h>
#include <string.h>

int main()
{
    int stateNum, finStateNum, binStrLen = 100, len;

    printf("How many states are there?: ");
    scanf("%d",&stateNum);

    char states[stateNum + 13];

    for(int i = 0; i < stateNum; i++)
    {
        states[i] = 'a' + i;
    }
    states[stateNum] = '\0';


    //State input, Q has been completed.

    char inputSymbolSigma[2] = {'0','1'};

    char startState = 'a';// default;

    printf("Number of finishing states: ");
    scanf("%d",&finStateNum);

    char finStates[finStateNum + 13];

    getchar();
    for(int i = 0; i < finStateNum ; i++)
    {
        printf("Finishing state number : %d\n",i + 1);
        scanf("%c",&finStates[i]);
    }
    getchar();
    finStates[finStateNum] = '\0';

    char tranFunc[stateNum + 5][2];

    for(int i = 0; i < stateNum; i++)
    {
        printf("Transition for sigma[%c][%d] and then sigma[%c][%d]: ",'a' + i, 0, 'a' + i, 1);
        scanf("%c %c",&tranFunc[i][0],&tranFunc[i][1]);

        printf("\n%c %c\n",tranFunc[i][0],tranFunc[i][1]);

        getchar();
    }

    /*
    printf("Now input your binary string length: \n");
    scanf("%d",&binStrLen);
    */
    char binStr[binStrLen + 10];

    printf("Now input your binary string: \n");

    //getchar();
    /*
    for(int i = 0; i < binStrLen; i++)
    {
        scanf("%c",&binStr[i]);
    }binStr[binStrLen] = '\0';
    */

    scanf("%s",binStr);
    len = strlen(binStr);

    char curState = startState;

    for(int i = 0; i + 1 < len; i++)
    {
        printf("Sigma[%c][%d]: ",curState, binStr[i] - '0');
        curState = tranFunc[(int)(curState - 'a')][(int)(binStr[i] -'0')];

        printf("%c\n", curState);
    }

    for(int i = 0; i < finStateNum ; i++){

        if(curState == finStates[i])
        {
            printf("The given string fits the automata definition, yay!\n");

            printf("A more apprehensive transition system follows :) \n\n");

            curState = startState;
            printf("%c --> ",curState);
            for(int i = 0; i + 1 < len; i++)
            {
                //printf("Sigma[%c][%d]: ",curState, binStr[i] - '0');
                curState = tranFunc[(int)(curState - 'a')][(int)(binStr[i] -'0')];

                //printf("%c\n", curState);
                printf("%c --> ",curState);
            }
            printf("THE END!\n\n");
            return 0;
        }
    }
    printf("The input string does not fit with the given automata definition :(\n\n\n");

    return 0;
}
