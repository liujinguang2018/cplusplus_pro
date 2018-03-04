#include <string>
#include <iostream>
#include <boost/scoped_ptr.hpp>

void test_scoped_ptr() {
    boost::scoped_ptr<std::string> p(new std::string("Use scoped_ptr often."));

    //Print the value of the string
    if (p) {
        std::cout << *p << std::endl;
    }

    //Get the size of the string
    size_t i = p->size();
    std::cout << "size = " << i << std::endl;

    //Assign a new value to the string
    *p = "Acts just like a pointer.";
    std::cout << *p << std::endl;    
}

//scoped_ptr��auto_ptr֮�����Ҫ�����������Ƕ�����Ȩ�Ĵ���ʽ��:
//auto_ptr�ڸ���ʱ��ʹԴauto_ptr�Զ���������Ȩ����scoped_ptr��������
void scoped_vs_auto() {
    boost::scoped_ptr<std::string> p_scoped(new std::string("Hello"));
    std::auto_ptr<std::string> p_auto(new std::string("Hello"));

    std::cout << "scoped size = " << p_scoped->size() << std::endl;
    std::cout << "auto size = " << p_auto->size() << std::endl;

    //scoped_ptr����ͨ����ֵ��������߸�ֵ
    //boost::scoped_ptr<std::string> p_another_scoped = p_scoped;

    //����Ȩת��
    std::auto_ptr<std::string> p_another_auto = p_auto;
    std::cout << "auto size = " << p_another_auto->size() << std::endl;

    //std::cout << *p_auto << std::endl;
}

int main() {
    std::cout << "=====Test scoped_ptr=====";
    test_scoped_ptr();

    std::cout << "=====scoped_ptr vs auto_ptr=====";
    scoped_vs_auto();

    return 0;
}