#include <bits/stdc++.h>
using namespace std;

bool isPossible(string input);
int prefixZeroCount(string input);
void formatIt();
int countSubZero(string input);


int main()
{
    string inputWord;
    cout<<"Input the word here: \n";
    cin >> inputWord;


    vector <string> transitionS = {"A1B00"};
    vector <string> transitionA = {"0A","epsilon"};
    vector <string> transitionB = {"0B","1B","epsilon"};

    if(!isPossible(inputWord))
        cout<<"This word is not contained in the given context free grammar.\n";

    else
    {
        cout<<"\t\t\t"<<transitionS[0]<<endl;

        formatIt();

        int preZeroCnt = prefixZeroCount(inputWord);
        int subZeroCnt = 0;

        string outputTemp = "";

        for(int i = 1; i <= preZeroCnt; i++)
        {

            outputTemp += "0";
            cout << "\t\t\t"<<outputTemp + transitionS[0] <<endl;
            formatIt();


        }

        cout<<"\t\t\t"<<outputTemp + "epsilon1B"<<endl;
        formatIt();

        cout <<"\t\t\t"<<outputTemp + "1B"<<endl;

        formatIt();

        string temp = outputTemp + "1";

        transitionS.push_back(temp);

        int idx = 0;

        for( ; idx < inputWord.size() and inputWord[idx] != '1'; idx++);

        idx++;

        while(idx < inputWord.size())
        {

            if(inputWord[idx] == '1')
            {

                transitionS[1] += "1";
            }else
            {
                transitionS[1] += "0";
            }

            cout <<"\t\t\t" << transitionS[1]+"B"<<endl;

            formatIt();

            idx++;
        }

        cout << "\t\t\t"<<inputWord + transitionB[2]<<endl;

        formatIt();



        cout<<"\t\t\t"<<inputWord <<endl;

        formatIt();

        cout <<"\t\t\tWe have arrived at the destination!\n\n";

        return 0;

        }


}

        /*
        cout <<"Now let us see the rightmost derivation: \n\n\n";
        transitionS.push_back("A1");

        cout<<"\t\t\t S\n";
        formatIt();
        cout<<"\t\t\t A1B\n";
        formatIt();

        idx = 0;

        for( ; idx < inputWord.size() and inputWord[idx] != '1'; idx++);

        idx++;

        while(idx < inputWord.size())
        {

            if(inputWord[idx] == '1')
            {

                transitionS[2] += "1";
            }else
            {
                transitionS[2] += "0";
            }

            cout <<"\t\t\t" << transitionS[2]+"B"<<endl;

            formatIt();

            idx++;
        }



        cout << "\t\t\t"<<transitionS[2] + transitionB[2]<<endl;

        formatIt();

         cout << "\t\t\t"<<transitionS[2] <<endl;

        formatIt();


        outputTemp = "";
        for(int i = 1; i <= preZeroCnt; i++)
        {

            outputTemp += "0";
            cout << "\t\t\t"<<outputTemp + transitionS[2] <<endl;
            formatIt();


        }

        cout<<"\t\t\t"<<inputWord <<endl;

        formatIt();
        cout <<"\t\t\tWe have arrived at the destination!\n\n";


    }*/

    //return 0;

//}

bool isPossible(string input)
{
    for(auto chars: input)
    {
        if(chars != '1' and chars != '0')
        {
            return false;
        }

    }

    int zeroSuf = 0;
    bool f = false;

    for(auto chars: input)
    {


        if(chars == '1')
            f = true;

    }

    if(input.size() >=2)
    {
        if(f == true and input[input.size() - 1] == '0' and input[input.size() - 2] == '0')
            return true;
    }

    return false;

}


int prefixZeroCount(string input)
{
    int cnt = 0;

    for(int i = 0; i < input.size(); i++)
    {
        if(input[i] == '1')
            return cnt;

        cnt++;
    }

    return cnt;
}

void formatIt()
{
    for(int i = 0; i < 3; i++)
        cout <<"\t\t\t |\n";
}

int countSubZero(string input)
{
    int idx = 0;

    for( ; idx < input.size() and input[idx] != '1'; idx++);

    idx++;

    int ans = 0;

    for( ; idx < input.size(); idx++)
    if(input[idx] == '0')
        ans++;

    return ans;
}

