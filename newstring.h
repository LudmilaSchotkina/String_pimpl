#ifndef NEWSTRING_H
#define NEWSTRING_H

#include <iostream>

class String
{
public:
    String();
    String(int n);
    String(const char *str);
    String(const String &original);
    ~String();

    int length() const;
    String substr(int first, int n) const;

    String &operator=(const String &original);
    String operator+(const String &x)const;

    bool operator==(const String &x)const;
    bool operator>=(const String &x)const;
    bool operator<=(const String &x)const;
    bool operator>(const String &x)const;
    bool operator<(const String &x)const;
protected:
    int get_size()const;
    char *get_array()const;
private:
    class ImString;
    ImString *pimpl;
    String(const ImString &original);
};
#endif
