// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_002f57d0 @ 0x002f57d0
// Store a new target offset and note whether it is (nearly) zero; if a listener is attached, notify it.
struct Vec3_2f57d0 {
    float x, y, z;
};

class Node {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void Notify(int arg);
    char pad8[0x10 - 4];
    void* listener;
    char pad14[0xa4 - 0x14];
    char nearZero;
    char pada5[3];
    Vec3_2f57d0 base;
    Vec3_2f57d0 target;

    void FUN_002f57d0(const Vec3_2f57d0* offset);
};

void Node::FUN_002f57d0(const Vec3_2f57d0* offset)
{
    target = *offset;
    float x = target.x + base.x;
    float y = base.y + target.y;
    float z = base.z + target.z;
    nearZero = (z * z + y * y + x * x < 1e-05f);
    if (listener) {
        Notify(0);
    }
}
