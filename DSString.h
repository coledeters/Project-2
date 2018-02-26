#ifndef STRING
#define STRING
#include <iostream>
#include <cstring>
#include <vector>
#include "vec.h"

using std::vector;

class DSString{

    private:
        char* str = nullptr;
        int posCount=0;
        int negCount=0;
        int isPos=0;//0 is neutral, 1 is positive, -1 is negitive
        int length=0;


        /**
         *  You will need to add some private data members here.
         *  This is up to your discretion.  However, we **strongly**
         *  encourage you to implement your string class as a wrapper
         *  for typical null-terminated c-strings.  In doing this, you
         *  may use c-sting functions in the methods in this class such
         *  as:
         *    * strlen(...)
         *    * strcpy(...)
         *    * strcmp(...)
         *    * strncpy(...)
         *    * strcat(...)
         *    * strncat(...)
         *
         *    A quick google search will return plenty of references on
         *    the c-string functions.
         **/


    public:

        /**
         * Constructors and destructor
         *
         * Make sure you do proper memory management.
         **/
        DSString();
        DSString(const char*);//should be a const in front of the DSString&
        DSString(char*);
        //DSString(DSString&);
        DSString(const DSString&);//should be a const in front of the DSString&
        DSString(const char*, int,int);
        DSString(const DSString&, int,int);
        ~DSString();


        /**
         * Standard relational operators.  You are free to expand this
         * list if you'd like.
         *
         * Note that for each operator, there are two overloaded versions:
         *    one that takes a String object
         *    one that takes a null-terminated c-string
         *
         **/
        DSString& operator= (const char*);//
        DSString& operator= (const DSString&);//should be a const in front of DDString&
        DSString operator+ (const DSString&);//should be a const in front of DDString&
        bool operator== (const char*);//
        bool operator== (const DSString&);//should be a const in front of DDString&
        bool operator> (const DSString&);
        char& operator[] (const int);

        /**
         * getLength() returns the number (count) of characters in the string.
         **/
        int getLength();
        int getLength() const;

        /**
         * The substring method returns a string object that contains a
         * sequence of characters from this string object.
         *
         * param start - the index of where to start
         * param numChars - the number (count) of characters to copy into
         *    the substring
         **/
        DSString& substring(int start, int numChars) const;

        /**
         * the c_str function returns a null-terminated c-string holding the
         * contents of this object.
         **/
        char* c_str();
        char* c_str() const;

        /**
         * Overloaded stream insertion operator to print the contents of this
         * string to the output stream in the first argument.
         **/
        friend std::ostream& operator<< (std::ostream&, const DSString&);

        //You are free to add more functionality to the class.  For example,
        //you may want to add a find(...) function that will search for a
        //string within a string.  (just an example)
        //
        //Further - you will be able to update and modify this class as the
        //semester progresses.

        void addPos();
        //will add 1 to the positive count

        void addNeg();
        //will add 1 to the negitive count

        int getPositivity();
        //gets the int for positivity
        int getPosCount();
        int getNegCount();

        int getPosCount() const;
        int getNegCount() const;

        void setPos(int);

        void setNeg(int);

        int getIntPos();

        void addTo(DSString &s);

        vec<DSString> splitWords(DSString v);
        void addtolist(vec<DSString>&, vec<DSString>& words);
        vec<DSString> purgelist(vec<DSString> &words);




};


#endif

//DSString.h
//Displaying DSString.h.
