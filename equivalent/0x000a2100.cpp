// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 26/26)
// FUN_000a2100 @ 0x000a2100
// FUN_000a2100 @ 0x000a2100
// Stick/axis tracker: samples a 0x43-dword input record, keeps two axis values (a dead zone resets them to the
// defaults passed in), and ramps a charge value `c` towards 1 / -1 / 0 depending on whether the axis keeps its
// direction.
#include "decls/data/game/unknown.h"

struct Sample_a2100 {
    unsigned pad0[0x1e];
    unsigned a;          // +0x78
    unsigned b;          // +0x7c
    unsigned pad1[0x17];
    unsigned c;          // +0xdc
    unsigned d;          // +0xe0
    unsigned pad2[10];
};

struct Source_a2100 {
    void FUN_000b3660(Sample_a2100 *dst);
};

struct Table_a2100 {
    Source_a2100 *FUN_000b3d20(int index);
};

struct Owner_a2100 {
    unsigned pad;
    Table_a2100 *table;
};

union Word_a2100 {
    unsigned u;
    float f;
};

static float Abs_a2100(float v)
{
    Word_a2100 w;
    w.f = v;
    w.u &= 0x7fffffff;
    return w.f;
}

class Axis_a2100 {
public:
    unsigned x;
    unsigned y;
    Word_a2100 ax;
    Word_a2100 ay;
    volatile float charge;
    char valid;

    void FUN_000a2100(Owner_a2100 *owner, char enable, float dt, float defX, float defY);
};

void Axis_a2100::FUN_000a2100(Owner_a2100 *owner, char enable, float dt, float defX, float defY)
{
    if (!enable) {
        x = 0;
        y = 0;
        ay.u = 0;
        ax.u = 0;
        charge = 0;
        valid = 0;
        return;
    }

    float oldX = ax.f;
    Sample_a2100 s;
    owner->table->FUN_000b3d20(0)->FUN_000b3660(&s);

    x = s.a;
    y = s.b;
    ax.u = s.c;
    ay.u = s.d;
    if (!DAT_004dd83a)
        ax.f = *(volatile float *)&s.c * -1.0f;
    if (DAT_004dd83b)
        ay.f = *(volatile float *)&s.d * -1.0f;

    valid = 1;
    if (Abs_a2100(ax.f) <= 0.01f && Abs_a2100(ay.f) <= 0.01f) {
        ax.u = *(unsigned *)&defX;
        ay.u = *(unsigned *)&defY;
        valid = 0;
    }

    if (Abs_a2100(ax.f) >= 0.9f && oldX * ax.f > 0.0f) {
        if (ax.f > 0.0f) {
            charge = dt + charge;
            if (charge < 1.0f) {
            } else {
                charge = 1.0f;
            }
        } else {
            charge = charge - dt;
            if (charge < -1.0f)
                charge = -1.0f;
        }
    } else {
        if (charge >= 0.0f) {
            charge = charge - dt * 10.0f;
            if (charge < 0.0f)
                charge = 0.0f;
        } else {
            charge = dt * 10.0f + charge;
            if (charge < 0.0f) {
            } else {
                charge = 0.0f;
            }
        }
    }
}
