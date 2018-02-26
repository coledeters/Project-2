#ifndef TWEET_H
#define TWEET_H
#include "DSString.cpp"
using std::vector;

class Tweet
{
private:
    int number;
    int ID;
    DSString numberS;
    DSString IDS;
    DSString name;
    DSString tweets;
    int positvity;
    vec<DSString> words;


public:
    Tweet();
    Tweet(DSString);
    Tweet(int i, DSString& n, DSString& t);
    Tweet(int i, DSString& n, DSString& t,int p);
    Tweet(DSString &nu, DSString &i, DSString &n, DSString &t);
    Tweet(DSString& i, DSString& n, DSString& t,int p);
    Tweet(DSString& t,int p);
    Tweet(int num,int i, DSString& n, DSString& t);
    Tweet(int num,int i, DSString& n, DSString& t,int p);
    int getID();
    void setID(int);

    DSString getIDS();
    void setIDS(DSString);
    DSString getNum();

    DSString getName();
    void setName(DSString);
    void addtolist(vec<DSString> &);
    vec<DSString> &thisVec();
    int getPositvity();
    void setPositvity(int);

    int determinePositvity(vec<DSString> &ww);
    void splitWords(DSString&);
    void splitWord(DSString&);
    void purgelist();





};

#endif // TWEET_H
