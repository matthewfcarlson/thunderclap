#include "gen/core.h"

struct Target {
    void f(int*, int);
};
namespace core {
} // namespace core
void core::DebugConsole::vfunc_5() {
    int a[2];
    a[1] = (int)this;
    a[0] = 3;
    (*(Target * *)&this->f_a4)->f(a, 8);
}
