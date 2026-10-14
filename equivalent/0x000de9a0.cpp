// STATUS: equivalent (tools/equiv.py level 3: 993 inputs, branch coverage 74/76, incomplete)
// FUN_000de9a0 @ 0x000de9a0
extern "C" void __fastcall __security_check_cookie(unsigned int);
extern unsigned int DAT_004d9968;

extern float DAT_004a0e60;
extern float DAT_004a0e64;
extern float DAT_004a0e68;

struct KeyBinding {
    int key;
    int value;
};

struct Sector {
    float lo;
    float hi;
    int key;
};

extern int DAT_004de8c0;
extern KeyBinding DAT_004de800[24];
extern Sector DAT_004de8d0[9];

float __cdecl FUN_000de800(float x, float y);

class Sink_de9a0 {
public:
    virtual void vfunc_0(int key, int pad);
    virtual void vfunc_1(int key, int pad);
    virtual void vfunc_2(int key, int pad);
};

class Pad_de9a0 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual float vfunc_4(int key);
    virtual float vfunc_5(int key);
    virtual int vfunc_6();
    virtual float vfunc_7(int axis);
    virtual void vfunc_8();
    virtual int vfunc_9();
    virtual float vfunc_10(int axis);
};

struct Frame_de9a0 {
    float ang;
    int p;
    Pad_de9a0* pad;
    float x;
    float y;
    Pad_de9a0** padSlot;
    int axis;
    int spill;
    unsigned char flags[8];
    volatile unsigned int cookie;
};

class InputMapper {
public:
    char pad00[8];
    Sink_de9a0* sink;
    char pad0c[4];
    Pad_de9a0* pads[1];
    unsigned char prev[3][8];
    float f2c;
    int lastKey;
    float f34;

    void FUN_000de1f0(int v);
    void FUN_000de9a0(char skip);
};

void InputMapper::FUN_000de9a0(char skip)
{
    Frame_de9a0 f;
    f.cookie = DAT_004d9968;
    unsigned char (*prevRow)[8] = prev;
    f.padSlot = &pads[0];
    for (f.p = 0; f.p < 1; f.p++) {
        f.pad = *f.padSlot;
        f.pad->vfunc_2();
        if (skip)
            break;

        bool found = false;
        for (int i = 0; i < DAT_004de8c0; i++) {
            if (f.pad->vfunc_5(DAT_004de800[i].key) <= DAT_004a0e68 &&
                f.pad->vfunc_4(DAT_004de800[i].key) > DAT_004a0e68) {
                found = true;
                FUN_000de1f0(0);
                if (sink)
                    sink->vfunc_0(DAT_004de800[i].value, f.p);
                if (sink)
                    sink->vfunc_2(DAT_004de800[i].value, f.p);
                f2c = 0;
            }
            if (f.pad->vfunc_5(DAT_004de800[i].key) > DAT_004a0e68 &&
                f.pad->vfunc_4(DAT_004de800[i].key) <= DAT_004a0e68) {
                if (sink)
                    sink->vfunc_1(DAT_004de800[i].value, f.p);
            }
        }
        if (!found)
            FUN_000de1f0(1);

        for (f.axis = 0; f.axis < 3; f.axis++) {
            Pad_de9a0* pad = f.pad;
            f.x = 0;
            f.y = 0;
            int axis = f.axis;
            if (axis < pad->vfunc_9())
                f.y = pad->vfunc_10(axis);
            if (axis < pad->vfunc_6())
                f.x = pad->vfunc_7(axis);
            *(unsigned int*)&f.flags[0] = 0;
            *(unsigned int*)&f.flags[4] = 0;
            f.ang = -DAT_004a0e68;
            if (f.x > DAT_004a0e68 || f.x < f.ang || f.y > DAT_004a0e68 || f.y < f.ang) {
                FUN_000de1f0(1);
                f.ang = 6.28318548f - FUN_000de800(f.x, f.y) * 0.0174533f;
                while (f.ang < 0.0f)
                    f.ang = f.ang + 6.28318548f;
                while (f.ang > 6.28318548f)
                    f.ang = f.ang - 6.28318548f;
                for (int s = 0; s < 9; s++) {
                    if (f.ang >= DAT_004de8d0[s].lo && f.ang < DAT_004de8d0[s].hi) {
                        int key = DAT_004de8d0[s].key;
                        if (!prevRow[f.axis][key]) {
                            if (sink)
                                sink->vfunc_0(key, f.p);
                            if (sink)
                                sink->vfunc_2(DAT_004de8d0[s].key, f.p);
                            lastKey = DAT_004de8d0[s].key;
                            f34 = 0;
                            f2c = 0;
                        }
                        f.flags[DAT_004de8d0[s].key] = 1;
                    }
                }
            }
            if (lastKey != 14 && f.flags[lastKey] && f34 > DAT_004a0e60 && f2c > DAT_004a0e64) {
                if (sink)
                    sink->vfunc_2(lastKey, f.p);
                f2c = 0;
            }
            for (int k = 0; k < 8; k++) {
                if (!f.flags[k] && prevRow[f.axis][k]) {
                    if (sink)
                        sink->vfunc_1(k, f.p);
                    lastKey = 14;
                }
            }
            *(unsigned int*)&prevRow[f.axis][0] = *(unsigned int*)&f.flags[0];
            *(unsigned int*)&prevRow[f.axis][4] = *(unsigned int*)&f.flags[4];
        }
        f.padSlot++;
    }
    __security_check_cookie(f.cookie);
}
