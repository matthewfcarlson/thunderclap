// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_002f7b00 @ 0x002f7b00
struct Vec3_2f7b00 { float x, y, z; };
class Probe_2f7b00 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8(Vec3_2f7b00 *in, Vec3_2f7b00 *out, int arg);
};
struct Target_2f7b00 {
    char pad0[0x1c];
    int arg1c;
    int arg20;
    Vec3_2f7b00 n;
    char pad1[0x38 - 0x30];
    Vec3_2f7b00 in0;
    Vec3_2f7b00 in1;
    char pad2[0xc];
    Vec3_2f7b00 out0;
    Vec3_2f7b00 out1;
    Vec3_2f7b00 diff;
    float dot;
    Probe_2f7b00 *p84;
    Probe_2f7b00 *p88;
    void FUN_002f7b00();
};
void Target_2f7b00::FUN_002f7b00()
{
    p84->v8(&in0, &out0, arg1c);
    p88->v8(&in1, &out1, arg20);
    diff.x = out0.x - out1.x;
    diff.y = out0.y - out1.y;
    diff.z = out0.z - out1.z;
    volatile Vec3_2f7b00 *d = &diff;
    dot = ((n.z * d->z) + (n.y * d->y)) + (n.x * d->x);
}
