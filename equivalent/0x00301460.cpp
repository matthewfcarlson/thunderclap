// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_00301460 @ 0x00301460
struct Vec3 {
    float x, y, z;
};

struct Probe {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual int Sample();    // slot 4
    char pad04[0x30];
    int field34;             // 0x34
};

struct Link {
    int first;
};

class Body {
public:
    char pad00[0x14];
    float vx, vy, vz;        // 0x14
    char pad20[0xc];
    Link link;               // 0x2c
    bool FUN_00314430(int a, int sample, int field, Vec3 *w, Link *l, Vec3 *v, Vec3 *u, int one);
    void FUN_00314be0(int a, Vec3 *v, Probe *p, Vec3 *u, int first, Vec3 *w);
    void FUN_00301460(int a, Probe *probe);
};

void Body::FUN_00301460(int a, Probe *probe) {
    Vec3 w, u, v;
    vx = vx * -1.0f;
    vy = vy * -1.0f;
    vz = vz * -1.0f;
    if (FUN_00314430(a, probe->Sample(), probe->field34, &w, &link, &v, &u, 1))
        FUN_00314be0(a, &v, probe, &u, link.first, &w);
}
