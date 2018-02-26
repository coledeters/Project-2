#ifndef DSSTRING_H
#define DSSTRING_H
//#define CATCH_CONFIG_RUNNER
#include <iostream>
#include <fstream>
#include "DSString.h"
#include "Tweet.h"
#include "vec.h"
//#include "test.cpp"
//#include "Catch.hpp"
using namespace std;

/*
 * The plan is to loop through both test files to build a vector of DSStrings
 * then put all of the elements of the vector on to a output file where each line is
 * the word, positive count, negative count
 *
 * then for testing, it should take all of the vector file into a vector, then it will take the
 * tweets and analize them and output the tweet ID and positivity score on the new output file
 */


int main(int argc, char* argv[]){

DSString* ssss= new DSString(argv[2]);
if(*ssss=="-c")
{
        ifstream TestData;
        ifstream OurData;
        fstream classify;

        TestData.open(argv[3],ios::in);
        OurData.open(argv[4],ios::in);
        //Classify.open(argv[4],ios::out);
        vec<DSString> theVec;
        Tweet* t;
        DSString* in;
        char header[100];
        char pram[300];
        char ourP[30];
        char ourN[30];
        char TDataNum[164];
        char TDataID[164];
        char TDataName[164];
        char TDataTweet[800];
        int P=0;
        int N=0;
        int FinalPos=0;
        TestData.getline(header,100);
        DSString* TDNum;
        DSString* TDID;
        DSString* TDName;
        DSString* TDTweet;


        while(!OurData.eof())
        //for(int i=0;i<125000;i++)
        {
            if(!OurData.eof())
            {
                OurData.getline(pram,300,',');
                OurData.getline(ourP,30,',');
                OurData.getline(ourN,30);
                P= atoi(ourP);
                N= atoi(ourN);
                in = new DSString(pram,P,N);
                theVec.push_back(*in);
            }
        }
        OurData.close();
        classify.open(argv[5],ios::out);
        while(!TestData.eof())
        {
            if(!TestData.eof()){
                TestData.getline(TDataNum,164,',');
                TestData.getline(TDataID,164,',');
                TestData.getline(TDataName,164,',');
                TestData.getline(TDataTweet,800);

                TDNum=new DSString(TDataNum);
                TDID=new DSString(TDataID);
                TDName=new DSString(TDataName);
                TDTweet=new DSString(TDataTweet);

                t=new Tweet(*TDNum,*TDID,*TDName,*TDTweet);
                FinalPos=t->determinePositvity(theVec);
                //cout<< t->getNum().c_str()<<","<<FinalPos<<","<<t->getIDS().c_str()<<endl;
                classify<< t->getNum().c_str()<<","<<FinalPos<<","<<t->getIDS().c_str()<<endl;
            }
        }
        classify.close();
        TestData.close();
}


    if(*ssss=="-r"){



            vec<DSString> list(100000);

        DSString s10 ="test";
        int p =0;

        Tweet* comb;

        comb= new Tweet(s10,p);

        ifstream TrainData;
        ifstream TrainTarget;


        Tweet* t;
        DSString* TDID;
        DSString* TDName;
        DSString* TDTweet;
        int TTPos;


        char headerData[164];
        char headerTarget[164];

        char TDataNum[164];
        char TDataID[164];
        char TDataName[164];
        char TDataTweet[800];
        char TTargetNum[164];
        char TTargetID[164];
        char TTargetPos[164];


        TrainData.open(argv[3],ios::in);
        TrainTarget.open(argv[4],ios::in);

        if(!TrainData.is_open()) {
            cout << "Training file did not open." << endl;
        }

        if(!TrainTarget.is_open()) {
            cout << "Target file did not open." << endl;
        }

        TrainData.getline(headerData,164);
        TrainTarget.getline(headerTarget,164);
    //    while(!TrainData.eof()&&!TrainTarget.eof()){
        comb->thisVec().resize(1000000);
        for(int i=0;i<80000;i++){

            cout<<i<<endl;

            if(!TrainData.eof()){
                TrainData.getline(TDataNum,164,',');
                TrainData.getline(TDataID,164,',');
                TrainData.getline(TDataName,164,',');
                TrainData.getline(TDataTweet,800);
            }

            if(!TrainTarget.eof()){
                TrainTarget.getline(TTargetNum,164,',');
                TrainTarget.getline(TTargetPos,164,',');
                TrainTarget.getline(TTargetID,164);
            }
            if(!TrainTarget.eof()&&!TrainData.eof()){
            TDID=new DSString(TDataID);
            TDName=new DSString(TDataName);
            TDTweet=new DSString(TDataTweet);
            TTPos = (int)TTargetPos[0];
            if(TTPos==48){TTPos=0;}
            if(TTPos==52){TTPos=4;}
            t=new Tweet(*TDID,*TDName,*TDTweet,TTPos);
            comb->addtolist(t->thisVec());
            }
        }

        vec<DSString> vv;
        int tot;
        for(int i=0;i<comb->thisVec().size();i++)
        {
            tot=comb->thisVec()[i].getNegCount()+comb->thisVec()[i].getPosCount();
            if(tot>1){
                vv.push_back(comb->thisVec()[i]);
            }
        }
        fstream outputter;
        outputter.open(argv[5],ios::out);
        for(int i=0;i<vv.size();i++)
        {
            outputter << vv[i]<<endl;
            //cout<<vv[i]<<endl;
        }
        outputter.close();
        TrainData.close();
        TrainTarget.close();

    }
    return 0;

}
#endif
