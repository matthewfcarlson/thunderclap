// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 4/4)
// FUN_000677d0 @ 0x000677d0
struct Vec3_677d0 {
    float x, y, z;
};

class Entity {
public:
    char pad0[0x10];
    class Sub_677d0 *sub;
};

class Sub_677d0 {
public:
    char pad0[0x124];
    Entity *entity;
};

class Owner_677d0 {
public:
    char pad0[0x20];
    Sub_677d0 *sub;
};

class Node {
public:
    void FUN_00059a50(Vec3_677d0 *out);
};

class Clock_677d0 {
public:
    float FUN_00086080();
};

class Effect_677d0 {
public:
    void FUN_000677d0();
    void FUN_00065b20();
    void FUN_000671b0(Vec3_677d0 *v);
    void FUN_00067730();
    void FUN_00067490(Vec3_677d0 *v, int flag);
    void FUN_00065b80(int flag);

    char pad0[4];
    Clock_677d0 *clock;
    char pad1[0x364 - 8];
    float threshold;
    char pad2[4];
    char active;
};

extern Owner_677d0 *DAT_004dd700;

void Effect_677d0::FUN_000677d0()
{
    Vec3_677d0 pos;
    pos.x = 0;
    pos.y = 0;
    pos.z = 0;
    ((Node *)DAT_004dd700->sub->entity->sub)->FUN_00059a50(&pos);
    FUN_00065b20();
    FUN_000671b0(&pos);
    FUN_00067730();
    FUN_00067490(&pos, 0);
    FUN_00065b80(0);
    if (active) {
        if (clock->FUN_00086080() >= threshold) {
            active = 0;
            threshold = 0;
        }
    }
}
