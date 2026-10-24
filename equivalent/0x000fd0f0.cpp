// STATUS: equivalent (tools/equiv.py level 3: 7018 inputs, branch coverage 32/32)
// CControllerAgent::vfunc_4 @ 0x000fd0f0
// CControllerAgent::vfunc_4 (ret 0xc, three stack args): controller facing/aim update. After the base
// update it reads the fighter's two stick samples (each a pair of floats) and the heading they steer to:
//   - while the turn is live (field a0) it builds the heading for each stick from the camera-relative
//     transform and starts the blend (a1) once the heading has swung past a threshold angle;
//   - while blending (a1) it rotates the previous heading towards the new one by the elapsed fraction;
//   - otherwise it just recomputes the headings.
// The headings and their speeds are written back into the fighter's input block.
// The frame struct below is the original's stack frame in slot order: the callees' out-parameters live in it,
// and the checker's stubs write through those pointers, so its layout is part of the behaviour.
// FUN_000fce60 takes an implicit edi (equiv-conv).
#include "compat/ptr.h"
#include "gen/global.h"
#include "decls/data/game/global.h"

extern "C" double sqrt(double);
extern "C" double sin(double);
extern "C" double cos(double);
extern "C" void *__cdecl memcpy(void *, const void *, unsigned int);

#if defined(_MSC_VER) && !defined(__clang__)
typedef volatile float hulk_fslot; // forces the store-and-reload MSVC 7.1 would otherwise skip
#else
typedef float hulk_fslot;
#endif

struct V3x_fd0f0 { float FUN_0022d110(); };
struct Cls3660 { void FUN_000b3660(hulk_uintptr a); };
struct Cls3d20 { hulk_uintptr FUN_000b3d20(hulk_uintptr a); };
struct Cls1c38f0 { void FUN_001c38f0(hulk_uintptr a, hulk_uintptr b); };
struct Cls1c3990 { unsigned FUN_001c3990(); };
struct Cls1c3950 { void FUN_001c3950(hulk_uintptr a, hulk_uintptr b); };
struct VFight {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
    virtual VFight *v6();
};

unsigned FUN_001c3d90();
float FUN_00018a20(float x);
void FUN_000fce60(hulk_uintptr s1, hulk_uintptr s2, hulk_uintptr s3, hulk_uintptr s4, hulk_uintptr s5, hulk_uintptr s6, hulk_uintptr s7);
void FUN_000fd010(hulk_uintptr s1, hulk_uintptr s2, hulk_uintptr s3, hulk_uintptr s4, hulk_uintptr s5, hulk_uintptr s6);

struct CControllerAgent_nv_fd0f0 {
    void FUN_000fc550(hulk_uintptr a, unsigned b, unsigned c);
};


// Stack frame (58 words, slot numbers are the original's esp+0x10+4n). Several slots are reused for different
// values at different times; the comments list them in order.
struct Frame_fd0f0 {
    hulk_fslot viewY;        // 0: camera pair, second word (also scratch)
    hulk_fslot scratch1;     // 1: stick B, second word / abs temp
    hulk_fslot viewX;        // 2: camera pair, first word
    hulk_fslot stickA1;      // 3: stick A, second word (info+0xa8); later cos / |candB||prev|
    hulk_fslot stickA0;      // 4: stick A, first word (info+0xa4); later the blend fraction
    hulk_fslot prevDir[3];   // 5-7: copy of this+0xb0
    hulk_fslot curDir[3];    // 8-10: copy of this+0xa4
    hulk_fslot stickB0;      // 11: stick B, first word (info+0xdc)
    hulk_fslot time;         // 12: info+0xa0
    hulk_fslot resA[3];      // 13-15: heading A (written back to info+0x10c)
    hulk_fslot infoSlot;     // 16: the info pointer, spilled; reused as a float product
    hulk_fslot aim[3];       // 17-19: aim direction
    hulk_fslot candA[3];     // 20-22: fresh heading for stick A
    hulk_fslot candB[3];     // 23-25: fresh heading for stick B
    hulk_fslot work26;       // 26: scratch word (the camera calls get its address)
    hulk_fslot resB[3];      // 27-29: heading B (written back to info+0x128)
    hulk_fslot velA[3];      // 30-32
    hulk_fslot velB[3];      // 33-35
    hulk_fslot mat[16];      // 36-51: camera matrix copy
    hulk_fslot velA2[3];     // 52-54
    hulk_fslot velB2[3];     // 55-57
};

static void CopyBits(volatile void *dst, const volatile void *src)
{
    *(volatile unsigned int *)dst = *(const volatile unsigned int *)src;
}

