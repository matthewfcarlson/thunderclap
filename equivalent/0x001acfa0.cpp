// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_001acfa0 @ 0x001acfa0
struct V3_1acfa0 {
    float x, y, z;
    V3_1acfa0* FUN_001acfa0(const V3_1acfa0* p, const V3_1acfa0* q);
};

extern "C" double __cdecl sqrt(double);

// 2D perpendicular line through p and q (x, y), normalised, with offset z.
V3_1acfa0* V3_1acfa0::FUN_001acfa0(const V3_1acfa0* p, const V3_1acfa0* q)
{
    y = q->x - p->x;
    x = p->z - q->z;
    if (y * y + x * x > 1e-5f) {
        double inv = 1.0f / sqrt(y * y + x * x);
        volatile V3_1acfa0* self = this;
        x = inv * self->x;
        y = inv * self->y;
        z = -(p->x * self->x + p->z * self->y);
        return this;
    }
    x = 0;
    y = 0;
    z = 0;
    return this;
}
