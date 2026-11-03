#include "decls/data/game/hulkfight/ai.h"
#include "gen/fight.h"

inline void* operator new(unsigned int, void* memory) {
    return memory;
}
void* __cdecl FUN_0008d690(unsigned int);
void __cdecl FUN_0012b190();
void __cdecl FUN_0012b1a0();
void __cdecl FUN_0012b1b0();
namespace hulkfight {
namespace ai {
class ThreatCondition_12cd80;
}
} // namespace hulkfight
struct Base_12cd80 {
    virtual void slot0();
    char pad[12];
    void(__cdecl* callback)();
    int tail;
};
namespace fight {
template <class T> struct ParamBool_12cd80 : Base_12cd80 {
    virtual void slot0();
};
template <class T> struct ParamName_12cd80 : Base_12cd80 {
    virtual void slot0();
};
} // namespace fight
void __cdecl FUN_002347b0(void*, void**, int);
void FUN_0012cd80() {
    if (!DAT_004e0e18) {
        void* params[3];
        Base_12cd80* mem = (Base_12cd80*)FUN_0008d690(24);
        if (mem) {
            ((fight::ParamValueBool *)(Base_12cd80 *)mem)->FUN_00234860("threat");
            fight::ParamBool_12cd80<hulkfight::ai::ThreatCondition_12cd80>* p =
                new (mem) fight::ParamBool_12cd80<hulkfight::ai::ThreatCondition_12cd80>;
            p->callback = FUN_0012b190;
            params[0] = p;
        } else
            params[0] = 0;
        mem = (Base_12cd80*)FUN_0008d690(24);
        if (mem) {
            ((fight::ParamValueName *)(Base_12cd80 *)mem)->FUN_00234a90("threatName");
            fight::ParamName_12cd80<hulkfight::ai::ThreatCondition_12cd80>* p =
                new (mem) fight::ParamName_12cd80<hulkfight::ai::ThreatCondition_12cd80>;
            p->callback = FUN_0012b1a0;
            params[1] = p;
        } else
            params[1] = 0;
        mem = (Base_12cd80*)FUN_0008d690(24);
        if (mem) {
            ((fight::ParamValueBool *)(Base_12cd80 *)mem)->FUN_00234860("threatRespondOnlyOnce");
            fight::ParamBool_12cd80<hulkfight::ai::ThreatCondition_12cd80>* p =
                new (mem) fight::ParamBool_12cd80<hulkfight::ai::ThreatCondition_12cd80>;
            p->callback = FUN_0012b1b0;
            params[2] = p;
        } else
            params[2] = 0;
        FUN_002347b0(&DAT_004e0e14, params, 3);
    }
    ++DAT_004e0e18;
}