// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_000c5900 @ 0x000c5900
struct Vec3 {
    float x, y, z;
    void FUN_0022d210(int m);
};

class Body {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual int v14();
    void FUN_00293af0(Vec3 *v);
};

void __cdecl FUN_000c5900(Body *body, int axis, float amount)
{
    float ax = 0.0f;
    float ay = 0.0f;
    float az = 0.0f;
    if (axis == 0)
        ax = amount;
    else if (axis == 1)
        ay = amount;
    else if (axis == 2)
        az = amount;
    Vec3 v;
    v.x = 0.0f;
    v.y = 0.0f;
    v.z = 0.0f;
    v.x = ax + v.x;
    v.y = ay + v.y;
    v.z = az + v.z;
    v.FUN_0022d210(body->v14());
    body->FUN_00293af0(&v);
}
