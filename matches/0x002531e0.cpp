#include "compat/ptr.h"
#include "decls/data/engine/audio.h"

class SeqEvent {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
};
class SeqEventVarPosDist : public SeqEvent {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual SeqEventVarPosDist* f4(int);
    void Prep();
};
extern void FUN_00247550(void*, SeqEventVarPosDist*);
SeqEventVarPosDist* SeqEventVarPosDist::f4(int flags) {
    Prep();
    if (flags & 1)
        FUN_00247550((void*)((hulk_intptr)((char*)((char*)&DAT_004e6ff0 + 72))), this);
    return this;
}