inline void* operator new(unsigned int, void* memory) {
    return memory;
}
void* __cdecl FUN_0008d690(unsigned int);
void __cdecl FUN_0012b190();
void __cdecl FUN_0012b1a0();
void __cdecl FUN_0012b1b0();
namespace hulkfight {
namespace ai {
class ThreatCondition;
}
} // namespace hulkfight
struct Base_12cd80 {
    virtual void slot0();
    char pad[12];
    void(__cdecl* callback)();
    int tail;
    void FUN_00234860(const char*);
    void FUN_00234a90(const char*);
};
namespace fight {
template <class T> struct ParamBool : Base_12cd80 {
    virtual void slot0();
};
template <class T> struct ParamName : Base_12cd80 {
    virtual void slot0();
};
} // namespace fight
extern int DAT_004e0e18;
extern int DAT_004e0e14;
void __cdecl FUN_002347b0(void*, void**, int);
void FUN_0012cd80() {
    if (!DAT_004e0e18) {
        void* params[3];
        Base_12cd80* mem = (Base_12cd80*)FUN_0008d690(24);
        if (mem) {
            mem->FUN_00234860("threat");
            fight::ParamBool<hulkfight::ai::ThreatCondition>* p =
                new (mem) fight::ParamBool<hulkfight::ai::ThreatCondition>;
            p->callback = FUN_0012b190;
            params[0] = p;
        } else
            params[0] = 0;
        mem = (Base_12cd80*)FUN_0008d690(24);
        if (mem) {
            mem->FUN_00234a90("threatName");
            fight::ParamName<hulkfight::ai::ThreatCondition>* p =
                new (mem) fight::ParamName<hulkfight::ai::ThreatCondition>;
            p->callback = FUN_0012b1a0;
            params[1] = p;
        } else
            params[1] = 0;
        mem = (Base_12cd80*)FUN_0008d690(24);
        if (mem) {
            mem->FUN_00234860("threatRespondOnlyOnce");
            fight::ParamBool<hulkfight::ai::ThreatCondition>* p =
                new (mem) fight::ParamBool<hulkfight::ai::ThreatCondition>;
            p->callback = FUN_0012b1b0;
            params[2] = p;
        } else
            params[2] = 0;
        FUN_002347b0(&DAT_004e0e14, params, 3);
    }
    ++DAT_004e0e18;
}