// STATUS: equivalent (tools/equiv.py level 3: 3064 inputs, branch coverage 74/97, incomplete)
// FUN_000b36d0 @ 0x000b36d0
#include "decls/data/game/global.h"

float __cdecl FUN_00224ea0(float x, float y);
float __cdecl FUN_00224fc0(float a, float b);

union Bits_b36d0 {
    float f;
    unsigned int u;
};

struct Btn {
    int state;                  // 0x00
    float a;                    // 0x04
    float b;                    // 0x08
};

struct Stick_b36d0 {
    int state;                  // 0x00
    float a;                    // 0x04
    float x;                    // 0x08
    float y;                    // 0x0c
    float m;                    // 0x10
    float ang;                  // 0x14
    float f14;                  // 0x18
    float f18;                  // 0x1c
    float f1c;                  // 0x20
    float f20;                  // 0x24
    float f24;                  // 0x28
    int mode;                   // 0x2c
    float f2c;                  // 0x30
    float f30;                  // 0x34
};

struct Input_b36d0 {
    Btn btn[13];                // 0x00
    Stick_b36d0 stick[2];             // 0x9c
};

struct Meter_b36d0 {
    float FUN_000ad3c0();
    float FUN_000ad2b0();
};

class Ctrl_b36d0 {
public:
    char pad00[8];
    Meter_b36d0 *meter;               // 0x08
    void FUN_000b36d0(Input_b36d0 *s, float v0, float v1, float v2, float v3, float v4, float v5, float v6,
                      float v7, float v8, float v9, float v10, float v11, float v12,
                      float x0, float y0, float x1, float y1, float dt);
};

void Ctrl_b36d0::FUN_000b36d0(Input_b36d0 *s, float v0, float v1, float v2, float v3, float v4, float v5, float v6,
                        float v7, float v8, float v9, float v10, float v11, float v12,
                        float x0, float y0, float x1, float y1, float dt)
{
    float *vals = &v0;
    float *xy = &x0;

    for (int i = 0; i < 13; i++) {
        float v = vals[i];
        Btn *b = &s->btn[i];
        if (v > 0.0f) {
            switch (b->state) {
            case 0:
                b->state = 1;
                b->a = dt + b->a;
                break;
            case 1:
                b->state = 2;
                b->a = dt;
                break;
            case 2:
                b->a = dt + b->a;
                break;
            case 3:
                b->state = 1;
                b->a = dt;
                break;
            }
        } else {
            switch (b->state) {
            case 0:
                b->a = dt + b->a;
                break;
            case 1:
                b->state = 3;
                b->a = dt;
                break;
            case 2:
                b->state = 3;
                b->a = dt + b->a;
                break;
            case 3:
                b->state = 0;
                b->a = dt;
                break;
            }
        }
        b->b = v;
    }

    for (int k = 0; k < 2; k++) {
        Stick_b36d0 *st = &s->stick[k];
        Bits_b36d0 bx, by, ax, ay;
        bx.f = xy[2 * k];
        by.f = xy[2 * k + 1];
        ax.u = bx.u & 0x7fffffff;
        ay.u = by.u & 0x7fffffff;
        st->m = ax.f;
        if (ay.f > ax.f)
            st->m = ay.f;
        if (st->m > 0.0f) {
            float ang = FUN_00224ea0(bx.f, by.f);
            int state = st->state;
            bool reset = false;
            bool diff = false;
            if (state == 0) {
                st->a = dt + st->a;
                reset = true;
            } else if (state == 1) {
                st->state = 2;
                st->a = dt;
                diff = true;
            } else if (state == 2) {
                st->a = dt + st->a;
                st->state = 2;
                diff = true;
            } else if (state == 3) {
                st->a = dt;
                reset = true;
            }
            if (reset) {
                st->state = 1;
                st->f14 = 0.0f;
                st->f18 = 0.0f;
                st->f24 = 0.0f;
            }
            if (diff) {
                float d = FUN_00224fc0(st->ang, ang);
                Bits_b36d0 ad;
                ad.f = d;
                ad.u &= 0x7fffffff;
                bool acc = false;
                if (ad.f <= 0.00001f)
                    acc = true;
                else if (d < 0.0f && st->f14 < 0.0f)
                    acc = true;
                else if (d > 0.0f && st->f14 > 0.0f)
                    acc = true;
                if (acc) {
                    st->f14 = d + st->f14;
                    st->f18 = dt + st->f18;
                    st->f24 = dt + st->f24;
                } else {
                    st->f14 = d;
                    st->f18 = dt;
                    st->f20 = st->ang;
                    st->f24 = dt;
                }
            }

            float r = meter->FUN_000ad3c0();
            if (r <= st->m) {
                if (st->mode == 0) {
                    st->mode = 1;
                    st->f30 = dt + st->f30;
                } else if (st->mode == 1) {
                    st->mode = 2;
                    st->f2c = st->ang;
                    st->f30 = dt;
                } else if (st->mode == 2) {
                    st->mode = 2;
                    st->f30 = dt + st->f30;
                }
            } else {
                if (st->mode == 1) {
                    st->f2c = st->ang;
                    st->f30 = 0.0f;
                }
                float r2 = meter->FUN_000ad2b0();
                if (!(r2 >= st->m))
                    st->mode = 2;
                else
                    st->mode = 0;
                st->f30 = dt + st->f30;
            }
            st->ang = ang;
            if ((DAT_004ddbcc & 1) == 0) {
                DAT_004ddbcc |= 1;
                (*(float*)&DAT_004ddbc8) = 1.5707964f;
            }
            float d2 = FUN_00224fc0(ang, st->f20);
            if (d2 > (*(float*)&DAT_004ddbc8) || st->f24 > 0.3f) {
                float q = d2 / st->f24;
                st->f20 = st->ang;
                st->f24 = 0.0f;
                Bits_b36d0 aq;
                aq.f = q;
                aq.u &= 0x7fffffff;
                st->f1c = aq.f;
            }
        } else {
            switch (st->state) {
            case 0:
                st->a = dt + st->a;
                break;
            case 1:
                st->state = 3;
                st->a = dt;
                break;
            case 2:
                st->state = 3;
                st->a = dt + st->a;
                break;
            case 3:
                st->state = 0;
                st->a = dt;
                break;
            }
            if (st->mode == 1) {
                st->f2c = st->ang;
                st->f30 = 0.0f;
            }
            st->mode = 0;
            float nf = dt + st->f30;
            st->ang = 0.0f;
            st->f14 = 0.0f;
            st->f18 = 0.0f;
            st->f30 = nf;
            st->f1c = 0.0f;
            st->f20 = 0.0f;
            st->f24 = 0.0f;
        }
        st->x = bx.f;
        st->y = by.f;
    }
}
