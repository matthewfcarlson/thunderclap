// STATUS: equivalent (tools/equiv.py level 3: 3047 inputs, branch coverage 58/58)
// hulkfight::motion::ProjectileEffect::vfunc_4 @ 0x00195bb0
#include "compat/ptr.h"
union FloatBits {
    float f;
    unsigned u;
};
struct Vec3 {
    float x, y, z;
    float FUN_0022d110();
    void FUN_0022b980();
    bool FUN_0022d2b0(hulk_uintptr other, float tolerance);
    void FUN_00011160(float distance, hulk_uintptr direction);
};
struct Transform {
    float elements[12];
    Vec3 position;
    void FUN_0022b980();
};
struct ProjectileConfig {
    char pad0[0x20];
    Vec3 forward;
    char pad2c[0x34];
    float targetSpeed;
    float acceleration;
    char pad68[8];
    float traceDistance;
    char pad74[0xc];
    unsigned traceMask;
    char pad84[4];
    float impactScale;
    char pad8c[4];
    Vec3 fallback;
    unsigned hitParam9c;
    char padA0[8];
    unsigned hitParamA8;
    char padAc[8];
    unsigned hitParamB4;
    unsigned hitParamB8;
    int impactCount;
};
struct Releasable {
    virtual void v0();
    virtual void Release();
};
struct Thing {
    unsigned FUN_001d72e0();
};
struct Registry {
    unsigned FUN_00059c10(unsigned id);
};
struct CollisionType {
    unsigned FUN_001d5e80(unsigned value);
};
struct Matrix {
    void FUN_0022c3b0(hulk_uintptr from, hulk_uintptr to);
};
struct VObj {
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
    virtual Matrix* v15();
};
struct Spawn {
    void FUN_0027ffc0(unsigned effect, hulk_uintptr transform);
    void FUN_0027ffb0(unsigned effect);
};
struct ImpactSpawner {
    void FUN_00283a40(hulk_uintptr config, hulk_uintptr transform, unsigned neg, unsigned pos);
};
struct ImpactEvents {
    void FUN_001f6cd0(unsigned effect, unsigned object, hulk_uintptr point, hulk_uintptr normal, hulk_uintptr direction,
                      unsigned count, unsigned a, unsigned b, unsigned c, unsigned d);
};
struct GlobalContext {
    char pad[0x38];
    ImpactEvents* events;
    char pad3c[8];
    Registry* registry;
};
extern GlobalContext* DAT_004dd700;
unsigned FUN_00098190(float dt, unsigned speed, unsigned distance, unsigned z1, hulk_uintptr object, unsigned z2,
                      hulk_uintptr position, hulk_uintptr direction, unsigned z3, unsigned z4, unsigned z5,
                      unsigned one);
// equiv-conv: FUN_00195290 ecx eax edx edi stack stack stack stack stack stack stack
char FUN_00195290(hulk_uintptr point, hulk_uintptr hitObject, hulk_uintptr effect, hulk_uintptr previous, hulk_uintptr position,
                  hulk_uintptr normal, hulk_uintptr hit, unsigned material, unsigned zero, hulk_uintptr flag,
                  unsigned zero2);
// equiv-conv: FUN_001958c0 eax stack stack stack stack stack stack stack stack stack stack
char FUN_001958c0(unsigned owner, hulk_uintptr hit, unsigned p9c, unsigned pa8, hulk_uintptr point, hulk_uintptr normal,
                  hulk_uintptr direction, unsigned pb8, unsigned pb4, unsigned zero, unsigned mask);
// equiv-conv: FUN_00195560 ecx eax ebx stack stack stack stack stack stack stack stack stack stack stack
char FUN_00195560(hulk_uintptr direction, hulk_uintptr hit, hulk_uintptr point, unsigned owner, unsigned p9c,
                  unsigned pa8, hulk_uintptr normal, unsigned pb8, unsigned pb4, unsigned zero, unsigned mask,
                  unsigned zero2, unsigned one, unsigned zero3);
unsigned FUN_0027f250();
float FUN_000964e0();
void FUN_00224db0(hulk_uintptr transform, hulk_uintptr a, hulk_uintptr b);
namespace hulkfight {
namespace motion {
class ProjectileEffect {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void vfunc_4(float dt);
    char pad04[8];
    float lifetime;
    unsigned char stopped;
    char pad11[7];
    ProjectileConfig* config;
    unsigned effect;
    unsigned owner;
    Releasable* tracked;
    Vec3 previous;
    Vec3 position;
    Vec3 direction;
    float speed;
};
} // namespace motion
} // namespace hulkfight

