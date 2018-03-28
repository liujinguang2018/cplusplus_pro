#include <boost/progress.hpp>
#include <boost/static_assert.hpp>

template <int N = 2>
class new_progress_timer : public boost::timer
{
  public:
    explicit new_progress_timer(std::ostream &os = std::cout)
        : timer(), m_os(os)
    {
        BOOST_STATIC_ASSERT(N >= 0 && N <= 10);
    }
    ~new_progress_timer()
    {
        //  A) Throwing an exception from a destructor is a Bad Thing.
        //  B) The progress_timer destructor does output which may throw.
        //  C) A progress_timer is usually not critical to the application.
        //  Therefore, wrap the I/O in a try block, catch and ignore all exceptions.
        try
        {
            std::istream::fmtflags old_flags = m_os.setf(std::istream::fixed, std::istream::floatfield);
            std::streamsize old_prec = m_os.precision(N);

            m_os << elapsed() << " s\n" << std::endl;

            m_os.flags(old_flags);
            m_os.precision(old_prec);
        }
        catch (...)
        {
        }
    }

  private:
    std::ostream &m_os;
};

//使用模板特化
template<>
class new_progress_timer<2>: public boost::progress_timer
{
};

int main()
{
    new_progress_timer<5> t;
}