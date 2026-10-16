// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 14/14)
// FUN_0008ced0 @ 0x0008ced0
#include "decls/data/game/unknown.h"

struct NameEntry_8ced0 {
    const char *name;
    int a, b;
};

class Slot_8ced0 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8();
    virtual void Query(int *x, int *c, int *b, int *a);   // slot 9
    virtual void v10();
    virtual int GetCount();                               // slot 11
};

class SlotTable_8ced0 {
public:
    int header;
    Slot_8ced0 *slots[19];         // 0x04
    void FUN_0008ced0(int index, int *outCount, int *outX, int *outA, int *outB, const char **outName);
};

void SlotTable_8ced0::FUN_0008ced0(int index, int *outCount, int *outX, int *outA, int *outB, const char **outName) {
    int slot = index;
    if (slot < 19 && slots[slot] != 0) {
        int a, b, c;
        slots[slot]->Query(&index, &c, &b, &a);
        if (outX)
            *outX = index;
        if (outA)
            *outA = a;
        if (outCount)
            *outCount = slots[slot]->GetCount();
        if (outB)
            *outB = b;
        if (outName)
            *outName = ((NameEntry_8ced0*)&DAT_00400520)[slot].name;
    }
}
