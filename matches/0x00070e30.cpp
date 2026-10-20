#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"

void* __cdecl FUN_0008d690(hulk_uintptr);
inline void* operator new(unsigned int, void* p) {
    return p;
}
void FUN_00068260();
void FUN_00069830();
void FUN_00068270();
struct FUN_00234960 {
    FUN_00234960(const char* = "timeBegin");
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    char data[12];
    void (*callback)();
    int tail;
};
struct FUN_002349e0 {
    FUN_002349e0(const char* = "string");
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    char data[12];
    void (*callback)();
    int tail;
};
struct FUN_00234cc0 {
    FUN_00234cc0(const char* = "type");
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    char data[12];
    int* list;
    int count;
    void (*callback)();
    int tail;
};
class CComboMessageTrack;
namespace fight {
template <class T> struct ParamFloatConstRange : FUN_00234960 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
};
template <class T> struct ParamString : FUN_002349e0 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
};
template <class T> struct ParamEnumConstList : FUN_00234cc0 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
};
} // namespace fight
void __cdecl FUN_002347b0(int*, void**, int);
void target() {
    if (!DAT_004dcf44) {
        void* entries[3];
        void* p = FUN_0008d690(24);
        if (p) {
            fight::ParamFloatConstRange<CComboMessageTrack>* b =
                new (p) fight::ParamFloatConstRange<CComboMessageTrack>;
            b->callback = FUN_00068260;
            entries[0] = b;
        } else
            entries[0] = 0;
        p = FUN_0008d690(24);
        if (p) {
            fight::ParamString<CComboMessageTrack>* b = new (p) fight::ParamString<CComboMessageTrack>;
            b->callback = FUN_00069830;
            entries[1] = b;
        } else
            entries[1] = 0;
        p = FUN_0008d690(32);
        if (p) {
            fight::ParamEnumConstList<CComboMessageTrack>* b =
                new (p) fight::ParamEnumConstList<CComboMessageTrack>;
            b->list = ((int*)&DAT_00496f8c);
            b->count = 4;
            b->callback = FUN_00068270;
            entries[2] = b;
        } else
            entries[2] = 0;
        FUN_002347b0(&DAT_004dcf40, entries, 3);
    }
    ++DAT_004dcf44;
}