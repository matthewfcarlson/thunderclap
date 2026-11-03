#include "gen/owners.h"
class Sub_311060 {
  public:
    void second(int);
    void third();
};
struct ThisCall_00310550 {
    void FUN_00310550();
};
void owners::C_311060::FUN_00311060() {
    a = b;
    ((ThisCall_00310550*)(this))->FUN_00310550();
    b = 0x4e6e6b28;
    Sub_311060* p = (Sub_311060*)((char*)this + 0x168);
    p->second(0x3c83126f);
    p->third();
}