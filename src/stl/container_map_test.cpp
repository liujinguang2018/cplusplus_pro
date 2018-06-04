#include <map>
#include <iostream>
#include <string.h>
#include <assert.h>
using namespace std;

struct ltstr
{
    bool operator()(const char *s1, const char *s2) const
    {
        return strcmp(s1, s2) < 0;
    }
};

void days_of_month()
{
    map<const char *, int, ltstr> days;
    
    days["january"] = 31;
    days["february"] = 28;
    days["march"] = 31;
    days["april"] = 30;
    days["may"] = 31;
    days["june"] = 30;
    days["july"] = 31;
    days["august"] = 31;
    days["september"] = 30;
    days["october"] = 31;
    days["november"] = 30;
    days["december"] = 31;

    cout << "june -> " << days["june"] << endl;
    auto cur = days.find("june");
    cout <<  (*cur).first << " -> " << (*cur).second << endl;

    map<const char*, int, ltstr>::const_iterator prev = cur;
    --prev;
    cout << "Previous (in alphabetical order) is " << (*prev).first << endl;

    auto next = cur;
    ++next;
    cout << "Next (in alphabetical order) is " << (*next).first << endl;
}

void insert_test()
{
    map<string, int> M;
    M.insert(make_pair("A", 17));
    M.insert(make_pair("B", 74));

    if (M.find("Z") == M.end())
    {
        cout << "Not found: Z" << endl;
    }

    //insert new value in map
    pair<map<string, int>::iterator, bool> p = M.insert(make_pair("C", 4));
    assert(p.second);

    p = M.insert(make_pair("B", 3));
    assert(!p.second);
}

int main(int argc, char *argv[])
{
    cout << "Days of month: " << endl;
    days_of_month();
    
    cout << "Test insert: " << endl;
    insert_test();
}
