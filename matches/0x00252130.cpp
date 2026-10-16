#include "gen/audio.h"

class SeqEvent_252130 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
};
class SeqEventCheck {
  public:
    bool CheckBase(void* p);
};
bool Read1(void*, void*);
bool Read2(void*, void*);
bool Read3(void*, void*);

int audio::SeqEventChannelVolumes::vfunc_0(void* __p0) { void * p = (void *)__p0;

    if (((SeqEventCheck*)this)->CheckBase(p)) {
        if (Read1(p, (char*)this + 0x18)) {
            if (Read2(p, (char*)this + 0x1c)) {
                if (Read3(p, (char*)this + 8)) {
                    return 1;
                }
            }
        }
    }
    return 0;
}
