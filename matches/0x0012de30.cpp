#include "decls/data/game/hulkfight.h"

void* __cdecl FUN_0008d690(unsigned int);
void __cdecl FUN_0012d920();
void __cdecl FUN_0012d930();
void __cdecl FUN_0012d950();
void __cdecl FUN_0012d970();
struct FUN_00234960 {
    FUN_00234960(const char* s = "timeBegin");
    virtual void slot0();
    char pad[12];
    void(__cdecl* callback)();
    char tail[4];
};
struct FUN_00234a90 {
    FUN_00234a90(const char* s = "text");
    virtual void slot0();
    char pad[12];
    void(__cdecl* callback)();
    char tail[4];
};
struct FUN_00234860 {
    FUN_00234860(const char* s = "onlyInTutorialMode");
    virtual void slot0();
    char pad[12];
    void(__cdecl* callback)();
    char tail[4];
};
namespace hulkfight {
class PostEvent_StringTrack;
}
namespace fight {
template <class T> struct ParamFloatConstRange : FUN_00234960 {
    virtual void slot0();
};
template <class T> struct ParamName : FUN_00234a90 {
    virtual void slot0();
};
template <class T> struct ParamBool : FUN_00234860 {
    virtual void slot0();
    ParamBool(const char* s = "onlyInTutorialMode") : FUN_00234860(s) {}
};
} // namespace fight
inline void* __cdecl operator new(unsigned int, void* p) {
    return p;
}
void __cdecl FUN_002347b0(int*, void**, int);
void target() {
    if (DAT_004e0e48 == 0) {
        void* items[4];
        void* p = FUN_0008d690(24);
        if (p) {
            fight::ParamFloatConstRange<hulkfight::PostEvent_StringTrack>* a =
                new (p) fight::ParamFloatConstRange<hulkfight::PostEvent_StringTrack>;
            a->callback = FUN_0012d920;
            items[0] = a;
        } else
            items[0] = 0;
        p = FUN_0008d690(24);
        if (p) {
            fight::ParamName<hulkfight::PostEvent_StringTrack>* a =
                new (p) fight::ParamName<hulkfight::PostEvent_StringTrack>;
            a->callback = FUN_0012d930;
            items[1] = a;
        } else
            items[1] = 0;
        p = FUN_0008d690(24);
        if (p) {
            fight::ParamBool<hulkfight::PostEvent_StringTrack>* a =
                new (p) fight::ParamBool<hulkfight::PostEvent_StringTrack>("onlyInTutorialMode");
            a->callback = FUN_0012d950;
            items[2] = a;
        } else
            items[2] = 0;
        p = FUN_0008d690(24);
        if (p) {
            fight::ParamBool<hulkfight::PostEvent_StringTrack>* a =
                new (p) fight::ParamBool<hulkfight::PostEvent_StringTrack>("unique");
            a->callback = FUN_0012d970;
            items[3] = a;
        } else
            items[3] = 0;
        FUN_002347b0(&DAT_004e0e44, items, 4);
    }
    ++DAT_004e0e48;
}