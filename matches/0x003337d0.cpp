#include "gen/owners.h"
class T_3337d0 {
  public:
    char pad[0x48];
    char mFlag;
    void Set(void* p);
};
void T_3337d0::Set(void* p) {
    mFlag = (p != 0);
    ((owners::Obj_3335e0 *)this)->FUN_003335e0();
}
