// STATUS: equivalent (tools/equiv.py level 3: 3008 inputs, branch coverage 10/10)
// FEAnimation::vfunc_2 @ 0x000e14b0
class FETarget {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void SetTime(float t, int flags);
};

struct FEParent {
    char pad[0x38];
    int state;
};

extern float (__cdecl *DAT_004de948)();

class FEAnimation {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    char pad4[8];
    FETarget* target;       // 0x0c
    FEParent* parent;       // 0x10
    char pad14[0x44];
    int reverse;            // 0x58
    bool started;           // 0x5c
};

void FEAnimation::vfunc_2()
{
    if (started)
        return;
    started = true;
    if (parent && parent->state == 2 && target) {
        target->SetTime(DAT_004de948() * ((reverse == 0) * 2 - 1) * 1000.0f, 0);
    }
}
