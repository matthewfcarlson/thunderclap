#include "compat/ptr.h"
#include "decls/data/records.h"

// Free a block: the heap tree's owner of the block (0x00266f50) frees it through its slot 4 (core::IMemoryAllocator's
// free, which takes the block as a pointer).
struct Obj_267090 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4(void*);
};
extern "C" Obj_267090** FUN_00266f50(void*, void*);
extern "C" void FUN_00267090(void* ptr) {
    Obj_267090** p = FUN_00266f50(((char*)&DAT_00527f40), ptr);
    (*p)->f4(ptr);
}
