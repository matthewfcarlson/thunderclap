#include "gen/fight.h"

extern "C" char DAT_00411344[];
class DialogueTrack_132cc0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    char pad[8];
    int a, b, c, d, e, f;
    char g;
    void Init();
};
void* __cdecl FUN_0008d690(unsigned int);

template <> void* fight::TrackFactoryTemplate<hulkfight::DialogueTrack>::vfunc_5() {
    DialogueTrack_132cc0* p = (DialogueTrack_132cc0*)FUN_0008d690(0x28);
    int z = 0;
    if (p != 0) {
        p->Init();
        p->a = z;
        p->b = z;
        p->c = z;
        p->d = z;
        p->e = z;
        p->f = z;
        p->g = (char)z;
        *(void**)p = (void*)((int)DAT_00411344);
        *((int*)p + 2) = 1;
        return (void*)(p);
    }
    return (void*)(0);
}
