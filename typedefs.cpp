#include <memory>
#include <map>

namespace Quux {
struct FooThread {};
struct BarThread {};

struct Foo {
  typedef std::shared_ptr<FooThread> thread_ptr_t;
  typedef std::map<int, thread_ptr_t> threads_t;

  threads_t threads;
  std::shared_ptr<BarThread> bar_thread;
};
}
