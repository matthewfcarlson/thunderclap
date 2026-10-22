#include "compat/ptr.h"
class ScriptHandler_1d2790 {
  public:
    char pad[8];
    int value;
    float helper(int, int);
    hulk_freg run(int x);
};
hulk_freg ScriptHandler_1d2790::run(int x) {
    return helper(x, value);
}
