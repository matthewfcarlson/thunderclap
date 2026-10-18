// FUN_00361760 @ 0x00361760
#include "decls/data/platform/xbox/core.h"

struct Slot_361760 {
    void* p;
    int a;
    int b;
};


void FUN_00361760()
{
    void* first = (*(void**)&DAT_004cd698);
    void* fourth = (*(void**)&DAT_004cd6a4);
    for (int i = 0; i < 8; i++) {
        ((Slot_361760*)&DAT_004cd6a8)[i].p = first;
    }
    void* second = (*(void**)&DAT_004cd69c);
    for (int i = 8; i < 16; i++) {
        ((Slot_361760*)&DAT_004cd6a8)[i].p = second;
    }
    void* third = (*(void**)&DAT_004cd6a0);
    ((Slot_361760*)&DAT_004cd6a8)[16].p = third;
    ((Slot_361760*)&DAT_004cd6a8)[17].p = fourth;
    ((Slot_361760*)&DAT_004cd6a8)[18].p = third;
    ((Slot_361760*)&DAT_004cd6a8)[19].p = fourth;
}
