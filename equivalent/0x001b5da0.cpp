// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 10/12, incomplete)
// FUN_001b5da0 @ 0x001b5da0
extern "C" void __fastcall __security_check_cookie(unsigned int);
extern "C" unsigned int DAT_004d9968;

class Settings {
public:
    unsigned char FUN_0023f760(const char *name, int a, int b);
};

class Input {
public:
    unsigned char FUN_00092940(int button);
};

class Display {
public:
    char pad0[0x54];
    Input *input;
};

class Pad {
public:
    Input *FUN_00086340();
};

class Gravity {
public:
    void FUN_002ece90(float x, float y, float z);
};

class Anim {
public:
    void FUN_002eea80();
    void FUN_002ed6e0(int t);
};

class Timer {
public:
    void FUN_002f9660();
};

struct Globals {
    char pad0[0x54];
    Pad *pad;
};

extern Settings *DAT_004dd6e8;
extern Globals *DAT_004dd700;
extern Gravity *DAT_00554c10;
extern Timer DAT_0055545c;

class Physics {
public:
    void FUN_001b5da0(int a, int b);
    void FUN_001b4d00(int a, int b);

    char pad0[8];
    Anim *anim;
    char pad1[0x5a8 - 0xc];
    float gravityY;
};

void Physics::FUN_001b5da0(int a, int b)
{
    unsigned int cookie = DAT_004d9968;
    if (DAT_004dd6e8->FUN_0023f760("DoPhysics", 0x66, 1)) {
        Input *input = DAT_004dd700->pad->FUN_00086340();
        union { float f; unsigned int u; } d;
        bool set = false;
        if (input->FUN_00092940(0x13)) {
            d.f = gravityY - -500.0f;
            d.u &= 0x7fffffff;
            if (!(d.f <= 1e-05f)) {
                gravityY = -500.0f;
                set = true;
                DAT_00554c10->FUN_002ece90(0.0f, -500.0f, 0.0f);
            }
        }
        if (!set) {
            d.f = gravityY - -3000.0f;
            d.u &= 0x7fffffff;
            if (!(d.f <= 1e-05f) && !input->FUN_00092940(0x13)) {
                gravityY = -3000.0f;
                DAT_00554c10->FUN_002ece90(0.0f, -3000.0f, 0.0f);
            }
        }
        FUN_001b4d00(a, b);
        if (anim) {
            anim->FUN_002eea80();
            anim->FUN_002ed6e0(b);
        }
        DAT_0055545c.FUN_002f9660();
    }
    __security_check_cookie(cookie);
}
