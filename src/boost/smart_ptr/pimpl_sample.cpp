#include "pimpl_sample.hpp"
#include <string>
#include <iostream>

struct impl {
    void do_something() {
        std::cout << s_ << std::endl;
    }

    std::string s_;
};

//pimpl_sample��Ĺ��캯���ڹ�����pimpl֮����ܻ��׳�һ���쳣
//�ڹ��캯�����׳��쳣��ζ�Ź������û���������ڣ������ջչ��
//ʱ��������������Ĺ��ź��������˵����impl_ָ����䲢������ڴ�
//����й¶
pimpl_sample::pimpl_sample() : pimpl_(new impl) {
    pimpl_->s_ = "This is the pimpl idiom";
}

pimpl_sample::~pimpl_sample() {
    delete pimpl_;
}

void pimpl_sample::do_something() {
    pimpl_->do_something();
}