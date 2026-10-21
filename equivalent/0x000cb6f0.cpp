// STATUS: equivalent (tools/equiv.py level 3: 20004 inputs, branch coverage 2/2)
// FUN_000cb6f0 @ 0x000cb6f0
#include "decls/data/game/global.h"
#include "compat/ptr.h"

struct Segment {
    virtual void unused0(); virtual void unused1(); virtual void unused2(); virtual void unused3();
    virtual void unused4(); virtual void unused5(); virtual void unused6();
    virtual float getDivisor();
    virtual void unused8(); virtual float evaluate(void* value);
};
struct Table {
    char reserved[0x24];
    Segment* segments[1];
    void* FUN_000f7220(int position);
};
struct Object {
    Table* table;
    char reserved[0x84];
    int selected;
    hulk_freg FUN_000cb6f0(int position, int index);
};
hulk_freg Object::FUN_000cb6f0(int position, int index) {
    if (position < 0) return (*(float*)&DAT_003f32e0);
    Segment* base = table->segments[0];
    Segment* item = table->segments[index];
    int chosen = selected;
    volatile float* value = (volatile float*)((char*)this + 8 + chosen * 16);
    float result = item->evaluate(table->FUN_000f7220(position));
    float divisor = base->getDivisor();
    double product = (*value / divisor) * result; // keep the original's multiplication order
    return product * (*(float*)&DAT_0040cc38);
}