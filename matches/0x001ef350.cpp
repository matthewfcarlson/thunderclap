#include "gen/owners.h"
class E_1ef350 {
  public:
    void F();
};
void owners::C_1ef350::FUN_001ef350() {
    E_1ef350* p = (E_1ef350*)((char*)this + 0x40);
    int n = 8;
    do {
        p = (E_1ef350*)((char*)p - 8);
        p->F();
        --n;
    } while (n != 0);
}