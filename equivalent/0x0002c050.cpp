// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_0002c050 @ 0x0002c050
extern float DAT_003f3ef4;
struct Loc_2c050 { int x, y, z; };
struct Pose { int x, y, z; float deg; };
class Object {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void GetPos(Loc_2c050* out);
    virtual float GetAngle();
};
struct Finder_2c050 { Object* FUN_001fd780(int key); };
struct Env_2c050 { char pad[0x28]; Finder_2c050* finder; };
struct Actor_2c050 {
    Env_2c050* env;
    char FUN_0002b970(int a1, Pose pose, int a3, int a4, int a5, int a6, int flag);
    char Place(int a1, int key, int a3, int a4, int a5, int a6);
};
char Actor_2c050::Place(int a1, int key, int a3, int a4, int a5, int a6) {
    if (!env->finder) return 0;
    Object* o = env->finder->FUN_001fd780(key);
    if (!o) return 0;
    Loc_2c050 loc;
    o->GetPos(&loc);
    Pose pose;
    pose.deg = o->GetAngle() * DAT_003f3ef4;
    pose.x = loc.x; pose.y = loc.y; pose.z = loc.z;
    return FUN_0002b970(a1, pose, a3, a4, a5, a6, 1);
}
