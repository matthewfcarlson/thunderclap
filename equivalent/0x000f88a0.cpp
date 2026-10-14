// STATUS: equivalent (tools/equiv.py level 3: 1320 inputs, branch coverage 8/8)
// FUN_000f88a0 @ 0x000f88a0
class Font {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6();
    virtual float GetHeight();                                      // slot 7
    virtual void v8(); virtual void v9();
    virtual float GetWidth(const unsigned short *text);             // slot 10
};

struct Owner {
    char pad0[0x24];
    Font *fonts[1];         // 0x24
};

struct StyleEntry {
    float width;
    float pad[3];
};

class Label;

struct Run {
    int fontIndex;          // 0x0
    const unsigned short *FUN_000f83f0(Owner *owner, Label *label);
};

class Label {
public:
    Owner *owner;           // 0x0
    char pad4[4];
    StyleEntry styles[8];   // 0x8
    int style;              // 0x88
    float spacing;          // 0x8c

    float FUN_000f88a0(Run *run);
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

float Label::FUN_000f88a0(Run *run)
{
    const unsigned short *text = run->FUN_000f83f0(owner, this);
    Font *font = owner->fonts[run->fontIndex];
    Font *first = owner->fonts[0];
    StyleEntry *entry = &styles[style];
    float scale = 14.0f / first->GetHeight();
    float width = font->GetWidth(text) * entry->width * scale;
    return width - ((CountBackspaces(text) * 0.073f) * spacing);
}
