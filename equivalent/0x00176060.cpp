// STATUS: equivalent (tools/equiv.py level 3: 153 inputs, branch coverage 31/32, incomplete)
// hulkfight::motion::SuckInPropsAction::vfunc_5 @ 0x00176060
struct Vec3_176060 {
    float x, y, z;
    float FUN_0022d110();
    void FUN_000344b0(float s);
    float FUN_00018990();
};

class Scaler_176060 {
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
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual float GetScale();
};

struct ScalerOwner {
    char pad00[0x70];
    Scaler_176060* scaler;
};

struct Controller_176060 {
    char pad00[0x10];
    ScalerOwner* owner;
};

struct Prop_176060 {
    char pad00[0xa0];
    Controller_176060* controller;
    char pad04[0x114 - 0xa4];
    int field114;
    char pad118[0x1a1 - 0x118];
    char active;
    char pad1a2[0x1ed - 0x1a2];
    char hit;
    Vec3_176060* FUN_001d6b40();
    void FUN_001d86d0(Vec3_176060* dir, Vec3_176060* extra);
};

struct PropList_176060 {
    int FUN_001dcf50();
    Prop_176060* FUN_001dc0b0(int index);
};

struct World {
    char pad00[0xc];
    PropList_176060* props;
};

struct Anchor_176060 {
    bool FUN_00059a50(Vec3_176060* out);
};

struct Player_176060 {
    char pad00[0x10];
    Anchor_176060* anchor;
};

struct Clock_176060 {
    Player_176060* FUN_00059a30();
};

struct Target_176060 {
    Clock_176060* FUN_000592a0();
};

struct Config_176060 {
    char pad00[0x14];
    int maxHits;
    float strength;
    float range;
};

extern World* DAT_004dd700;

namespace hulkfight {
namespace motion {

class SuckInPropsAction {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual bool vfunc_5(int skip, float dt);

    char pad04[0x1c - 4];
    Config_176060* cfg;
    Target_176060* owner;
};

bool SuckInPropsAction::vfunc_5(int skip, float dt)
{
    if (skip != 0)
        return true;
    if (dt == 0.0f)
        return true;

    int hits = 0;
    Clock_176060* clock = owner->FUN_000592a0();
    Player_176060* player = 0;
    if (clock)
        player = clock->FUN_00059a30();
    if (player == 0)
        return false;

    Vec3_176060 playerPos;
    player->anchor->FUN_00059a50(&playerPos);

    for (int i = 0; i < DAT_004dd700->props->FUN_001dcf50(); i++) {
        Prop_176060* prop = DAT_004dd700->props->FUN_001dc0b0(i);
        if (prop == 0)
            continue;
        if (prop->controller == 0)
            continue;
        if (prop->controller->owner == 0)
            continue;
        Scaler_176060* s = prop->controller->owner->scaler;
        if (s == 0)
            continue;
        if (s->GetScale() == 0.0f)
            continue;
        if (prop->active == 0)
            continue;
        if (prop->field114 != 0)
            continue;

        Vec3_176060 zero;
        zero.x = 0.0f;
        zero.y = 0.0f;
        zero.z = 0.0f;
        Vec3_176060* pp = prop->FUN_001d6b40();
        Vec3_176060 propPos = *pp;
        Vec3_176060 toPlayer;
        Vec3_176060 toProp;
        toProp.x = propPos.x - playerPos.x;
        toProp.y = propPos.y - playerPos.y;
        toProp.z = propPos.z - playerPos.z;
        toPlayer.x = playerPos.x - propPos.x;
        toPlayer.y = playerPos.y - propPos.y;
        toPlayer.z = playerPos.z - propPos.z;
        toPlayer.FUN_0022d110();
        float num = cfg->strength;
        float scale = num / prop->controller->owner->scaler->GetScale();
        toPlayer.FUN_000344b0(scale);
        Config_176060* c = cfg;
        if (!(toProp.FUN_00018990() < c->range))
            continue;
        hits++;
        if (hits > c->maxHits)
            break;
        if (hits > 8)
            break;
        prop->FUN_001d86d0(&toPlayer, &zero);
        prop->hit = 1;
    }
    return true;
}

}
}
