// STATUS: equivalent (tools/equiv.py level 3: 873 inputs, branch coverage 22/22)
// FUN_00042680 @ 0x00042680
struct Vec3 {
    float x, y, z;
};

struct Matrix {
    float m[16];
};

struct Xform {
    float FUN_002220d0();
};

struct Tracker {
    char pad00[0x10];
    Xform xf;
    void FUN_002226e0(int v);
    void FUN_00223060();
};

struct Mgr {
    Tracker* FUN_00059a40();
    bool FUN_00059a50(Vec3* out);
};

class Releasable {
public:
    virtual void v0();
    virtual void Release();
};

class Provider {
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
    virtual void v14();
    virtual int GetHandle();
};

struct Source {
    char pad00[0x10];
    Matrix matrix;
};

struct Slot {
    Releasable* first;
    Releasable* second;
    char pad08[0x28 - 8];
};

float __cdecl FUN_00224fc0(float from, float to);

class Mover {
public:
    char pad00[0x10];
    Mgr* mgr;
    Xform xf14;
    char pad15[0x44 - 0x15];
    Vec3 prevPos;
    char pad50[0x74 - 0x50];
    Vec3 vel;
    char pad80[0x8c - 0x80];
    float angVel;
    char pad90[0x119 - 0x90];
    char disabled;
    char pad11a[0x128 - 0x11a];
    Provider* provider;
    char pad12c[0x14c - 0x12c];
    Source* source;
    Matrix matrix;
    char pad190[0x634 - 0x190];
    int slotCount;
    Slot slots[183];
    char pad22d0[0x10];
    char flag22e0;

    void FUN_0003c1d0(float a, float dt);
    void FUN_0003d350(float a, float dt);
    void FUN_000418f0(float a, float dt);
    void FUN_00036480(float a, float dt);
    void FUN_0003dd70(float a, float dt);

    void FUN_00042680(float a, float dt);
};

void Mover::FUN_00042680(float a, float dt)
{
    if (disabled)
        return;

    if (flag22e0)
        FUN_0003c1d0(a, dt);

    for (int i = 0; i < slotCount; i++) {
        if (slots[i].second) {
            slots[i].second->Release();
            slots[i].second = 0;
        }
        if (slots[i].first) {
            slots[i].first->Release();
            slots[i].first = 0;
        }
    }
    slotCount = 0;

    FUN_0003d350(a, dt);
    FUN_000418f0(a, dt);

    Tracker* tracker = mgr->FUN_00059a40();
    if (!flag22e0 && provider)
        tracker->FUN_002226e0(provider->GetHandle());
    tracker->FUN_00223060();

    if (source)
        matrix = source->matrix;

    FUN_00036480(a, dt);

    union {
        float f;
        unsigned int u;
    } mag;
    mag.f = dt;
    mag.u &= 0x7fffffff;
    if (!(mag.f <= 1e-5f)) {
        Vec3 prev = prevPos;
        Vec3 pos;
        pos.x = 0.0f;
        pos.y = 0.0f;
        pos.z = 0.0f;
        mgr->FUN_00059a50(&pos);
        float invDt = 1.0f / dt;
        vel = pos;
        vel.x = vel.x - prev.x;
        vel.y = vel.y - prev.y;
        vel.z = vel.z - prev.z;
        vel.x = invDt * vel.x;
        vel.y = invDt * vel.y;
        vel.z = invDt * vel.z;

        Tracker* t = mgr->FUN_00059a40();
        float target;
        if (t == 0)
            target = 0.0f;
        else
            target = t->xf.FUN_002220d0();
        float current = xf14.FUN_002220d0();
        angVel = FUN_00224fc0(current, target) * invDt;
    }

    FUN_0003dd70(a, dt);
}
