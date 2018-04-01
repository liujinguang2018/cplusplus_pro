//#include <string>
#include <boost/ref.hpp>
#include <assert.h>
#include <math.h>
#include <string>
#include <iostream>
#include <typeinfo>
#include <set>



using namespace std;
using namespace boost;

void test_reference_wrapper()
{
    int x = 10;

    boost::reference_wrapper<int> rw(x);

    assert(x == rw);

    (int &)rw = 100;

    assert(x == 100);


    boost::reference_wrapper<int> rw2(rw);

    assert(rw2 == 100);

    string str;
    boost::reference_wrapper<string> rws(str);
    *rws.get_pointer() = "test reference_wrapper";
    cout << rws.get().size() << endl;
    cout << rws.get() << endl;
}

void test_ref()
{
    double pi = 3.1415926;
    auto rw = boost::cref(pi);
    cout << typeid(rw).name() << endl;

    string str;
    auto rws = boost::ref(str);
    cout << typeid(rws).name() << endl;
    cout << typeid(boost::unwrap_reference<decltype(rws)>::type).name() << endl;
    assert(boost::is_reference_wrapper<decltype(rws)>::value);
    assert(!boost::is_reference_wrapper<decltype(str)>::value);

    double value = 2.0;
    cout << sqrt(boost::ref(value)) << endl;

    set<int> s;
    auto rwset = boost::ref(s);
    boost::unwrap_ref(rwset).insert(12);  //返回被包装对象的引用
}

int main()
{
    test_reference_wrapper();
    cout << "============================" << endl;

    test_ref();
}