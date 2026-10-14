// STATUS: equivalent (tools/equiv.py level 3: 92 inputs, branch coverage 43/47, incomplete)
// ControllerPollerBase::vfunc_1 @ 0x000de590
struct ButtonEntry {
    float value;
    int id;
};

struct AxisEntry {
    int id;
    float lo;
    float hi;
};

class Device_de590 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual float vfunc_4(float v);
    virtual void vfunc_5();
    virtual int vfunc_6();
    virtual float vfunc_7(int i);
    virtual void vfunc_8();
    virtual int vfunc_9();
    virtual float vfunc_10(int i);
};

extern ButtonEntry DAT_004de800[24];
extern int DAT_004de8c0;
extern AxisEntry DAT_004a0e70[8];
extern float DAT_004a0e68;

float __cdecl FUN_000de530(float x, float lo, float hi);

class ControllerPollerBase {
public:
    virtual void vfunc_0();
    virtual float vfunc_1(unsigned int cmd, int index);
    char pad04[0xc];
    Device_de590 *devices[4];
};

float ControllerPollerBase::vfunc_1(unsigned int cmd, int index)
{
    Device_de590 *dev = devices[index];
    float best = 0.0f;

    switch (cmd) {
    case 8:
    case 10:
    case 11:
        for (int i = 0; i < DAT_004de8c0; i++) {
            if (DAT_004de800[i].id == (int)cmd) {
                float v = devices[index]->vfunc_4(DAT_004de800[i].value);
                if (v > best)
                    best = v;
            }
        }
        if (best > DAT_004a0e68)
            return (best - DAT_004a0e68) / (1.0f - DAT_004a0e68);
        return 0.0f;

    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
        for (int k = 0; k < 8; k++) {
            if (DAT_004a0e70[k].id == (int)cmd) {
                for (int j = 0; j < dev->vfunc_6(); j++) {
                    float a = dev->vfunc_7(j);
                    float r = FUN_000de530(a, 0.0f, DAT_004a0e70[k].lo);
                    union { float f; unsigned int u; } ab;
                    ab.f = r;
                    ab.u = ab.u & 0x7fffffff;
                    if (ab.f > best)
                        best = ab.f;
                }
                for (int j = 0; j < dev->vfunc_9(); j++) {
                    float v = dev->vfunc_10(j);
                    float lo = 0.0f;
                    float hi = DAT_004a0e70[k].hi;
                    float r;
                    if (lo > hi) {
                        if (v >= hi && v <= lo)
                            r = v;
                        else if (v > lo)
                            r = lo;
                        else
                            r = hi;
                    } else {
                        if (v >= lo && v <= hi)
                            r = v;
                        else if (v > hi)
                            r = hi;
                        else
                            r = lo;
                    }
                    union { float f; unsigned int u; } ab;
                    ab.f = r;
                    ab.u = ab.u & 0x7fffffff;
                    if (ab.f > best)
                        best = ab.f;
                }
            }
        }
        if (best > DAT_004a0e68)
            return (best - DAT_004a0e68) / (1.0f - DAT_004a0e68);
        return 0.0f;

    default:
        return 0.0f;
    }
}
