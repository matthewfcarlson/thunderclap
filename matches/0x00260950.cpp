#include "decls/data/engine/audio.h"
#include "decls/data/records.h"
// data: gCount_260950 = DAT_004e7a18.count, gSource = DAT_004cd380

#include "compat/ptr.h"
#include "gen/owners.h"
extern "C" char DAT_0042aa7c[];
extern "C" void FUN_002603e0(void*, void*);
void DestroySeq(void*);
class Sub_260950 {
  public:
};
class Type {
  public:
    virtual void dtor(unsigned int);
    virtual void vfunc1();
    virtual Type* vfunc2(unsigned int);
    virtual void vfunc3();
};
class SeqEventType : public Type {
  public:
    char pad[0x54];
    Sub_260950 sub;
    void FUN_002580e0();
    SeqEventType* vfunc2(unsigned int flags);
};
SeqEventType* SeqEventType::vfunc2(unsigned int flags) {
    void* p = (*(void**)&DAT_004cd380);
    *(void**)this = (void*)((hulk_intptr)DAT_0042aa7c);
    FUN_002603e0(p, this);
    --DAT_004e7a18.count;
    ((owners::Str_240060 *)&((SeqEventTypeHead *)this)->name)->FUN_00240060();
    FUN_002580e0();
    if (flags & 1)
        DestroySeq(this);
    return this;
}
