// STATUS: equivalent (tools/equiv.py level 3: 2996 inputs, branch coverage 4/4)
// hulkfight::ai::TokenSupressAction::vfunc_3 @ 0x0010de70
struct Stats_10de70 {
    char pad0[0x18];
    float value;
};
struct Singleton_10de70 {
    char pad0[0x368];
    int f368;
    void FUN_000661f0();
};
void* __fastcall FUN_000592a0(void* p);
void* __fastcall FUN_00059a30(void* p);
Singleton_10de70* FUN_000678d0();
namespace hulkfight { namespace ai {
class TokenSupressAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual bool vfunc_3(int a, int b);
    char pad04[0x18];
    Stats_10de70* stats;
    void* owner;
    int saved;
};
bool TokenSupressAction::vfunc_3(int a, int b) {
    if (owner == 0)
        return false;
    FUN_00059a30(FUN_000592a0(owner));
    saved = FUN_000678d0()->f368;
    if (stats->value >= 0.0f) {
        int bits = *(int*)&stats->value;
        FUN_000678d0()->f368 = bits;
    }
    FUN_000678d0()->FUN_000661f0();
    return true;
}
}}
