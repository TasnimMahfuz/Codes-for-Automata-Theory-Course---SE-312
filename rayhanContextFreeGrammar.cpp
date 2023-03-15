#include <bits/stdc++.h>
using namespace std;

map < string , vector <  string > > mp;
stack <string > stacky;
string  inputStr;

void grammarize();
void checkIt(string str);

int main()
{
    cout<<"Enter your input string: \n"; cin >> inputStr;

    grammarize();

    checkIt("S");


    cout<<"The string is not in the context free grammar:(\n";
    return 0;

}

void grammarize()
{
    mp["S"].push_back("A1B");

    mp["A"].push_back("0A");
    mp["A"].push_back("");

    mp["B"].push_back("0B");
    mp["B"].push_back("1B");
    mp["B"].push_back("");
}

void checkIt(string str)
{
    int cnt = 0;

    for(int i = 0; i < str.size(); i++)
        if(str[i] == '0' or str[i] == '1')
            cnt++;

    if(cnt > inputStr.size())
        return;


    stacky.push(str);

    if(str == inputStr)
    {

        cout << "The input falls withing the context free grammar. The process follows: \n\n";
        vector < string > vec;

        while(stacky.empty() == false)
        {
            string temp;
            temp = stacky.top();
            vec.push_back(temp);

            stacky.pop();
        }

        reverse(vec.begin(), vec.end());

        bool f = false;

        for(auto words: vec)
        {
            if(f)
                cout<<"-->";
            else
                f = true;

            cout << words<<endl;
        }
        exit(0);
    }

    for(int i = 0; i < str.size(); i++)
    {
        if(str[i] == '0' or str[i] == '1')
            continue;

        string pre = str.substr(0, i);
        string sub = str.substr(i + 1, str.size() - (i + 1));

        string transition = str.substr(i,1);


        for(auto vals: mp[transition])
        {

            string willSend = pre + vals + sub;

            checkIt(willSend);
        }
    }

    stacky.pop();

}
