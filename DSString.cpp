#ifndef DSSTRING_H
#define DSSTRING_H
#include "DSString.h"
#include <cstring>
#include <iostream>
#include <vector>
#include <memory>
#include <cstdlib>

using std::vector;


DSString::DSString()
{
    str=nullptr;
}

DSString::DSString(const char* pram)//was a const before char*
{
    if(pram!= nullptr){
    str= new char[strlen(pram)+1];
    strcpy(str,pram);
    }else{str=nullptr;}
}

DSString::DSString(char* pram)
{
    if(pram!= nullptr){
    str= new char[strlen(pram)+1];
    strcpy(str,pram);
    }else{str=nullptr;}
}

DSString::DSString(const DSString &pram)
{
    delete str;
    str=new char[pram.getLength()];
    for(int i =0;i<pram.getLength();i++)
        str[i]=pram.c_str()[i];
    posCount=pram.getPosCount();
    negCount=pram.getNegCount();
}

//DSString::DSString(DSString &pram)
//{


//    str=new char[pram.getLength()];
//    for(int i =0;i<pram.getLength();i++)
//        str[i]=pram.c_str()[i];


//    negCount=pram.getNegCount();
//    posCount=pram.getPosCount();

//}

DSString::DSString(const char * pram, int p, int n)
{
    str=new char[strlen(pram)+1];
    strcpy(str,pram);
    posCount=p;
    negCount=n;
}

DSString::DSString(const DSString& pram, int p, int n)
{
    str=new char[pram.getLength()];
    for(int i =0;i<pram.getLength();i++)
        str[i]=pram.c_str()[i];

    posCount=p;
    negCount=n;
}

DSString::~DSString()
{
    this==NULL;
    str=NULL;
    delete[] str;
}

int DSString::getLength()
{
    if(str==nullptr)
        return 0;
    return strlen(str);
}
int DSString::getLength() const
{
    if(str==nullptr)
        return 0;
    return strlen(str);
}

DSString& DSString::substring(int start, int numChars) const
{
    int leng=strlen(str);
    char* si;
    if(leng<start)
    {
        DSString c;
        return c;
    }
    else
    if(leng<(start+numChars))            //may need to be <= here
    {

        si=new char[leng-start];                                 //may need to add a 1 here
        for(int i=0;i<leng-start;i++)
        {
            si[i]=str[i+start];
        }
    }
    else
    {
        si=new char[numChars];                                          //may need to add a 1 here
        for(int i=0;i<numChars;i++)
        {
            si[i]=str[i+start];
        }
    }
    DSString* s= new DSString(si);
    return *s;
}

char* DSString::c_str()
{
    return str;
}

char* DSString::c_str() const
{
    return str;
}

DSString& DSString::operator=(const char* c)
{
    if(str==c)
        return *this;
    delete str;
    str=new char[strlen(c)];                                            //may need to add a 1 here
    for(int i =0;i<strlen(c);i++)
        str[i]=c[i];
    return *this;
}

DSString& DSString::operator=(const DSString& c)
{
    char* tem;
    tem=c.c_str();
    this->setNeg(c.getNegCount());
    this->setPos(c.getPosCount());
    delete str;
    str=tem;
    return *this;

}

DSString DSString::operator +(const DSString& s)
{
    int leng=strlen(str);
    char* c= new char[leng+s.getLength()];                               //may need to add a 1 here
    for(unsigned i=0;i<leng;i++){c[i]=str[i];}
    for(int i=0;i<s.getLength();i++){c[i+leng]=s.c_str()[i];}
    delete str;
    str= c;
    return *this;

}

bool DSString::operator==(const char* c)
{
    if(strlen(str)==strlen(c)){
        for(int i=0;i<strlen(str);i++)
        {
            if(str[i]==c[i]){}
            else{return false;}
        }
    }else{return false;}
            return true;

}

bool DSString::operator== (const DSString& c)
{
    if(strlen(str)==c.getLength()){
        for(int i=0;i<strlen(str);i++)
        {
            if(str[i]==c.c_str()[i]){}
            else{return false;}
        }
    }else{return false;}
            return true;
}

char& DSString::operator [](const int i)
{
    return str[i];
}

bool DSString::operator> (const DSString& c)
{
    if(str>c.c_str())
    {
        return true;
    }
    return false;
}

std::ostream &operator<< (std::ostream& os, const DSString& s)
{
    os<<s.c_str()<<","<<s.getPosCount()<<","<<s.getNegCount();
    return os;

}


void DSString::addPos()
{
    posCount=posCount+1;
}

void DSString::addNeg()
{
    negCount=negCount+1;
}

void DSString::setPos(int i)
{
    posCount=i;
}

void DSString::setNeg(int i)
{
    negCount=i;
}

int DSString::getPosCount(){return posCount;}
int DSString::getNegCount(){return negCount;}

int DSString::getPosCount()const{return posCount;}
int DSString::getNegCount()const{return negCount;}

int DSString::getPositivity()
{
    double total=posCount+negCount;
    if((posCount/total)>.5)
    {
        return 1;
    }
    if((negCount/total)>.55)
    {
        return -1;
    }
    return 0;
}

int DSString::getIntPos()
{
    if(str=="0"){return 0;}
    if(str=="4"){return 4;}
    return 0;
}

void DSString::addTo(DSString& s)
{
    negCount=negCount+s.getNegCount();
    posCount=posCount+s.getPosCount();

}

vec<DSString> DSString::splitWords(DSString v)
{
    vec<DSString> word;
    int e=0;
    DSString* s;

    for(int i=0;i<v.getLength();i++)
    {
        if(str[i]==' ')
        {
            if(i==e+1)
            {
                e=i+1;
            }
            else{
                s=new DSString(v.substring(e,i-e));
                word.push_back(*s);
                e=i+1;
            }
        }
    }
    s=new DSString(v.substring(e,v.getLength()));
//    if(s->c_str()!=nullptr)
//    {
        word.push_back(*s);
//    }
    //delete s;
    return word;

}

void DSString::addtolist(vec<DSString> &ww, vec<DSString> &words)
{
    int t=0;

    for(int i=0;i<ww.size();i++)
    {
        for(int j=0;j<words.size();j++)
        {
            if(words[j]==ww[i])
            {
                words[j].setNeg(words[j].getNegCount()+ww[i].getNegCount());
                words[j].setPos(words[j].getPosCount()+ww[i].getPosCount());
                t=1;
                j=words.size();
            }
        }
        if(t==0){
            words.push_back(ww[i]);
        }
        t=0;
    }
}

vec<DSString> DSString::purgelist(vec<DSString>& words)
{
    vec<DSString> v;
    int tot;
    for(int i=0;i<words.size();i++)
    {
        tot=words[i].getNegCount()+words[i].getPosCount();
        if(tot>1){
            v.push_back(words[i]);
        }
    }
    words.~vec();
    words=v;
    return v;
}


#endif // DSSTRING_H
