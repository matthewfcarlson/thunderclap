#include "compat/ptr.h"
#include "gen/audio.h"

class SeqAction_253eb0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3(int);
    virtual void f4();
    virtual void f5();
    virtual void f6();
};
extern int FUN_0024afe0(int);
extern void FUN_0024c160(int);

void audio::SeqActionStream::vfunc_3(hulk_intptr p) {
    int v = *(int*)((char*)p + 0x34);
    int x = FUN_0024afe0(v);
    if (x == 2) {
        v = *(int*)((char*)p + 0x34);
        FUN_0024c160(v);
    }
    this->f_20 = 4;
}
