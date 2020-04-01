//Functions
#ifndef Functions_hpp
#define Functions_hpp
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//global変数
vector<int> canput;

u_long bitCount(u_long n);
int ShowIDs(u_long x);   
int InputID(string s);
string OutputID(int x);
//フラグの立っている数を数える
u_long bitCount(u_long n){
    u_long x = n;
    x = (x & 0x5555555555555555) + (x >> 1 & 0x5555555555555555);
    x = (x & 0x3333333333333333) + (x >> 2 & 0x3333333333333333);
    x = (x & 0x0f0f0f0f0f0f0f0f) + (x >> 4 & 0x0f0f0f0f0f0f0f0f);
    x = (x & 0x00ff00ff00ff00ff) + (x >> 8 & 0x00ff00ff00ff00ff);
    x = (x & 0x0000ffff0000ffff) + (x >>16 & 0x0000ffff0000ffff);
    x = (x & 0x00000000ffffffff) + (x >>32 & 0x00000000ffffffff);
    return x;
}


int ShowIDs(u_long x){
    if(x==(u_long)0){
        cout<<"pass"<<endl;
        return 1;
    }
    else{
        canput.resize(0);
        for (int i = 0; i < 64; i++)
        {
            if(x & ((u_long)1 << i)){
                cout<<OutputID(i)<<", ";
                canput.push_back(i);
            }
        }
        cout<<endl;
        return 0;
    }
    
}
int InputID(string s){
    int r = 0;
    for (int i = 0; i < 2; i++)
    {
        switch(s[i]){
            case 'a':
            case 'A':
                r+=0;
                break;
            case 'b':
            case 'B':
                r+=8;
                break;
            case 'c':
            case 'C':
                r+=16;
                break;
            case 'd':
            case 'D':
                r+=24;
                break;
            case 'e':
            case 'E':
                r+=32;
                break;
            case 'f':
            case 'F':
                r+=40;
                break;
            case 'g':
            case 'G':
                r+=48;
                break;
            case 'h':
            case 'H':
                r+=56;
                break;
            default:
                r+=s[i]-'0';
        }    
    }
    return r;
}
string OutputID(int x){
    string s(2,'0');
    s[0] = (char)(x/8+65);  
    s[1] = (char)(x%8+48);
    return s;
}
bool InArry(vector<int> v,int x){
    for (int i = 0; i < v.size(); ++i)
    {
        if(v[i]==x){
            return true;
        }
    }
    return false;
}
#endif
