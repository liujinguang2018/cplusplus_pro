#ifndef PIMPL_SAMPLE
#define PIMPL_SAMPLE
//
// pimpl���÷���˼·�ǰѿͻ������˽�в�����������롣��Ϊ�ͻ����������ͷ�ļ���Ϊ����
// ͷ�ļ��б仯Ӱ�쵽�ͻ���pimpl�Ĺ��÷���ͨ����˽�����ݺͺ������뵽������ʵ���ļ���
// һ�����������У��ú���ͷ�ļ��ж�������ͽ���ǰ��������������һ��ָ������͵�ָ�룬
// �������ϸ�����ݡ�
//

struct impl;

class pimpl_sample {
    impl * pimpl_;
    //boost::scoped_ptr<impl> pimpl_;

    public:
    pimpl_sample();
    ~pimpl_sample();
    void do_something();
};

#endif