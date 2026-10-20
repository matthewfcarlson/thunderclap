#include "compat/ptr.h"
#include "decls/data/engine/audio.h"

class SeqEvent {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual SeqEvent* f4(int);
    virtual void f5();
};
class SeqEventStream : public SeqEvent {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual SeqEventStream* f4(int);
};
class Helper_254160 {
  public:
    void Run();
};
extern void __cdecl FUN_00247550(void*, SeqEventStream*);
SeqEventStream* SeqEventStream::f4(int flag) {
    ((Helper_254160*)this)->Run();
    if (flag & 1)
        FUN_00247550((void*)((hulk_intptr)DAT_004e7200), this);
    return this;
}