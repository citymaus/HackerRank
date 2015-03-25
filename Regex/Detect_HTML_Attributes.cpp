#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <regex>
#include <map>
using namespace std;

map<string, string> m;
void parse_attr(string s);

void parse_attr(string tag, string s)
{
    //cout << "parse_attr: " << s << endl;
    map<string, string> attr;
    string attr_str = "";
    regex rx("\\s([a-z]+)=[\"|'][^\"']*[\"|']", regex_constants::icase);
    smatch match;
    bool matches;
    while(regex_search(s, match, rx))
    {
        //cout << "ATTR:" << match.str(1) << endl;
        attr[match.str(1)] = match.str(1);
        s = match.suffix().str();
    }
    
    string currattr = m[tag];
    string delimiter = ",";
    int pos = 0;
    if (currattr.length() > 0)
    {
        currattr += delimiter;
        while ((pos = currattr.find(delimiter)) != string::npos) 
        {
            string token = currattr.substr(0, pos);
            attr[token] = token;
            currattr.erase(0, pos + delimiter.length());
        }
    }
    for (map<string,string>::iterator iter=attr.begin(); iter!=attr.end(); ++iter) 
    {
        if (attr_str.length() == 0)
        {
            attr_str = iter->first;
        }
        else
        {
            attr_str += "," + iter->first;
        }
    }
    
    m[tag] = attr_str;
}

void html_attr(string s)
{   
    //cout << "html_attr: " << s << endl;
    regex rx("<([a-z0-9]+)((\\s([a-z]+)=[\"|'][^\"']*[\"|'])*)*(\\s*/)*>", regex_constants::icase);
    smatch match;
    
    //matches = regex_match(s, match, rx);
    while(regex_search(s, match, rx))
    {
        parse_attr(match.str(1), match.str(2));
        s = match.suffix().str();
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N;
    cin >> N;
    string s;
    getline(cin, s);
    for (int i = 0; i < N; i++)
    {
        getline(cin, s);
        html_attr(s);
    }
    for(map<string, string>::iterator iter = m.begin();
     iter != m.end();
     ++iter)
    {
        cout << iter->first << ":" << iter->second << endl;
    }
    return 0;
}
