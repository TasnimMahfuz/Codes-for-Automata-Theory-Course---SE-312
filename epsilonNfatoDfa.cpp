#include <bits/stdc++.h>
using namespace std;

int idxFinder(vector<char> &vec, char c)
{
    for(int i = 0; i < vec.size(); i++)
    {
        if(vec[i] == c)
            return i;
    }
    return -1;
}



void checkAcceptance(set<char> &setS,vector<char> &fin)
{
    for(int i = 0; i < fin.size(); i++)
    {
        char temp = fin[i];

        for(auto c: setS)
        {
            if(c == temp)
            {
                cout<<c<<" is in both the set of accepting states and the set of final non-deterministic states that the NFA can be in."<<endl;
                cout<<"Thus,the given string is accepted by the language."<<endl<<endl<<endl<<endl;
                return;
            }
        }
    }

    cout<<"The string can not reach any accepting state. So, it is not from the language of this NFA."<<endl<<endl<<endl;
    return;
}

vector<char> eClose(vector<set<char> > &vEpsilon, vector<char> &state, char ch)
{
    set<char> processing;

    vector< char > toRet;

    int idx = idxFinder(state, ch);//oi borner index neo

    //to work here.

    processing = vEpsilon[idx];// oi index epsilon diye koi koi jai

    int id = 0;

    for(auto c: processing)
        toRet.push_back(c);//seta age vector e push kore rakho.

    while( id <= toRet.size())
    {
        if(id == toRet.size() and id > 0)
            break;

        processing.clear();

        int pt = idxFinder(state,toRet[id]);//id theke character niye kaaj shuru koro.

        processing = vEpsilon[pt];//oi character er epsilon diye transition niye neo.

        for(auto chr: processing)
        {
            bool flag = true;

            for(int j = 0; j < toRet.size(); j++)
            {
                if(toRet[j] == chr)
                {
                    flag = false;
                }
            }

            if(flag)
                toRet.push_back(chr);//jara jara eri majhe input hoi nai, tader ke input kore neo.
        }
        id++;// a queue data structure implementation with pointer like index.
    }
    return toRet;
}




