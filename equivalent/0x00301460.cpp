// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_00301460 @ 0x00301460
struct Vec3_301460 {
    float x, y, z;
};

struct Probe_301460 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual int Sample();    // slot 4
    char pad04[0x30];
    int field34;             // 0x34
};

struct Link_301460 {
    int first;
};

class Body_301460 {
public:
    char pad00[0x14];
    float vx, vy, vz;        // 0x14
    char pad20[0xc];
    Link_301460 link;               // 0x2c
    bool FUN_00314430(int a, int sample, int field, Vec3_301460 *w, Link_301460 *l, Vec3_301460 *v, Vec3_301460 *u, int one);
    void FUN_00314be0(int a, Vec3_301460 *v, Probe_301460 *p, Vec3_301460 *u, int first, Vec3_301460 *w);
    void FUN_00301460(int a, Probe_301460 *probe);
};

void Body_301460::FUN_00301460(int a, Probe_301460 *probe) {
    Vec3_301460 w, u, v;
    vx = vx * -1.0f;
    vy = vy * -1.0f;
    vz = vz * -1.0f;
    if (FUN_00314430(a, probe->Sample(), probe->field34, &w, &link, &v, &u, 1))
        FUN_00314be0(a, &v, probe, &u, link.first, &w);
}
