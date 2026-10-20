#include "compat/ptr.h"
#include "decls/data/game/hulkfight/motion.h"

inline void* operator new(unsigned int, void* p) {
    return p;
}
extern void* __cdecl FUN_0008d690(hulk_uintptr);
extern void __cdecl FUN_001330b0();
extern void __cdecl FUN_001330c0();
extern void __cdecl FUN_001330e0();
struct ParamStorage {
    char storage[24];
    void FUN_00234960(const char*);
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
class GrappleHoverTrack;
}
} // namespace hulkfight
namespace fight {
template <class T> struct ParamFloatConstRange : Base_137b60 {
    virtual void slot0();
};
template <class T> struct ParamIntConstRange : Base_137b60 {
    virtual void slot0();
};
} // namespace fight
extern void __cdecl FUN_002347b0(int*, Base_137b60**, int);
void target() {
    if (!DAT_004e0ecc) {
        Base_137b60* entries[3];
        void* p = FUN_0008d690(24);
        if (p) {
            ((ParamStorage*)p)->FUN_00234960("timeBegin");
            fight::ParamFloatConstRange<hulkfight::motion::GrappleHoverTrack>* a =
                new (p) fight::ParamFloatConstRange<hulkfight::motion::GrappleHoverTrack>;
            a->callback = FUN_001330b0;
            entries[0] = a;
        } else
            entries[0] = 0;
        p = FUN_0008d690(24);
        if (p) {
            ((ParamStorage*)p)->FUN_00234960("timeEnd");
            fight::ParamFloatConstRange<hulkfight::motion::GrappleHoverTrack>* a =
                new (p) fight::ParamFloatConstRange<hulkfight::motion::GrappleHoverTrack>;
            a->callback = FUN_001330c0;
            entries[1] = a;
        } else
            entries[1] = 0;
        p = FUN_0008d690(24);
        if (p) {
            ((ParamStorage*)p)->FUN_002348e0("groundFixup");
            fight::ParamIntConstRange<hulkfight::motion::GrappleHoverTrack>* a =
                new (p) fight::ParamIntConstRange<hulkfight::motion::GrappleHoverTrack>;
            a->callback = FUN_001330e0;
            entries[2] = a;
        } else
            entries[2] = 0;
        FUN_002347b0(&DAT_004e0ec8, entries, 3);
    }
    ++DAT_004e0ecc;
}
