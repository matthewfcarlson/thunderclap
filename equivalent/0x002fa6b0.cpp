// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_002fa6b0 @ 0x002fa6b0
struct V3 {
    float x, y, z;
    void FUN_0022d180();
};

// out = normalised cross product (a - b) x (a - c)
void FUN_002fa6b0(const V3* a, const V3* b, const V3* c, V3* out)
{
    float dx = a->x - c->x;
    float dy = a->y - c->y;
    float dz = a->z - c->z;
    volatile float e[3];
    e[0] = a->x - b->x;
    e[1] = a->y - b->y;
    float ez = a->z - b->z;
    out->x = e[1] * dz - ez * dy;
    out->y = ez * dx - dz * e[0];
    out->z = e[0] * dy - e[1] * dx;
    out->FUN_0022d180();
}
