#include <memory>
#include <functional>
#include <algorithm>
#include <assert.h>

using namespace std;

int main()
{
    pair<int *, ptrdiff_t> P = get_temporary_buffer<int>(10000);
    int *buf = P.first;
    ptrdiff_t N = P.second;

    uninitialized_fill_n(buf, N, 42);
    int *result = find_if(buf, buf+N, bind2nd(not_equal_to<int>(), 42));

    assert(result == buf+N);

    return_temporary_buffer(buf);
}