int main()
{
    int numState,numAlphabet, startState, finState;
    vector<char> state, alphabet, start, finish;
    vector<set<char> > vZero,vOne,vEpsilon,vClosed;

    set<char> startSet, boroSet;
    string input;
    vector<set<char> > dfa;

    cout<<"Number of states in your NFA?: "<<endl;
    cin >>numState;

    for(int i = 0; i < numState; i++)
    {
        char temp;cin >> temp;
        state.push_back(temp);
    }

    cout<<"Number of alphabets in your NFA?: "<<endl;
    cin >> numAlphabet;

    for(int i = 0; i < numAlphabet; i++)
    {
        char temp; cin >> temp;
        alphabet.push_back(temp);
    }

    cout<<"How many start states?: "<<endl;
    cin >> startState;

    for(int i = 0; i < startState; i++)
    {
        char temp; cin >> temp;
        start.push_back(temp);
    }

    cout<<"How many finishing states?: "<<endl;
    cin >> finState;

    for(int i = 0; i < finState; i++)
    {
        char temp; cin >> temp;
        finish.push_back(temp);
    }


    //Input taking follows for transition table set.
    for(int i = 0; i < state.size(); i++)
    {
        //transition with zero
        cout<<"From "<<state[i]<<", how many transitions can happen with 0?"<<endl;
        int temp;cin >> temp;
        set<char> setZero;

        while(temp--)
        {
            char tempC; cin >> tempC;

            setZero.insert(tempC);

        }

        vZero.push_back(setZero);
        setZero.clear();

        //transition with one.
        cout<<"From "<<state[i]<<", how many transitions can happen with 1?"<<endl;
        temp;cin >> temp;
        set<char> setOne;

        while(temp--)
        {
            char tempC; cin >> tempC;

            setOne.insert(tempC);

        }

        vOne.push_back(setOne);
        setOne.clear();


        //transition with epsilon.

        set<char> setEpsilon;

        cout<<"From "<<state[i]<<", how many transitions can happen with no input or epsilon?"<<endl;
        temp;cin >> temp;
        setEpsilon.insert(state[i]);


        while(temp--)
        {
            char tempC; cin >> tempC;

            setEpsilon.insert(tempC);

        }

        vEpsilon.push_back(setEpsilon);
        setEpsilon.clear();


    }


    //eclose of all states.

    for(int i = 0; i < state.size(); i++)
    {
        vector <char> temp = eClose( vEpsilon, state, state[i]);

        set<char> toInsert;

        for(auto ch: temp)
            toInsert.insert(ch);

        vClosed.push_back(toInsert);
        toInsert.clear();


    }

    // Eclose set printing:

    for(int i = 0; i < state.size() ; i++)
    {
        cout<< state[i] <<" :  \t\t\t";

        cout<<"{ ";
        for(auto ch: vClosed[i])
        {
            cout << ch << " ";
        }
        cout<<"}"<<endl;
    }
    //eclose set printing done.


    for(int i = 0; i < start.size(); i++)
        startSet.insert(start[i]);


    getchar();
    cout<<"Enter your string to check its fitness for your given language: "<<endl;
    cin >> input;

    for(int i = 0; i < input.size(); i++)
    {
        cout<<input[i]<<"--> ";
        for(auto cc: startSet)
        {
            cout<<cc<<"\t";
        }cout<<endl;

        if(input[i] == '1')
        {
            for(auto val: startSet)
            {
                int idx = idxFinder(state,val);

                for(auto chars: vOne[idx])
                    boroSet.insert(chars);
            }
        }else
        {
            for(auto val: startSet)
            {
                int idx = idxFinder(state,val);

                for(auto chars: vZero[idx])
                    boroSet.insert(chars);
            }
        }
        startSet.clear();
        startSet = boroSet;
        boroSet.clear();

        /*
        startSet.clear();

        for(auto temp: boroSet)
            startSet.insert(boroSet);

        */

    }
    cout<<endl<<endl<<endl<<endl;

    checkAcceptance(startSet, finish);

    int id = 0;

    startSet.clear();

    for(auto k: start)
        startSet.insert(k);

    dfa.push_back(startSet);

    while(id <= dfa.size())
    {
        if(id == dfa.size() and id > 0)
            break;

        cout<<"{ ";
        for(auto cc: dfa[id])
        {
            cout<<cc<<" ";
        }cout<<"}   ||  ";


        set<char> temp1,temp2;

        for(auto k:dfa[id])
        {
            int idx = idxFinder(state,k);

            for(auto chars: vZero[idx])
            {
                temp1.insert(chars);
            }

            for(auto chars: vOne[idx])
            {
                temp2.insert(chars);
            }
        }

        cout<<"{ ";
        for(auto cc: temp1)
        {
            cout<<cc<<" ";
        }cout<<"}   ||  ";


        cout<<"{ ";
        for(auto cc: temp2)
        {
            cout<<cc<<" ";
        }cout<<"}\n\n";


        bool flag = true;
        for(int i = 0; i < dfa.size(); i++)
        {
            if(dfa[i] == temp1)
                flag = false;
        }

        if(flag)
            dfa.push_back(temp1);

        flag = true;

        for(int i = 0; i < dfa.size(); i++)
        {
            if(dfa[i] == temp2)
                flag = false;
        }

        if(flag)
            dfa.push_back(temp2);

        id++;

    }


    //tweaking for epsilon closed NFA.
    dfa.clear();
    cout<<endl<<endl<<endl <<"Now let us transition to DFA, given that epsilon transition is a valid operation!!!\n\n\n";
    id = 0;

    startSet.clear();

    /*
    for(auto k: start)
        startSet.insert(k);*/

    //startSet = vClosed[0];

    for(auto k: vClosed[0])
        startSet.insert(k);

    dfa.push_back(startSet);

    while(id <= dfa.size())
    {
        if(id == dfa.size() and id > 0)
            break;

        cout<<"{ ";
        for(auto cc: dfa[id])
        {
            cout<<cc<<" ";
        }cout<<"}   ||  ";


        set<char> temp1,temp2, tempOne, tempTwo;

        for(auto k:dfa[id])
        {
            int idx = idxFinder(state,k);

            for(auto chars: vZero[idx])
            {
                temp1.insert(chars);
            }

            for(auto chars: temp1)
            {
                int pt = idxFinder(state, chars);

                for(auto chr: vClosed[pt])
                    tempOne.insert(chr);
            }

            for(auto chars: vOne[idx])
            {
                temp2.insert(chars);
            }

            for(auto chars: temp2)
            {
                int pt = idxFinder(state, chars);

                for(auto chr: vClosed[pt])
                    tempTwo.insert(chr);
            }

        }

        cout<<"{ ";
        for(auto cc: tempOne)
        {
            cout<<cc<<" ";
        }cout<<"}   ||  ";


        cout<<"{ ";
        for(auto cc: tempTwo)
        {
            cout<<cc<<" ";
        }cout<<"}\n\n";


        bool flag = true;
        for(int i = 0; i < dfa.size(); i++)
        {
            if(dfa[i] == tempOne)
                flag = false;
        }

        if(flag)
            dfa.push_back(tempOne);

        flag = true;

        for(int i = 0; i < dfa.size(); i++)
        {
            if(dfa[i] == tempTwo)
                flag = false;
        }

        if(flag)
            dfa.push_back(tempTwo);

        id++;

    }



    return 0;

}
/*
4
a b c d
2
0 1
1
a
1
d
1 a 2 a b
0 1 c
0 1 d
1 d 1 d

*/

/*
5
a b c d e
2 0 1
1 a
1 e
2 a b
1 a
0
1 c
1 d
0
0
1 e
1 e
1 e
00110111100111111111001010101010

*/
//The following one is the input for epsilon transition.
/*
4
a b c d
2
0 1
1 a
1 d
2 a b 1 a 2 a c
0 1 c 1 b
1 d 0 2 b c
1 d 1 d 1 d
001100110011010000
*/

