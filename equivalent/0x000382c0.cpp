// STATUS: equivalent (tools/equiv.py level 3: 82 inputs, branch coverage 15/15)
// FUN_000382c0 @ 0x000382c0
struct Vec3_382c0 {
    float x, y, z;
};

struct Bias {
    float p0;
    float p4;
    float p8;
};

struct Limits_382c0 {
    char pad0[0x18];
    float minY;
};

struct World {
    char pad0[0x24];
    Limits_382c0 *limits;
};

struct Anchor_382c0 {
    // equiv-conv: FUN_00059a50 ecx stack
    bool FUN_00059a50(Vec3_382c0 *out);
};

extern unsigned int DAT_004d9968;
extern int DAT_004dc0e0;
extern int DAT_004dc0e4;
extern World *DAT_004dd700;
extern Bias DAT_0048f5d4;
extern Bias DAT_0048f5e0;
extern "C" void __fastcall __security_check_cookie(unsigned int);

class Camera {
public:
    char pad0[8];
    int f8;
    int fc;
    Anchor_382c0 *anchor;
    char pad14[0x12c];
    int mode;

    bool FUN_000352b0(Vec3_382c0 *out);
    bool FUN_00035550(Vec3_382c0 *out);
    bool FUN_000382c0(Vec3_382c0 *out);
};

bool Camera::FUN_000382c0(Vec3_382c0 *out)
{
    unsigned int cookie = DAT_004d9968;
    Vec3_382c0 pos;
    Vec3_382c0 off;

    if (!anchor->FUN_00059a50(&pos)) {
        __security_check_cookie(cookie);
        return false;
    }
    if (f8 != DAT_004dc0e0 || fc != DAT_004dc0e4) {
        if (!FUN_000352b0(out))
            *out = pos;
        __security_check_cookie(cookie);
        return true;
    }
    *out = pos;
    Bias *b = 0;
    switch (mode) {
    case 1:
    case 2:
        b = &DAT_0048f5d4;
        break;
    case 3:
        FUN_000352b0(out);
        break;
    case 4:
        b = &DAT_0048f5e0;
        break;
    }
    if (b != 0) {
        FUN_00035550(&off);
        out->x = off.x * b->p8 + out->x;
        out->z = off.z * b->p8 + out->z;
        out->y = off.y * b->p8 + out->y + b->p4;
    }
    float limit = DAT_004dd700->limits->minY;
    if (limit > out->y)
        out->y = limit;
    __security_check_cookie(cookie);
    return true;
}
