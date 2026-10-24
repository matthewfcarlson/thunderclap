#include "gen/global.h"

class A_1dd450 {
  public:
    int f();
};
struct CSPManager_nv_1dd450 {
    void g(int);
};

void CSPManager::FUN_001dd450(void* __p0) { A_1dd450 * arg = (A_1dd450 *)__p0;

    int x = arg->f();
    ((CSPManager_nv_1dd450*)this)->g(x);
}
