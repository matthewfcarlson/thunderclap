// STATUS: equivalent (tools/equiv.py level 3: 108 inputs, branch coverage 26/26)
// hulkfight::motion::TimerCondition::vfunc_6 @ 0x0018d480
struct Timing {
    char pad0[0x1e60];
    float values[14];
    unsigned char valid[14];
    float FUN_0003eca0(const char* name);
    void FUN_00036350(int idx, float v);
};
struct Clock {
    Timing* FUN_00059a30();
};
namespace fight {
class Params {
public:
    virtual void vfunc_0();
    char pad4[4];
    Clock* FUN_000592a0();
};
}
class CFightParams : public fight::Params {
public:
    virtual void vfunc_0();
};
extern const char* DAT_004bebb4[14];
bool FUN_00018960(float a, float b, float eps);

class TimerCondition {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual bool vfunc_6(int a, fight::Params* params, int c);
    char pad04[8];
    int index;
    int mode;
    float limit;
    char useNamed;
    char pad19[3];
    int nameIndex;
};

bool TimerCondition::vfunc_6(int a, fight::Params* params, int c)
{
    if (index < 0 || index >= 14)
        return false;
    if (dynamic_cast<CFightParams*>(params) == 0)
        return false;
    Timing* timing = params->FUN_000592a0()->FUN_00059a30();
    float target = limit;
    if (useNamed != 0) {
        float v = timing->FUN_0003eca0(DAT_004bebb4[nameIndex]);
        if (v == 0.0f) {
            target = 3.4028235e38f;
        } else {
            target = v;
            if (timing->valid[index] == 0)
                timing->FUN_00036350(index, v);
        }
    }
    float cur = timing->values[index];
    switch (mode) {
    case 0:
        return cur < target;
    case 1:
        return cur <= target;
    case 2:
        return FUN_00018960(cur, target, 1e-5f);
    case 3:
        return !FUN_00018960(cur, target, 1e-5f);
    case 4:
        return cur >= target;
    case 5:
        return cur > target;
    }
    return false;
}
