#include "gen/global.h"
#include "gen/owners.h"

class A_1dd450 {
  public:
};
struct CSPManager_nv_1dd450 {
    void g(int);
};

void CSPManager::FUN_001dd450(void* __p0) { A_1dd450 * arg = (A_1dd450 *)__p0;

    int x = ((owners::C_1d6c70 *)arg)->FUN_001d6c70();
    ((CSPManager_nv_1dd450*)this)->g(x);
}
