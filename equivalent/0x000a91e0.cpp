// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_000a91e0 @ 0x000a91e0
struct Vec3_a91e0 {
    float x, y, z;
    float FUN_0022d110();
};
struct Info_a91e0 {
    char pad0[0x20];
    Vec3_a91e0 dir;
    char pad1[4];
    Vec3_a91e0 pos;
};
class Owner_a91e0 {
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
    virtual Info_a91e0* GetInfo();
    bool FUN_000a91e0(const Vec3_a91e0* target);
};
bool Owner_a91e0::FUN_000a91e0(const Vec3_a91e0* target) {
    Info_a91e0* info = GetInfo();
    Vec3_a91e0 d;
    d.z = target->z - info->pos.z;
    d.y = target->y - info->pos.y;
    d.x = target->x - info->pos.x;
    d.FUN_0022d110();
    Info_a91e0* info2 = GetInfo();
    return d.z * info2->dir.z + d.y * info2->dir.y + d.x * info2->dir.x < 0.3f;
}
