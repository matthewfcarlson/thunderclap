#include "decls/data/engine/audio.h"

class SeqEvent {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    void Base();
};
class SeqEventChannelVolumes : public SeqEvent {
  public:
    virtual SeqEventChannelVolumes* f4(int);
};
extern void __cdecl FUN_00247550(void*, void*);
SeqEventChannelVolumes* SeqEventChannelVolumes::f4(int flag) {
    Base();
    if (flag & 1)
        FUN_00247550(((char*)((char*)&DAT_004e6d28 + 8)), this);
    return this;
}