#include "decls/address.h"
struct StateHook {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void begin();
    virtual void end();
};
namespace pure3d {
struct SpriteParticleEmitter;
}
struct Gfx {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual void s23();
    virtual void s24();
    virtual void s25();
    virtual void s26();
    virtual void s27();
    virtual void s28();
    virtual void s29();
    virtual void s30();
    virtual void s31();
    virtual void s32();
    virtual void s33();
    virtual void s34();
    virtual void s35();
    virtual void s36();
    virtual void s37();
    virtual void s38();
    virtual void s39();
    virtual void s40();
    virtual void s41();
    virtual void s42();
    virtual void s43();
    virtual void s44();
    virtual void s45();
    virtual void s46();
    virtual void s47();
    virtual void s48();
    virtual void s49();
    virtual void s50();
    virtual void s51();
    virtual void s52();
    virtual void s53();
    virtual void s54();
    virtual void s55();
    virtual void s56();
    virtual void s57();
    virtual void s58();
    virtual void s59();
    virtual void setMode(int);
    virtual int getMode();
    virtual void setFlag(unsigned char);
    virtual unsigned char getFlag();
};
struct ParticleDrawer {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void draw(pure3d::SpriteParticleEmitter*);
};
namespace pure3d {
struct SpriteParticleEmitter {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    char pad04[0x7c];
    StateHook* hook;
    char pad84[0xc];
    ParticleDrawer* drawer;
    char pad94[0x11];
    unsigned char modeEnabled;
    unsigned char flag;
    char padA7[0x91];
    unsigned char active;
};
void SpriteParticleEmitter::vfunc_6() {
    if (active != 1 || !drawer)
        return;
    if (hook)
        hook->begin();
    unsigned char oldFlag = DAT_0052c2a8->getFlag();
    if (oldFlag != flag)
        DAT_0052c2a8->setFlag(flag);
    int oldMode = DAT_0052c2a8->getMode();
    if (!modeEnabled && oldMode != 1)
        DAT_0052c2a8->setMode(1);
    drawer->draw(this);
    if (!modeEnabled && oldMode != 1)
        DAT_0052c2a8->setMode(oldMode);
    if (oldFlag != flag)
        DAT_0052c2a8->setFlag(oldFlag);
    if (hook)
        hook->end();
}
} // namespace pure3d