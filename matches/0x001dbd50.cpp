#include "compat/ptr.h"
#include "decls/data/game/global.h"

class Loader_1dbd50 {
  public:
    void Config(const char*, int, int);
    void Type(const char*, int, int);
    void Pair(int, int);
    void Finish(int);
};
extern Loader_1dbd50* __cdecl FUN_001d4c90();
extern const int vals[];
void __cdecl FUN_001dbd50() {
    Loader_1dbd50* p = FUN_001d4c90();
    if (p) {
        p->Config("constants", 1, 1);
        p->Type("weaponTypes", 0, 1);
        const int* q = vals;
        do {
            p->Pair(*q, *q);
            ++q;
        } while ((hulk_intptr)q < ((hulk_intptr)DAT_004c6044));
        p->Finish(2);
    }
}