// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_000a91e0 @ 0x000a91e0
struct Vec3 {
    float x, y, z;
    float FUN_0022d110();
};
struct Info {
    char pad0[0x20];
    Vec3 dir;
    char pad1[4];
    Vec3 pos;
};
class Owner {
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
    virtual Info* GetInfo();
    bool FUN_000a91e0(const Vec3* target);
};
bool Owner::FUN_000a91e0(const Vec3* target) {
    Info* info = GetInfo();
    Vec3 d;
    d.z = target->z - info->pos.z;
    d.y = target->y - info->pos.y;
    d.x = target->x - info->pos.x;
    d.FUN_0022d110();
    Info* info2 = GetInfo();
    return d.z * info2->dir.z + d.y * info2->dir.y + d.x * info2->dir.x < 0.3f;
}
