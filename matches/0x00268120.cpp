// FUN_00268120 @ 0x00268120
#include "decls/data/engine/core.h"

void __cdecl FUN_002705f0();
void __cdecl FUN_002702a0(void *, unsigned, unsigned, unsigned, unsigned, const char *, unsigned);
void *__cdecl FUN_00266e00(unsigned, unsigned);
namespace core {
struct ITimerList {
    virtual void timerMethod();
};
struct Object {
    int id;
    virtual void objectMethod();
    Object() {
        id = DAT_004cdbb0;
        FUN_002705f0();
    }
};
struct TimerList : ITimerList, Object {
    int active;
    char enabled;
    char reserved[7];
    char entries[4];
    unsigned count;
    void **items;
    TimerList(unsigned size, unsigned tag);
    virtual void timerMethod();
    virtual void objectMethod();
};
TimerList::TimerList(unsigned size, unsigned tag) {
    active = 1;
    enabled = 0;
    count = size;
    FUN_002705f0();
    FUN_002702a0(entries, 0x24, size, 0, tag, "TimerList", 4);
    items = (void **)FUN_00266e00(tag, size * 4);
    FUN_002705f0();
    for (unsigned i = 0; i < size; ++i)
        items[i] = 0;
}
}
