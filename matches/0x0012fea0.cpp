#include "compat/ptr.h"
class StatTrack {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual ~StatTrack();
    virtual void v6();
    int pad04[3];
    int m10;
    void trackCall();
};
extern void __cdecl thunk_FUN_00267090(hulk_intptr);
StatTrack::~StatTrack() {
    thunk_FUN_00267090(m10);
    trackCall();
}
