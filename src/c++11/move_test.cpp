#include <utility>
#include <algorithm>

class movable
{
  private:
    int x;

  public:
    movable() {}
    movable(movable &&other) //转移构造函数
    {
        std::swap(x, other.x);
    }

    //movable&
};