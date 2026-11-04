#include "decls/data/game/hulkfight/motion.h"
#include "gen/fight.h"

inline void* operator new(unsigned int, void* p) {
    return p;
}
extern void* __cdecl FUN_0008d690(unsigned int);
extern void __cdecl SetTimeBegin_001330b0();
extern void __cdecl SetTimeEnd_001330c0();
extern void __cdecl SetGroundFixup_001330e0();
struct ParamStorage {
    char storage[24];
    void FUN_002348e0(const char*);
};
struct Base_137b60 {
    virtual void slot0();
    char data[12];
    void(__cdecl* callback)();
    int tail;
};
namespace hulkfight {
namespace motion {
class GrappleHoverTrack_137b60;
}
} // namespace hulkfight
namespace fight {
template <class T> struct ParamFloatConstRange_137b60 : Base_137b60 {
    virtual void slot0();
};
template <class T> struct ParamIntConstRange_137b60 : Base_137b60 {
    virtual void slot0();
};
} // namespace fight
extern void __cdecl FUN_002347b0(int*, Base_137b60**, int);
void target() {
    if (!DAT_004e0ecc) {
        Base_137b60* entries[3];
        void* p = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_137b60<hulkfight::motion::GrappleHoverTrack_137b60>));
        if (p) {
            ((fight::ParamValueFloat *)(((ParamStorage*)p)))->FUN_00234960("timeBegin");
            fight::ParamFloatConstRange_137b60<hulkfight::motion::GrappleHoverTrack_137b60>* a =
                new (p) fight::ParamFloatConstRange_137b60<hulkfight::motion::GrappleHoverTrack_137b60>;
            a->callback = SetTimeBegin_001330b0;
            entries[0] = a;
        } else
            entries[0] = 0;
        p = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_137b60<hulkfight::motion::GrappleHoverTrack_137b60>));
        if (p) {
            ((fight::ParamValueFloat *)(((ParamStorage*)p)))->FUN_00234960("timeEnd");
            fight::ParamFloatConstRange_137b60<hulkfight::motion::GrappleHoverTrack_137b60>* a =
                new (p) fight::ParamFloatConstRange_137b60<hulkfight::motion::GrappleHoverTrack_137b60>;
            a->callback = SetTimeEnd_001330c0;
            entries[1] = a;
        } else
            entries[1] = 0;
        p = FUN_0008d690((int)sizeof(fight::ParamIntConstRange_137b60<hulkfight::motion::GrappleHoverTrack_137b60>));
        if (p) {
            ((ParamStorage*)p)->FUN_002348e0("groundFixup");
            fight::ParamIntConstRange_137b60<hulkfight::motion::GrappleHoverTrack_137b60>* a =
                new (p) fight::ParamIntConstRange_137b60<hulkfight::motion::GrappleHoverTrack_137b60>;
            a->callback = SetGroundFixup_001330e0;
            entries[2] = a;
        } else
            entries[2] = 0;
        FUN_002347b0(&DAT_004e0ec8, entries, 3);
    }
    ++DAT_004e0ecc;
}
