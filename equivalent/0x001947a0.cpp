// STATUS: equivalent (tools/equiv.py level 3: 94 inputs, branch coverage 16/16)
// FUN_001947a0 @ 0x001947a0
struct Vec3 {
    float x, y, z;
};

struct Wanderer {
    char pad0[0x1d1c];
    int steps;
    char pad1d20[0x1d2c - 0x1d20];
    int direction;
};

struct RandState {
    unsigned s0;
    unsigned s1;
    float FUN_000787e0(float lo, float hi);
};

RandState* FUN_000964d0();

// Random walk step: the position arrives in esi, the walker and the step size on the stack.
// equiv-conv: FUN_001947a0 esi stack stack
void FUN_001947a0(Vec3* pos, Wanderer* w, float step)
{
    RandState* rng = FUN_000964d0();
    int dir = w->direction;
    if (dir == 1 || dir == 0) {
        rng->s0 = (rng->s0 & 0xffff) * 0x9069 + (rng->s0 >> 16);
        rng->s1 = (rng->s1 & 0xffff) * 0x4650 + (rng->s1 >> 16);
        dir = (int)(((rng->s0 << 16) + (rng->s1 & 0xffff)) % 10) + 2;
    }
    w->steps--;
    float r;
    switch (dir) {
    case 2:
        r = rng->FUN_000787e0(step, step);
        pos->x = pos->x + r;
        r = rng->FUN_000787e0(step, step);
        pos->x = pos->x - r;
        break;
    case 3:
        r = rng->FUN_000787e0(step, step);
        pos->z = pos->z + r;
        break;
    case 4:
        r = rng->FUN_000787e0(step, step);
        pos->z = pos->z - r;
        break;
    case 5:
        r = rng->FUN_000787e0(step, step);
        pos->z = pos->z + r;
        r = rng->FUN_000787e0(step, step);
        pos->z = pos->z - r;
        break;
    case 6:
        r = rng->FUN_000787e0(step, step);
        pos->z = pos->z + r;
        r = rng->FUN_000787e0(step, step);
        pos->x = pos->x - r;
        break;
    case 7:
        r = rng->FUN_000787e0(step, step);
        pos->z = pos->z - r;
        r = rng->FUN_000787e0(step, step);
        pos->x = pos->x + r;
        break;
    case 8:
        r = rng->FUN_000787e0(step, step);
        pos->x = pos->x + r;
        r = rng->FUN_000787e0(step, step);
        pos->z = pos->z + r;
        break;
    case 9:
        r = rng->FUN_000787e0(step, step);
        pos->x = pos->x - r;
        r = rng->FUN_000787e0(step, step);
        pos->z = pos->z - r;
        break;
    case 10:
        r = rng->FUN_000787e0(step, step);
        pos->x = pos->x + r;
        break;
    case 11:
        r = rng->FUN_000787e0(step, step);
        pos->x = pos->x - r;
        break;
    default:
        break;
    }
    w->direction = dir;
}
