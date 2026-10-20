#include "compat/ptr.h"
extern "C" char DAT_003f9a5c[];
class CGrabTrack {
  public:
    unsigned int* vptr;
    char pad[0x44 - 4];
    CGrabTrack* vfunc_5(unsigned int);
    void FUN_00236d60();
};
class H1 {
  public:
    void FUN_00234150();
};
class H2_5b8c0 {
  public:
    void FUN_0027af50();
};
void thunk_FUN_00267090(CGrabTrack*);
CGrabTrack* CGrabTrack::vfunc_5(unsigned int flag) {
    vptr = (unsigned int*)((hulk_intptr)DAT_003f9a5c);
    ((H1*)((char*)this + 0x44))->FUN_00234150();
    ((H1*)((char*)this + 0x38))->FUN_00234150();
    ((H2_5b8c0*)((char*)this + 0x18))->FUN_0027af50();
    FUN_00236d60();
    if (flag & 1)
        thunk_FUN_00267090(this);
    return this;
}