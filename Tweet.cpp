#include "Tweet.h"
#include "vec.h"

Tweet::Tweet()
{

}
Tweet::Tweet(DSString&nu,DSString &i, DSString &n, DSString &t)
{
    numberS=nu;
    IDS=i;
    name=n;
    tweets=t;
    this->splitWord(t);
}

Tweet::Tweet(DSString &i, DSString &n, DSString &t, int p)
{
    IDS=i;
    name=n;
    tweets=t;
    positvity=p;
    this->splitWord(t);
    if(positvity==4)
    {
        for(int i=0;i<words.size();i++)
        {
            words[i].addPos();
        }
    }
    else
    {
        for(int i=0;i<words.size();i++)
        {
            words[i].addNeg();
        }
    }
}

Tweet::Tweet(DSString &t, int p)
{
    tweets=t;
    positvity=p;
    words.resize(100000);
    this->splitWord(t);
    if(positvity==4)
    {
        for(int i=0;i<words.size();i++)
        {
            words[i].addPos();
        }
    }
    else
    {
        for(int i=0;i<words.size();i++)
        {
            words[i].addNeg();
        }
    }
}
int Tweet::getID()
{
    return ID;
}

DSString Tweet::getIDS()
{
    return IDS;
}

DSString Tweet::getName()
{
    return name;
}

int Tweet::getPositvity()
{
    return positvity;
}

DSString Tweet::getNum()
{
    return numberS;
}

void Tweet::addtolist(vec<DSString> &ww)
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

void Tweet::splitWord(DSString& tweet)
{
    int e=0;
    DSString* s;

    for(int i=0;i<tweet.getLength();i++)
    {
        //if(tweet[i]=='\0'){}else
        if(tweet[i]==' '
                ||tweet[i]=='.'
                ||tweet[i]==','
                ||tweet[i]=='!'
                ||tweet[i]=='?'
                ||tweet[i]=='"'
                ||tweet[i]==';'
                ||tweet[i]=='('
                ||tweet[i]==')'
                ||tweet[i]==')'
                ||tweet[i]==':'

                )
        {
            if(i==e+1||i==e)
            {
                e=i+1;
            }
            else{
                s=new DSString(tweet.substring(e,i-e));

                words.push_back(*s);
                e=i+1;
            }
        }


    }
    s=new DSString(tweet.substring(e,tweet.getLength()));
    if(s->c_str()!=nullptr)
    {
        words.push_back(*s);
    }
    delete s;
}




vec<DSString>& Tweet::thisVec()
{
    return words;
}


int Tweet::determinePositvity(vec<DSString>& ww)
{
    double posc=0;
    double negc=0;
    for(unsigned i=0;i < ww.size();i++)
    {
        for(unsigned j=0;j<words.size();j++)
        {
            if(ww[i]==words[j])
            {
                if(ww[i].getPositivity()==1){posc++;}else
                if(ww[i].getPositivity()==-1){negc++;}
            }
        }
    }

    if(posc/(posc+negc)>.51)
    {
        return 4;
    }

    return 0;

}


void Tweet::purgelist()
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
    words.clear();
    words.~vec();
    words=v;
}


