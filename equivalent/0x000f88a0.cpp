// STATUS: equivalent (tools/equiv.py level 3: 19991 inputs, branch coverage 8/8)
// FUN_000f88a0 @ 0x000f88a0
#include "compat/ptr.h"
class Font {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6();
    virtual float GetHeight();                                      // slot 7
    virtual void v8(); virtual void v9();
    virtual float GetWidth(const unsigned short *text);             // slot 10
};

struct Owner_f88a0 {
    char pad0[0x24];
    Font *fonts[1];         // 0x24
};

struct StyleEntry {
    float width;
    float pad[3];
};

class Label_f88a0;

struct Run_f88a0 {
    int fontIndex;          // 0x0
    const unsigned short *FUN_000f83f0(Owner_f88a0 *owner, Label_f88a0 *label);
};

class Label_f88a0 {
public:
    Owner_f88a0 *owner;           // 0x0
    char pad4[4];
    StyleEntry styles[8];   // 0x8
    int style;              // 0x88
    float spacing;          // 0x8c

    hulk_freg FUN_000f88a0(Run_f88a0 *run);
};

static __forceinline int CountBackspaces(const unsigned short *p)
{
    int count = 0;
    if (p != 0) {
        for (; *p != 0; p++) {
            if (*p == 8)
                count++;
        }
    }
    return count;
}

hulk_freg Label_f88a0::FUN_000f88a0(Run_f88a0 *run)
{
    const unsigned short *text = run->FUN_000f83f0(owner, this);
    Font *font = owner->fonts[run->fontIndex];
    Font *first = owner->fonts[0];
    StyleEntry *entry = &styles[style];
    float scale = 14.0f / first->GetHeight();
    float width = font->GetWidth(text) * entry->width * scale;
    return width - ((CountBackspaces(text) * 0.073f) * spacing);
}
