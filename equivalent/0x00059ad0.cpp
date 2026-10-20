// STATUS: equivalent (tools/equiv.py level 3: 69 inputs, branch coverage 8/8)
// FUN_00059ad0 @ 0x00059ad0
#include "compat/ptr.h"
extern "C" void *__cdecl FUN_0008d6d0(hulk_uintptr size);

struct Entry_59ad0 {
    int f00, f04, f08, f0c, f10, f14, f18;
    int f1c, f20;
};

class EntryPool {
public:
    int f00;
    unsigned int count;
    Entry_59ad0 *entries;
    unsigned char *flags;
    EntryPool *FUN_00059ad0();
};

EntryPool *EntryPool::FUN_00059ad0()
{
    f00 = 1;
    count = 100;
    unsigned int *raw = (unsigned int *)FUN_0008d6d0(100 * sizeof(Entry_59ad0) + 4);
    Entry_59ad0 *array = 0;
    if (raw) {
        *raw = 100;
        array = (Entry_59ad0 *)(raw + 1);
        for (int i = 0; i < 100; i++) {
            Entry_59ad0 *e = &array[i];
            e->f00 = 0;
            e->f04 = 0;
            e->f08 = 0;
            e->f0c = 0;
            e->f10 = 0;
            e->f14 = 0;
            e->f18 = 0;
        }
    }
    entries = array;
    flags = (unsigned char *)FUN_0008d6d0(count);
    for (unsigned int i = 0; i < count; i++)
        flags[i] = 0;
    return this;
}
