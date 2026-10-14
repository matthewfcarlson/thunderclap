// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_002d17b0 @ 0x002d17b0
struct Curves_2d17b0 {
    char pad0[0x14];
    float *tableA;      // 0x14
    char pad18[8];
    float *tableB;      // 0x20
};

struct Owner_2d17b0 {
    char pad0[0x1a4];
    float gain;         // 0x1a4
    char pad1a8[4];
    float weight;       // 0x1ac
    char pad1b0[0xc];
    Curves_2d17b0 *curves;     // 0x1bc
};

struct State_2d17b0 {
    float x;            // 0
    float y;            // 4
    float z;            // 8
    char pad0c[0x14];
    float vx;           // 0x20
    float vy;           // 0x24
    float vz;           // 0x28
    char pad2c[0xc];
    float accum;        // 0x38
    short steps;        // 0x3c
};

void __cdecl FUN_002d17b0(float dt, int index, float t, Owner_2d17b0 *owner, State_2d17b0 *state)
{
    float *a = owner->curves->tableA;
    float *b = owner->curves->tableB;
    float w = owner->weight;
    float ia = a[index] + (a[index + 1] - a[index]) * t;
    float ib = b[index] + (b[index + 1] - b[index]) * t;
    state->accum += ib * (int)state->steps * owner->gain * 0.00390625f * dt;
    state->x += ia * state->vx * w * dt;
    state->y += (ia * state->vy + state->accum) * w * dt;
    state->z += ia * state->vz * w * dt;
}
