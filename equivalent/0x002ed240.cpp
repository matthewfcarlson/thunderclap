// STATUS: equivalent (tools/equiv.py level 3: 156 inputs, branch coverage 25/26, incomplete; run with --inputs 12000)
// FUN_002ed240 @ 0x002ed240
struct Vec3_2ed240 { float x, y, z; };

class Body_2ed240 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual Vec3_2ed240 *getPosition();
    char pad04[0x24];
    Vec3_2ed240 half;
};

struct Entry_2ed240 {
    char pad0[0x20];
    Body_2ed240 *body;
    char pad24[0x34];
    unsigned int maskA_lo;
    unsigned int maskA_hi;
    unsigned int maskB_lo;
    unsigned int maskB_hi;
};

struct Span_2ed240 {
    Entry_2ed240 *other;
    float lo;
    float hi;
    float zmax;
    float zmin;
};

struct Resolver_2ed240 {
    char pad0[0x30];
    void FUN_00302ed0(Body_2ed240 *a, Body_2ed240 *b, void *out);
};

class Broadphase_2ed240 {
public:
    char pad0[0x14];
    Entry_2ed240 **entries;
    char pad18[0xc];
    Span_2ed240 *spans;
    unsigned int spanCount;
    char field2c[0x44];
    Resolver_2ed240 resolver;
    int resultCount;
    void FUN_002ed240(int index);
};

void Broadphase_2ed240::FUN_002ed240(int index)
{
    Entry_2ed240 *en = entries[index];
    Body_2ed240 *body = en->body;
    Vec3_2ed240 *p = body->getPosition();
    float px = p->x;
    float pz = p->z;
    unsigned int maskB_lo = en->maskB_lo;
    float hx = body->half.x;
    float hz = body->half.z;
    float xmin = px - hx;
    float xmax = hx + px;
    unsigned int maskB_hi = en->maskB_hi;
    unsigned int maskA_hi = en->maskA_hi;
    unsigned int maskA_lo = en->maskA_lo;
    bool seen = false;
    for (unsigned int i = 0; i < spanCount; i++) {
        Span_2ed240 *s = &spans[i];
        if (s->lo > xmax)
            break;
        if (!seen) {
            if (s->lo > xmin)
                seen = true;
            else if (!(s->hi > xmin))
                continue;
        }
        if (!(pz - hz < s->zmin || s->zmax < hz + pz))
            continue;
        Entry_2ed240 *o = s->other;
        if ((o->maskA_lo & maskB_lo) == 0 && (o->maskA_hi & maskB_hi) == 0)
            continue;
        if ((o->maskB_lo & maskA_lo) == 0 && (o->maskB_hi & maskA_hi) == 0)
            continue;
        resultCount = 0;
        resolver.FUN_00302ed0(en->body, s->other->body, field2c);
    }
}
