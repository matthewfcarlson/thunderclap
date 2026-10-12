// STATUS: equivalent (tools/equiv.py level 3: 156 inputs, branch coverage 25/26, incomplete; run with --inputs 12000)
// FUN_002ed240 @ 0x002ed240
struct Vec3 { float x, y, z; };

class Body {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual Vec3 *getPosition();
    char pad04[0x24];
    Vec3 half;
};

struct Entry {
    char pad0[0x20];
    Body *body;
    char pad24[0x34];
    unsigned int maskA_lo;
    unsigned int maskA_hi;
    unsigned int maskB_lo;
    unsigned int maskB_hi;
};

struct Span {
    Entry *other;
    float lo;
    float hi;
    float zmax;
    float zmin;
};

struct Resolver {
    char pad0[0x30];
    void FUN_00302ed0(Body *a, Body *b, void *out);
};

class Broadphase {
public:
    char pad0[0x14];
    Entry **entries;
    char pad18[0xc];
    Span *spans;
    unsigned int spanCount;
    char field2c[0x44];
    Resolver resolver;
    int resultCount;
    void FUN_002ed240(int index);
};

void Broadphase::FUN_002ed240(int index)
{
    Entry *en = entries[index];
    Body *body = en->body;
    Vec3 *p = body->getPosition();
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
        Span *s = &spans[i];
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
        Entry *o = s->other;
        if ((o->maskA_lo & maskB_lo) == 0 && (o->maskA_hi & maskB_hi) == 0)
            continue;
        if ((o->maskB_lo & maskA_lo) == 0 && (o->maskB_hi & maskA_hi) == 0)
            continue;
        resultCount = 0;
        resolver.FUN_00302ed0(en->body, s->other->body, field2c);
    }
}