static float AbsBits(float v)
{
    unsigned int bits = *(unsigned int *)&v & 0x7fffffff;
    return *(float *)&bits;
}

#define FADDR(p) ((hulk_uintptr)(float *)(p))

void CControllerAgent::vfunc_4(int __p0, int __p1, int __p2) { hulk_uintptr a1 = (unsigned int)__p0; unsigned int a2 = (unsigned int)__p1; unsigned int a3 = (unsigned int)__p2;

    Frame_fd0f0 fr;
    // Fields of this that the generated class does not list yet.
    float *curHeading = (float *)((char *)this + 0xa4);    // current heading (3 floats)
    float *prevHeading = (float *)((char *)this + 0xb0);   // previous heading (3 floats)
    float &turnStart = *(float *)((char *)this + 0xd4);    // time the turn started (also f_d4)
    hulk_uintptr stateBlock = (hulk_uintptr)((char *)this + 0xd8);
    unsigned int &camX = *(unsigned int *)((char *)this + 0x118);
    unsigned int &camY = *(unsigned int *)((char *)this + 0x11c);

    ((CControllerAgent_nv_fd0f0 *)this)->FUN_000fc550(a1, a2, a3);
    hulk_uintptr fighter = (hulk_uintptr)((VFight *)*(hulk_uintptr *)((char *)this + 0x58))->v6();
    if (*(unsigned *)((char *)fighter + 0x140) == 4) {
        // Aim along the fighter's stored heading, flattened and normalised.
        CopyBits(&fr.aim[0], (char *)fighter + 0x1af8);
        CopyBits(&fr.aim[1], (char *)fighter + 0x1afc);
        CopyBits(&fr.aim[2], (char *)fighter + 0x1b00);
        fr.aim[1] = 0;
        ((V3x_fd0f0 *)fr.aim)->FUN_0022d110();
    } else {
        fr.aim[0] = 0;
        fr.aim[1] = 1.0f;
        fr.aim[2] = 0;
    }
    hulk_uintptr info = fighter + 0x1f58;
    *(hulk_uintptr *)&fr.infoSlot = info;
    unsigned int slot = *(unsigned *)((char *)fighter + 0x20a8);
    if ((int)slot >= 0 && (int)slot < 4)
        ((Cls3660 *)((Cls3d20 *)*(hulk_uintptr *)((char *)a1 + 4))->FUN_000b3d20(slot))->FUN_000b3660(info);
    hulk_uintptr camera = FUN_001c3d90();

    // The two stick samples and the sample time.
    float *infoF = (float *)info;
    CopyBits(&fr.stickA1, &infoF[42]);
    unsigned int bits55 = *(unsigned *)&infoF[55];
    CopyBits(&fr.stickA0, &infoF[41]);
    CopyBits(&fr.time, &infoF[40]);
    CopyBits(&fr.scratch1, &infoF[56]);
    *(unsigned int *)&fr.stickB0 = bits55;

    bool reset = (fr.time < turnStart);
    if (!reset) {
        *(unsigned int *)&fr.viewY = *(unsigned *)((char *)info + 0xa0) & 0x7fffffff;
        reset = (fr.viewY <= 1e-5f);
        if (!reset) {
            *(unsigned int *)&fr.viewY = *(unsigned *)((char *)this + 0xd4) & 0x7fffffff;
            reset = (fr.viewY <= 1e-5f);
        }
    }
    if (reset) {
        this->f_a1 = 0;
        this->f_a0 = 0;
    }
    if (this->f_a1 != 0) {
        if (fr.time - turnStart > DAT_004a1aac)
            this->f_a1 = 0;
    }

    hulk_uintptr heading; // the info block the headings are written to
    if (this->f_a0 != 0) {
        // Turn is live: headings from the current camera transform.
        FUN_000fce60(stateBlock, FADDR(fr.aim), camX, camY, *(unsigned *)&fr.stickA0, *(unsigned *)&fr.stickA1, FADDR(fr.resA));
        FUN_000fce60(stateBlock, FADDR(fr.aim), camX, camY, *(unsigned *)&fr.stickB0, *(unsigned *)&fr.scratch1, FADDR(fr.resB));
        FUN_000fd010(stateBlock, camX, camY, *(unsigned *)&fr.stickA0, *(unsigned *)&fr.stickA1, FADDR(fr.velA));
        FUN_000fd010(stateBlock, camX, camY, *(unsigned *)&fr.stickB0, *(unsigned *)&fr.scratch1, FADDR(fr.velB));
        double lenCur = sqrt(((curHeading[0] * curHeading[0]) + (curHeading[1] * curHeading[1])) + (curHeading[2] * curHeading[2]));
        double lenNew = sqrt(((fr.resA[2] * fr.resA[2]) + (fr.resA[1] * fr.resA[1])) + (fr.resA[0] * fr.resA[0]));
        fr.infoSlot = lenCur * lenNew;
        fr.scratch1 = lenCur * lenNew;
        *(unsigned int *)&fr.scratch1 = *(unsigned int *)&fr.scratch1 & 0x7fffffff;
        double ang;
        if (fr.scratch1 <= 1e-5f) {
            this->f_a1 = 0;
            this->f_a0 = 0;
            ang = 0.0;
        } else {
            ang = FUN_00018a20(((((fr.resA[2] * curHeading[2]) + (fr.resA[1] * curHeading[1])) + (fr.resA[0] * curHeading[0])) / fr.infoSlot));
        }
        if (ang > DAT_004a1ab0 * 0.017453292f) {
            // Swung past the threshold: start the blend.
            this->f_a1 = 1;
            this->f_a0 = 0;
            *(unsigned int *)&turnStart = *(unsigned int *)&fr.time;
        }
        heading = info;
    } else if (this->f_a1 != 0) {
        // Blending: rotate the previous heading towards the new one by the elapsed fraction.
        CopyBits(&fr.curDir[0], &curHeading[0]);
        CopyBits(&fr.curDir[1], &curHeading[1]);
        CopyBits(&fr.curDir[2], &curHeading[2]);
        CopyBits(&fr.prevDir[0], &prevHeading[0]);
        CopyBits(&fr.prevDir[1], &prevHeading[1]);
        CopyBits(&fr.prevDir[2], &prevHeading[2]);
        ((Cls1c38f0 *)camera)->FUN_001c38f0(FADDR(&fr.viewX), FADDR(&fr.work26));
        hulk_uintptr cameraMat = ((Cls1c3990 *)camera)->FUN_001c3990();
        memcpy((void *)fr.mat, (const void *)cameraMat, 64);
        ((Cls1c3950 *)camera)->FUN_001c3950(FADDR(&fr.viewY), FADDR(&fr.work26));
        unsigned int sA1 = *(unsigned *)&fr.stickA1;
        unsigned int sA0 = *(unsigned *)&fr.stickA0;
        FUN_000fce60(FADDR(fr.mat), FADDR(fr.aim), *(unsigned *)&fr.viewX, *(unsigned *)&fr.viewY, sA0, sA1, FADDR(fr.candA));
        FUN_000fce60(FADDR(fr.mat), FADDR(fr.aim), *(unsigned *)&fr.viewX, *(unsigned *)&fr.viewY, *(unsigned *)&fr.stickB0, *(unsigned *)&fr.scratch1, FADDR(fr.candB));
        FUN_000fd010(FADDR(fr.mat), *(unsigned *)&fr.viewX, *(unsigned *)&fr.viewY, sA0, sA1, FADDR(fr.velA2));
        FUN_000fd010(FADDR(fr.mat), *(unsigned *)&fr.viewX, *(unsigned *)&fr.viewY, *(unsigned *)&fr.stickB0, *(unsigned *)&fr.scratch1, FADDR(fr.velB2));
        // Blend fraction, and the signed turn angles from the previous heading to each fresh one.
        *(unsigned int *)&fr.viewY = 0;
        fr.stickA0 = ((fr.time - turnStart) / DAT_004a1aac);
        fr.scratch1 = (sqrt((((fr.candA[1] * fr.candA[1]) + (fr.candA[2] * fr.candA[2])) + (fr.candA[0] * fr.candA[0]))) * sqrt((((fr.curDir[1] * fr.curDir[1]) + (fr.curDir[0] * fr.curDir[0])) + (fr.curDir[2] * fr.curDir[2]))));
        *(unsigned int *)&fr.scratch1 = *(unsigned int *)&fr.scratch1 & 0x7fffffff;
        if (!(fr.scratch1 <= 1e-5f)) {
            hulk_fslot cosA = ((((fr.candA[1] * fr.curDir[1]) + (fr.curDir[0] * fr.candA[0])) + (fr.candA[2] * fr.curDir[2])) / (sqrt((((fr.candA[1] * fr.candA[1]) + (fr.candA[2] * fr.candA[2])) + (fr.candA[0] * fr.candA[0]))) * sqrt((((fr.curDir[1] * fr.curDir[1]) + (fr.curDir[0] * fr.curDir[0])) + (fr.curDir[2] * fr.curDir[2])))));
            float arg = cosA;
            fr.viewY = FUN_00018a20(arg);
        }
        if (((fr.candA[0] * fr.curDir[2]) - (fr.candA[2] * fr.curDir[0])) < 0.0f)
            fr.viewY = -fr.viewY;
        fr.stickA1 = (sqrt((((fr.candB[1] * fr.candB[1]) + (fr.candB[2] * fr.candB[2])) + (fr.candB[0] * fr.candB[0]))) * sqrt((((fr.prevDir[1] * fr.prevDir[1]) + (fr.prevDir[0] * fr.prevDir[0])) + (fr.prevDir[2] * fr.prevDir[2]))));
        unsigned int absBits = *(unsigned int *)&fr.stickA1;
        *(unsigned int *)&fr.scratch1 = absBits;
        *(unsigned int *)&fr.scratch1 = absBits & 0x7fffffff;
        double angB;
        if (fr.scratch1 <= 1e-5f) {
            angB = 0.0;
        } else {
            hulk_fslot cosB = ((((fr.candB[1] * fr.prevDir[1]) + (fr.candB[2] * fr.prevDir[2])) + (fr.prevDir[0] * fr.candB[0])) / fr.stickA1);
            float arg = cosB;
            angB = FUN_00018a20(arg);
        }
        if (((fr.candB[0] * fr.prevDir[2]) - (fr.candB[2] * fr.prevDir[0])) < 0.0f)
            angB = -angB;
        CopyBits(&fr.resA[1], &fr.curDir[1]);
        CopyBits(&fr.resB[1], &fr.prevDir[1]);
        fr.scratch1 = sin((fr.viewY * fr.stickA0));
        fr.stickA1 = cos((fr.viewY * fr.stickA0));
        fr.resA[0] = ((fr.stickA1 * fr.curDir[0]) + (fr.scratch1 * fr.curDir[2]));
        fr.resA[2] = ((fr.stickA1 * fr.curDir[2]) - (fr.scratch1 * fr.curDir[0]));
        fr.resB[0] = ((fr.prevDir[0] * cos((angB * fr.stickA0))) + (sin((angB * fr.stickA0)) * fr.prevDir[2]));
        fr.resB[2] = ((cos((angB * fr.stickA0)) * fr.prevDir[2]) - (sin((angB * fr.stickA0)) * fr.prevDir[0]));
        heading = *(hulk_uintptr *)&fr.infoSlot;
    } else {
        // Idle: headings straight from the camera transform.
        ((Cls1c38f0 *)camera)->FUN_001c38f0(FADDR(&fr.viewX), FADDR(&fr.work26));
        hulk_uintptr cameraMat = ((Cls1c3990 *)camera)->FUN_001c3990();
        memcpy((void *)fr.mat, (const void *)cameraMat, 64);
        ((Cls1c3950 *)camera)->FUN_001c3950(FADDR(&fr.viewY), FADDR(&fr.work26));
        unsigned int sA1 = *(unsigned *)&fr.stickA1;
        unsigned int sA0 = *(unsigned *)&fr.stickA0;
        FUN_000fce60(FADDR(fr.mat), FADDR(fr.aim), *(unsigned *)&fr.viewX, *(unsigned *)&fr.viewY, sA0, sA1, FADDR(fr.resA));
        unsigned int sB0 = *(unsigned *)&fr.stickB0;
        unsigned int sB1 = *(unsigned *)&fr.scratch1;
        FUN_000fce60(FADDR(fr.mat), FADDR(fr.aim), *(unsigned *)&fr.viewX, *(unsigned *)&fr.viewY, sB0, sB1, FADDR(fr.resB));
        FUN_000fd010(FADDR(fr.mat), *(unsigned *)&fr.viewX, *(unsigned *)&fr.viewY, sA0, sA1, FADDR(fr.velA));
        FUN_000fd010(FADDR(fr.mat), *(unsigned *)&fr.viewX, *(unsigned *)&fr.viewY, sB0, sB1, FADDR(fr.velB));
        heading = *(hulk_uintptr *)&fr.infoSlot;
    }

    // Publish the headings into the fighter's input block.
    CopyBits((char *)heading + 0x10c + 0x0, &fr.resA[0]);
    CopyBits((char *)heading + 0x10c + 0x4, &fr.resA[1]);
    CopyBits((char *)heading + 0x10c + 0x8, &fr.resA[2]);
    float speed = ((V3x_fd0f0 *)(heading + 0x10c))->FUN_0022d110();
    *(float *)((char *)heading + 0x118) = speed;
    *(unsigned *)((char *)heading + 0x124) = 0;
    *(unsigned *)((char *)heading + 0x120) = 0;
    *(unsigned *)((char *)heading + 0x11c) = 0;
    CopyBits((char *)heading + 0x128, &fr.resB[0]);
    CopyBits((char *)heading + 0x12c, &fr.resB[1]);
    CopyBits((char *)heading + 0x130, &fr.resB[2]);
}
