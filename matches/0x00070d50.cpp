#include "decls/data/game/global.h"

void* __cdecl FUN_0008d690(unsigned int);
void __cdecl FUN_00068250();
void __cdecl FUN_00069730();
void __cdecl FUN_00069750();
void __cdecl FUN_002347b0(void*, void**, int);
inline void* __cdecl operator new(unsigned int, void* p) {
    return p;
}
class CSoundTrack;
struct FUN_00234960 {
    FUN_00234960(const char* = "timeBegin");
    virtual void slot0();
    char data[12];
    void(__cdecl* callback)();
    int tail;
};
struct FUN_002349e0 {
    FUN_002349e0(const char* = "sound");
    virtual void slot0();
    char data[12];
    void(__cdecl* callback)();
    int tail;
};
struct FUN_00234860 {
    FUN_00234860(const char* = "weapon");
    virtual void slot0();
    char data[12];
    void(__cdecl* callback)();
    int tail;
};
namespace fight {
template <class T> struct ParamFloatConstRange : FUN_00234960 {
    virtual void slot0();
};
template <class T> struct ParamString : FUN_002349e0 {
    virtual void slot0();
};
template <class T> struct ParamBool : FUN_00234860 {
    virtual void slot0();
};
} // namespace fight
void FUN_00070d50() {
    if (DAT_004dcf3c == 0) {
        void* params[3];
        void* mem = FUN_0008d690(24);
        if (mem) {
            fight::ParamFloatConstRange<CSoundTrack>* p = new (mem) fight::ParamFloatConstRange<CSoundTrack>;
            p->callback = FUN_00068250;
            params[0] = p;
        } else
            params[0] = 0;
        mem = FUN_0008d690(24);
        if (mem) {
            fight::ParamString<CSoundTrack>* p = new (mem) fight::ParamString<CSoundTrack>;
            p->callback = FUN_00069730;
            params[1] = p;
        } else
            params[1] = 0;
        mem = FUN_0008d690(24);
        if (mem) {
            fight::ParamBool<CSoundTrack>* p = new (mem) fight::ParamBool<CSoundTrack>;
            p->callback = FUN_00069750;
            params[2] = p;
        } else
            params[2] = 0;
        FUN_002347b0(&DAT_004dcf38, params, 3);
    }
    ++DAT_004dcf3c;
}