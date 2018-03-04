#include <boost/shared_ptr.hpp>

#include <cassert>

class A {
    boost::shared_ptr<int> no_;

    public:
        A(boost::shared_ptr<int> no) : no_(no) {
            
        }
}
