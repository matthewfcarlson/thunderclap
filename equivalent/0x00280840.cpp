// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 8/8)
// FUN_00280840 @ 0x00280840
extern "C" double sqrt(double);

struct V3 { float x, y, z; };

static float DistSq(const V3 &c, const V3 *p) {
    float dx = c.x - p->x;
    float dy = c.y - p->y;
    float dz = c.z - p->z;
    return dz * dz + dy * dy + dx * dx;
}

int __cdecl FUN_00280840(const V3 *center, float margin, const V3 *a, const V3 *b, const V3 *c) {
    float sx = a->x + b->x;
    float sy = a->y + b->y;
    float sz = b->z + a->z;
    sx = sx + c->x;
    sy = sy + c->y;
    sz = sz + c->z;
    V3 m;
    m.x = sx * (1.0f / 3.0f);
    m.y = sy * (1.0f / 3.0f);
    m.z = sz * (1.0f / 3.0f);
    float best = 0.0f;
    float d = DistSq(m, a);
    if (d > best) best = d;
    d = DistSq(m, b);
    if (d > best) best = d;
    d = DistSq(m, c);
    if (d > best) best = d;
    float r = (float)sqrt((double)best);
    float dc = (float)sqrt((double)DistSq(m, center));
    return r + margin > dc;
}
