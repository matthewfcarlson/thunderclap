// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_001f3a50 @ 0x001f3a50
class Anim_1f3a50 {
public:
    char pad0[4];
    int next;
    int current;
    void FUN_001f34f0();
    void FUN_001f32b0(int a, int b, int c);
    void FUN_001f3370(int a);
};

extern float DAT_004c7df8;
extern "C" void __cdecl FUN_00247890(int next, float speed);

class Player_1f3a50 {
public:
    char pad0[0xc4];
    Anim_1f3a50* anim;
    char pad1[0x334 - 0xc8];
    float speedScale;
    bool FUN_001f3a50(int target, int arg);
};

bool Player_1f3a50::FUN_001f3a50(int target, int arg) {
    if (!anim || !target)
        return false;
    if (anim->current != target) {
        anim->FUN_001f34f0();
        anim->FUN_001f32b0(target, 0, 0);
    }
    if (anim->next)
        FUN_00247890(anim->next, DAT_004c7df8 * speedScale * 0.01f);
    anim->FUN_001f3370(arg);
    return true;
}
