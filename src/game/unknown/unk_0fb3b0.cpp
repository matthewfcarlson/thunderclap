// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000fb3b0..0x000fb830 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f4646cfc {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f4646cfc {} using namespace fn_f4646cfc;
#include "game/unknown.h"

// ---- declarations shared by the functions below
namespace fn_f4646cfc {
struct IVec3 { int x, y, z; };
struct Src_fb3b0 { char pad0[0x3c]; int v3c; char pad1[0x78 - 0x40]; IVec3 v78; };
struct Target_fb3b0 {
    int f0;
    Src_fb3b0 *src;
    int f8;
    float fc;
    int f10;
    int f14;
    int f18;
    int f1c;
    IVec3 v20;
    float f2c;
    int f30;
    char flag;
    void FUN_000fb3b0(Src_fb3b0 *s, char flag);
};
struct Vec3 {
    unsigned int x, y, z;
};
struct Destination {
    char pad0[0x3c];
    unsigned int value;
    char pad1[0x38];
    Vec3 position;
};
inline void copyVec(Vec3* d, volatile Vec3* s) {
    d->x = s->x;
    d->y = s->y;
    d->z = s->z;
}
} // namespace fn_f4646cfc
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" char* __cdecl strncpy(char*, const char*, unsigned int);
#endif
namespace fn_f4646cfc {
struct Vec3_fb4b0 { float x, y, z; };
struct Target_fb4b0 {
    char pad0[0x3c];
    unsigned int color;      // 0x3c
    char pad1[0x78 - 0x40];
    Vec3_fb4b0 offset;             // 0x78
};
union FloatBits_fb4b0 {
    float f;
    unsigned int u;
};
class Fade_fb4b0 {
public:
    int state;               // 0x0
    Target_fb4b0 *target;          // 0x4
    float start;             // 0x8
    float duration;          // 0xc
    float time;              // 0x10
    float scale[3];          // 0x14
    Vec3_fb4b0 base;               // 0x20
    float floor;             // 0x2c
    unsigned char b0;        // 0x30
    unsigned char b1;        // 0x31
    unsigned char b2;        // 0x32
    unsigned char alpha;     // 0x33
    char reverse;            // 0x34
    bool FUN_000fb4b0(float dt);
};
struct Dest;
struct Source {
  public:
    union { unsigned int a; unsigned int state; };
    union { unsigned int b; Destination* destination; };
    unsigned int c;
    unsigned int d;
    unsigned int e;
    unsigned int f;
    char _m_pad_18[0x8];
    Vec3 position;
    char _m_pad_2c[0x4];
    volatile unsigned int value;
    void FUN_000fb420();
    void FUN_000fb640(Dest *dest, hulk_uintptr x, unsigned int y);
};
struct Dest { unsigned int type; unsigned int pad4; unsigned int a,b; unsigned int pad10; unsigned int c,d,e; char pad20[12]; unsigned int f; void FUN_000fb3b0(unsigned int x,unsigned int y); void FUN_000fb4b0(unsigned int x); };
typedef unsigned int uint_fb6e0;


// 0x000fb3b0 FUN_000fb3b0 (109 B): equivalent/0x000fb3b0.cpp
// sym: ?FUN_000fb3b0@Target_fb3b0@fn_f4646cfc@@QAEXPAUSrc_fb3b0@2@D@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_000fb3b0 @ 0x000fb3b0
void Target_fb3b0::FUN_000fb3b0(Src_fb3b0 *s, char fl)
{
    flag = fl;
    src = s;
    f10 = 0;
    f8 = 0;
    f14 = 0;
    f18 = 0;
    f1c = 0;
    f2c = 1.0f;
    fc = 1.0f;
    f30 = s->v3c;
    IVec3 v = s->v78;
    v20 = v;
    f0 = 1;
}


// 0x000fb420 FUN_000fb420 (69 B): matches/0x000fb420.cpp
// sym: ?FUN_000fb420@Source@fn_f4646cfc@@QAEXXZ
void Source::FUN_000fb420() {
    destination->value = value;
    volatile Vec3 tmp = position;
    copyVec(&destination->position, &tmp);
    state = 0;
}

} // namespace fn_f4646cfc

// 0x000fb470 FUN_000fb470 (51 B): matches/0x000fb470.cpp
// sym: ?FUN_000fb470@Thing_fb470@owners@@QAEPAU12@PBD@Z
owners::Thing_fb470* owners::Thing_fb470::FUN_000fb470(const char* s) {
    strncpy(text, s, 0x20);
    a[0] = 0;
    a[1] = 0;
    a[2] = 0;
    a[3] = 0;
    a[4] = 0;
    value = 1.0f;
    return this;
}

