几个公认的基本原理：
1. I/O的开销是昂贵的
2. 函数调用的开销是一个因素，因此应该采用内联短小、频繁调用的函数
3. 复制对象的开销是昂贵的，最好选择引用传递，而不是按值传递
经验表明，这三个原理没有涵盖C++性能的主要问题，主要问题是对不必要对象
的创建和后面的删除，这些不必要的对象设计要使用但确没有使用。Trace实现
是一个示例，说明了无用对象对性能的破坏性影响，即使是对Trace对象最简单
的使用，这一点也是非常明显。