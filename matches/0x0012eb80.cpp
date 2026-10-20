#include "compat/ptr.h"
extern "C" char DAT_00411344[];
typedef unsigned int U_12eb80;
class DialogueTrack;
extern void __fastcall final_fn(DialogueTrack*);
extern void __cdecl release(U_12eb80);
class DialogueTrack {
  public:
    void* vf;
    char pad[12];
    U_12eb80 a;
    U_12eb80 b;
    char pad2[4];
    U_12eb80 c;
    U_12eb80 d;
    void destroy();
};
void DialogueTrack::destroy() {
    vf = (void*)((hulk_intptr)DAT_00411344);
    release(a);
    release(b);
    release(c);
    release(d);
    final_fn(this);
}
