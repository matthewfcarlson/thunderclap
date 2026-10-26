#include "decls/data/engine/audio.h"
// data: gCount_260950 = DAT_004e7a2c, gSource = DAT_004cd380

#include "compat/ptr.h"
extern "C" char DAT_0042aa7c[];
void InitSeq(void*, void*);
void DestroySeq(void*);
class Sub_260950 {
  public:
    void Clean();
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
    void Finish();
    SeqEventType* vfunc2(unsigned int flags);
};
SeqEventType* SeqEventType::vfunc2(unsigned int flags) {
    void* p = (*(void**)&DAT_004cd380);
    *(void**)this = (void*)((hulk_intptr)DAT_0042aa7c);
    InitSeq(p, this);
    --(*(int*)&DAT_004e7a2c);
    sub.Clean();
    Finish();
    if (flags & 1)
        DestroySeq(this);
    return this;
}
