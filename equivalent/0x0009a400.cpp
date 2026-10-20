// STATUS: equivalent (tools/equiv.py level 3: 3004 inputs, branch coverage 4/4)
// FUN_0009a400 @ 0x0009a400
struct Camera {
    void FUN_000361c0(int flag);
    void FUN_00036140(int flag);
};
struct Scene_9a400 { void FUN_000ac560(int v); };
struct Stage_9a400 { void FUN_00086100(float v); };
struct StageOwner { Stage_9a400* FUN_00086320(); };
struct Cast { char pad[0x124]; Camera* camera; };
struct Hud;
struct Player_9a400 { char pad[0x20]; Cast* cast; };

struct Widget_9a400 {
    char pad0[4];
    unsigned int flags;
    char pad8[4];
    StageOwner* owner;
    int f10;
    int f14;
    char pad18[0xc0 - 0x18];
    Scene_9a400* scene;
    void FUN_000991b0(Player_9a400* p, int a, int b, int c, int d);
    void FUN_0009a400(Player_9a400* p);
};

void Widget_9a400::FUN_0009a400(Player_9a400* p) {
    if (((flags >> 3) & 1) == 0)
        return;
    flags &= 0xfffffff7;
    owner->FUN_00086320()->FUN_00086100(1.0f);
    scene->FUN_000ac560(0);
    Camera* camera = p->cast->camera;
    if (camera != 0) {
        camera->FUN_000361c0(0);
        camera->FUN_00036140(0);
    }
    FUN_000991b0(p, f10, f14, 0, 0);
}
