// STATUS: equivalent (tools/equiv.py level 3: 83 inputs, branch coverage 14/16, incomplete)
// CGroundDistanceCondition::vfunc_7 @ 0x0004bca0
struct Vec3 { float x, y, z; };

struct Fighter {
    char pad0[0x18];
    struct Body *body;
    char FUN_00059a50(Vec3 *out);
};
struct Body { char pad[0x40]; Vec3 pos; };

struct Actor {
    char pad[0x1a39];
    char grounded;
    char pad1a3a[0x1a48 - 0x1a3a];
    Vec3 groundPos;
};

Fighter *__fastcall FUN_000592a0(void *owner);
Actor *__fastcall FUN_00059a30(Fighter *f);
int __cdecl FUN_00018960(float a, float b, float c);

class CGroundDistanceCondition {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual char vfunc_7(void *owner);
    char pad04[8];
    int mode;
    float threshold;
};

char CGroundDistanceCondition::vfunc_7(void *owner)
{
    Fighter *fighter = FUN_000592a0(owner);
    Actor *actor = FUN_00059a30(fighter);
    Vec3 pos;
    pos.x = 0.0f;
    pos.y = 0.0f;
    pos.z = 0.0f;
    fighter->FUN_00059a50(&pos);
    Vec3 ground = actor->groundPos;
    float floorY;
    if (actor->grounded)
        floorY = ground.y;
    else
        floorY = -10000.0f;
    float dist = pos.y - floorY;
    switch (mode) {
    case 0: return dist < threshold;
    case 1: return dist <= threshold;
    case 2: return (char)FUN_00018960(dist, threshold, 1e-5f);
    case 3: return (char)FUN_00018960(dist, threshold, 1e-5f) == 0;
    case 4: return dist >= threshold;
    case 5: return dist > threshold;
    }
    return 0;
}
