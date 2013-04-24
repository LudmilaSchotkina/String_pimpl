#include <iostream>
#include "newstring.h"

using namespace std;

class ConString: public String
{
public:
    ConString();
    ConString(int n);
    ConString(const char *str);
    ConString(const ConString &original);
    ConString(const String &original):String(original) {}
    ~ConString();

    ConString &operator=(const ConString &original);

    friend ostream &operator<<(ostream &output, const ConString &a);
    friend istream  &operator>>(istream &input, const ConString &a);
};

int main()
{
    ConString a("hello");
    ConString b("world");
    ConString c;
    c=a+b;
    cout<<"First string: "<<a<<endl;
    cout<<"Second string: "<<b<<endl;
    cout<<"a+b: "<<c<<endl;
    cout<<endl;

    ConString g;
    g=c.substr(3,6);
    cout<<"String  from 3 position 6 elements: "<<g<<endl;
    cout<<endl<<endl;

    if(a>=b)
        cout<<a<<" >= "<<b<<endl;
    else
        cout<<a<<" !>= "<<b<<endl;

    if(a<=b)
        cout<<a<<" <= "<<b<<endl;
    else
        cout<<a<<" !<= "<<b<<endl;

    if(a>b)
        cout<<a<<" > "<<b<<endl;
    else
        cout<<a<<" !> "<<b<<endl;

    if(a<b)
        cout<<a<<" < "<<b<<endl;
    else
        cout<<a<<" !< "<<b<<endl;

    if(a==b)
        cout<<a<<" == "<<b<<endl;
    else
        cout<<a<<" != "<<b<<endl<<endl<<endl;

    int len;
    cout<<"Length n = ";
    cin>>len;
    ConString ar(len);
    cout<<endl<<"Enter string (lenght n-1): ";
    cin>>ar;
    cout<<ar;

    return 0;
}

ConString::ConString():
    String()
{

}

ConString::ConString(int x):
    String(x)
{

}

ConString::ConString(const char *str):
    String(str)
{

}

ConString::ConString(const ConString &original):
    String(original)
{

}

ConString::~ConString()
{
}

ConString &ConString::operator=(const ConString &original)
{
    String::operator=(original);
    return *this;
}

ostream &operator<<(ostream &output, const ConString &a)
{
    char *array=a.get_array();
    for (int i=0; i<a.get_size(); ++i)
        output<<array[i];
    return output;
}
istream  &operator>>(istream &input, const ConString &a)
{
    int size=a.get_size();
    char *array=a.get_array();

    for(int i=0; i<size-1; ++i)
        input>>array[i];
    return input;
}
