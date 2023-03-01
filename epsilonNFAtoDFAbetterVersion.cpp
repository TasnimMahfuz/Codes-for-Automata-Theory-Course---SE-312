#include <bits/stdc++.h>
using namespace std;

int idxFind(vector<char> &vec, char c)
{
    for(int i = 0; i < vec.size(); i++)
    {
        if(c == vec[i])
        {
            return i;
        }
    }
    return -1;
}

void isAc(set<char> &setS, vector<char> &fin)
{
    for(int i = 0; i < fin.size(); i++)
    {
        char temp = fin[i];

        for(auto c: setS)
        {
            if(c == temp)
            {
                printf("%c is in the set of states the input word finally reaches and also in the set of final states.\n",c);\
                printf("Thus, this is absolutely ACCEPTED!!!");

                return;

            }
        }
    }
    printf("Ehhe, the states reached by the input word do not contain any element of the finishing state.\n");
    printf("Declined, sorry!:(");
    return;
}


int main()
{
    int numState,numTranSym, numAlphabet, stStateNum, finStateNum;
    vector<char> state, alphabet, start, finish;

    cout<<"How many transition symbols?\n";
    cin >> numTranSym;

    vector < set<char> > V[numTranSym + 1];

    for(int i = 0; i < numState; i++)
    {
        char temp; cin >> temp;
        state.push_back(temp);
    }

    cout<< "How many alphabets in the NFA?\n";
    cin >> numAlphabet;

    for(int i = 0; i < numAlphabet; i++)
    {
        char temp; cin >> temp;
        alphabet.push_back(temp);
    }

    cout<<"How many start states?\n";
    cin >> stStateNum;

    for(int i = 0; i < stStateNum; i++)
    {
        char temp; cin >> temp;
        start.push_back(temp);
    }

    cout<<"How many finishing states?\n";
    cin >> finStateNum;

    for(int i = 0; i < finStateNum; i++)
    {
        char temp; cin >> temp;
        finish.push_back(temp);
    }

    //Input taking for transition table.

    for(int i = 0; i <state.size() ; i++)
    {
        set<char> inputSet;

        for(int j = 0; j <= numTranSym ; i++)
        {
            if(j == numTranSym)
            {
                cout<<"From "<< state[i] <<", how many transitions can happen with epsilon?\n";
            }else
            {
                cout<<"From "<< state[i] <<", how many transitions can happen with"<< alphabet[j]<<" ?\n";
            }int temp; cin >> temp;

            while(temp--)
            {
                char tmpC; cin >> tmpC;

                inputSet.insert(tmpC);
            }

        }
    }
}
