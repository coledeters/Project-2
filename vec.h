#ifndef VEC_H
#define VEC_H
#include <array>
template <typename T>
class vec
{

private:
    int siz=0;
    int capacity=0;
    T* ary=NULL;
public:
    vec();
    vec(int);
    vec(vec&);
    vec(const vec&);
    ~vec();
    void clear();
    void push_back(T);
    void erase(int);
    int size();
    int size() const;
    void resize(int);
    T* getAry() const;
    //T operator[] (int);
    T& operator[] (int);
    vec<T>& operator =(const vec);






};


template<typename T>
vec<T>::vec()
{
    siz =0;
    capacity=80;
    ary =new  T[capacity];
}

template<typename T>
vec<T>::vec(int i)
{
    siz=0;
    capacity=i;
    ary=new T[capacity];
}

template<typename T>
vec<T>::vec(vec& s)
{
    siz=s.size();//breakpoint
    capacity=siz+80;//clean this up and make it faster
    ary=new T[capacity];
    for(int i=0;i<siz;i++)
    {
        ary[i]=s[i];
    }
}






template<typename T>
vec<T>::~vec()
{
    ary=NULL;
    delete[] ary;
}



template<typename T>
T* vec<T>::getAry() const
{
    return ary;
}

template<typename T>
int vec<T>::size()
{
    if(this==NULL){return 0;}
    return siz;

}

template<typename T>
int vec<T>::size() const
{
    return siz;

}


template<typename T>
void vec<T>::push_back(T s)
{
    if(siz<capacity)
    {
        ary[siz]=s;
    }
    else{
        resize(capacity+150);
        ary[siz]=s;
    }
    siz++;
}

template<typename T>
T& vec<T>::operator[] (int i)
{
    return ary[i];
}


template<typename T>
void vec<T>::resize(int i)
{
    T* a;
    a=new T[i];
    if(i>capacity){
    for(int j=0;j<capacity;j++)
    {
        a[j]=ary[j];
    }
    }else{
        for(int j=0;j<i;j++)
        {
            a[j]=ary[j];
        }
    }
    delete[] ary;
    capacity=i;
    ary=a;
}

template<typename T>
void vec<T>::erase(int e)
{
    T a[capacity];
    for(int i=0;i<e;i++)
    {
        a[i]=ary[i];
    }
    for(int i=e;i<siz-1;i++)
    {
        a[i]=ary[i+1];
    }

    delete[] ary;
    ary=a;
    siz=siz-1;
    delete[] a;
}

template<typename T>
vec<T>& vec<T>::operator= (const vec<T> v)
{
    T* b=v.getAry();
    delete[] ary;
    ary=b;
    siz=v.size();
    capacity=siz+300;
    return *this;
}

template<typename T>
void vec<T>::clear()
{
    delete[] ary;
    siz=0;
    ary=NULL;
    ary=new T[capacity];



}

#endif // VEC_H