void hulkfight::motion::ProjectileEffect::vfunc_4(float dt) {
    FloatBits absolute;
    absolute.f = dt;
    absolute.u &= 0x7fffffff;
    if (stopped || absolute.f <= 1e-5f)
        return;

    lifetime -= dt;
    ProjectileConfig* settings = config;
    float traceDistance = settings->traceDistance;
    if (tracked && traceDistance > 0.0f) {
        if (!FUN_00098190(dt, *(unsigned*)&speed, *(unsigned*)&traceDistance, 0, (hulk_uintptr)tracked, 0,
                          (hulk_uintptr)&position, (hulk_uintptr)&direction, 0, 0, 0, 1)) {
            Releasable* old = tracked;
            if (old)
                old->Release();
            tracked = 0;
        }
    }

    settings = config;
    if (settings->acceleration <= 0.0f) {
        speed = settings->targetSpeed;
    } else {
        volatile float maxChange = settings->acceleration * dt;
        if (speed - settings->targetSpeed < -maxChange)
            speed = maxChange + speed;
        else if (speed - settings->targetSpeed > maxChange)
            speed = speed - maxChange;
        else
            speed = settings->targetSpeed;
    }

    struct Frame {
        unsigned flagWord;
        FloatBits material;
        Vec3 orientation;
        Vec3 normal;
        unsigned hit;
        unsigned object;
        unsigned directionAddress;
        Vec3 point;
        unsigned effect;
        unsigned context;
        Vec3 up;
        Transform transform;
    } frame;
    frame.orientation.x = direction.x;
    frame.orientation.y = direction.y;
    frame.orientation.z = direction.z;
    volatile float currentSpeed = speed;
    frame.orientation.y = frame.orientation.y * currentSpeed;
    frame.orientation.z = frame.orientation.z * currentSpeed;
    position.x = ((frame.orientation.x * currentSpeed) * dt) + position.x;
    position.y = frame.orientation.y * dt + position.y;
    position.z = frame.orientation.z * dt + position.z;

    GlobalContext* context = DAT_004dd700;
    frame.material.u = 0;
    hulk_uintptr materialObject = context->registry->FUN_00059c10(owner);
    if (materialObject)
        frame.material.u = *(unsigned*)((char*)materialObject + 0x12c);

    frame.hit = 0;
    frame.object = 0;
    frame.directionAddress = (hulk_uintptr)&direction;
    frame.effect = 0;
    frame.context = (hulk_uintptr)context;
    unsigned char* hitFlag = (unsigned char*)&frame.flagWord + 3;
    *hitFlag = FUN_00195290((hulk_uintptr)&frame.point, (hulk_uintptr)&frame.object, (hulk_uintptr)&frame.effect,
                            (hulk_uintptr)&previous, (hulk_uintptr)&position, (hulk_uintptr)&frame.normal,
                            (hulk_uintptr)&frame.hit, frame.material.u, 0, (hulk_uintptr)hitFlag, 0);
    previous.x = position.x;
    previous.y = position.y;
    previous.z = position.z;

    hulk_uintptr collision = frame.hit;
    if (frame.object && *(unsigned*)(frame.object + 0x38) == 5)
        collision = ((Thing*)*(hulk_uintptr*)(frame.object + 0x3c))->FUN_001d72e0();

    if (collision) {
        unsigned collisionKind = *(unsigned*)(collision + 0xc);
        if (collisionKind == 1) {
            settings = config;
            unsigned mask = settings->traceMask;
            unsigned pb4 = settings->hitParamB4;
            unsigned pb8 = settings->hitParamB8;
            unsigned pa8 = settings->hitParamA8;
            unsigned p9c = settings->hitParam9c;
            if (!FUN_00195560((hulk_uintptr)&direction, collision, (hulk_uintptr)&frame.point, owner, p9c, pa8,
                              (hulk_uintptr)&frame.normal, pb8, pb4, 0, mask, 0, 0x3f800000, 0))
                *hitFlag = 0;
        } else if (collisionKind == 5) {
            settings = config;
            unsigned mask = settings->traceMask;
            unsigned pb4 = settings->hitParamB4;
            unsigned pb8 = settings->hitParamB8;
            unsigned pa8 = settings->hitParamA8;
            unsigned p9c = settings->hitParam9c;
            if (!FUN_001958c0(owner, collision, p9c, pa8, (hulk_uintptr)&frame.point, (hulk_uintptr)&frame.normal,
                              (hulk_uintptr)&direction, pb8, pb4, 0, mask)) {
                *hitFlag = 0;
            } else {
                collision = *(unsigned*)(collision + 8);
                if (collision && ((CollisionType*)*(hulk_uintptr*)(collision + 0xec))
                                         ->FUN_001d5e80(*(unsigned*)(collision + 0x40)) == 2) {
                    frame.up.x = 0.0f;
                    frame.up.y = 1.0f;
                    frame.up.z = 0.0f;
                    ((VObj*)collision)->v15()->FUN_0022c3b0((hulk_uintptr)&frame.up, (hulk_uintptr)&frame.normal);

                    if ((frame.normal.z * direction.z + frame.normal.y * direction.y +
                         frame.normal.x * direction.x) > 0.0f) {
                        frame.normal.x = frame.normal.x * -1.0f;
                        frame.normal.y = frame.normal.y * -1.0f;
                        frame.normal.z = frame.normal.z * -1.0f;
                    }
                    volatile float dot = ((-direction.z * frame.normal.z) + (-direction.y * frame.normal.y)) +
                                         (-direction.x * frame.normal.x);
                    frame.orientation.x = frame.normal.x;
                    frame.orientation.y = frame.normal.y;
                    frame.orientation.z = frame.normal.z;
                    volatile float reflectedY = frame.orientation.y * (dot + dot);
                    volatile float reflectedZ = frame.orientation.z * (dot + dot);
                    volatile float reflectedX = frame.orientation.x * (dot + dot) + direction.x;
                    frame.orientation.x = reflectedX;
                    frame.orientation.y = reflectedY + direction.y;
                    frame.orientation.z = reflectedZ + direction.z;
                    frame.orientation.FUN_0022d110();
                    direction.y = frame.orientation.y;
                    direction.x = frame.orientation.x;
                    direction.z = frame.orientation.z;
                    position.y = frame.point.y;
                    position.x = frame.point.x;
                    position.z = frame.point.z;
                    volatile float distance = dt * speed;
                    position.FUN_00011160(distance, (hulk_uintptr)&direction);
                    *hitFlag = 0;
                    hulk_uintptr next = *(unsigned*)(collision + 0x114);
                    if (next && *(unsigned*)(next + 0xc) == 1) {
                        next = *(unsigned*)(next + 8);
                        if (next)
                            owner = **(unsigned**)(next + 0x10);
                    }
                }
            }
        }
    }

    hulk_uintptr spawner = FUN_0027f250();
    if (!*hitFlag) {
        frame.transform.FUN_0022b980();
        frame.orientation.x = config->forward.x;
        frame.orientation.y = config->forward.y;
        frame.orientation.z = config->forward.z;
        frame.orientation.FUN_0022d110();
        if (!direction.FUN_0022d2b0((hulk_uintptr)&frame.orientation, 1e-5f))
            FUN_00224db0((hulk_uintptr)&frame.transform, (hulk_uintptr)&frame.orientation, (hulk_uintptr)&direction);
        frame.transform.position.x = position.x;
        frame.transform.position.y = position.y;
        frame.transform.position.z = position.z;
        ((Spawn*)spawner)->FUN_0027ffc0(effect, (hulk_uintptr)&frame.transform);
        return;
    }

    ((Spawn*)spawner)->FUN_0027ffb0(effect);
    effect = 0;
    frame.transform.FUN_0022b980();
    frame.orientation.x = config->fallback.x;
    frame.orientation.y = config->fallback.y;
    frame.orientation.z = config->fallback.z;
    FloatBits length;
    length.f = frame.orientation.FUN_0022d110();
    length.u &= 0x7fffffff;
    if (length.f <= 1e-5f) {
        frame.orientation.x = FUN_000964e0() + 0.001f;
        frame.orientation.y = FUN_000964e0() + 0.001f;
        frame.orientation.z = FUN_000964e0() + 0.001f;
        frame.orientation.FUN_0022d110();
    }
    if (!frame.orientation.FUN_0022d2b0((hulk_uintptr)&frame.normal, 1e-5f))
        FUN_00224db0((hulk_uintptr)&frame.transform, (hulk_uintptr)&frame.orientation, (hulk_uintptr)&frame.normal);
    frame.transform.position.x = frame.point.x;
    frame.transform.position.y = frame.point.y;
    frame.transform.position.z = frame.point.z;
    ((ImpactSpawner*)spawner)
        ->FUN_00283a40((hulk_uintptr)&config->impactScale, (hulk_uintptr)&frame.transform, 0xbf800000, 0x3f800000);
    lifetime = 0.0f;
    if (frame.effect) {
        int count = ((volatile ProjectileConfig*)config)->impactCount;
        if (count > 0)
            ((GlobalContext*)frame.context)
                ->events->FUN_001f6cd0(frame.effect, frame.object, (hulk_uintptr)&frame.point,
                                       (hulk_uintptr)&frame.normal, (hulk_uintptr)&direction, count - 1, 0x3f800000,
                                       0x3f800000, 0, 0);
    }
}
