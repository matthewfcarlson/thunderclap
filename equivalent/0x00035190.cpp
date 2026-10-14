// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_00035190 @ 0x00035190
struct Vec3 { float x, y, z; };

struct Transform {
    char pad0[0x30];
    Vec3 position;
};

class Effect {
public:
    void FUN_001c5e80(const Vec3* position);
    void FUN_001c5ed0(void* target);
    void FUN_001c5ef0(bool enabled);
};

class Listener {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6(Transform* t, int flags);
};

class Scene {
public:
    void FUN_002226e0(Transform* t);
};

class Owner {
public:
    Scene* FUN_00059a40();
};

class Entity {
public:
    char pad0[0x10];
    Owner* owner;
    char pad14[0x124 - 0x14];
    Effect* effect;
    char pad128[4];
    Listener* listener;
    char pad130[0x140 - 0x130];
    int mode;
    char pad144[0x1a84 - 0x144];
    char effectTarget[1];
    bool FUN_00035190(Transform* t);
};

bool Entity::FUN_00035190(Transform* t) {
    Scene* scene = owner->FUN_00059a40();
    if (!scene)
        return false;
    scene->FUN_002226e0(t);
    if (effect) {
        effect->FUN_001c5e80(&t->position);
        effect->FUN_001c5ed0(effectTarget);
        effect->FUN_001c5ef0(mode == 3);
    }
    if (listener)
        listener->v6(t, 0);
    return true;
}
