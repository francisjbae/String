#ifndef STRING_H
#define STRING_H
#include <iostream>
using std::ostream; using std::ofstream; using std::ifstream; using std::istream;
using std::cout; using std::endl; using std::streambuf;

namespace String
{
    class string
    {
    public:
        string();
        string(const char s[]);

        //big 3
        string(const string& other);
        string& operator=(const string& other);
        ~string();

        int length() const;
        int size() const;

        char& operator[](int i);
        const char& operator[](int i) const;

        string operator+(const string& other) const;
        string operator+(const char& ch) const;

        bool operator==(const string& other) const;
        int find(const char* s, int pos = 0) const;

        //string substr(int start, int length) const;
        void print(ostream& out) const;
    private:
        char* buffer;
        int len;
    };

    ostream& operator<<(ostream& out, const string& str);
    istream& operator>>(istream& in, string& str);
    bool operator!=(const string& s, const string& t);
    bool operator>(const string& lhs, const string& rhs);
}
#endif