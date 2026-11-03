#include "gen/owners.h"
struct E_27a570 {
    void f();
};
void owners::X_27a570::FUN_0027a570() {
    E_27a570* p = (E_27a570*)((char*)this + 0xa0);
    int i = 0x14;
    do {
        p = (E_27a570*)((char*)p - 8);
        p->f();
        --i;
    } while (i != 0);
}