namespace fn_f4646cfc {

// 0x000fb4b0 FUN_000fb4b0 (391 B): equivalent/0x000fb4b0.cpp
// sym: ?FUN_000fb4b0@Fade_fb4b0@fn_f4646cfc@@QAE_NM@Z
// STATUS: equivalent (tools/equiv.py level 3: 19921 inputs, branch coverage 14/14)
// FUN_000fb4b0 @ 0x000fb4b0
bool Fade_fb4b0::FUN_000fb4b0(float dt)
{
    double end = start + duration;
    double t = dt + time;
    double cur;
    if (t >= 0.0 && t <= end)
        cur = t;
    else if (t > end)
        cur = end;
    else
        cur = 0.0;
    time = (float)cur;
    FloatBits_fb4b0 d;
    d.f = (float)(cur - end);
    d.u &= 0x7fffffff;
    if (d.f <= 1e-5f)
        time = (float)end;
    double u;
    if (time < start)
        u = 1.0;
    else
        u = (end - time) / duration;
    if (reverse)
        u = 1.0 - u;
    double v = 1.0 - u;
    float w0 = (float)(v * scale[0]);
    float w1 = (float)(v * scale[1]);
    float w2 = (float)(v * scale[2]);
    int a = (int)(__int64)(((1.0 - floor) * u + floor) * (int)(__int64)alpha);
    unsigned int c = ((unsigned int)(__int64)a << 8) | b2;
    c = (c << 8) | b1;
    c = (c << 8) | b0;
    target->color = c;
    target->offset.x = w0 + base.x;
    target->offset.y = w1 + base.y;
    target->offset.z = w2 + base.z;
    FloatBits_fb4b0 e;
    e.f = (float)(time - end);
    e.u &= 0x7fffffff;
    if (e.f <= 1e-5f) {
        state = 3;
        return false;
    }
    return true;
}


// 0x000fb640 FUN_000fb640 (74 B): equivalent/0x000fb640.cpp
// sym: ?FUN_000fb640@Source@fn_f4646cfc@@QAEXPAUDest@2@II@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_000fb640 @ 0x000fb640
void Source::FUN_000fb640(Dest *dest,hulk_uintptr x,unsigned int y) { dest->FUN_000fb3b0(x,y); dest->a=a; dest->b=b; dest->c=c; dest->d=d; dest->e=e; dest->f=f; dest->type=2; dest->FUN_000fb4b0(0); }


// 0x000fb690 FUN_000fb690 (75 B): equivalent/0x000fb690.cpp
// sym: _FUN_000fb690
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_000fb690 @ 0x000fb690
extern "C" void __cdecl FUN_000fb690(unsigned short *destination, const unsigned short *source, int capacity)
{
    if (*source != 0) {
        int index = 0;
        while (index != capacity - 1) {
            destination[index] = source[index];
            ++index;
            if (source[index] == 0)
                break;
        }
        destination[index] = 0;
    } else {
        *destination = 0;
    }
}


// 0x000fb6e0 FUN_000fb6e0 (49 B): matches/0x000fb6e0.cpp
// sym: _FUN_000fb6e0
extern "C" bool FUN_000fb6e0(const short* a, const short* b, uint_fb6e0 count) {
    uint_fb6e0 i = 0;
    while (i < count) {
        if (*a != *b)
            return false;
        ++a;
        ++b;
        ++i;
    }
    return true;
}


// 0x000fb720 FUN_000fb720 (27 B): matches/0x000fb720.cpp
// sym: _FUN_000fb720
extern "C" int FUN_000fb720(const short* p) {
    int n = 0;
    while (*p != 0) {
        ++p;
        ++n;
    }
    return n;
}


// 0x000fb740 FUN_000fb740 (77 B): equivalent/0x000fb740.cpp
// sym: _FUN_000fb740
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_000fb740 @ 0x000fb740
extern "C" void __cdecl FUN_000fb740(short *dest, const char *src, hulk_intptr count)
{
    if (*src != 0) {
        int i = 0;
        do {
            if (i == count - 1)
                break;
            *dest++ = (short)*src++;
            ++i;
        } while (*src != 0);
    }
    *dest = 0;
}


// 0x000fb790 FUN_000fb790 (107 B): equivalent/0x000fb790.cpp
// sym: _FUN_000fb790
// STATUS: equivalent (tools/equiv.py level 3: 552 inputs, branch coverage 12/12)
// FUN_000fb790 @ 0x000fb790
extern "C" void FUN_000fb790(short *dst, const char *src, int n)
{
    short *p = dst;
    if (*p != 0) {
        int off = 0;
        do {
            if ((off >> 1) == n - 1)
                break;
            p++;
            off += 2;
        } while (*p != 0);
    }
    if (*src != 0) {
        hulk_intptr off = (hulk_intptr)p - (hulk_intptr)dst;
        do {
            if ((off >> 1) == n - 1)
                break;
            *p = (short)*src;
            p++;
            off += 2;
            src++;
        } while (*src != 0);
    }
    *p = 0;
}


// 0x000fb800 FUN_000fb800 (39 B): equivalent/0x000fb800.cpp
// sym: ?FUN_000fb800@fn_f4646cfc@@YI_NPBGG@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_000fb800 @ 0x000fb800
// equiv-conv: FUN_000fb800 ecx edx
bool __fastcall FUN_000fb800(const wchar16* text, wchar16 value) {
    while (*text) {
        if (*text == value) return true;
        ++text;
    }
    return false;
}

} // namespace fn_f4646cfc
