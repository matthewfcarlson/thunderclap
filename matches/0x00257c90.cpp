#include "decls/data/engine/audio.h"

extern void* DAT_0042a640[];
void FUN_00256d40(void*);
void FUN_00257730(void*);
void FUN_00247550(void*, void*);
class Entity_257c90 {
  public:
    void* vptr;
    void Fin();
};
class Sequence_257c90 : public Entity_257c90 {
  public:
    char pad[0x24];
    struct SB {
        char* p;
        char b[0x10];
        void Reset() { p = b; }
    } sb;
    char m3c[8];
    char m44[8];
    Sequence_257c90* f2(unsigned char flags);
};
Sequence_257c90* Sequence_257c90::f2(unsigned char flags) {
    vptr = DAT_0042a640;
    sb.Reset();
    FUN_00256d40(m3c);
    FUN_00257730(m44);
    Fin();
    if (flags & 1)
        FUN_00247550(((char*)((char*)&DAT_004e75b8 + 104)), this);
    return this;
}
