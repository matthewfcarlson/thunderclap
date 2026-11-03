#include "decls/data/engine/audio.h"
#include "gen/owners.h"

class Elem_250350 {
  public:
};
class SeqEvent {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    char pad[4];
    Elem_250350 sub;
};
class SeqEventWait : public SeqEvent {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual SeqEventWait* f4(int);
    void Finish();
};
extern "C" void __cdecl FUN_00247550(void*, void*);
SeqEventWait* SeqEventWait::f4(int flags) {
    ((owners::Str_240060 *)&sub)->FUN_00240060();
    Finish();
    if (flags & 1)
        FUN_00247550(((int*)&DAT_004e69b0), this);
    return this;
}