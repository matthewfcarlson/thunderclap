#include "decls/data/engine/audio.h"

class SeqEvent {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual SeqEvent* f4(int);
    virtual void f5();
    void setup();
};
class SeqEventVarTempo : public SeqEvent {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual SeqEventVarTempo* f4(int);
};
extern void FUN_00247550(const char*, SeqEventVarTempo*);
SeqEventVarTempo* SeqEventVarTempo::f4(int flags) {
    SeqEvent::setup();
    if (flags & 1)
        FUN_00247550(((char*)&DAT_004e6f88), this);
    return this;
}