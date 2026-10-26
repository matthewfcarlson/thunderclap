// Same code shape as 0x00269560 (propagated; names are from that function)
#include "decls/data/engine/core.h"
// data: globalValue = DAT_004cdbb0

typedef unsigned char u8_270130;
extern void __cdecl release(int, void*);
class MemoryPool_270130 {
  public:
    void cleanup();
    virtual void f0();
    virtual void f1();
    virtual MemoryPool_270130* f2(u8_270130);
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
};
MemoryPool_270130* MemoryPool_270130::f2(u8_270130 flag) {
    cleanup();
    if (flag & 1)
        release(DAT_004cdbb0, this);
    return this;
}