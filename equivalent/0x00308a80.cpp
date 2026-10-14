// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 10/10)
// FUN_00308a80 @ 0x00308a80
// FUN_00308a80: arm the trigger once the tracked point is inside 1.5x the radius
struct V3_308a80 {
    float x, y, z;
};

class Sub_308a80 {
public:
    virtual void Start(float delay, float volume, int flags);
    virtual void v1();
    virtual float Elapsed();
};

class Trigger_308a80 {
public:
    virtual void v0();
    virtual void v1();
    virtual V3_308a80 *Position();
    char pad04[0x28];
    Sub_308a80 subObj;
    char pad30[0x10];
    float radius;
    float delay;
    char pad48[4];
    float volume;
    char pad50[0xd];
    char armed;

    void FUN_00308a80(int unused);
};

void Trigger_308a80::FUN_00308a80(int unused)
{
    if (armed == 1)
        return;
    Sub_308a80 *sub = &subObj;
    V3_308a80 p = *Position();
    float r = radius;
    if (p.y > r || p.x > r * 1.5f || p.z > r * 1.5f) {
        sub->Start(delay, 0.5f * volume, 0);
        return;
    }
    if (!(sub->Elapsed() > delay))
        armed = 1;
}
