#include "compat/ptr.h"
typedef unsigned char byte_13a9a0;
struct Helper_13a9a0 {
    int x;
    void run();
};
struct Main_13a9a0 {
    void run();
};
extern int vf_13a9a0;
extern void cleanup(void*);
class AnimationVelocityScaledTrack {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual AnimationVelocityScaledTrack* v5(byte_13a9a0);
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    char pad[0x14];
    Helper_13a9a0 h18;
    char gap[0x24];
    Helper_13a9a0 h40;
};
AnimationVelocityScaledTrack* AnimationVelocityScaledTrack::v5(byte_13a9a0 x) {
    *(hulk_intptr*)this = (hulk_intptr)&vf_13a9a0;
    h40.run();
    h18.run();
    ((Main_13a9a0*)this)->run();
    if (x & 1)
        cleanup(this);
    return this;
}